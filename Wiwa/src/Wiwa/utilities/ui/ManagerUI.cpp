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

		//PLAY BUTTON
		ResourceId imgId = Wiwa::Resources::Load<Wiwa::Image>("Assets/Play.png");
		Wiwa::Image* img = Wiwa::Resources::GetResourceById<Wiwa::Image>(imgId);
		Wiwa::Vector2i pos = { 495, 540 };
		Wiwa::Size2i size = img->GetSize();
		Wiwa::Rect2i rect = { 0, 0, size.w, size.h };

		//CROSSHAIR
		ResourceId croshairId = Wiwa::Resources::Load<Wiwa::Image>("Assets/sexo.png");
		Wiwa::Image* crosshairImg = Wiwa::Resources::GetResourceById<Wiwa::Image>(imgId);
		Wiwa::Vector2i crosshairPos = { 960, 540 };
		Wiwa::Size2i crosshairSize = img->GetSize();
		Wiwa::Rect2i crosshairRect = { 0, 0, size.w, size.h };

		
		r2d2.CreateInstancedQuadTex((int)SceneUi::CROSSHAIR, croshairId, crosshairPos, crosshairSize);
		
		//PLAY BUTTON
		Wiwa::ManagerUi::Get()->CreateControlUi(SceneUi::MAIN, Wiwa::UiType::BUTTON, pos, imgId, rect);
		//BACKGROUND
		r2d2.CreateInstancedQuadTex((int)SceneUi::MAIN, bgId2, pos2, size2);

		currentScene = SceneUi::CROSSHAIR;
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
		
		if (Wiwa::Input::IsKeyPressed(Wiwa::Key::F1))
		{
			ChangeScene(SceneUi::CROSSHAIR);
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