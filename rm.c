#include "common.h"

extern BuiltinCmd blt[MAX_BUILTIN_FUNC_NUM];

int rm(int * retc, char ** retv, const int argc, const char ** argv) {
    if(retc)
        *retc = 0;

    if(argc == 0)
        return 1;

    /*int cmdIdx = findBuiltinCmd(argv[0]);
    if(cmdIdx < 0) {
        printf("command: %s, non-builtin command\n", argv[0]);
        return 0;
    }

    printf("command: %s, builtin command\n  %s\n", argv[0], blt[cmdIdx].desc);
    /** Add your man function here */
    remove(argv[0]);
    return 0;
}

int rmAddBuiltin(){
    BuiltinCmd x;
    strcpy(x.name, "rm");
    strcpy(x.desc, "remove.");
    x.hasAction = false;
    x.func = &rm;

    x.optNum = 0;
    memset(x.opt, 0, sizeof(x.opt));

    addBuiltinCmd(&x);
    return 0;
}
