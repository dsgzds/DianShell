#include "common.h"

extern BuiltinCmd blt[MAX_BUILTIN_FUNC_NUM];

int cat(int * retc, char ** retv, const int argc, const char ** argv) {
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
    //printf("into\n");
    FILE *fp;
    char ch;
    fp=fopen(argv[0],"r+");
    while((ch=fgetc(fp))!=EOF){
        putchar(ch);
        //printf("hello\n");
    }
    fclose(fp);
    return 0;
}

int catAddBuiltin(){
    BuiltinCmd x;
    strcpy(x.name, "cat");
    strcpy(x.desc, "print content of file");
    x.hasAction = false;
    x.func = &cat;

    x.optNum = 0;
    memset(x.opt, 0, sizeof(x.opt));

    addBuiltinCmd(&x);
    return 0;
}