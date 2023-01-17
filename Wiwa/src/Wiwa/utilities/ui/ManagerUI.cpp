#include "wipch.h"

#include "ManagerUI.h"
#include "Wiwa/core/Application.h"
#include <Wiwa/core/Resources.h>
#include "ButtonUI.h"
#include "Wiwa/core/Input.h"

#include "CheckUI.h"

namespace Wiwa
{
	//std::vector<Button> m_Buttons;
	ManagerUi* ManagerUi::instance = NULL;

	ManagerUi::ManagerUi()
	{
	}

	ManagerUi::~ManagerUi() {}


	bool ManagerUi::Start()
	{
		Wiwa::Renderer2D& r2d2 = Wiwa::Application::Get().GetRenderer2D();
		for (int i = 0; i < (int)SceneUi::NONE;i++)
		{
			r2d2.CreateInstance();
		}
		//BACKGROUND
		ResourceId bgId2 = Wiwa::Resources::Load<Wiwa::Image>("Assets/bg.jpg");
		Wiwa::Image* bg2 = Wiwa::Resources::GetResourceById<Wiwa::Image>(bgId2);
		Wiwa::Vector2i pos2 = { 0,0 };
		Wiwa::Size2i size2 = { 1920 * 2, 1080 * 2 };
		Wiwa::Rect2i rect2 = { 0, 0, size2.w, size2.h };
		
		//BACKGROUND2
		ResourceId bgId = Wiwa::Resources::Load<Wiwa::Image>("Assets/bgOptions.jpg");
		Wiwa::Image* bg = Wiwa::Resources::GetResourceById<Wiwa::Image>(bgId);
		Wiwa::Vector2i pos3 = { 0,0 };
		Wiwa::Size2i size3 = { 1920 * 2, 1080 * 2 };
		Wiwa::Rect2i rect3 = { 0, 0, size3.w, size3.h };

		//PLAY BUTTON
		ResourceId imgId = Wiwa::Resources::Load<Wiwa::Image>("Assets/Play.png");
		Wiwa::Image* img = Wiwa::Resources::GetResourceById<Wiwa::Image>(imgId);
		Wiwa::Vector2i pos = { 495, 540 };
		Wiwa::Size2i size = img->GetSize();
		Wiwa::Rect2i rect = { 0, 0, size.w, size.h };

		//CROSSHAIR
		ResourceId croshairId = Wiwa::Resources::Load<Wiwa::Image>("Assets/Mark.png");
		Wiwa::Image* crosshairImg = Wiwa::Resources::GetResourceById<Wiwa::Image>(croshairId);
		Wiwa::Vector2i crosshairPos = { 960, 540 };
		Wiwa::Size2i crosshairSize = crosshairImg->GetSize();
		Wiwa::Rect2i crosshairRect = { 0, 0, crosshairSize.w, crosshairSize.h };

		//CHECKBOX
		ResourceId checkId = Wiwa::Resources::Load<Wiwa::Image>("Assets/checkbox.png");
		Wiwa::Image* checkImg = Wiwa::Resources::GetResourceById<Wiwa::Image>(checkId);
		Wiwa::Vector2i checkPos = { 960, 540 };
		Wiwa::Size2i checkSize = checkImg->GetSize();
		checkSize.h /= 2;
		Wiwa::Rect2i checkRect = { 0, 0, checkSize.w, checkSize.h};
		
		
		r2d2.CreateInstancedQuadTex((int)SceneUi::CROSSHAIR, croshairId, crosshairPos, crosshairSize);

		//r2d2.CreateInstancedQuadTex((int)SceneUi::OPTIONS, checkId, checkPos, checkSize);
		
		//PLAY BUTTON
		Wiwa::ManagerUi::Get()->CreateControlUi(SceneUi::MAIN, Wiwa::UiType::BUTTON, pos, imgId, rect);

		Wiwa::ManagerUi::Get()->CreateControlUi(SceneUi::OPTIONS, Wiwa::UiType::CHECK, checkPos, checkId, checkRect);
		//BACKGROUND
		r2d2.CreateInstancedQuadTex((int)SceneUi::MAIN, bgId2, pos2, size2);

		r2d2.CreateInstancedQuadTex((int)SceneUi::OPTIONS, bgId, pos3, size3);

		currentScene = SceneUi::MAIN;
		r2d2.SetActiveInstance((int)currentScene);
		
		return true;
	}

	ControlUi* ManagerUi::CreateControlUi(SceneUi scene, UiType type, Vector2i position, ResourceId spriteId, Wiwa::Rect2i bounds)
	{
		ControlUi* control = nullptr;
		switch (type)
		{
		case UiType::BUTTON:
		{
			control = new Button(ButtonType::PLAY, position, bounds, spriteId);
			m_Buttons.push_back(control);
			
		}
		break;
		case UiType::CHECK:
		{
			control = new CheckUi(bounds, spriteId, position, false);
			m_Check.push_back(control);
			
		}
		break;
		default:
			break;
		}

		// Created UIControls are added to the list of controls
		if (control != nullptr) controls.push_back(control);

		return control;
	}

	void ManagerUi::DestroyControlUi(ControlUi* entity)
	{

	}

	bool ManagerUi::Update()
	{
		bool ret = true;
		for (size_t i = 0; i < m_Buttons.size(); i++) 
		{
			m_Buttons[i]->Update();
		}

		for (size_t i = 0; i < m_Check.size(); i++)
		{
			m_Check[i]->Update();
		
		}
		
		if (Wiwa::Input::IsKeyPressed(Wiwa::Key::F3))
		{
			ChangeScene(SceneUi::CROSSHAIR);
		}
		if (Wiwa::Input::IsKeyPressed(Wiwa::Key::F1))
		{
			ChangeScene(SceneUi::OPTIONS);
		}
		else if (Wiwa::Input::IsKeyPressed(Wiwa::Key::F2))
		{
			ChangeScene(SceneUi::MAIN);
		}

		return ret;
	}

	bool ManagerUi::UpdateAll() 
	{
		bool ret = true;

		return ret;
	}

	void ManagerUi::ChangeScene(SceneUi newScene)
	{
		currentScene = newScene;
		Wiwa::Renderer2D& r2d2 = Wiwa::Application::Get().GetRenderer2D();
		r2d2.SetActiveInstance((int)currentScene);
	}


	bool ManagerUi::CleanUp()
	{
		return true;
	}
}