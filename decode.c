#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "packets.h"

static uint8_t bcast[] = {0x00, 0x6b, 0x69, 0x76, 0x61, 0x6e, 0x63, 0x00, 0x00,
    0x00, 0x00, 0x63, 0x61, 0x6b, 0x6d, 0x61, 0x6b, 0x00, 0x00, 0x00, 0x00};

static uint8_t ucast[] = {0x01, 0x6b, 0x69, 0x76, 0x61, 0x6e, 0x63, 0x00, 0x00,
    0x00, 0x00, 0x63, 0x61, 0x6b, 0x6d, 0x61, 0x6b, 0x00, 0x00, 0x00, 0x00,
    0x64, 0x65, 0x76, 0x69, 0x6e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6d, 0x75,
    0x6e, 0x67, 0x61, 0x6e, 0x00, 0x00, 0x00, 0x00};

static void decode_ucast();

static void decode_bcast();

int main(void)
{
    uint8_t *type;

    type = &bcast[0];
    if (*type == QUERY_BROADCAST) {
        decode_bcast();
    }

    fprintf(stdout, "\n\n");

    type = &ucast[0];
    if (*type == QUERY_UNICAST) {
        decode_ucast();
    }

    return 0;
}

static void decode_bcast()
{
    struct query_bcast *q;
    q = (struct query_bcast*) bcast;

    fprintf(stdout, "* decoding broadcast query *\n");
    fprintf(stdout, "q->type: %d\n", q->type);

    fprintf(stdout, "q->name: %s\n", q->name);
    fprintf(stdout, "q->surname: %s\n", q->surname);
}

static void decode_ucast()
{
    struct query_ucast *q;
    q = (struct query_ucast*) ucast;

    fprintf(stdout, "* decoding unicast query *\n");
    fprintf(stdout, "q->type: %d\n", q->type);

    fprintf(stdout, "q->name: %s\n", q->name);
    fprintf(stdout, "q->surname: %s\n", q->surname);

    fprintf(stdout, "q->target_name: %s\n", q->target_name);
    fprintf(stdout, "q->target_surname: %s\n", q->target_surname);
}
