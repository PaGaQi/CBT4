#include <wipch.h>
#include "ButtonUI.h"

#include <Wiwa/core/Renderer2D.h>
#include <Wiwa/core/Application.h>
#include <Wiwa/core/Input.h>
#include <Wiwa/utilities/ui/ManagerUI.h>

namespace Wiwa {

	Button::Button(ButtonType btype, const Vector2i& position, const Rect2i& bounds, ResourceId spriteId)
		: m_BType(btype), m_SpriteID(spriteId), m_Bounds(bounds), ControlUi(position, bounds)
	{
		m_Renderer2D = &Application::Get().GetRenderer2D();

		Image* img = Resources::GetResourceById<Image>(spriteId);

		m_Bounds.y = (int)m_State * m_Bounds.height;
		m_InstanceId = m_Renderer2D->CreateInstancedQuadTex((int)SceneUi::MAIN, spriteId, position, img->GetSize(), Color::WHITE, m_Bounds, Wiwa::Renderer2D::Pivot::UPLEFT);
	}

	void Button::Update()
	{
		//std::cout << Input::GetMousePosition().second << "\n";
		//std::cout << "Webo" << std::endl;
		//std::cout << m_Bounds.y - m_Bounds.height << std::endl;
		
		//std::cout << Input::GetMousePosition().first << "\n";
		Vector2f mousePos = Input::GetOverrideMousePos();
		mousePos.x *= m_Resolution.w;
		mousePos.y *= m_Resolution.h;

		//WI_INFO("{0}, {1}", mousePos.x, mousePos.y);

		if (mousePos.x > m_Position.x && mousePos.x < m_Bounds.width + m_Position.x
			&& mousePos.y > m_Position.y && mousePos.y < m_Position.y + m_Bounds.height)
		{
			if (Wiwa::Input::IsMouseButtonPressed(0) && ManagerUi::Get()->currentScene == SceneUi::MAIN)
				{
					//state = UiState::PRESS;
					OnClick();
				}
		}		
	}

	void Button::OnClick()
	{
		switch (m_BType) {
		case ButtonType::PLAY:
			std::cout << "Iso click webon \n";
			ManagerUi::Get()->ChangeScene(SceneUi::PLAYING);
					
			break;
		}
	}
}
