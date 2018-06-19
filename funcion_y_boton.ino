int PULSADOR = 2;
int AMARILLO = 7;
int FOCO = 4;
const int pinSensor = 5;
int lectura;
int estado_sensor;
int ROJO = 8;
int estado = LOW;
int contador;
int boton = 0;
int AUTOMATICO = 3;

void setup() {
  //Serial.begin(9600);
  pinMode(PULSADOR, INPUT);
  pinMode(AMARILLO, OUTPUT);
  pinMode(ROJO, OUTPUT);
  pinMode(AUTOMATICO, OUTPUT);
  pinMode(FOCO, OUTPUT);
}
void loop() {
  boton = digitalRead(PULSADOR);
  if (boton == HIGH){
    delay(300);
    conteo1();   
          }
  else {
    contador = 0;
    sensor();  
         
      }      
        }
void modo_manual(){
    delay(300);
    
     boton = digitalRead(PULSADOR);
    if (boton == HIGH){
      delay(300);
    conteo2();   
          }
      do{    
      //digitalWrite(ROJO, HIGH);  
     // delay(200);
      //digitalWrite(ROJO, LOW);
      //delay(200); 
      //digitalWrite(ROJO, HIGH);  
      //delay(200);
      //digitalWrite(ROJO, LOW);
      delay(400); 
      
      boton = digitalRead(PULSADOR);
    if (boton == HIGH){
    conteo3();
    }
    else {
    control_manual();
      
    }
      }while (contador != 2); 
        
      }
void sensor(){
      /*digitalWrite(AUTOMATICO, LOW);
      contador = 0;
      digitalWrite(AMARILLO, HIGH);  
      delay(200);
      digitalWrite(AMARILLO, LOW);
      delay(200); 
      digitalWrite(AMARILLO, HIGH);  
      delay(200);
      digitalWrite(AMARILLO, LOW);
      delay(200); */
      estado_sensor = digitalRead(pinSensor);
    if (estado_sensor == HIGH) {
        digitalWrite(FOCO, HIGH);
        lectura = 0;
        delay(200);
      }
    else {
      lectura = lectura + 1;
    delay(200);
    if (lectura >= 20){
        digitalWrite(FOCO, LOW);
        contador = 0;
        lectura = 0;
      }

      //Serial.print("Lectura:");
      //Serial.println(lectura);
      delay(200);
      
//delay(100);
} 
      loop ();   
      }
void conteo1(){
        delay(300);
        boton = digitalRead(PULSADOR);
        if (boton == HIGH){
          delay(300);
          digitalWrite(AUTOMATICO, HIGH);
         modo_manual(); 
        }

}

void conteo2(){
        //delay(600);
        boton = digitalRead(PULSADOR);
        if (boton == HIGH){
          delay(200);
          contador++;
          digitalWrite(AUTOMATICO, LOW);
         sensor(); 
        }
}

void conteo3(){
        delay(300);
        boton = digitalRead(PULSADOR);
        if (boton == HIGH){
          contador++;
         loop(); 
        }
}

void control_manual() {
  while(digitalRead(PULSADOR)==LOW);
  estado = digitalRead(FOCO);
  digitalWrite(FOCO, !estado);
  while(digitalRead(PULSADOR)==HIGH);
    digitalWrite(ROJO, HIGH);  
      delay(200);
      digitalWrite(ROJO, LOW);
      delay(200);
    modo_manual();

}

