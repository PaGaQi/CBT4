#include <wipch.h>
#include "ButtonUI.h"

#include <Wiwa/core/Renderer2D.h>
#include <Wiwa/core/Application.h>
#include <Wiwa/core/Input.h>
//#include <Wiwa/utilities/ui/ManagerUI.h>

namespace Wiwa {

	SceneUi Button::currentScene = SceneUi::MAIN;

	Button::Button(ButtonType btype, const Vector2i& position, const Rect2i& bounds, ResourceId spriteId)
		: m_BType(btype), m_SpriteID(spriteId), m_Bounds(bounds), ControlUi(position, bounds)
	{
		m_Renderer2D = &Application::Get().GetRenderer2D();

		Image* img = Resources::GetResourceById<Image>(spriteId);

		m_Bounds.y = (int)m_State * m_Bounds.height;
		m_InstanceId = m_Renderer2D->CreateInstancedQuadTex(spriteId, position, img->GetSize(), Color::WHITE, m_Bounds, Wiwa::Renderer2D::Pivot::UPLEFT);
	}

	void Button::Update()
	{
		//std::cout << Input::GetMousePosition().second << "\n";
		//std::cout << "Webo" << std::endl;
		//std::cout << m_Bounds.y - m_Bounds.height << std::endl;
		if (Input::GetMousePosition().first > m_Bounds.x && Input::GetMousePosition().first < m_Bounds.width
			&& Input::GetMousePosition().second > m_Bounds.y- m_Bounds.height && Input::GetMousePosition().second < m_Bounds.height)
		{
			if (Wiwa::Input::IsMouseButtonPressed(0))
				{
					//state = UiState::PRESS;
					OnClick();
				}
		}
		//if (Input::GetMousePosition().first > 0 && Input::GetMousePosition().first < 620
		//	&& Input::GetMousePosition().second >0 && Input::GetMousePosition().second < 620)
		//{
		//	if (Wiwa::Input::IsMouseButtonPressed(0))
		//	{
		//		//state = UiState::PRESS;
		//		OnClick();
		//		std::cout << "pito";
		//	}
		//	
		//}
	}

	void Button::OnClick()
	{
		switch (m_BType) {
		case ButtonType::PLAY:
			std::cout << "Iso click webon \n";
			currentScene = SceneUi::PLAYING;
			
			break;
		}
	}
}
