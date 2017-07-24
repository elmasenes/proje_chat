#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "packets.h"

void to_struct_chat(void *str_addrs)
{
	struct chat *output;
	
	output=(struct chat *)str_addrs;
	printf("%d ",output->Type);
	printf("%s ",output->message);
	printf("%d\n",output->length);
	}

void to_struct_dis_brd(void *str_addrs)
{
	struct discovery_broadcast *output;
	
	output=(struct discovery_broadcast *)str_addrs;
	printf("%d ",output->Type);
	printf("%s ",output->requester_name);
	printf("%s\n",output->requester_surname);
}
void to_struct_dis_uni(void *str_addrs)
{
	struct discovery_unicast *output;
	
	output=(struct discovery_unicast *)str_addrs;
	printf("%d ",output->Type);
	printf("%s ",output->requester_name);
	printf("%s\n",output->requester_surname);
	printf("%s ",output->target_name);
	printf("%s ",output->target_surname);

}
void to_struct_response(void *str_addrs)
{
	struct hello_response *output;
	
	output=(struct hello_response *)str_addrs;
	printf("%d ",output->Type);
	printf("%s ",output->responder_name);
	printf("%s\n",output->responder_surname);
	printf("%s ",output->queryier_name);
	printf("%s ",output->queryier_surname);

}
void to_struct_chat_ACK(void *str_addrs)
{
	struct chat_ACK *output;
	
	output=(struct chat_ACK *)str_addrs;
	printf("%d ",output->Type);
	printf("%d ",output->packet_id);

}
void to_struct_exiting(void *str_addrs)
{
	struct exiting *output;
	
	output=(struct exiting *)str_addrs;
	printf("%d ",output->Type);
	printf("%s ",output->name);
	printf("%s\n",output->surname);
}
	struct exiting output5;
