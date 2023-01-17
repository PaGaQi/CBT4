#pragma once
#include <Wiwa/core/Core.h>
#include <Wiwa/utilities/math/Vector2i.h>
#include <Wiwa/utilities/math/Rectangle.h>
#include <Wiwa/core/Resources.h>
#include <Wiwa/utilities/ui/ControlUI.h>

namespace Wiwa {
	class SceneManagerUi 
	{
	private:

		//ResourceId m_SpriteID;
		//Rect2i m_Bounds;

		//ButtonType m_BType;

		//uint32_t m_InstanceId;

	public:
		SceneManagerUi();
		~SceneManagerUi();
		
		void Update();
		
		//static SceneUi currentScene;
	};
}