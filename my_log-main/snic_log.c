#include <stdio.h>
#include"zlog.h"
#include"snic_log.h"
static int dgb_level = DBGEnable;
struct zlog_category_s *zc = NULL;

int snic_get_dbg_level(void)
{
	return dgb_level;
}

void snic_set_dbg_level(__uint32_t level)
{
	dgb_level = level;
}


int snic_log_init(const char *confpath)
{
	//parser config file,set log level, log file size, log file dir, format, etc.
	zlog_init(confpath);
}


zlog_category_t *module(int category)
{
	zlog_category_t *module;
	if(category == 0)
	{
		module = zlog_get_category("module_net");
	}
	else if(category == 1)
	{
		module = zlog_get_category("module_blk");
	}
	else if(category == 2)
	{
		module = zlog_get_category("module_sys");
	}
}

char  *str_info(int category){
	if(category == 0)
	{
		return "hello, net --info";
	}
	else if(category == 1)
	{
		return "hello, blk --info";
	}
	else if(category == 2)
	{
		return "hello, sys --info";
	}
}

char *str_debug(int category){
	if(category == 0)
	{
		return "hello, net --debug";
	}
	else if(category == 1)
	{
		return "hello, blk --debug";
	}
	else if(category == 2)
	{
		return "hello, sys --debug";
	}
}

char *str_warn(int category){
	if(category == 0)
	{
		return "hello, net --warn";
	}
	else if(category == 1)
	{
		return "hello, blk --warn";
	}
	else if(category == 2)
	{
		return "hello, sys --warn";
	}
}

char *str_error(int category){
	if(category == 0)
	{
		return "hello, net --error";
	}
	else if(category == 1)
	{
		return "hello, blk --error";
	}
	else if(category == 2)
	{
		return "hello, sys --error";
	}
}

char *str_panic(int category){
	if(category == 0)
	{
		return "hello, net --panic";
	}
	else if(category == 1)
	{
		return "hello, blk --panic";
	}
	else if(category == 2)
	{
		return "hello, sys --panic";
	}
}

void snic_log_fini(void)
{
	zlog_fini();
}

int snic_logfilter(int log_level, int module, const char *file_name, size_t file_len,
	const char *func_name, size_t func_len, long line_num, const char*format, ...)
{

}

