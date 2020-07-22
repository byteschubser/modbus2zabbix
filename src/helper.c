#include <arpa/inet.h>
#include <stdio.h>
#include <stdbool.h>

void print_error_msg(int err_id, int err_arg) {
	if (err_id == 1)
		fprintf(stderr, "Option -%c requieres an argument.\n", err_arg);
	else if (err_id == 2)
		fprintf(stderr, "Unknown option `-%c'.\n", err_arg);
	else if (err_id == 3)	
         	fprintf(stderr, "Unknown option character `\\x%x'.\n", err_arg);
	else if (err_id == 4)
		fprintf(stderr, "-r (RTU) and -t (TCP) are exclusive and can't be used together.\n");
	else if (err_id == 5)
		fprintf(stderr, "I don't know which comm method I should use. Please specify -r for RTU xor -t for TCP.\n");
	else if (err_id == 6)
		fprintf(stderr, "No valid IP address.\n");
	return;
}

void print_help() {
	fprintf(stdout, "modbus2zabbix V0.1\n");
	fprintf(stdout, "\n");
	fprintf(stdout, "Usage:\n");
	fprintf(stdout, "	modbus2zabbix [[-t | -r] -R <num> -l <num> -i <num> -A <IP|Serial>] | -h]\n");
	fprintf(stdout, "		-t		ModBus via TCP\n");
	fprintf(stdout, "		-r		ModBus vis serial connection (RTU)\n");
	fprintf(stdout, "		-R <num>	Number of the ModBus Register\n");
	fprintf(stdout, "		-l <num>	length of the data; usual 1 or 2\n");
	fprintf(stdout, "		-i <num>	ID of the Modbus Device, usual between 1 and 255\n");
	fprintf(stdout, "		-A <IP|Serial>	targed IP for TCP (-t) or local serial device für RTU (-r)\n");
	fprintf(stdout, "		-h		this help\n");
}	

bool isValidIpAddress(char *ipAddress)
{
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, ipAddress, &(sa.sin_addr));
    return result != 0;
}
