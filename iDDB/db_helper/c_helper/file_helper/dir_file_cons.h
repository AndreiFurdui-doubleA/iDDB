// positive constants
#define TRUE 1
#define SUCCESS 1
#define SUCCESS_STR "SUCCESS"

// negative constants
#define FALSE 0
#define FAILURE 0
#define FAILURE_STR "FAILURE"

// general usage
#define MAX_STREAM_LENGTH 102400
#define MIN_STREAM_LENGTH 1024
#define TABLE_MANIPULATION_LENGTH 48
#define DATE_LENGTH 10

// log level accepted
#define INFO "INFO"
#define DEBUG "DEBUG"
#define WARN "WARN" //(a.k.a WARNING)
#define ERROR "ERROR"
#define DEBUG_YES 1
#define DEBUG_NO 0 
// we can have only following values:
//DEBUG=TRUE or DEBUG=FALSE so 16 is more than enough
#define DEBUG_ARRAY_LENGTH 16

// the path starting from the $HOME dir
#define DB_PATH "var/iDDB/database/"
#define TABLE_FILE_EXTENSION ".iddb"
#define TABLE_NAME "table_name:"
#define COLUMN_NUMBER "column #"
#define TABLE_PROPERTIES_COMMENT "###########################################\n"
