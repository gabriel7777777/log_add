#include"log_util.h"

void get_file_name(const char *filepath,char *filename){
    char *ptr;
    ptr = strrchr(filepath,'/');
    if(!ptr){
        filename=filepath;
    }
    memcpy(filename,ptr+1,strlen(ptr+1));

}


int log_expired(const char *filename,time_t*time)
{
    char *bptr=strchr(filename,'-');
    char data[20];
    memset(data, '\0', sizeof(data));
    strncpy(data,bptr+1,8);

    struct tm stm;
    strptime(data, "%Y%m%d ",&stm);
    //printf("%d%d%d",stm.tm_year+1900,stm.tm_mon+1,stm.tm_mday);

    struct tm *dtm;
    dtm=localtime(time);
    //printf("%d%d%d",dtm->tm_year+1900,dtm->tm_mon+1,dtm->tm_mday);

    if((dtm->tm_year+1900) > (stm.tm_year+1900)) return 0;
    if((dtm->tm_mon+1) > (stm.tm_mon+1)) return 0;
    if(dtm->tm_mday >stm.tm_mday) return 0;
    return -1;


}


long detect_log_size(const char *filepath,long targetsize){
    int fd;
    fd = open(filepath,O_RDONLY);
    struct stat buf;
    stat(fd,&buf);
    targetsize=targetsize*1024;//*1024;//input 1MB --->1024b
    if(buf.st_size>=targetsize)
    {
        return buf.st_size;
    }
    return -1;


}


void compress_log(const char *filepath){

    char cmd[200];
    char filename[100];
    memset(filename,'\0',sizeof(filename));
    get_file_name(filepath,filename);
    printf("%s\n",filename);
    sprintf(cmd,"tar czvfP %s.tar.gz %s",filename,filepath);
    printf("%s",cmd);
    system(cmd);


}


int dellog(const char *filepath){
    int ret=remove(filepath);
    return ret;

}

