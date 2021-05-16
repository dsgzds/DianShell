#include "common.h"

extern BuiltinCmd blt[MAX_BUILTIN_FUNC_NUM];

int du(int * retc, char ** retv, const int argc, const char ** argv) {
    if(retc)
        *retc = 0;

    if(argc == 0)
        return 1;

    int cmdIdx = findBuiltinCmd(argv[0]);
    if(cmdIdx < 0) {
        printf("command: %s, non-builtin command\n", argv[0]);
        return 0;
    }

    printf("command: %s, builtin command\n  %s\n", argv[0], blt[cmdIdx].desc);
    /** Add your man function here */

    return 0;
}

int duAddBuiltin(){
    BuiltinCmd x;
    strcpy(x.name, "du");
    strcpy(x.desc, "disk usage.Print out the file file (generally directory, default value is the current directory.) space usage statistics, the default press output the file name in ascending ASCII order.");
    x.hasAction = false;
    x.func = &du;

    x.optNum = 0;
    memset(x.opt, 0, sizeof(x.opt));

    addBuiltinCmd(&x);
    return 0;
}
