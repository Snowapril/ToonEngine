#include "stdafx.h"
#include "ToonGL3PlusInputSystem.h"

namespace Common
{
	template <> ToonGL3Plus::GL3PlusInputSystem* Singleton<ToonGL3Plus::GL3PlusInputSystem>::instance = nullptr;
}

namespace ToonGL3Plus
{
	using namespace Common;
	GL3PlusInputSystem::~GL3PlusInputSystem() noexcept
	{
	}
};