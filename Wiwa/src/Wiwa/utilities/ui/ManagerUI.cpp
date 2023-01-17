#include "wipch.h"

#include "ManagerUI.h"
#include "Wiwa/core/Application.h"
#include <Wiwa/core/Resources.h>

#include "CheckUI.h"

namespace Wiwa
{
	//std::vector<Button> m_Buttons;
	ManagerUi* ManagerUi::instance = NULL;

	ManagerUi::ManagerUi()
	{
	}

	ManagerUi::~ManagerUi() {}


	bool ManagerUi::Start()
	{

		return true;
	}

	Button* ManagerUi::CreateControlUi(UiType type, ButtonType btype, Vector2i position, ResourceId spriteId, Wiwa::Rect2i bounds)
	{
		Button* control = nullptr;
		switch (type)
		{
		case UiType::BUTTON:
		{
			control = new Button(btype, position, bounds, spriteId);
			m_Buttons.push_back(control);
		}
			break;

		default:
			break;
		}

		// Created UIControls are added to the list of controls
		if (control != nullptr) controls.push_back(control);

		return control;
	}

	void ManagerUi::DestroyControlUi(Button* entity)
	{

	}

	bool ManagerUi::Update()
	{
		bool ret = true;
		for (size_t i = 0; i < m_Buttons.size(); i++) 
		{
			m_Buttons[i]->Update();
		}

		return ret;
	}

	bool ManagerUi::UpdateAll() 
	{
		bool ret = true;

		return ret;
	}


	bool ManagerUi::CleanUp()
	{

		return true;
	}
}