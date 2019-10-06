#include<stdio.h>
#include<wiringPi.h>
#define SW 4
void one();
void two();
void three();
int main(void){
	int i,a,b,c;
	int cnt=0;
	wiringPiSetup();
	int arr[10][5]={
		{0,0,0,0},//0
		{1,0,0,0},//1
		{0,1,0,0},//2
		{1,1,0,0},//3
		{0,0,1,0},//4
		{1,0,1,0},//5
		{0,1,1,0},//6
		{1,1,1,0},//7
		{0,0,0,1},//8
		{1,0,0,1}}//9
	;

	for(i=0;i<5;i++){
		pinMode(i,OUTPUT);
	}
	pinMode(SW,INPUT);
	for(i=0;i<4;i++){
		digitalWrite(i,0);
	}
	while(1){
		if(digitalRead(SW) == HIGH){
			cnt++;
		}
	
		if(cnt==1){
			digitalWrite(0,1);
			digitalWrite(1,0);
			digitalWrite(2,0);
			digitalWrite(3,0);
		}else if(cnt==2){
			digitalWrite(0,0);
			digitalWrite(1,1);
			digitalWrite(2,0);
			digitalWrite(3,0);
		}else if(cnt==3){
			digitalWrite(0,1);
			digitalWrite(1,1);
			digitalWrite(2,0);
			digitalWrite(3,0);
		}else if(cnt==4){
			digitalWrite(0,0);
			digitalWrite(1,0);
			digitalWrite(2,1);
		}else if(cnt==5){
			digitalWrite(0,1);
		}else if(cnt==6){
			digitalWrite(0,0);
			digitalWrite(1,1);
		}else if(cnt==7){
			digitalWrite(0,1);
		}else if(cnt==8){
			digitalWrite(0,0);
			digitalWrite(1,0);
			digitalWrite(2,0);
			digitalWrite(3,1);
		}else if(cnt==9){
			digitalWrite(0,1);
		}else if(cnt==10){
			digitalWrite(0,0);
			digitalWrite(3,0);
			cnt=0;
		}
		delay(150);
	}
/*
	for(a=0;a<10;a++){
		for(b=0;b<5;b++){
			digitalWrite(b,arr[a][b]);
		}
		delay(500);
	}
*/
	return 0;
}
