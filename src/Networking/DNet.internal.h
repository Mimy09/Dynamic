#pragma once
#include "DNet.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include "../Container/DArray.h"

struct DNet {
	DNetSocket         _socket;
	struct sockaddr_in _address;
};
