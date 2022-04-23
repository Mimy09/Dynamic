#include "DNet.internal.h"
#include "../Core/DLog.h"
#include <pthread.h>

#define DNet_check(x, m, r) if ((x) == -1) { DPrint_err(m); return r; }

DNet* DNet_client_create(uint32_t in_port, enum DNet_protocol in_protocol) {
	DNet* net = (DNet*)malloc(sizeof(DNet));

	if (in_protocol == DNET_TCP) {
		DNet_check(net->_socket = socket(AF_INET, SOCK_STREAM, 0), "Failed to create TCP socket", NULL);
	}
	else if (in_protocol == DNET_UDP) {
		DNet_check(net->_socket = socket(AF_INET, SOCK_DGRAM, 0), "Failed to create UDP socket", NULL);
	}

	net->_address.sin_family 	  = AF_INET;
	net->_address.sin_port   	  = htons(in_port);
	net->_address.sin_addr.s_addr = INADDR_ANY;

	DNet_check(connect(net->_socket, (struct sockaddr*)&net->_address, sizeof(net->_address)), "Failed to connect to socket!", NULL);


	return net;
}

DNet* DNet_server_create(uint32_t in_port, enum DNet_protocol in_protocol) {
	DNet* net = (DNet*)malloc(sizeof(DNet));

	if (in_protocol == DNET_TCP) { DNet_check(net->_socket = socket(AF_INET, SOCK_STREAM, 0), "Failed to create TCP socket", NULL); }
	else if (in_protocol == DNET_UDP) { DNet_check(net->_socket = socket(AF_INET, SOCK_DGRAM, 0), "Failed to create UDP socket", NULL); }

	net->_address.sin_family 	  = AF_INET;
	net->_address.sin_port   	  = htons(in_port);
	net->_address.sin_addr.s_addr = INADDR_ANY;

	DNet_check(bind(net->_socket, (struct sockaddr*)&net->_address, sizeof(net->_address)), "Failed to bind to socket!", NULL);
	DNet_check(listen(net->_socket, 25), "Failed to listen to socket!", NULL);

	return net;
}

void DNet_free(DNet* in_net) {
	if (in_net != NULL) {
		close(in_net->_socket);
		free(in_net);
	}
}

DNetSocket DNet_socket(DNet* in_net) {
	return in_net->_socket;
}

DNetSocket DNet_server_accept(DNet* in_net) {
	socklen_t address_length = (socklen_t)sizeof((*(struct sockaddr_in*)&in_net->_address));
	return accept(in_net->_socket, (struct sockaddr*)&in_net->_address, &address_length);
}

char* DNet_read(DNetSocket in_socket, char* io_buffer, uint32_t in_size) {
	memset(io_buffer, 0, in_size);
	read(in_socket, io_buffer, in_size);
	return io_buffer;
}

void DNet_write(DNetSocket in_socket, char* in_buffer, uint32_t in_size) {
	write(in_socket, in_buffer, in_size);
}
