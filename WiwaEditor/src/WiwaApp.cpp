#include <Wiwa.h>

#include "Layers/EditorLayer.h"

#include <Wiwa/ecs/systems/System.h>
#include <Wiwa/scripting/ScriptEngine.h>

#include <Wiwa/audio/Audio.h>
#include <Wiwa/core/Renderer2D.h>

//#include <Wiwa/utilities/ui/ButtonUI.h>
#include <Wiwa/utilities/ui/ManagerUI.h>

USE_REFLECTION;
class WiwaApp : public Wiwa::Application
{
public:
	REFLECTION_BODY_INL;

	WiwaApp(int argc, char** argv) : Wiwa::Application(argc, argv)
	{
		REFLECTION_REGISTER();

		PushOverlay(new EditorLayer());

		ResourceId imgId = Wiwa::Resources::Load<Wiwa::Image>("Assets/sexo.png");
		Wiwa::Image* img = Wiwa::Resources::GetResourceById<Wiwa::Image>(imgId);
		Wiwa::Vector2i pos = { 0,0 };
		Wiwa::Size2i size = img->GetSize();
		Wiwa::Rect2i rect = {0, 0, size.w, size.h};


		//Wiwa::Renderer2D& r2d = Wiwa::Application::Get().GetRenderer2D();
		//r2d.CreateInstancedQuadTex(imgId, pos, size);
		
		Wiwa::ManagerUi::Get()->CreateControlUi(Wiwa::UiType::BUTTON, Wiwa::ButtonType::PLAY, pos, imgId, rect);
	}

	~WiwaApp()
	{
	}
};

Wiwa::Application* Wiwa::CreateApplication(int argc, char** argv)
{
	return new WiwaApp(argc, argv);
}