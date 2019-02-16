#ifndef APPLICATION_H
#define APPLICATION_H

#include "ToonHeaderPrefix.h"
#include "Singleton.h"
#include <string>
#include <memory>
#include "ToonPrerequisites.h"

struct GLFWwindow;

namespace Toon
{
	class Application : public Singleton<Application>
	{
	protected:
		std::string windowTitle;
		GLFWwindow *window			= nullptr;
		int			clientWidth		= 0;
		int			clientHeight	= 0;
		bool        bFullscreen		= false;
	private: // plugins
		std::unique_ptr<Logger>		logger;
		std::unique_ptr<FileSystem>	fs;
		std::unique_ptr<Timer>		timer;
	protected:
		virtual void initialUpdate	(void) = 0;
		virtual void updateScene	(float dt) = 0;
		virtual void drawScene		(void) const = 0;
		virtual void release		(void);
		virtual bool reset			(void);
	private:
		void registerCallback(void);
	public:
		Application();
		~Application();

		bool initContext( int width, int height, char const *wndTitle, bool fullscreen = false );
		int  runApplicationLoop(void);

		GLFWwindow const* getAppWindow	(void)	const { return window; }
		float			  getAspectRatio(void)	const { return static_cast<float>(clientWidth) / clientHeight; }

		virtual void keyCallback		( int key, int scancode, int action, int mode ) = 0;
		virtual void mousePosCallback	( double xpos, double ypos ) = 0;
		virtual void mouseBtnCallback	( int btn, int action, int mods ) = 0;
		virtual void scrollCallback		( double xoffset, double yoffset ) = 0;
		virtual void resizingCallback	( int newWidth, int newHeight );
	public:
		static Application const&	getConstInstance(void);
		static Application&			getMutableInstance(void);
		static bool					isDestroyed(void) { return instance == nullptr; }
	};
};

#include "ToonHeaderPostfix.h"

#endif