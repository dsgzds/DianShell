#include "common.h"

BuiltinCmd blt[MAX_BUILTIN_FUNC_NUM];
int bltNum;

/** builtin 初始化 */
int initBuiltin() {
    memset(blt, 0, sizeof(blt));

    /** Register builtin commands here */
    manAddBuiltin();
    pwdAddBuiltin();
    commandAddBuiltin();
    testAddBuiltin();
    cdAddBuiltin();
    duAddBuiltin();
    lsAddBuiltin();
    treeAddBuiltin();
    chmodAddBuiltin();
    cpAddBuiltin();
    rmAddBuiltin();
    touchAddBuiltin();
    findAddBuiltin();
    mkdirAddBuiltin();
    rmdirAddBuiltin();
    testpathAddBuiltin();
    appendAddBuiltin();
    catAddBuiltin();
    grepAddBuiltin();
    clearAddBuiltin();
    echoAddBuiltin();
    injectAddBuiltin();
    return 0;
}

int addBuiltinCmd(const BuiltinCmd * cmd) {
    memcpy(blt + bltNum, cmd, sizeof(BuiltinCmd));
    bltNum ++;
    return 0;
}

/** 查找名称为 name 的内置命令 */
int findBuiltinCmd(const char * name) {
    int i;
    for(i = 0; i < bltNum; i++)
        if(strcmp(name, blt[i].name) == 0) return i;
    return -1;
}

/** 是否为内置命令 */
bool isBuiltinCmd(const char * name) {
    return findBuiltinCmd(name) >= 0;
}

/** 查找 cmd 中名称为 shortOpt 的短命令 */
int findCmdShortOpt(const BuiltinCmd * cmd, const char shortOpt) {
    int i;
    for(i = 0; i < cmd->optNum; i++)
        if(shortOpt == cmd->opt[i].shortOpt) return i;
    return -1;
}

/** 添加一个设置 */
int addCmdFlag(BuiltinCmd * cmd, const char shortOpt, const char * longOpt, const char * desc, const int paramNum) {
    if(findCmdShortOpt(cmd, shortOpt) >= 0)
        return 1;

    CmdFlags * flag = cmd->opt + cmd->optNum;
    flag->shortOpt = shortOpt;
    strcpy(flag->longOpt, longOpt);
    strcpy(flag->desc, desc);
    flag->paramNum = paramNum;
    flag->var = NULL;

    cmd->optNum ++;
    return 0;
}
