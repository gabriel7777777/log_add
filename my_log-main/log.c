static int dgb_level = DBGEnable;
struct zlog_category_s *zc = NULL;

int snic_get_dbg_level(void)
{
	return dgb_level;
}

void snic_set_dbg_level(uint32_t level)
{
	dgb_level = level;
}


int snic_log_init()
{
	//parser config file,set log level, log file size, log file dir, format, etc.
}

int snic_log_fini()
{
	
}

int snic_logfilter(int log_level, int module, const char *file_name, size_t file_len,
	const char *func_name, size_t func_len, long line_num, const char*format, ...)
{

}

