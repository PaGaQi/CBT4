#include <wipch.h>
#include "ButtonUI.h"

#include <Wiwa/core/Renderer2D.h>
#include <Wiwa/core/Application.h>
#include <Wiwa/core/Input.h>

namespace Wiwa {
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
		//std::cout << "Webo" << std::endl;
		//if ()
		//{
		//	if (Wiwa::Input::IsMouseButtonPressed(0))
		//		{
		//			//state = UiState::PRESS;
		//			OnClick();
		//		}
		//}
	}

	void Button::OnClick()
	{
		switch (m_BType) {
		case ButtonType::PLAY:
			std::cout << "Iso click webon \n";
			break;
		}
	}
}
