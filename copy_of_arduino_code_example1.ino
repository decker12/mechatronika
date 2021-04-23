// Assign constants
const int switchPosition1 = 2;
const int switchPosition2 = 3;
const int led1 = 4;
const int led2 = 5;
const int potPosition = A0;

void setup() { 
	// Assign the pin types (INPUT or OUTPUT)
	pinMode(switchPosition1, INPUT);
	pinMode(switchPosition2, INPUT);
	pinMode(led1, OUTPUT);
	pinMode(led2, OUTPUT);
  	pinMode(potPosition, INPUT);
	Serial.begin(9600);
}

void loop() {
	int positionOneActive = digitalRead(switchPosition1);
	int positionTwoActive = digitalRead(switchPosition2);

	// Respond to active position
	if (positionOneActive == HIGH){
		digitalWrite(led1, HIGH);
	} 
	if (positionOneActive == LOW){
		digitalWrite(led1, LOW);
	} 
	if (positionTwoActive == HIGH){
		digitalWrite(led2, HIGH);
	}
	if (positionTwoActive == LOW){
		digitalWrite(led2, LOW);
	}
  
  //Read the value and print to Serial
	int currentPotValue = analogRead(potPosition);
	int mappedPotValue = map(currentPotValue, 0, 1023, 0, 50);
	Serial.print("Pot Value (original): ");
	Serial.println(currentPotValue);

	Serial.print("Pot Value (new): ");
	Serial.println(mappedPotValue);
  
  delay(700);
}