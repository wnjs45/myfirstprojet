#include<stdio.h>
#include<termios.h>
#include<unistd.h>
#include<wiringPi.h>
#define p 18
int tones[8]={261,294,330,349,392,440,494,523};
//do,re,mi,pa,sol,ra,si,do#

int getch(void){
		struct termios oldt,newt;
		int ch;
		tcgetattr(STDIN_FILENO,&oldt);
		newt = oldt;
		newt.c_lflag&=~(ICANON|ECHO);
		tcsetattr(STDIN_FILENO, TCSANOW,&newt);
		ch = getchar();
		tcsetattr(STDIN_FILENO, TCSANOW,&oldt);
		return ch;
}

int main(){
		if(-1==wiringPiSetup()){
				printf("setup failed!\n");
				return 1;
		}
		pinMode(p,OUTPUT);
		int c;
		while(1){
				c=getch();
				if(c=='a') tone(p,tones[0]);
				else if(c=='s') tone(p, tones[1]);
				else if(c=='d') tone(p, tones[2]);
				else if(c=='f') tone(p, tones[3]);
				else if(c=='j') tone(p, tones[4]);
				else if(c=='k') tone(p, tones[5]);
				else if(c=='l') tone(p, tones[6]);
				else if(c==';') tone(p, tones[7]);
				else if(c=='q') break;
				delay(500);
				c=0;
		}

		return 0;
}
