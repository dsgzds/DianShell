#include "common.h"

char PS1[MAX_COMMAND_LENGTH] = "\033[32m[\\u \\p]$\033[0m ";
char PS1Buf[MAX_DIR_CONCAT_LENGTH];
//char now_dir[1024];

// 打印提示符
int putPS1() {
    static char * x[1] = {PS1Buf};
    int retc;

    size_t pos = 0;
    size_t len = strlen(PS1);
    while(pos < len) {
        if(PS1[pos] == '\\' && pos < len - 1) {
            switch(PS1[pos + 1]) {
            case 'p':
                pwd(&retc, (char **) x, 0, NULL); // print pwd
                printf("%s", PS1Buf);
                break;
            case 'u':
                printf("root"); //print user
                break;
            default:
                putchar('\\');
                pos --;
            }
            pos += 2;
        } else {
            putchar(PS1[pos++]);
        }
    }
    return 0;
}

// 分割输入的字符串，去除注释和开头结尾多余的空字符, 生成 cmdParser 的输入
int splitCmdInput(const char* str) {
    int argc = 0;
    char * argv[MAX_ARGV_LENGTH] = {0};

    char * posA = (char *) str;
    while(*posA && *posA == ' ') posA++;

    char * posB = posA;
    while(*posB) {
        if(*posB == '#') {
            *posB = 0; // '#' means comment
            break;
        } else if(*posB == '\t') {
            *posB = ' '; // convert '\t' to ' '
        }
        posB ++;
    }
    while(*(posB - 1) && *(posB - 1) == ' ') *(--posB) = 0;

    if(*posA) {
        posB = posA++;
        while(*posA) {
            if(*posA == ' ') {
                argv[argc] = (char *)malloc(posA - posB + 1);
                strncpy(argv[argc], posB, posA - posB);
                argv[argc][posA - posB] = 0;
                argc ++;
                posB = posA + 1;
            }
            posA ++;
        }
        if(posA > posB) {
            argv[argc] = (char *)malloc(posA - posB + 1);
            strncpy(argv[argc], posB, posA - posB);
            argv[argc][posA - posB] = 0;
            argc ++;
        }
    }
    int ret = cmdParser(argc, (const char **) argv);
    while(argc--) if(argv[argc]) free(argv[argc]); // free malloc
    return ret;
}

