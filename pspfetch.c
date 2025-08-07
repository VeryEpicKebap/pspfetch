#include <pspkernel.h>
#include <pspdebug.h>
#define W 0xFFFFFFFF
#define G 0xFF00FF00
PSP_MODULE_INFO("PSPFetch", 0, 1, 1);

int main(void)
{
    u32 version = sceKernelDevkitVersion();
    int major = (version >> 24) & 0xFF;
    int minor = (version >> 16) & 0xFF;
    u32 total = sceKernelTotalFreeMemSize();
    u32 used = sceKernelMaxFreeMemSize();
    u32 total_mem = 0;
    if (sceKernelTotalFreeMemSize() > 20 * 1024 * 1024)
        total_mem= 64*1024*1024;
    else
        total_mem= 32*1024*1024;
    pspDebugScreenInit();
    pspDebugScreenSetTextColor(G);
    pspDebugScreenPrintf("              ___________          _______ ___________\n");
    pspDebugScreenPrintf("                         |        |                   |\n");
    pspDebugScreenPrintf("                         |        |                   |\n");
    pspDebugScreenPrintf("              -----------         |        ----------- \n");
    pspDebugScreenPrintf("              |                   |        |\n");
    pspDebugScreenPrintf("              |            _______|        |\n");
    pspDebugScreenSetTextColor(W);
    pspDebugScreenPrintf("\n\nFW Version: %d.%d \n",major,minor);
    pspDebugScreenPrintf("RAM: %u KB / %u KB", used / 1024, total_mem / 1024);
    sceKernelSleepThread();
    return 0;
}
