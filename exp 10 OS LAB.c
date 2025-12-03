#include <windows.h>
#include <stdio.h>

int main() {
    const char *PIPE_NAME = "\\\\.\\pipe\\mypipe";
    HANDLE hPipe;

     
    hPipe = CreateNamedPipe(
        PIPE_NAME,
        PIPE_ACCESS_OUTBOUND,
        PIPE_TYPE_BYTE | PIPE_READMODE_BYTE | PIPE_WAIT,
        1,
        1024, 1024,
        0,
        NULL
    );

    if (hPipe == INVALID_HANDLE_VALUE) {
        printf("Failed to create pipe. Error: %ld\n", GetLastError());
        return 1;
    }

    printf("Parent: Waiting for child to connect...\n");

    
    STARTUPINFO si = { sizeof(si) };
    PROCESS_INFORMATION pi;

    if (!CreateProcess(
        NULL,
        "msg_child.exe",   
        NULL, NULL, FALSE,
        0, NULL, NULL,
        &si, &pi
    )) {
        printf("Failed to start child. Error: %ld\n", GetLastError());
        return 1;
    }

    
    ConnectNamedPipe(hPipe, NULL);

    const char *message = "hello via Windows pipe";
    DWORD written;

    WriteFile(hPipe, message, strlen(message) + 1, &written, NULL);

    CloseHandle(hPipe);
    WaitForSingleObject(pi.hProcess, INFINITE);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    printf("Parent: Message sent.\n");

    return 0;
}

