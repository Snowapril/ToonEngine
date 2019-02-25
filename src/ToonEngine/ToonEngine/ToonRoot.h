#ifndef TOON_ROOT_H
#define TOON_ROOT_H

#include "ToonHeaderPrefix.h"
#include "ToonSingleton.h"
#include <string>
#include <memory>
#include "ToonPrerequisites.h"

struct GLFWwindow;

namespace Toon
{
	class ToonRoot : public ToonSingleton<ToonRoot>
	{
	protected:
		ToonRenderSystem* renderSystem;
	private: // plugins
		std::unique_ptr<ToonLogger>		logger;
		std::unique_ptr<ToonFilesystem>	fs;
		std::unique_ptr<ToonTimer>		timer;
	protected:
		virtual void initialUpdate	(void) = 0;
		virtual void updateScene	(float dt) = 0;
		virtual void drawScene		(void) const = 0;
		virtual void release		(void);
		virtual bool reset			(void);
	private:
		void registerCallback(void);
	public:
		ToonRoot();
		~ToonRoot();

		bool initContext( int width, int height, char const *wndTitle, bool fullscreen = false );
		int  runApplicationLoop(void);

		virtual void keyCallback		( int key, int scancode, int action, int mode ) = 0;
		virtual void mousePosCallback	( double xpos, double ypos ) = 0;
		virtual void mouseBtnCallback	( int btn, int action, int mods ) = 0;
		virtual void scrollCallback		( double xoffset, double yoffset ) = 0;
		virtual void resizingCallback	( int newWidth, int newHeight );
	public:
		static ToonRoot const&		getConstInstance(void);
		static ToonRoot&			getMutableInstance(void);
		static bool					isDestroyed(void) { return instance == nullptr; }
	};
};

#include "ToonHeaderPostfix.h"

#endif