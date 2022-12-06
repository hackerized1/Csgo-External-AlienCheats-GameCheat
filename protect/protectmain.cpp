#include "protectmain.h"
#include "antidump.h"
#include "anti_debugger.h"



void blue_screen()
{
    BOOLEAN bluescr;
    ULONG cevap;
    RtlAdjustPrivilege(19, TRUE, FALSE, &bluescr);
    NtRaiseHardError(STATUS_ASSERTION_FAILURE, 0, 0, NULL, 6, &cevap);
}

void kill_process()
{
	system(_("taskkill /f /im HTTPDebuggerUI.exe >nul 2>&1").c_str());
	system(_("taskkill /f /im HTTPDebuggerSvc.exe >nul 2>&1").c_str());
	system(_("sc stop HTTPDebuggerPro >nul 2>&1").c_str());
	system(_("taskkill /FI \"IMAGENAME eq cheatengine*\" /IM * /F /T >nul 2>&1").c_str());
	system(_("taskkill /FI \"IMAGENAME eq httpdebugger*\" /IM * /F /T >nul 2>&1").c_str());
	system(_("taskkill /FI \"IMAGENAME eq processhacker*\" /IM * /F /T >nul 2>&1").c_str());
}

void mainprotect() {
	std::thread(hidethread).detach();
	std::thread(remotepresent).detach();
	std::thread(contextthread).detach();
	std::thread(debugstring).detach();
	std::thread(kill_process).detach();
}