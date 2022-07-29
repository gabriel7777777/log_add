#define LevelOff                 0
#define ERREnable                1
#define WARNEnable               2
#define INFOEnable               3
#define DBGEnable                4


#define MODULE_NET                 0
#define MODULE_BLK                 1
#define MODULE_SYS                 2



#define SNIC__PRINT_DBG(module, fmt, arg...) do { \
if (snic_get_dbg_level() >= DBGEnable) { \
    snic_logfilter(ZLOG_LEVEL_DEBUG, module,__FILE__, sizeof(__FILE__) - 1,__func__,\
	sizeof(__func__) -1,__LINE__, fmt, ##arg);\          \
} } while (0)

#define SNIC__PRINT_INFO(module, fmt, arg...) do { \
if (snic_get_dbg_level() >= INFOEnable) { \
    snic_logfilter(ZLOG_LEVEL_INFO, module,__FILE__, sizeof(__FILE__) - 1,__func__,\
	sizeof(__func__) -1,__LINE__, fmt, ##arg);\  
} } while (0)

#define SNIC__PRINT_WARN(module, fmt, arg...) do { \
if (snic_get_dbg_level() >= WARNEnable) { \
    snic_logfilter(ZLOG_LEVEL_WARN, module,__FILE__, sizeof(__FILE__) - 1,__func__,\
	sizeof(__func__) -1,__LINE__, fmt, ##arg);\  
} } while (0)

#define SNIC__PRINT_ERR(module, fmt, arg...) do { \
if (snic_get_dbg_level() >= ERREnable) { \
    snic_logfilter(ZLOG_LEVEL_ERROR, module,__FILE__, sizeof(__FILE__) - 1,__func__,\
	sizeof(__func__) -1,__LINE__, fmt, ##arg);\  
} } while (0)

#define SNIC__PANIC(module, fmt, arg...) do { \
	SNIC__PRINT_ERR(module, fmt, ##arg);            \
	abort();
} while (0)

int snic_log_init();

