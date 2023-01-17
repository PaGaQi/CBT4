#pragma once
#include <Wiwa/core/Core.h>
#include <Wiwa/utilities/math/Vector2i.h>
#include <Wiwa/utilities/math/Rectangle.h>
#include <Wiwa/core/Resources.h>

namespace Wiwa {
	class Renderer2D;

	enum class UiType {
		BUTTON,
		NONE
	};

	enum class UiState {
		DISABLED,
		NORMAL,
		FOCUS,
		PRESS,
		NONE
	};
	
	class WI_API ControlUi {
	protected:
		Renderer2D* m_Renderer2D;

		UiType m_Type;
		Vector2i m_Position;

		UiState m_State;

		Size2i m_Resolution;

	public:
		ControlUi(const Vector2i& position, const Rect2i& bounds);

		void Update();

		void OnClick();
	};
}