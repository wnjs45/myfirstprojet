#include<stdio.h>
#include<wiringPi.h>
#include"text.h"
#include<softPwm.h>
#define p 25
int main(){
	wiringPiSetup();
	pinMode(p,OUTPUT);
	softPwmCreate(p,0,200);
	int c;
	softPwmWrite(p,100);
	while(1){
		c=getch();
		if(c=='a') softPwmWrite(p,24);
		else if(c=='w') softPwmWrite(p,15);
		else if(c=='d') softPwmWrite(p,5);
		delay(100);
		c=0;
	}

	return 0;
}
