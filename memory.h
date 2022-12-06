#include <Windows.h>
#include <TlHelp32.h>

uintptr_t p_pid;
DWORD procces_id;
HANDLE game;
class Memory
{
public:
    bool GetInfoWindow(const wchar_t* process_name, DWORD& process_id, HANDLE& hn) {
        DWORD processId = 0;
        HWND wn = FindWindowW(NULL, process_name);
        if (wn == NULL) {
            return false;
        }
        GetWindowThreadProcessId(wn, &processId);
        process_id = processId;
        hn = OpenProcess(PROCESS_ALL_ACCESS, NULL, processId);
        return true;
    }

    uintptr_t GetModuleBaseAddress(DWORD procId, const wchar_t* modName)
    {
        uintptr_t modBaseAddr = 0;
        HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, procId);
        if (hSnap != INVALID_HANDLE_VALUE)
        {
            MODULEENTRY32 modEntry;
            modEntry.dwSize = sizeof(modEntry);
            if (Module32First(hSnap, &modEntry))
            {
                do
                {
                    if (!_wcsicmp(modEntry.szModule, modName))
                    {
                        modBaseAddr = (uintptr_t)modEntry.modBaseAddr;
                        break;
                    }
                } while (Module32Next(hSnap, &modEntry));
            }
        }
        CloseHandle(hSnap);
        return modBaseAddr;
    }

    template <class T>
    T Read(uintptr_t dwAdr) {
        T _read;
        ReadProcessMemory(game, LPCVOID(dwAdr), &_read, sizeof(T), NULL);
        return _read;
    }

    void Read(uintptr_t dwAdr, LPVOID wts, int byte) {
        ReadProcessMemory(game, LPCVOID(dwAdr), wts, byte, NULL);
    }

    template <class T>
    void Write(uintptr_t dwAdr, T _value) {
        WriteProcessMemory(game, LPVOID(dwAdr), &_value, sizeof(T), NULL);
    }

    void Exit(HANDLE game) {
        CloseHandle(game);
    }
};
