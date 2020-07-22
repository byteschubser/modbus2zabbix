#ifndef __MODBUS2ZABBIX_H__
#define __MODBUS2ZABBIX_H__
#include <stdbool.h>
void print_error_msg(int, int);
void print_help(void);
void use_tcp(char*, int, int, int, int);
void use_rtu(char*, int, int, int, int);
bool isValidIpAddress(char*);
#endif
