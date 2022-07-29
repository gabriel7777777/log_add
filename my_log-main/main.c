#include <stdio.h>
#include<string.h>
#include "zlog.h"
//#include "snic_log.h"
#include "snic_log.c"
#include "log_util.h"
int main(int argc,char** argv)
{
	int rc = 0;
	

	rc = snic_log_init("testzzf1.conf");
	if (rc){
	//....
		printf("init failed\n");
		return -1;
	}
	//module()：括号里为0时选择net模块，
	//括号里为1时选择blk模块
	//括号里为3时选择sys模块
	zlog_info(module(1),str_info(1));
	zlog_debug(module(1),str_debug(1));
	zlog_warn(module(1),str_warn(1));
	zlog_error(module(1),str_error(1));
	zlog_panic(module(1),str_panic(1));


	snic_log_fini();
	return 0;
}
