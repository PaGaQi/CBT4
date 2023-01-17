#include <Wiwa/core/Renderer2D.h>
#include <Wiwa/utilities/math/Vector2i.h>
#include <Wiwa/utilities/ui/ControlUI.h>

namespace Wiwa
{
	enum class UiState;
	class CheckUi : public ControlUi
	{
	public:

		CheckUi(int id, Rect2i bounds, ResourceId spriteId, Vector2i position, bool initState = false);
		virtual ~CheckUi();

		bool Update(float dt);

		bool GetValue() { return checked; };
		void SetValue(bool state) { checked = state; };

		int mouseX, mouseY;		
		unsigned int click;

		Rect2i m_Bounds;
		//ResourceId spriteIdCheck;
		bool checked;

		int onClickFX;
		int onHoverFX;
		bool isPlaying;

		//Need to fix STATE
		UiState state;

		uint32_t m_InstanceId;

		bool canClick = true;

		void OnClick();
};
}