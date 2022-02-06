#pragma once


#ifdef FE_PLATFORM_WINDOWS

extern Funingine::MainApplication* Funingine::CreateMainApplication();

int main(int argc, char** argv) 
{
	auto mainApplication = Funingine::CreateMainApplication();
	mainApplication->Run();
	delete mainApplication;
}

#endif