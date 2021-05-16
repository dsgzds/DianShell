#include "common.h"

extern BuiltinCmd blt[MAX_BUILTIN_FUNC_NUM];

int ls(int * retc, char ** retv, const int argc, const char ** argv) {
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

    return 0;
}

int lsAddBuiltin(){
    BuiltinCmd x;
    strcpy(x.name, "ls");
    strcpy(x.desc, "List directory contents.Prints all file information in the directory (default is the current directory.), by default according to the file name ASCII code is output in ascending order.");
    x.hasAction = false;
    x.func = &ls;

    x.optNum = 0;
    memset(x.opt, 0, sizeof(x.opt));

    addBuiltinCmd(&x);
    return 0;
}
