#include <arpa/inet.h>
#include <linux/if_packet.h>
#include <linux/ip.h>
#include <linux/udp.h>
#include <stdio.h>
#include <unistd.h>

#include <string.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <net/if.h>
#include <netinet/ether.h>
#include "packets.h"
struct discovery_broadcast bune;
int main()
{
	struct discovery_broadcast deneme;
	memset(&deneme, 0, sizeof(struct discovery_broadcast));

	deneme.Type=0;
	snprintf(deneme.requester_name,10,"%s","kivanc");
	snprintf(deneme.requester_surname,10,"%s","kivanc");
	while(1){
	tx((void *) &deneme);
	sleep(3);
}
}