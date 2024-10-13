#include "App.h"
#include <string>

void ResizeBuffer(std::string &buffer, size_t newSize)
{
	if(newSize > buffer.size())
	{
		buffer.resize(newSize);
	}
}

App::App() : showDemoWindow_(false), textBuffer("")
{ }

App::~App()
{ }

void App::init()
{ }

void App::update()
{
	// Enable docking 
	ImGui::DockSpaceOverViewport(0, ImGui::GetMainViewport());

	showMenuBar();

	// sidebar for different modes
	{
		ImGui::Begin("Side Bar");

		ImGui::Text("Side bar menu");

		ImGui::End();
	}

	if(showDemoWindow_)
	{
		ImGui::ShowDemoWindow(&showDemoWindow_);
	}

	{
		ImGui::Begin("Story");

		ImGui::InputTextMultiline("##StoryLine", &textBuffer[0], textBuffer.size(), ImVec2(-FLT_MIN, ImGui::GetTextLineHeight() * 16), ImGuiInputTextFlags_AllowTabInput);

		if(ImGui::IsItemActive() || ImGui::IsItemFocused())
		{
			if(ImGui::GetIO().KeysDown[ImGuiKey_Enter] || ImGui::GetIO().KeysDown[ImGuiKey_Tab])
			{
				ResizeBuffer(textBuffer, textBuffer.size() + 1024);
			}
		}

		ImGui::End();
	}
}