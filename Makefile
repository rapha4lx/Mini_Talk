
CLIENT= client.c
SERVER= server.c
AUX_FUNC= aux_func.c

CC= cc
CFLAGS= -Wall -Werror -Wextra

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

all:
	$(CC) $(CFLAGS) $(CLIENT) $(AUX_FUNC) -o client
	$(CC) $(CFLAGS) $(SERVER) $(AUX_FUNC) -o server