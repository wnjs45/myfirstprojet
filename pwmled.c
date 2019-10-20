#include<stdio.h>
#include<wiringPi.h>
#include<softPwm.h>
#include"text.h"
#define R 25
#define G 5
#define B 4
int main(void){
	wiringPiSetup();
	int i,j,k;
	pinMode(R,OUTPUT);
	pinMode(G, OUTPUT);
	pinMode(B, OUTPUT);
	softPwmCreate(R,0,255);
	softPwmCreate(G,0,255);
	softPwmCreate(B,0,255);
	j=0;
	while(1){
		k=100;
		for(i=0;i<100;i++){
			softPwmWrite(R,i);
			softPwmWrite(G,j);
			softPwmWrite(B,k);
			delay(10);
			k--;
		}
		j=0;k=0;
		for(i=100;i>0;i--){
			softPwmWrite(B,k);
			softPwmWrite(G,j);
			softPwmWrite(R,i);
			delay(10);
			j++;
			
		}
		i=0;
		for(j=100;j>0;j--){
			softPwmWrite(R,i);
			softPwmWrite(G,j);
			softPwmWrite(B,k);
			delay(10);
			k++;
		}

	}
	return 0;
}
