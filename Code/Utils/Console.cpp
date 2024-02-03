#include "Console.hpp"

#if 1
namespace Engine
{
	HANDLE Console::Handle = NULL;
	__ConsoleOutputHandler Console::Out = {};

	bool Console::CreateEngineConsole(const wchar_t* title)
	{
		if (Console::Handle == NULL)
		{
			if (AllocConsole())
			{
				SetConsoleOutputCP(CP_UTF8);
				SetConsoleTitleW(title);

				Console::Handle = GetStdHandle(STD_OUTPUT_HANDLE);

				return true;
			}
		}

		return false;
	}

	bool Console::AttachToConsole()
	{
		if (Console::Handle == NULL)
		{
			Console::Handle = GetStdHandle(STD_OUTPUT_HANDLE);
			return (Console::Handle != NULL);
		}

		return false;
	}

	void Console::DestroyConsole()
	{
		if (Console::Handle == NULL) return;

		FreeConsole();
		Console::Handle = NULL;
	}
}
#endif