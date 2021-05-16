#include "common.h"
char now_dir[1024];
int pwd(int * retc, char ** retv, const int argc, const char ** argv) {
    if(!retc) return 1;
    *retc = 1;
    /** Add your pwd function here */
    sprintf(retv[0], "/%s",now_dir);
    return 0;
}

int pwdAddBuiltin() {
    BuiltinCmd x;
    strcpy(x.name, "pwd");
    strcpy(x.desc, "Print working directory.");
    x.hasAction = false;
    x.func = &pwd;

    x.optNum = 0;
    memset(x.opt, 0, sizeof(x.opt));
    addBuiltinCmd(&x);
    return 0;
}
