#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#define MAX_COMMAND_LENGTH (16384)
#define MAX_DIR_CONCAT_LENGTH (4096)
#define MAX_ARGV_LENGTH (1024)

int putPS1();
int splitCmdInput(const char* str);
int cmdParser(const int argc, const char * argv[]);

#endif // INPUT_H_INCLUDED
