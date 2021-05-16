#include "common.h"

extern BuiltinCmd blt[MAX_BUILTIN_FUNC_NUM];

int inject(int * retc, char ** retv, const int argc, const char ** argv) {
    char command[MAX_COMMAND_LENGTH][100];
    int i=0,j=0;
    if(retc)
        *retc = 0;

    if(argc == 0)
        return 1;

    /*int cmdIdx = findBuiltinCmd(argv[0]);
    if(cmdIdx < 0) {
        printf("command: %s, non-builtin command\n", argv[0]);
        return 0;
    }

    printf("command: %s, builtin command\n  %s\n", argv[0], blt[cmdIdx].desc);*/
    FILE *fp;
    fp=fopen(argv[0],"r+");
    if(fp==NULL){
        printf("未找到该文件");
        return 0;
    }
    while(fscanf(fp,"%s\n",command[i++])!=EOF){
        printf("%s\n",command[i-1]);
    }
    for(j=0;j<i;j++){
        splitCmdInput(command[j]);
    }
    
    fclose(fp);
    return 0;
}

int injectAddBuiltin(){
    BuiltinCmd x;
    strcpy(x.name, "inject");
    strcpy(x.desc, "inject file");
    x.hasAction = false;
    x.func = &inject;

    x.optNum = 0;
    memset(x.opt, 0, sizeof(x.opt));

    addBuiltinCmd(&x);
    return 0;
}
