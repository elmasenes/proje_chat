CC=gcc

SRC_ENCODE=encode.c
TARGET_ENCODE=encode

SRC_DECODE=decode.c
TARGET_DECODE=decode

CFLAGS += -Wall

default: $(TARGET_ENCODE) $(TARGET_DECODE)

$(TARGET_ENCODE): $(SRC_ENCODE)
	$(CC) $(CFLAGS) $(SRC_ENCODE) -o $(TARGET_ENCODE)

$(TARGET_DECODE): $(SRC_DECODE)
	$(CC) $(CFLAGS) $(SRC_DECODE) -o $(TARGET_DECODE)

clean:
	rm -rf $(TARGET_ENCODE) $(TARGET_DECODE)

