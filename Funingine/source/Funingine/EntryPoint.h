#pragma once


#ifdef FE_PLATFORM_WINDOWS

extern Funingine::MainApplication* Funingine::CreateMainApplication();

int main(int argc, char** argv) 
{
	Funingine::Log::Init();
	Funingine::Log::GetCoreLogger()->warn("Initialized Core Logger");
	Funingine::Log::GetClientLogger()->info("Initialized Client Logger");

	auto mainApplication = Funingine::CreateMainApplication();
	mainApplication->Run();
	delete mainApplication;
}

#endif