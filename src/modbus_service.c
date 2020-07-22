#include </usr/local/include/modbus/modbus.h>
#include <stdio.h>
#include <errno.h>
#include "definitions.h"


void use_tcp(char *address, int mod_reg, int laenge, int id, int swap) {
	int		rc;
	uint16_t        ui16[4];

	modbus_t *mb = modbus_new_tcp(address, 502);
        modbus_set_slave(mb, id);
        modbus_connect(mb);
        rc = modbus_read_registers(mb, mod_reg, laenge, ui16);
        if (rc == -1)
                fprintf(stderr, "Register Read Status:%s\n", modbus_strerror(errno));
        else if (laenge == 2) {
		if (swap == 0) { 
        		printf("%d\n", (ui16[1] << 16) | ui16[0]);
		}
		else if (swap == 1) {
        		printf("%d\n", (ui16[0] << 16) | ui16[1]);
		}
	}
	else
		printf("%d\n", ui16[0]);
        modbus_close(mb);
        modbus_free(mb);
	return;
}

void use_rtu(char *address, int mod_reg, int laenge, int id, int swap) {
        modbus_t        *mb;
        int             rc;
        uint16_t        ui16[4];

        mb = modbus_new_rtu(address, 9600, 'N', 8, 1);
        modbus_set_slave(mb, id);
        modbus_connect(mb);
        rc = modbus_read_registers(mb, mod_reg, laenge, ui16);
        if (rc == -1) 
                fprintf(stderr, "Register Read Status:%s\n", modbus_strerror(errno));
        else if (laenge == 2)
		if (swap == 0)
			printf("%d\n", (ui16[1] << 16) | ui16[0]);
		else if (swap == 1)
			printf("%d\n", (ui16[0] << 16) | ui16[1]);
	else
        	printf("%d\n", ui16[0]);
        modbus_close(mb);
        modbus_free(mb);
        return;
}

