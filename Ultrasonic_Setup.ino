#define TRIG_ESQ 3 // Dando o nome "TRIG_ESQ" para o pino 3
#define ECHO_ESQ 2 // Dando o nome "ECHO_ESQ" para o pino 2
#define TRIG_DIR 6 
#define ECHO_DIR 5 
#define BUZZER_DIR 13
#define BUZZER_ESQ 12


int lerDistancia(int pinoTrig, int pinoEcho, String nomeSensor) {
  // Loop que o som vai ser disparado
  digitalWrite(pinoTrig, LOW); 
  delayMicroseconds(2);
  digitalWrite(pinoTrig, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(pinoTrig, LOW);
  // Fim do Loop que dispara.

  // Conta quantos *microssegundos* o ECHO se manteve ligado.
  long duration = pulseIn(pinoEcho, HIGH);
  int distance = duration * 0.034 / 2; 
  
  /* Fórmula da distância convertida em centímetros. Explicação abaixo:

  0.034: Velocidade do som no ar em centímetros por microssegundo.
  2: Divide por dois pq foi a ida e a volta, mas só queremos a ida e não o caminho todo.
  em resumo a formula é: distancia = (tempo * velocidade) / 2
  */

  // IMPRESSÃO DOS RESULTADOS
  Serial.print(nomeSensor);
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm ");
  // Tempo pra ficar legível

  return distance;
}

void emitirSom(int distancia, int pinoBuzzer) {
/* Se a distancia for menor que 1 metro, ele apita. 
 a frequencia do quanto apita é definida pela distancia do objeto */
  
/* A função tone([buzzer], 1000) -> OBS: esse mil é = 1000Hz) essa funcao tone() chega até 65000Hz
 O tempo do buzzer é controlado com delay().
 noTone(buzzer) faz o som parar.*/
  if (distancia < 100 && distancia > 0) { 
    tone(pinoBuzzer, 1000); 
    delay(50);
    noTone(pinoBuzzer);
    delay(distancia * 2);
  } else {
    noTone(pinoBuzzer);
  }
}

void setup() {
  Serial.begin(9600);
  // Trig vai disparar o som do sensor (Output) || // Echo vai lê a info quando o som voltar. (Input)
  // Setup da Esquerda
  pinMode(TRIG_ESQ, OUTPUT); 
  pinMode(ECHO_ESQ, INPUT);  
  // Setup da Direita
  pinMode(TRIG_DIR, OUTPUT);
  pinMode(ECHO_DIR, INPUT);
  // Setup dos Buzzers
  pinMode(BUZZER_DIR, OUTPUT);
  pinMode(BUZZER_ESQ, OUTPUT);
}

void loop() {
  int distanciaEsq = lerDistancia(TRIG_ESQ, ECHO_ESQ, "Esq: ");
  int distanciaDir = lerDistancia(TRIG_DIR, ECHO_DIR, "Dir: ");
  
  emitirSom(distanciaEsq, BUZZER_ESQ);
  emitirSom(distanciaDir, BUZZER_DIR);



}