/** 命令行解析 */
int cmdParser(const int argc, const char * argv[]) {
    bool builtin;
    int i;
    char parameter[1024][MAX_ARGV_LENGTH];
    char shortopt[1024][3];
    char longopt[1024][MAX_BUILTIN_OPT_LENGTH];
    char optpara[1024][MAX_BUILTIN_OPT_LENGTH];
    //char note[1024]={0};
    char temp[100];
    char now_dir[MAX_COMMAND_LENGTH];
    shortCommand commands[20];
    //longCom lcommands[20];
    if(argc == 0)
        return 0;
    /*for(int i=0;i<argc;i++){
        printf("%s\n",argv[i]);
    }*/
    //printf("%d\n",!strcmp("man",argv[0]));
    if(!strcmp("man",argv[0])){
        if(argc == 1) {
            printf("Usage: man <command>\n");
            return 1;
        }
        //strcpy((char *)argv[1],strcat(now_dir,argv[1]));
        man(NULL, NULL, 1, (const char **)(argv+1));
    }
    else if(!strcmp("inject",argv[0])){
        if(argc==1){
            printf("Usage: inject <file>\n");
            return 1;
        }
        //strcpy((char *)argv[1],strcat(now_dir,argv[1]));
        inject(NULL,NULL,1,(const char **)(argv+1));
    }
    else if(!strcmp("touch",argv[0])){
        if(argc==1){
            printf("Usage:touch <file>\n");
            return 1;
        }
        //strcpy((char *)argv[1],strcat(now_dir,argv[1]));
        //printf("into\n");
        touch(NULL,NULL,1,(const char **)(argv+1));
    }
    else if(!strcmp("rm",argv[0])){
        if(argc==1){
            printf("Usage:touch <file>\n");
            return 1;
        }
        //strcpy((char *)argv[1],strcat(now_dir,argv[1]));
        rm(NULL,NULL,1,(const char **)(argv+1));
    }
    else if(!strcmp("cp",argv[0])){
        if(argc==1){
            printf("Usage:touch <file>\n");
            return 1;
        }
        //strcpy((char *)argv[1],strcat(now_dir,argv[1]));
        cp(NULL,NULL,1,(const char **)(argv+1));
    }
    else if(!strcmp("mkdir",argv[0])){
        if(argc==1){
            printf("Usage:touch <file>\n");
            return 1;
        }
        //strcpy((char *)argv[1],strcat(now_dir,argv[1]));
        mymkdir(NULL,NULL,1,(const char **)(argv+1));
    }
    else if(!strcmp("rmdir",argv[0])){
        if(argc==1){
            printf("Usage:touch <file>\n");
            return 1;
        }
        //strcpy((char *)argv[1],strcat(now_dir,argv[1]));
        myrmdir(NULL,NULL,1,(const char **)(argv+1));
    }
    else if(!strcmp("cd",argv[0])){
        if(argc==1){
            printf("Usage:touch <file>\n");
            return 1;
        }
       // strcpy((char *)argv[1],strcat(now_dir,argv[1]));
        cd(NULL,NULL,1,(const char **)(argv+1));
    }
    /*else if(!strcmp("ls",argv[0])){
        if(argc==1){
            printf("Usage:touch <file>\n");
            return 1;
        }
        ls(NULL,NULL,1,argv+1);
    }*/
    else if(!strcmp("append",argv[0])){
        if(argc==1){
            printf("Usage:touch <file>\n");
            return 1;
        }
        for(i=3;argv[i];i++){
            strcat(argv[2]," ");
            strcat(argv[2],argv[i]);
        }
        //strcpy((char *)argv[1],strcat(now_dir,argv[1]));
        append(NULL,NULL,1,(const char **)(argv+1));
    }
    else if(!strcmp("cat",argv[0])){
        if(argc==1){
            printf("Usage:touch <file>\n");
            return 1;
        }
        //strcpy((char *)argv[1],strcat(now_dir,argv[1]));
        cat(NULL,NULL,1,(const char **)(argv+1));
    }
    else{
        //printf("into2\n");
        builtin = isBuiltinCmd(argv[0]);
        printf("Command: %s, %sbuiltin command\n", argv[0], builtin ? "" : "non-");

        int j=0,v=1,k=0,m=0,count=0,l,t,flag;
        printf("options:\n");
        for(i=1,v=1;i<argc-1;i++){
            if(argv[i][0]!='-'&&argv[i+1][0]!='-')
                strcpy(parameter[j++],argv[i+1]);
            else if(argv[i][0]=='-'){
                if(argv[i][1]!='-') strcpy(commands[v].Option,argv[i]);
                else commands[v].Option[0]='-',commands[v].Option[1]=argv[i][2],commands[v].Option[3]='\0';//strncpy(commands[v].Option,argv[i],2);
                if(argv[i+1][0]!='-'){
                strcpy(commands[v++].para,argv[i+1]);
                //strcpy(commands[v++].para,argv[i+1]);
                }else commands[v++].para[0]='\0';
            }
        }
        k=v-1;
        l=j;
        for(j=0;j<v-1;j++){
            for(i=0;i+1<k-j;i++){
            if(tolower(commands[i].Option[1])>tolower(commands[i+1].Option[1])){
                strcpy(temp,commands[i].Option);
                strcpy(commands[i].Option,commands[i+1].Option);
                strcpy(commands[i+1].Option,temp);
                strcpy(temp,commands[i].para);
                strcpy(commands[i].para,commands[i+1].para);
                strcpy(commands[i+1].para,temp);
            }
        }
        }
        for(i=0;i<v;i++){
            switch(commands[i].Option[1]){
                case 'h': strcpy(longopt[i],"--help");break;
                case 'a':strcpy(longopt[i],"--all");break;
                case 'd':strcpy(longopt[i],"--director");break;
                case 's':strcpy(longopt[i],"--sort-by");break;
                case 'b':strcpy(longopt[i],"--batch");break;
                case 'c':strcpy(longopt[i],"--check");break;
                case 'e':strcpy(longopt[i],"--execute");break;
                case 'f':strcpy(longopt[i],"--force");break;
                case 'g':strcpy(longopt[i],"--gcc");break;
                case 'i':strcpy(longopt[i],"--initialize");break;
                case 'j':strcpy(longopt[i],"--j....");break;
                case 'k':strcpy(longopt[i],"--keep");break;
                case 'l':strcpy(longopt[i],"--login");break;
                case 'm':strcpy(longopt[i],"--message");break;
                case 'n':strcpy(longopt[i],"--number");break;
                case 'o':strcpy(longopt[i],"--output");break;
                case 'p':strcpy(longopt[i],"--port");break;
                case 'q':strcpy(longopt[i],"--quite");break;
                case 'r':strcpy(longopt[i],"--reverse");break;
                case 't':strcpy(longopt[i],"--tag");break;
                case 'u':strcpy(longopt[i],"--user");break;
                case 'v':strcpy(longopt[i],"--version");break;
                case 'w':strcpy(longopt[i],"--width");break;
                case 'x':strcpy(longopt[i],"--extract");break;
                case 'y':strcpy(longopt[i],"--yes");break;
                case 'z':strcpy(longopt[i],"--zip");break;
            }
        }
        for(i=1; i < v; i++) {
        /* Add your code here */
        printf("  ");
        if(commands[i].para[0]=='\0')
        printf("%s, %s\n",commands[i].Option,longopt[i]);
        else printf("%s, %s %s\n",commands[i].Option,longopt[i],commands[i].para);
    }
        printf("parameter:\n");
        for(i=0;i<l;i++){
            printf("  ");
            printf("[%d] %s\n",i,parameter[i]);
        }

    }
    return 0;
}
