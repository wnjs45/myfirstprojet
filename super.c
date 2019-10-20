#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<wiringPi.h>
#include<softTone.h>
#include"text.h"
#define p 25
int tone[8]={520,587,659,698,784,880,988,1045};
//int tone[8]={330,392,523,659,784,823,911,1023};
int main(){
	int i;
	wiringPiSetup();
	softToneCreate(p);
	int c;
	while(1){
		c=getch();
		if(c=='a') softToneWrite(p,tone[0]);
		else if(c=='s') softToneWrite(p,tone[1]);
		else if(c=='d') softToneWrite(p,tone[2]);
		else if(c=='f') softToneWrite(p,tone[3]);
		else if(c=='j') softToneWrite(p,tone[4]);
		else if(c=='k') softToneWrite(p,tone[5]);
		else if(c=='l') softToneWrite(p,tone[6]);
		else if(c==';') softToneWrite(p,tone[7]);
		delay(90);
		softToneWrite(p,0);
		c=0;
	}
	return 0;
}
