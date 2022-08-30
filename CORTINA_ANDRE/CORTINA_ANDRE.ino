const int PASSO = 11;
const int LADO =  10;
const int STATS = 13;
static const int DMX =  4;// PORTA QUE SERA USADA PARA ENTRADA DO SINAL DMX
static const int LUZ = 5;// PORTA PARA USAR SE ACABAR A LUZ E PRECISSAR VOLTAR
//=====//

int MEMORIA = 0;
//==//
int TEMPO;
float FINAL;
//==================================================================

void setup() {
  FINAL = 200;// QUANTOS PASSOS NESSESITA DAR PARA CHEGAR AO FINAL
  TEMPO = 250;// TEMPO DE DELAY A CADA PASSO
  //==============//
  pinMode(DMX, INPUT_PULLUP);
  pinMode(LUZ, INPUT_PULLUP);
  //=============//
  pinMode(PASSO, OUTPUT);
  pinMode(LADO, OUTPUT);
  pinMode(STATS, OUTPUT);
  //==============//
  digitalWrite(LADO, HIGH);
  //==============//
  //Serial.begin(9600);
}
//============================================================//
void loop() {

  int ESTADO = digitalRead(DMX);
//  int LUS = digitalRead(LUZ);
//  if (LUS == HIGH)
//  {
//    digitalWrite(LADO, HIGH);
//    for (int VOLTAR = 500 ; VOLTAR >= 0; VOLTAR--) {
//      //=============//
//      digitalWrite(PASSO, HIGH);
//      delayMicroseconds(TEMPO);
//      digitalWrite(PASSO, LOW);
//      delayMicroseconds(TEMPO);
//      //=============//
//      //delay (2000);
//    }//for
//    delay (2000);
//  }
  if (ESTADO == HIGH)
  {
    MEMORIA = MEMORIA + 1;
    if (MEMORIA == 1)
    {
      digitalWrite(STATS, HIGH);
      digitalWrite(LADO, LOW);
      for (float STEP = FINAL ; STEP >= 0; STEP--) {
        //=============//
        digitalWrite(PASSO, HIGH);
        delayMicroseconds(TEMPO);
        digitalWrite(PASSO, LOW);
        delayMicroseconds(TEMPO);
        //Serial.print("FASE 1 COMPLETA");//aa
        //=============//
        //delay (2000);
      }//for
    }
    digitalWrite(STATS, LOW);
    delay (2000);
    if (MEMORIA == 2)
    {
      digitalWrite(STATS, HIGH);
      digitalWrite(LADO, HIGH);
      for (float STEP = 0 ; STEP <= FINAL; STEP++) {
        //=============//
        digitalWrite(PASSO, HIGH);
        delayMicroseconds(TEMPO);
        digitalWrite(PASSO , LOW);
        delayMicroseconds(TEMPO);
        //Serial.print("FASE 222222 COMPLETA");//aa
        //============//}
        //delay(2000);
      }//for
      MEMORIA = 0;
    }//if memoria = 2
  }//if
}//LOOP
