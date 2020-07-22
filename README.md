# modbus2zabbix
simple modbus tcp/rtu poller 

## Features
polls modbus via tcp and rtu (serial)

return value can be piped to zabbix sender (xargs)

honours little endian / big endian coding of modbus values


### Steps:
1) git clone https://github.com/byteschubser/modbus2zabbix.git

2) run ./bootstrap.sh

3) run ./configure

4) run make && make install

### Usage:

modbus2zabbix V0.1

Usage:
        modbus2zabbix [[-t | -r] -R <num> -l <num> -i <num> -A <IP|Serial>] | -h]
                -t              ModBus via TCP
                -r              ModBus vis serial connection (RTU)
                -R <num>        Number of the ModBus Register
                -l <num>        length of the data; usual 1 or 2
                -i <num>        ID of the Modbus Device, usual between 1 and 255
                -A <IP|Serial>  targed IP for TCP (-t) or local serial device für RTU (-r)
                -h              this help
		-S		bit swap (little endian / big endian)


Example of polling a SolarLog device via TCP about the current dc voltage and send the value to zabbix

modbus2zabbix -t -A 10.90.1.2 -i 1 -l 1 -R 3507 | xargs zabbix_sender -z 10.70.3.5 -p 10051 -s SolarLog -k solarlog.udc -o

Example of polling a Siemens power meter via RTU about the yield with swapped words

modbus2zabbix -r -A /dev/ttyUSB1 -i 1 -l 2 -R 6697 -S
