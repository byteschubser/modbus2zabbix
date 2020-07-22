#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <getopt.h>
#include <ctype.h>
#include <stdint.h>
#include "modbus2zabbix.h"
#include "definitions.h"

int main(int argc, char **argv) {
	int		tflag = 0;	// -t tcp
	int		rflag = 0;	// -r rtu
	int		mod_reg = 0;	// -R Nummer des Registers
	int 		laenge = 0;	// -l Länge des Registers
	int		id = 0;		// -i ModBus Slave ID
	int		swap = 0;	// -S Bit Swap (little vs. big endian)
	char		*address = NULL;// Adressangaben /dev/ttyUSB0 oder 1.2.3.4
	int		c = 0;		// GetOpt Rückgabewert
	
	opterr = 0;

	while ((c = getopt(argc, argv, "ShtrR:l:i:A:")) != -1)
			switch(c) {
				case 't':
					tflag = 1;
					break;
				case 'r':
					rflag = 1;
					break;
				case 'R':
					mod_reg = atoi(optarg);
					break;
				case 'l':
					laenge = atoi(optarg);
					break;
				case 'i':
					id = atoi(optarg);
					break;
				case 'A':
					address = optarg;
					break;
				case 'S':
					swap = 1;
					break;
				case '?':
					if (optopt == 'R')
						print_error_msg(1, optopt);
					else if (optopt == 'A')
						print_error_msg(1, optopt);
					else if (optopt == 'l')
						print_error_msg(1, optopt);	
					else if (optopt == 'i')
						print_error_msg(1, optopt);
					else if (isprint (optopt))
						print_error_msg(2, optopt);
        				else
						print_error_msg(3, optopt);
        				return EXIT_FAILURE;
      				default:
					print_help();
					return EXIT_SUCCESS;
					break;
			}
	if ((tflag == 1) && (rflag == 1)) {
		print_error_msg(4, 0);
		return EXIT_FAILURE;
	}
	else if ((tflag == 0) && (rflag == 0)) {
		print_error_msg(5,0);
		return EXIT_FAILURE;
	}

	if (tflag == 1) 
		if (isValidIpAddress(address)) 
			use_tcp(address, mod_reg, laenge, id, swap);
		else {
			print_error_msg(6, 0);
			return EXIT_FAILURE;
		}
	else if (rflag == 1)
		use_rtu(address, mod_reg, laenge, id, swap);
	return EXIT_SUCCESS;
}
