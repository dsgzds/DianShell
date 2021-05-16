#include "common.h"
extern BuiltinCmd blt[MAX_BUILTIN_FUNC_NUM];
int command(int * retc, char ** retv, const int argc, const char ** argv){
        if(retc)
        *retc = 0;

    if(argc == 0)
        return 1;
    int cmdIdx = findBuiltinCmd(argv[0]);
    printf("command: %s, %sbuiltin command\n", argv[0],cmdIdx<0?"non-":"");
        
    
    return 0;
}
int commandAddBuiltin() {
    BuiltinCmd x;
    strcpy(x.name, "command");
    strcpy(x.desc, "belong to builtin or not");
    x.hasAction = false;
    x.func = &command;

    x.optNum = 0;
    memset(x.opt, 0, sizeof(x.opt));

    addBuiltinCmd(&x);
    return 0;
}