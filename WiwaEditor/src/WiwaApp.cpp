#include <Wiwa.h>

#include "Layers/EditorLayer.h"

#include <Wiwa/ecs/systems/System.h>
#include <Wiwa/scripting/ScriptEngine.h>

#include <Wiwa/audio/Audio.h>
#include <Wiwa/core/Renderer2D.h>

//#include <Wiwa/utilities/ui/ButtonUI.h>
#include <Wiwa/utilities/ui/ManagerUI.h>
#include <Wiwa/core/Application.h>

USE_REFLECTION;
class WiwaApp : public Wiwa::Application
{
public:
	REFLECTION_BODY_INL;

	WiwaApp(int argc, char** argv) : Wiwa::Application(argc, argv)
	{
		REFLECTION_REGISTER();

		PushOverlay(new EditorLayer());

		Wiwa::ManagerUi::Get()->Start();

	}

	~WiwaApp()
	{
	}
};

Wiwa::Application* Wiwa::CreateApplication(int argc, char** argv)
{
	return new WiwaApp(argc, argv);
}