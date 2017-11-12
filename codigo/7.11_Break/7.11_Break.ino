void setup() {
  // put your setup code here, to run once:

}
int temperatura;
void loop() {

  
  for(int i=0;i<10;i++){
    
    if (temperatura>100) {
      continue; // nos saltamos el resto de esta iteración
      //Instrucciones que nos saltamos
    }else{
       break;  // salimos del bucle
    }
  }



}
