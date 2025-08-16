CC = gcc
CFLAGS = -Wall -g

# Compilar o teste de Stream
teste_stream: main/teste_stream.c arvoreBB/stream_BB.c arvoreBB/bst_utils.c
	$(CC) $(CFLAGS) -o teste_stream main/teste_stream.c arvoreBB/stream_BB.c arvoreBB/bst_utils.c

clean:
	rm -f teste_stream