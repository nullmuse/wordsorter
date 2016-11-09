CFLAGS = -Wall -Werror
OBJS = wmain.o help.o 


all: ws

ws: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o ws

 
