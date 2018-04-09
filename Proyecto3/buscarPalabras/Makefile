all: Servidor Cliente
Servidor: servidor.cpp SocketMulticast.o SocketDatagrama.o  Archivo.o
	g++ servidor.cpp SocketDatagrama.o SocketMulticast.o PaqueteDatagrama.o Archivo.o  -o servidor 
Cliente: cliente.cpp SocketMulticast.o SocketDatagrama.o
	g++ cliente.cpp SocketDatagrama.o SocketMulticast.o PaqueteDatagrama.o -o cliente -lpthread
SocketMulticast.o: SocketMulticast.cpp SocketMulticast.h PaqueteDatagrama.o
	g++ SocketMulticast.cpp -c
SocketDatagrama.o: SocketDatagrama.cpp SocketDatagrama.h PaqueteDatagrama.o
	g++ SocketDatagrama.cpp -c
PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c
Archivo.o: Archivo.cpp Archivo.h
	g++ Archivo.cpp -c
clean:
	rm *.o
	rm Cliente
	rm Servidor