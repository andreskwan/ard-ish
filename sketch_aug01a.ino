volatile int contador = 0;
int n = contador; 
long T0 = 0;

void setup() {
  Serial.begin(9600);
  attachInterrupt(0,buttonCounter, LOW);
}

void loop() {
  //si cambio imprimir el valor del contador 
  Serial.println("outside ISR before if n:"+ n);
  if (n != contador) {
    Serial.println(millis());
    Serial.println(contador);
    Serial.println(T0);
    Serial.println(millis());
    n = contador;
  }
  Serial.println("outside ISR after if n:"+ n);
}

void buttonCounter(){
  if(millis() > T0 + 2000) {
    contador++;
    T0 = millis(); 
  }
}

