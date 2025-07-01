#include "core/commands/Command.hpp"
#include "game/gta/ScriptLocal.hpp"

namespace YimMenu::Features
{
	class SkipNextObjective : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			if (auto thread = Scripts::FindScriptThread("fm_mission_controller_2020"_J))
			{
				*ScriptLocal(thread, 54763).At(2).As<int*>() = (1 << 17);  //1.71  iLocal_54763.f_2;  fm_mission_controller_2020.c
			}
			if (auto thread = Scripts::FindScriptThread("fm_mission_controller"_J))
			{
				*ScriptLocal(thread, 20391).At(2).As<int*>() = (1 << 17);  //171  iLocal_20391.f_2, 17  fm_mission_controller.c
			}
		}
	};

	static SkipNextObjective _SkipNextObjective{ "skipnextobjective", "Skip Next Objective", "" };
}