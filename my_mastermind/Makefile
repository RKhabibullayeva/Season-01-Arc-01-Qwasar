CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
SOURCE = my_mastermind.c
TARGET = my_mastermind

$(TARGET):$(SOURCE)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: fclean

fclean:
	@rm -r $(TARGET)
