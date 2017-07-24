#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "packets.h"

#define MY_NAME "kivanc"
#define MY_SURNAME "cakmak"

#define TARGET_NAME "devin"
#define TARGET_SURNAME "mungan"

static void fill_query_bcast(struct query_bcast *q);

static void fill_query_ucast(struct query_ucast *q);

static void hex_print(void *pack, size_t len);

int main(void)
{
    struct query_bcast query_bcast;
    struct query_ucast query_ucast;

    memset(&query_bcast, 0, sizeof(struct query_bcast));
    memset(&query_ucast, 0, sizeof(struct query_ucast));

    fill_query_bcast(&query_bcast);
    hex_print((void *) &query_bcast, sizeof(struct query_bcast));

    fill_query_ucast(&query_ucast);
    hex_print((void *) &query_ucast, sizeof(struct query_ucast));

    return 0;
}

/**
 * @brief 
 *
 * @param[out] q
 */
static void fill_query_bcast(struct query_bcast *q)
{
    q->type = QUERY_BROADCAST;
    snprintf(q->name, MAX_NAME_SIZE, "%s", MY_NAME);
    snprintf(q->surname, MAX_NAME_SIZE, "%s", MY_SURNAME);
}

/**
 * @brief 
 *
 * @param[out] q
 */
static void fill_query_ucast(struct query_ucast *q)
{
    q->type = QUERY_UNICAST;
    snprintf(q->name, MAX_NAME_SIZE, "%s", MY_NAME);
    snprintf(q->surname, MAX_NAME_SIZE, "%s", MY_SURNAME);
    snprintf(q->target_name, MAX_NAME_SIZE, "%s", TARGET_NAME);
    snprintf(q->target_surname, MAX_NAME_SIZE, "%s", TARGET_SURNAME);
}

/**
 * @brief generic print of struct in hexadecimal
 * format
 *
 * @param[in] pack
 * @param[in] len
 */
static void hex_print(void *pack, size_t len)
{
    int i = 0;
    for (i = 0; i < len; i++) {
        fprintf(stdout, "%02x ", ((uint8_t *) pack)[i]);
    }
    fprintf(stdout, "\n");
}
