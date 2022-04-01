#include "DNet.internal.h"

DNet* DNet_client_create(uint32_t in_port, enum DNet_protocol in_protocol) {
	DNet* net = (DNet*)malloc(sizeof(DNet));

	if (in_protocol == DNET_TCP)
		net->_socket = socket(AF_INET, SOCK_STREAM, 0);
	else if (in_protocol == DNET_UDP)
		net->_socket = socket(AF_INET, SOCK_DGRAM, 0);

	if (net->_socket == -1) {
		perror("ERR: SERVER");
		return NULL;
	}

	net->_address.sin_family 	  = AF_INET;
	net->_address.sin_port   	  = htons(in_port);
	net->_address.sin_addr.s_addr = INADDR_ANY;

	int32_t ret = connect(net->_socket, (struct sockaddr*)&net->_address, sizeof(net->_address));
	
	if (ret == -1) {
		perror("ERR: CLIENT");
	}

	return net;
}

DNet* DNet_server_create(uint32_t in_port, enum DNet_protocol in_protocol) {
	DNet* net = (DNet*)malloc(sizeof(DNet));

	if (in_protocol == DNET_TCP)
		net->_socket = socket(AF_INET, SOCK_STREAM, 0);
	else if (in_protocol == DNET_UDP)
		net->_socket = socket(AF_INET, SOCK_DGRAM, 0);

	if (net->_socket == -1) {
		perror("ERR: SERVER");
		return NULL;
	}

	net->_address.sin_family 	  = AF_INET;
	net->_address.sin_port   	  = htons(in_port);
	net->_address.sin_addr.s_addr = INADDR_ANY;

	int32_t ret = bind(net->_socket, (struct sockaddr*)&net->_address, sizeof(net->_address));

	if (ret == -1) {
		perror("ERR: SERVER");
		return NULL;
	}

	listen(net->_socket, 25);

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
