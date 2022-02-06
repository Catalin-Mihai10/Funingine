#pragma once

#include "CoreMacros.h"

namespace Funingine {

	class FE_API MainApplication
	{
	public:
		MainApplication();
		virtual ~MainApplication();
	
		void Run();
	};

	MainApplication* CreateMainApplication();
}

