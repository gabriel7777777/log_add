
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <time.h>

void get_file_name(const char *,char *);

/****
judge log is older than timer time
0 expired -1 not expired
****/
int log_expired(const char *,time_t*);
/*
detect log file size ,if over designed size return size ,else -1
*/
long detect_log_size(const char *filepath,long targetsize);
/****
 * log compress and delete old file
****/ß
void compress_log(const char *);

/*****
 * delete  the whole expired file
 * succes 0 failed -1
 *****/
int dellog(const char *);

