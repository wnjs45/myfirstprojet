#include<stdio.h>
#include<wiringPi.h>
#define SW 1
#define LED1 4
#define LED2 5
int main(){
	wiringPiSetup();
	
	int i;
	int exit=1;
	int sww=3;
	pinMode(SW, INPUT);
	pinMode(LED1, OUTPUT);
	pinMode(LED2, OUTPUT);
	

	while(exit){
		if(digitalRead(SW) == LOW){
			sww++;
		}
		if(sww == 0){
		       	digitalWrite(LED1, HIGH);
		}else if(sww == 1){
			digitalWrite(LED1, LOW);
			digitalWrite(LED2, HIGH);
		}else if(sww == 2){
			digitalWrite(LED1, HIGH);
		}else if(sww == 3){
			digitalWrite(LED1, LOW);
			digitalWrite(LED2, LOW);
		}else if(sww ==4){
			sww = 0;
		}	
	}

	return 0;
}

	


