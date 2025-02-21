#pragma once

#include <Wiwa/core/Core.h>
#include <Wiwa/utilities/math/Vector2f.h>

namespace Wiwa
{
	class WI_API Input
	{
	public:
		inline static bool IsKeyPressed(int keycode) { return s_Instance->IsKeyPressedImpl(keycode); }	
		inline static bool IsMouseButtonPressed(int button) { return s_Instance->IsMouseButtonPressedImpl(button); }
		inline static bool IsMouseButtonReleased(int button) { return s_Instance->IsMouseButtonReleasedImpl(button); }
		inline static std::pair<float, float> GetMousePosition() { return s_Instance->GetMousePositionImpl(); }
		inline static float GetMouseX() { return s_Instance->GetMouseXImpl(); }
		inline static float GetMouseY() { return s_Instance->GetMouseYImpl(); }
		inline static void OverrideMousePos(const Vector2f& position) { m_Position = position; }

		inline static Vector2f GetOverrideMousePos() { return m_Position; }

		inline static void OverrideMouseinWin(bool inWin) { s_InWin = inWin; }
		inline static bool IsMouseInWin() { return s_InWin; }

	protected:
		virtual bool IsKeyPressedImpl(int keycode) = 0;
		virtual bool IsMouseButtonPressedImpl(int button) = 0;
		virtual bool IsMouseButtonReleasedImpl(int button) = 0;
		virtual std::pair<float, float> GetMousePositionImpl() = 0;
		virtual float GetMouseXImpl() = 0;
		virtual float GetMouseYImpl() = 0;
		virtual std::pair<float, float> OverrideMousePosImpl(std::pair<float,float> offset) = 0;

		virtual void OverrideMouseInWinImpl(bool inWin) = 0;
		virtual bool IsMouseInWinImpl() = 0;

		static Vector2f m_Position;
		static bool s_InWin;
		static std::pair<float, float> offset;
	private:
		static Input* s_Instance;
	};
}