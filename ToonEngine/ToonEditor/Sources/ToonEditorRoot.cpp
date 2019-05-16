#include "stdafx.h"
#include "ToonEditorRoot.h"

#include <ToonLogger.h>
#include <ToonObfuscator.h>
#include <ToonTimer.h>
#include <ToonFileSystem.h>
#include <ToonRenderSystem.h>
#include <ToonSystemMessageBus.h>
#include <ToonSystemMessage.h>
#include <ToonExceptions.h>
#include <ToonInputSystem.h>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_internal.h>

namespace Common
{
	template <> ToonEditor::ToonEditorRoot* Singleton<ToonEditor::ToonEditorRoot>::instance = nullptr;
}

namespace ToonEditor
{
	/****************************************************************************
						ToonRoot class definition
	****************************************************************************/
	ToonEditorRoot::ToonEditorRoot()
		: super_t()
	{
		ImGui_ImplGlfwGL3_Init(window, true);

	}
	ToonEditorRoot::~ToonEditorRoot()
	{
		ImGui_ImplGlfwGL3_NewFrame();
	}

	void ToonEditorRoot::drawToolbar(void) noexcept
	{
	}
	void ToonEditorRoot::drawToolbox(void) noexcept
	{
	}
	void ToonEditorRoot::drawPreview(void) noexcept
	{
	}
	void ToonEditorRoot::drawFooter(void) noexcept
	{
	}
	void ToonEditorRoot::drawMenubar(void) noexcept
	{
		if (ImGui::BeginMenuBar())
		{
			if (ImGui::BeginMenu("FILE"))
			{
				ImGui::EndMenu();
			}
			if (ImGui::BeginMenu("EDIT"))
			{
				ImGui::EndMenu();
			}
			if (ImGui::BeginMenu("VIEW"))
			{
				ImGui::EndMenu();
			}
			if (ImGui::BeginMenu("PROJECT"))
			{
				ImGui::EndMenu();
			}
			if (ImGui::BeginMenu("BUILD"))
			{
				ImGui::EndMenu();
			}
			if (ImGui::BeginMenu("TOOLS"))
			{
				ImGui::EndMenu();
			}
			if (ImGui::BeginMenu("HELP"))
			{
				ImGui::EndMenu();
			}
		}
		ImGui::EndMainMenuBar();
	}
	int ToonEditorRoot::runMainLoop(void) noexcept
	{
		//timer reset
		timer->reset();

		initialUpdate();

		while (!renderSystem->getWindowShouldClose())
		{
			timer->tick();
			float dt = timer->getDeltaTime();
			float totalTime = timer->getTotalTime();

			if (timer->isPaused())
			{
				SleepCrossPlatform(100U);
			}
			else
			{
				drawMenubar();
				preUpdateScene(dt); // 1) pre-simulation step
				updateScene(dt);    // 2) simulation	 step
				preDrawScene();	    // 3) pre-draw		 step
				drawScene();	    // 4) darw  		 step
			}
		}

		return 0;
	}
};