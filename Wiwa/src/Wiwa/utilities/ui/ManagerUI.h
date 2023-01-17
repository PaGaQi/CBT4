#pragma once

#include "ControlUI.h"
#include <vector>

namespace Wiwa
{
	enum class SceneUi {
		MAIN,
		PLAYING,
		CROSSHAIR,
		OPTIONS,
		NONE
	};

	class WI_API ManagerUi
	{
	private:
		// Constructor
		ManagerUi();

		static ManagerUi* instance;

		std::vector<ControlUi*> m_Buttons;

	public:
		SceneUi currentScene;
		
		static ManagerUi* Get() 
		{ 
			if (instance == NULL)
			{
				instance = new ManagerUi();
			}

			return instance;
		}

		// Destructor
		virtual ~ManagerUi();

		bool Start();

		bool Update();

		bool UpdateAll();

		bool Draw();

		// Called before quitting
		bool CleanUp();

		// Additional methods
		ControlUi* CreateControlUi(SceneUi scene, UiType type, Vector2i position, ResourceId spriteId, Wiwa::Rect2i bounds);
		void DestroyControlUi(ControlUi* entity);
		void AddControlUi(ControlUi* entity);

		//Scene Managing
		void ChangeScene(SceneUi newScene);

	public:

		std::vector<ControlUi*> controls;
	};
}

