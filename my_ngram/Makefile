CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
COURCES = my_ngram.c
TARGET = my_ngram

$(TARGET):$(COURCES)
	$(CC) $(CFLAGS) -o $@ $^
clean:
	rm -f *.o
fclean: clean
	rm -f $(TARGET)