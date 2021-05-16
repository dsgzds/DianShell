#include "common.h"

extern BuiltinCmd blt[MAX_BUILTIN_FUNC_NUM];

int grep(int * retc, char ** retv, const int argc, const char ** argv) {
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

int grepAddBuiltin(){
    BuiltinCmd x;
    strcpy(x.name, "grep");
    strcpy(x.desc, "The grep command is used to find and print out the sections of the file that contain STR. If file is a folder, recurse when -r is enabled Search, or do not operate. Like find, STR also supports two wildcards: * and? .");
    x.hasAction = false;
    x.func = &grep;

    x.optNum = 0;
    memset(x.opt, 0, sizeof(x.opt));

    addBuiltinCmd(&x);
    return 0;
}
