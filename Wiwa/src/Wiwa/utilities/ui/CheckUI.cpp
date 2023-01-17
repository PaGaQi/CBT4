#include <wipch.h>

#include <Wiwa/core/Input.h>
#include <Wiwa/utilities/ui/CheckUI.h>
#include <Wiwa/core/Renderer2D.h>
#include <Wiwa/core/Application.h>
#include <Wiwa/core/Window.h>
#include <Wiwa/utilities/ui/ButtonUI.h>

namespace Wiwa
{
	CheckUi::CheckUi(int id, Rect2i bounds, ResourceId spriteId, bool initState)
	{
		boundsCheck = bounds;
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
		
		if (state != UiState::DISABLED)
		{			
			

		}

		return ret;
	}
}