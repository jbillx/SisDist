#define MAX_WORD	25
#define MAX_BOOK	100

#define BROADCAST	1
#define	BUSQUEDA	2

#define	TERMINA		3
#define LIBRO_INV	4

struct messageCS
{
	char palabra[MAX_WORD];
	uint32_t num_libro;
	uint32_t solicitud;	
	// struct timeval timestamp;
};

struct messageSC
{
	uint32_t num_libro;
	char libro[MAX_BOOK];
	uint32_t offset;
	uint32_t error;
	// struct timeval timestamp;
};