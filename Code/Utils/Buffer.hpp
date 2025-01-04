#pragma once

#include <fstream>
#include <vector>

class WriteBuffer
{
public:
	WriteBuffer() = default;
	~WriteBuffer() = default;

	void writeBytes(const void* data, std::size_t dataSize)
	{
		m_bytes.insert(
			m_bytes.end(),
			reinterpret_cast<const std::uint8_t*>(data),
			reinterpret_cast<const std::uint8_t*>(data) + dataSize
		);
	}

	template<typename T>
	void writeObject(const T& obj)
	{
		this->writeBytes(&obj, sizeof(T));
	}

	void writeString(const std::string& str)
	{
		// Truncate the string size so there can only be 255 characters
		const std::uint8_t v_strSz = (std::uint8_t)str.size();

		this->writeObject(v_strSz);
		this->writeBytes(str.c_str(), (std::size_t)v_strSz);
	}

	bool writeToFile(const char* path) const
	{
		std::ofstream v_outFile(path, std::ios::binary);
		if (!v_outFile.is_open()) return false;

		v_outFile.write(reinterpret_cast<const char*>(m_bytes.data()), m_bytes.size());
		return true;
	}

private:
	std::vector<std::uint8_t> m_bytes;
};

class ReadBuffer
{
public:
	inline ReadBuffer(const std::vector<std::uint8_t>& vecBytes) noexcept :
		m_begin(vecBytes.data()),
		m_end(vecBytes.data() + vecBytes.size()),
		m_ptr(vecBytes.data())
	{}

	bool hasEnoughBytes(std::size_t readSize) const
	{
		return (m_ptr + readSize) <= m_end;
	}

	bool readBytes(void* outBuffer, std::size_t readSize)
	{
		if (!this->hasEnoughBytes(readSize))
			return false;

		std::memcpy(outBuffer, m_ptr, readSize);
		m_ptr += readSize;

		return true;
	}

	template<typename T>
	bool readObject(T* objPtr)
	{
		return this->readBytes(objPtr, sizeof(T));
	}

	bool readString(std::string& outString)
	{
		std::uint8_t v_strSz;
		if (!this->readObject(&v_strSz)) return false;

		outString.resize(v_strSz);
		return this->readBytes(&outString[0], outString.size());
	}

	static bool ReadFromFile(const char* filePath, std::vector<std::uint8_t>& outBytes)
	{
		std::ifstream v_inputFile(filePath, std::ios::binary | std::ios::ate);
		if (!v_inputFile.is_open()) return false;

		outBytes.resize(v_inputFile.tellg());
		v_inputFile.seekg(0, std::ios::beg);
		v_inputFile.read(reinterpret_cast<char*>(outBytes.data()), outBytes.size());

		return true;
	}

private:
	const std::uint8_t* m_begin;
	const std::uint8_t* m_end;
	const std::uint8_t* m_ptr;
};