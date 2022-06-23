#include "Test.h"

#if SYSTEM_WINDOWS

int Main(int argc, char** argv)
{
	static_cast<void>(argc, argv);

	test::Perform();

	return 0;
}

#if CONFIG_DIST

#include <Windows.h>

int APIENTRY WinMain(_In_ HINSTANCE hInst, _In_opt_ HINSTANCE hInstPrev, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	static_cast<void>(hInst, hInstPrev, lpCmdLine, nCmdShow);
	return Main(__argc, __argv);
}

#else // !CONFIG_DIST

int main(int argc, char** argv)
{
	return Main(argc, argv);
}

#endif // CONFIG_DIST

#endif // SYSTEM_WINDOWS
