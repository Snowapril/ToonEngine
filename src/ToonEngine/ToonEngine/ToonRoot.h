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
	/****************************************************************************
				ToonRoot class declaration
	****************************************************************************/
	class ToonRoot : public Singleton<ToonRoot>
	{
		friend class RenderSystem;
	protected:
		std::unique_ptr<RenderSystem>		renderSystem;
	private: // plugins
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
		bool initSubsystems(void);
	public:
		ToonRoot();
		virtual ~ToonRoot();

		bool initialize(bool autoCreateWindow, std::string const & windowTitle, std::string const & configFilePath);
		int  runMainLoop(void);
	public:
		static ToonRoot const&		getConstInstance  (void);
		static ToonRoot&			getMutableInstance(void);
		static bool					isDestroyed		  (void)  { return instance == nullptr; }
	};
};

#include "ToonHeaderPostfix.h"

#endif