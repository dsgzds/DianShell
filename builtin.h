#ifndef BUILTIN_H_INCLUDED
#define BUILTIN_H_INCLUDED

#define MAX_BUILTIN_FUNC_NUM (128)
#define MAX_BUILTIN_NAME_LENGTH (128)
#define MAX_BUILTIN_OPT_LENGTH (64)

#define MAX_LONGOPT_NAME_LENGTH (128)
#define MAX_BUILTIN_DESC_LENGTH (1024)
typedef struct CmdFlags {
    char shortOpt; // 短命令, '\0' 表示无
    char longOpt[MAX_LONGOPT_NAME_LENGTH]; // 长命令, 空字符串表示无
    char desc[MAX_BUILTIN_DESC_LENGTH]; // 对此设置的描述
    int paramNum; // 0: 不带参数, 正数: 定长参数, 负数: 不定长参数
    char ** var; // 指向存储值的指针
} CmdFlags;
typedef struct Command{
    //int flag;
    char Option[20];
    char para[20];
}shortCommand;
typedef struct Com{
    char Option[20];
    char para[20];
}longCom;
/** retc, retv, argc, argv */
typedef int BUILTIN_FUNC_TYPE(int *, char **, const int, const char **);

typedef struct BuiltinCmd {
    char name[MAX_BUILTIN_NAME_LENGTH]; // 命令名称
    char desc[MAX_BUILTIN_DESC_LENGTH]; // 对此命令的描述
    bool hasAction; // 是否有 action
    int optNum; // 设置的个数
    CmdFlags opt[MAX_BUILTIN_OPT_LENGTH]; // 设置数组
    BUILTIN_FUNC_TYPE * func; // 回调函数
} BuiltinCmd;

int initBuiltin();
int addBuiltinCmd(const BuiltinCmd * cmd);
int findBuiltinCmd(const char * name);
bool isBuiltinCmd(const char * name);
int findCmdShortOpt(const BuiltinCmd * cmd, const char shortOpt);
int addCmdFlag(BuiltinCmd * cmd, const char shortOpt, const char * longOpt, const char * desc, const int paramNum);

BUILTIN_FUNC_TYPE pwd;
int pwdAddBuiltin();
BUILTIN_FUNC_TYPE append;
int appendAddBuiltin();
BUILTIN_FUNC_TYPE cp;
int cpAddBuiltin();
BUILTIN_FUNC_TYPE du;
int duAddBuiltin();
BUILTIN_FUNC_TYPE command;
int commandAddBuiltin();
BUILTIN_FUNC_TYPE cat;
int catAddBuiltin();
BUILTIN_FUNC_TYPE tree;
int treeAddBuiltin();
BUILTIN_FUNC_TYPE echo;
int echoAddBuiltin();
BUILTIN_FUNC_TYPE clear;
int clearAddBuiltin();
BUILTIN_FUNC_TYPE inject;
int injectAddBuiltin();
BUILTIN_FUNC_TYPE man; 
int manAddBuiltin();
BUILTIN_FUNC_TYPE ls;
int lsAddBuiltin();
BUILTIN_FUNC_TYPE mymkdir;
int mkdirAddBuiltin();
BUILTIN_FUNC_TYPE myrmdir;
int rmdirAddBuiltin();
BUILTIN_FUNC_TYPE find;
int findAddBuiltin();
BUILTIN_FUNC_TYPE touch;
int touchAddBuiltin();
BUILTIN_FUNC_TYPE grep;
int grepAddBuiltin();
BUILTIN_FUNC_TYPE rm;
int rmAddBuiltin();
BUILTIN_FUNC_TYPE test;
int testAddBuiltin();
BUILTIN_FUNC_TYPE testpath;
int testpathAddBuiltin();
BUILTIN_FUNC_TYPE cd;
int cdAddBuiltin();
BUILTIN_FUNC_TYPE my_chmod;
int chmodAddBuiltin();
#endif // BUILTIN_H_INCLUDED
