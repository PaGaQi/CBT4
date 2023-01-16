#pragma once

#include "ButtonUI.h"
#include <vector>

namespace Wiwa
{
	class WI_API ManagerUi
	{
	private:
		// Constructor
		ManagerUi();

		static ManagerUi* instance;

		std::vector<Button*> m_Buttons;
	public:
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
		Button* CreateControlUi(UiType type, ButtonType btype, Vector2i position, ResourceId spriteId, Wiwa::Rect2i bounds);
		void DestroyControlUi(Button* entity);
		void AddControlUi(Button* entity);

	public:

		std::vector<Button*> controls;
	};
}

