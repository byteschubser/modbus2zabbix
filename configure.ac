AC_INIT([modbus2zabbix], [0.1], [uwe@kiewel-online.ch])
AM_INIT_AUTOMAKE([-Wall] foreign subdir-objects)
AC_PROG_CC
PKG_CHECK_MODULES([MODBUS], [libmodbus])
AC_CHECK_HEADERS([arpa/inet.h stdio.h stdlib.h errno.h getopt.h ctype.h stdint.h stdbool.h])
AC_CONFIG_FILES([Makefile src/Makefile])
AC_OUTPUT
