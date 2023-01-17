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
	CheckUi::CheckUi(int id, Rect2i bounds, ResourceId spriteId, Vector2i position, bool initState) : ControlUi(position, bounds)
	{
		m_Bounds = bounds;
		//spriteIdCheck = spriteId;

		canClick = true;

		checked = initState;

	};

	CheckUi::~CheckUi()
	{

	}

	bool CheckUi::Update(float dt)
	{
		bool ret = true;

		Vector2f mousePos = Input::GetOverrideMousePos();
		mousePos.x *= m_Resolution.w;
		mousePos.y *= m_Resolution.h;

		WI_INFO("{0}, {1}", mousePos.x, mousePos.y);

		if (mousePos.x > m_Position.x && mousePos.x < m_Bounds.width + m_Position.x
			&& mousePos.y > m_Position.y && mousePos.y < m_Position.y + m_Bounds.height)
		{
			if (Wiwa::Input::IsMouseButtonPressed(0) && ManagerUi::Get()->currentScene == SceneUi::MAIN)
			{
				//state = UiState::PRESS;
				OnClick();
			}
		}
		

		return ret;
	}

	void CheckUi::OnClick()
	{
		checked != checked;
		Wiwa::Application::Get().GetWindow().SetVSync(checked);
	}
}