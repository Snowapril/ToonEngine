#ifndef TOON_ROOT_H
#define TOON_ROOT_H

#include "ToonHeaderPrefix.h"
#include "ToonPrerequisites.h"
#include "ToonObfuscator.h"

#include <ToonSingleton.h>
#include <INIParser.h>
#include <string>
#include <memory>
#include <stack>

struct GLFWwindow;

namespace Toon
{
	/****************************************************************************
				ToonRoot class declaration
	****************************************************************************/
	class ToonRoot : public Common::Singleton<ToonRoot>
	{
		using super_t = Common::Singleton<ToonRoot>;
	protected:
		std::unique_ptr<RenderSystem>		renderSystem;
		std::unique_ptr<InputSystem>		inputSystem;
		std::unique_ptr<Logger>				logger;
		std::unique_ptr<SystemMessageBus>	systemMessageBus;
		std::unique_ptr<Filesystem>			filesystem;
		std::unique_ptr<Timer>				timer;
	protected:
		virtual void initialUpdate	(  void	 );
		virtual void preUpdateScene	(float dt);
		virtual void updateScene	(float dt);
		virtual void preDrawScene	(  void  ) const;
		virtual void drawScene		(  void  ) const;
		virtual void release		(  void  );
	private:
		bool initSubsystems(ToonResourceParser::INIParser const&);
	public:
		ToonRoot();
		virtual ~ToonRoot();

		bool initialize(bool autoCreateWindow = true, std::string const & windowTitle = OBFUSCATE("ToonEngine"), std::string const & configFilePath = "");
		int  runMainLoop(void) noexcept; // this is only for testing ToonEngine. will be remove at later.
	};
};

#include "ToonHeaderPostfix.h"

#endif