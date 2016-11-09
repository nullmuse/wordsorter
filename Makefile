CFLAGS = -Wall -Werror
OBJS = help.o wmain.o 


all: ws

ws: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o ws

 
