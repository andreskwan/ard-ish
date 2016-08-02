volatile int contador = 0;
int n = contador; 

void setup() {
  Serial.begin(9600);
  attachInterrupt(0,buttonCounter, FALLING);
}

void loop() {
  //si cambio imprimir el valor del contador 
  if (n != contador) {
    Serial.println(contador);
    n = contador;
  }
}

void buttonCounter(){
  contador++;
}

