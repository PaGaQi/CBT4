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

		ResourceId bgId2 = Wiwa::Resources::Load<Wiwa::Image>("Assets/bg.jpg");
		Wiwa::Image* bg2 = Wiwa::Resources::GetResourceById<Wiwa::Image>(bgId2);
		Wiwa::Vector2i pos2 = { 0,0 };
		Wiwa::Size2i size2 = {1920*2, 1080*2};
		Wiwa::Rect2i rect2 = { 0, 0, size2.w, size2.h};

		ResourceId imgId = Wiwa::Resources::Load<Wiwa::Image>("Assets/Play.png");
		Wiwa::Image* img = Wiwa::Resources::GetResourceById<Wiwa::Image>(imgId);
		Wiwa::Vector2i pos = { 960, 540};
		Wiwa::Size2i size = img->GetSize();
		Wiwa::Rect2i rect = {0, 0, size.w, size.h};
		

		
		
		Wiwa::ManagerUi::Get()->CreateControlUi(Wiwa::UiType::BUTTON, Wiwa::ButtonType::PLAY, pos, imgId, rect);

		Wiwa::Renderer2D& r2d = Wiwa::Application::Get().GetRenderer2D();
		r2d.CreateInstancedQuadTex(bgId2, pos2, size2);

	}

	~WiwaApp()
	{
	}
};

Wiwa::Application* Wiwa::CreateApplication(int argc, char** argv)
{
	return new WiwaApp(argc, argv);
}