#include <wipch.h>
#include "ButtonUI.h"

#include <Wiwa/core/Renderer2D.h>
#include <Wiwa/core/Application.h>
#include "ControlUI.h"

Wiwa::ControlUi::ControlUi(const Vector2i& position, const Rect2i& bounds)
{
	m_Renderer2D = &Wiwa::Application::Get().GetRenderer2D();
	m_State = UiState::NORMAL;
	m_Type = UiType::BUTTON;
	m_Position = position;

}