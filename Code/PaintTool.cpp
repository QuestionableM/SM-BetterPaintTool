#include "PaintTool.hpp"

#include "Utils/Console.hpp"
#include "PaintToolGui.hpp"

PaintTool::t_init_sig PaintTool::o_initialize = nullptr;

bool PaintTool::h_initialize(PaintTool* self)
{
	const bool v_out = PaintTool::o_initialize(self);

	if (self->m_pGuiInterface)
	{
		self->m_pGuiInterface->m_mapStringToFunction.emplace("HexInput",
			[self](const std::string& str) -> void {
				Color v_color(str);

				self->visualization_color = v_color;
				self->paint_color = v_color;
				self->network_data->paint_color = v_color;
			}
		);

		self->m_pGuiInterface->m_mapStringToFunction.emplace("InitFunc",
			[self](const std::string& str) -> void {
				std::dynamic_pointer_cast<PaintToolGui, GuiBase>(
					self->m_pGuiInterface->m_pGuiBase)->initParams(self);
			}
		);
	}

	return v_out;
}