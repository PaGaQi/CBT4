#include <wipch.h>

#include <Wiwa/core/Input.h>
#include <Wiwa/utilities/ui/CheckUI.h>
#include <Wiwa/core/Renderer2D.h>
#include <Wiwa/core/Application.h>
#include <Wiwa/core/Window.h>
#include <Wiwa/utilities/ui/ButtonUI.h>
#include <Wiwa/utilities/ui/ManagerUI.h>

namespace Wiwa
{
	CheckUi::CheckUi(Rect2i bounds, ResourceId spriteId, Vector2i position, bool initState) : ControlUi(position, bounds)
	{
		m_Bounds = bounds;
		//spriteIdCheck = spriteId;

		canClick = true;

		checked = initState;

		m_Renderer2D = &Application::Get().GetRenderer2D();

		Image* img = Resources::GetResourceById<Image>(spriteId);

		Size2i pito = img->GetSize();
		pito.h /= 2;

		m_Bounds.y = checked * m_Bounds.height;
		m_InstanceId = m_Renderer2D->CreateInstancedQuadTex((int)SceneUi::OPTIONS, spriteId, position, pito, Color::WHITE, m_Bounds, Wiwa::Renderer2D::Pivot::UPLEFT);

	};

	CheckUi::~CheckUi()
	{

	}

	void CheckUi::Update()
	{
		bool ret = true;

		Vector2f mousePos = Input::GetOverrideMousePos();
		mousePos.x *= m_Resolution.w;
		mousePos.y *= m_Resolution.h;

		//WI_INFO("{0}, {1}", mousePos.x, mousePos.y);

		if (mousePos.x > m_Position.x && mousePos.x < m_Bounds.width + m_Position.x
			&& mousePos.y > m_Position.y && mousePos.y < m_Position.y + m_Bounds.height)
		{
			if (Wiwa::Input::IsMouseButtonPressed(0))
			{
				wasPressed = true;
			}
			if (Wiwa::Input::IsMouseButtonReleased(0) && ManagerUi::Get()->currentScene == SceneUi::OPTIONS && wasPressed)
			{
				//state = UiState::PRESS;
				OnClick();
			}
		}
	}

	void CheckUi::OnClick()
	{
		checked = !checked;
		Wiwa::Application::Get().GetWindow().SetVSync(checked);
		std::cout << "SAMUELLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL DESAYUNA CON WEBO \n";
		wasPressed = false;
		m_Bounds.y = checked * m_Bounds.height;
		m_Renderer2D->UpdateInstancedQuadTex((int)SceneUi::OPTIONS, m_InstanceId, m_Bounds, {m_Bounds.width,m_Bounds.height*2});
	}
}