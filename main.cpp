#include <windows.h>
#include <QApplication>
#include "./include/scenes.h"

DWORD WINAPI MainThread(LPVOID param) {
    QApplication app(__argc, __argv);

    Scenes scene;
    scene.show();

    app.exec();
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(hModule);
        CreateThread(NULL, 0, MainThread, NULL, 0, NULL);
    }
    return TRUE;
}
