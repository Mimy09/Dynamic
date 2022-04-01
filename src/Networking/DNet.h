#pragma once
#include <stdint.h>

typedef struct DNet DNet;
typedef int32_t DNetSocket;

enum DNet_protocol {
	DNET_TCP, DNET_UDP
};

DNet* DNet_client_create(uint32_t in_port, enum DNet_protocol in_protocol);
DNet* DNet_server_create(uint32_t in_port, enum DNet_protocol in_protocol);
void  DNet_free(DNet* in_net);

DNetSocket DNet_socket(DNet* in_net);
DNetSocket DNet_server_accept(DNet* in_net);
char*      DNet_read(DNetSocket in_socket, char* io_buffer, uint32_t in_size);
void       DNet_write(DNetSocket in_socket, char* in_buffer, uint32_t in_size);
