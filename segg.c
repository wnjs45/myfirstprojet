#include <stdio.h>
#include <wiringPi.h>
#define SW 0
int main(void) {
    int i, a, b;
    int cnt = 0;
    int sevenseg [10][7] = {{0, 0, 0, 0, 0, 0, 1}, // 0
                {1, 0, 0, 1, 1, 1, 1}, // 1
                {0, 0, 1, 0, 0, 1, 0}, // 2
                {0, 0, 0, 0, 1, 1, 0}, // 3
                {1, 0, 0, 1, 1, 0, 0}, // 4
                {0, 1, 0, 0, 1, 0, 0}, // 5
                {0, 1, 0, 0, 0, 0, 0}, // 6
                {0, 0, 0, 1, 1, 1, 1}, // 7
                {0, 0, 0, 0, 0, 0, 0}, // 8
                {0, 0, 0, 0, 1, 0, 0} // 9
                };
    wiringPiSetup();
    pinMode(SW, INPUT);
    for(i = 0; i < 8; i++){	// wiringPi의 핀번호
        pinMode(i, OUTPUT);
    }

    for(b=0;b<7;b++){
	    digitalWrite(b,sevenseg [5][b]);
    }
	delay(1000);

    while(1){
	for(b=0;b<7;b++){
		digitalWrite(b,sevenseg [cnt][b]);
	}
	delay(1000);
	if(digitalRead(SW) == LOW){
		cnt++;
		delay(1000);
		}
	if(cnt == 11)
		cnt = 0;
 	}
	
    return 0;
}
