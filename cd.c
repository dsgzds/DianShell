#include "common.h"

extern BuiltinCmd blt[MAX_BUILTIN_FUNC_NUM];

int cd(int * retc, char ** retv, const int argc, const char ** argv) {
    char now_dir[MAX_COMMAND_LENGTH];
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
    if(argv[0][0]=='.'&&argv[0][1]=='.'&&argv[0][2]=='/'){
        for(int i=strlen(now_dir)-1;i>=0;i--){
            if(now_dir[i]=='/'&&argv[0][3]){
                for(int j=i,v=3;argv[0][v];j++,v++){
                    now_dir[j]=argv[0][v];
                }
                break;
            }
            else if(now_dir[i]=='/'){
                now_dir[i]='\0';
                break;
            }
        }
    }
    else if(argv[0][0]=='.'&&argv[0][1]=='/'){
        strcat(now_dir,&argv[0][2]);
    }
    else if(!access(argv[0],0)){
        printf("cannot find path!\n");
    }
    else{
        strcpy(now_dir,argv[0]);
    }
    
    return 0;
}

int cdAddBuiltin(){
    BuiltinCmd x;
    strcpy(x.name, "cd");
    strcpy(x.desc, "cd stands for Change Directory. Set the current working directory to Directory. $HOME is the environment variable representing the user's initial directory.The default is root/when not set.");
    x.hasAction = false;
    x.func = &cd;

    x.optNum = 0;
    memset(x.opt, 0, sizeof(x.opt));

    addBuiltinCmd(&x);
    return 0;
}
