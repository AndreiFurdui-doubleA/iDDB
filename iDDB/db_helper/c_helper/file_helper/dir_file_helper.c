#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <dirent.h>
#include <fcntl.h>
#include <errno.h>
//#include<stdio.h>
#include "dir_file_cons.h"
#include "../../../logger/c_logger/c_logger.c"


// Returns True if the specified argument contains at least 1 character,
// False otherwise
int check_null_argument (char *argument) {
	return strlen(argument) == 0 ? FALSE:TRUE;
}

// Returns False if the specified dir exists, true otherwise
// database_call parameter specifies if this is a call from the
// database manipulation level (e.g. the one in charge with creation/deletion
// of database etc.). If so, this parameter should have the value 1, 0 otherwise
int check_dir_exists (char *dir, int database_call) {
   	DIR *dr = opendir(dir);
	char *log_info = (char *) malloc (sizeof (char *) * MAX_STREAM_LENGTH/2);
    	if (dr == NULL) {
		if (!database_call) {
			strcpy(log_info, "check_dir_exists.c line 17 - ");
			strcat(log_info, "Could not open the specified directory (or database): ");
			strcat(log_info, dir);
			write_log(ERROR, log_info);
		}
		// this clause refers to the database manipulation work (e.g.
		// an user tries to create a new database etc.)
		else {
			strcpy(log_info, "An user tries to see (list) the database: ");
			strcat(log_info, dir);
			strcat(log_info, " but it doesn't exist...");
			write_log(INFO, log_info);
		}
		closedir(dr);
		free(log_info);
		return TRUE;
    	}

	if (!database_call) {
		strcpy(log_info, "Open the specified directory (or database): ");
		strcat(log_info, dir);
		write_log(INFO, log_info);
	} else {
		strcpy(log_info, "An user tries to see (list) the database: ");
		strcat(log_info, dir);
		strcat(log_info, " and it already exists...");
		write_log(INFO, log_info);
	}
	closedir(dr);
	free(log_info);
	return FALSE;
}

// Returns True if the specified file exists, false otherwise
int check_file_exists (char *file) {
	int fd = open(file, O_CREAT | O_WRONLY | O_EXCL, S_IRUSR | S_IWUSR);
	if (fd < 0) {
	  	if (errno == EEXIST) {
			close (fd);
	    		return TRUE;
	  	}
	}
	close (fd);
	return FALSE;
}

// Returns the $HOME path for the current user
char * home_path() {
	char *homedir;
	if ((homedir = getenv("HOME")) == NULL) {
    		homedir = getpwuid(getuid())->pw_dir;
	}
	strcat(homedir, "/");
	return homedir;
}	
