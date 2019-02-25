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
	class ToonRoot : public Singleton<ToonRoot>
	{
		friend class RenderSystem;
	protected:
		RenderSystem* renderSystem;
	private: // plugins
		std::unique_ptr<SystemMessageBus>	systemMessageBus;
		std::unique_ptr<Logger>				logger;
		std::unique_ptr<Filesystem>			filesystem;
		std::unique_ptr<Timer>				timer;
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

		bool initialize(bool autoCreateWindow, std::string const & windowTitle, std::string const & configFilePath);
		int  runApplicationLoop(void);
	public:
		static ToonRoot const&		getConstInstance(void);
		static ToonRoot&			getMutableInstance(void);
		static bool					isDestroyed(void) { return instance == nullptr; }
	};
};

#include "ToonHeaderPostfix.h"

#endif