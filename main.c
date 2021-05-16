#include "common.h"

int init() {
    time_t t;
    t = time(NULL);
    printf("> Dian Shell\nCurrent Timestamp: %lld\nPress Ctrl+C to exit.\n", t);

    initBuiltin();

#ifdef X_WIN
    // set windows console mode
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);

    DWORD modeIn, modeOut;
    GetConsoleMode(hOut, &modeOut);
    SetConsoleMode(hOut, modeOut | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
    GetConsoleMode(hIn, &modeIn);
    // SetConsoleMode(hIn, modeIn | ENABLE_VIRTUAL_TERMINAL_INPUT);

    CONSOLE_SCREEN_BUFFER_INFO ptInfo;
    GetConsoleScreenBufferInfo(hOut, &ptInfo);
    printf(
        "Console Size: %d x %d (buffer %d x %d)\n",
        ptInfo.dwMaximumWindowSize.X, ptInfo.dwMaximumWindowSize.Y,
        ptInfo.dwSize.X, ptInfo.dwSize.Y
    );

    GetConsoleMode(hIn, &modeIn);
    GetConsoleMode(hOut, &modeOut);
    printf("Console Mode: in 0x%04x out 0x%04x\n", modeIn, modeOut);
#endif // X_WIN

    printf("Init done...\n");
    return 0;
}

int main(int argc, char * argv[]) {
    char line[MAX_COMMAND_LENGTH];
    memset(line, 0, sizeof(line));

    if(init())
        return 1;

    putPS1();
    while(EOF != scanf("%[^\n]", &line)) {
        getchar(); // read '\n'
        splitCmdInput(line);
        putPS1();
    }
    return 0;
}
