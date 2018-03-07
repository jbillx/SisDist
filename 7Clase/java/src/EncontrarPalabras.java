public class EncontrarPalabras {

    public static void main (String args[]){

        String cadenota="";
        int numPalabras = 26*26*26*10;
        int aux =0;
        for(int i = 0 ;i < ( (numPalabras*3) +(numPalabras));i++ ){
            if (aux == 3){
                cadenota+=" ";
                aux=0;
            }else{
                int letra = (int)Math.floor(Math.random()*(90-65)+65);
                cadenota+=(char)letra;
                aux++;
            }
        }
        cadenota+="IPN";

        String palabraEncontrar="IPN";
        String[] part = cadenota.split(" ");
        int encontrados=0;
        for(int i = 0; i < part.length;i++){
            if(palabraEncontrar.equals(part[i])){
                encontrados++;
            }
        }

        //System.out.println("Elementos encontrados :"+ cadenota);

        System.out.println("Coincidencias con "+palabraEncontrar+" = "+encontrados);


    }
}
