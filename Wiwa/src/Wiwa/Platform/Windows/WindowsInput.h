#pragma once

#include <Wiwa/core/Input.h>

namespace Wiwa
{
	class WindowsInput : public Input 
	{
	protected:
		virtual bool IsKeyPressedImpl(int keycode) override;
		virtual bool IsMouseButtonPressedImpl(int button) override;
		virtual bool IsMouseButtonReleasedImpl(int button) override;
		virtual std::pair<float, float> GetMousePositionImpl() override;
		virtual float GetMouseXImpl() override;
		virtual float GetMouseYImpl() override;
		virtual std::pair<float, float> OverrideMousePosImpl(std::pair<float, float> offset) override;

		virtual void OverrideMouseInWinImpl(bool inWindow) override;
		virtual bool IsMouseInWinImpl() override;
	};
}