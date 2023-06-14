all: keygen enc_client enc_server dec_client dec_server

keygen: keygen.c
	gcc -std=gnu99 -o keygen keygen.c
enc_client: enc_client.c
	gcc -std=gnu99 -o enc_client enc_client.c
enc_server: enc_server.c
	gcc -std=gnu99 -pthread -o enc_server enc_server.c
dec_client: dec_client.c
	gcc -std=gnu99 -o dec_client dec_client.c
dec_server: dec_server.c
	gcc -std=gnu99 -pthread -o dec_server dec_server.c