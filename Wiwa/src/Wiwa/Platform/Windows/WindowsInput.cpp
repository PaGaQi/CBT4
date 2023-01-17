#include "wipch.h"
#include "WindowsInput.h"

#include <Wiwa/core/KeyCodes.h>
#include <Wiwa/core/Application.h>

#include <GLFW/glfw3.h>

namespace Wiwa
{
	Input* Input::s_Instance = new WindowsInput();
	bool Input::s_InWin = false;

	std::pair<float, float> Input::offset = {0.0f,0.0f};
	Vector2f Input::m_Position = { 0.0f,0.0f };

	bool WindowsInput::IsKeyPressedImpl(int keycode)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(window, keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}
	bool WindowsInput::IsMouseButtonPressedImpl(int button)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetMouseButton(window, button);
		return state == GLFW_PRESS;
	}
	std::pair<float, float> WindowsInput::GetMousePositionImpl()
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		
			xpos -= offset.first;
			ypos -= offset.second;

		return {(float)xpos, (float)ypos};
	}
	float WindowsInput::GetMouseXImpl()
	{
		auto [x, y] = GetMousePosition();
		return x;
	}
	float WindowsInput::GetMouseYImpl()
	{
		auto [x, y] = GetMousePosition();
		return y;
	}
	std::pair<float, float> WindowsInput::OverrideMousePosImpl(std::pair<float, float> pito)
	{
		/*auto [x, y] = GetMousePosition();
		offset = pito;
		auto [xoff, yoff] = offset;
		x -= xoff;
		y -= yoff;
		return offset;*/
		return pito;
	}

	void WindowsInput::OverrideMouseInWinImpl(bool inWindow)
	{
		s_InWin = inWindow;
	}
	bool WindowsInput::IsMouseInWinImpl()
	{
		return s_InWin;
	}
}