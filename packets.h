#ifndef _PACKETS_H
#define _PACKETS_H

#define MAX_NAME_SIZE 10

enum {
   QUERY_BROADCAST,
   QUERY_UNICAST,
   HELLO_RESPONSE,
   CHAT,
   CHAT_ACK,
   EXITING,
} EN_PACKET;
void to_struct_chat(void *str_addrs);
void to_struct_dis_brd(void *str_addrs);
void to_struct_dis_uni(void *str_addrs);
void to_struct_response(void *str_addrs);
void to_struct_chat_ACK(void *str_addrs);
void to_struct_exiting(void *str_addrs);
void tx(void *str_addrs);
static char size_of_struct(char type);

struct discovery_broadcast
{
	char Type;
	char requester_name[MAX_NAME_SIZE];
	char requester_surname[MAX_NAME_SIZE];
}__attribute__((packed));

struct discovery_unicast
{
	char Type;
	char requester_name[MAX_NAME_SIZE];
	char requester_surname[MAX_NAME_SIZE];
	char target_name[MAX_NAME_SIZE];
	char target_surname[MAX_NAME_SIZE];
}__attribute__((packed));

struct hello_response
{
	char Type;
	char responder_name[MAX_NAME_SIZE];
	char responder_surname[MAX_NAME_SIZE];
	char queryier_name[MAX_NAME_SIZE];
	char queryier_surname[MAX_NAME_SIZE];
}__attribute__((packed));

struct chat
{
	char Type;
	short int length;
	char packet_id;
	char message[25];
}__attribute__((packed));

struct chat_ACK
{
	char Type;
	char packet_id;
}__attribute__((packed));

struct exiting
{
	char Type;
	char name[MAX_NAME_SIZE];
	char surname[MAX_NAME_SIZE];
}__attribute__((packed));
#endif
