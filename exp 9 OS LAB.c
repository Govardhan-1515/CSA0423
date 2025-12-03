#include <windows.h>
#include <stdio.h>
#include <string.h>

int main() {
    const char *name = "MySharedMemory";

    HANDLE hMap = CreateFileMapping(
        INVALID_HANDLE_VALUE,    // use RAM, not a real file
        NULL,
        PAGE_READWRITE,
        0,
        1024,
        name
    );

    if (hMap == NULL) {
        printf("CreateFileMapping error: %ld\n", GetLastError());
        return 1;
    }

    char *p = (char*) MapViewOfFile(hMap, FILE_MAP_WRITE, 0, 0, 0);
    if (p == NULL) {
        printf("MapViewOfFile error: %ld\n", GetLastError());
        CloseHandle(hMap);
        return 1;
    }

    // Write message to shared memory
    strcpy(p, "hello from parent");

    printf("Parent wrote data.\n");

    // Launch child.exe
    system("child.exe");

    // Cleanup
    UnmapViewOfFile(p);
    CloseHandle(hMap);

    return 0;
}
