#ifndef CSTRINGS_H_
  #define CSTRINGS_H_
    class Cstrings{
      private:
        char *cadenota;
        char *palabra;
        int numeroDePalabras;
        int tamanioPalabra;
      public:
        Cstrings(int sizePalabra);
        void addPalabra(char** cadenota, char **palabra);
        void generarCadenota(int n);
        void imprimirCadenota();
        void liberarMemoria();
        void encuentraCadena(char* cadena);
    };
#endif
