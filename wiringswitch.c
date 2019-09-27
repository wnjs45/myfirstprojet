#include <wiringPi.h>
#include <stdio.h>

#define SW  1      /* GPIO24 */
#define LED 4      /* GPIO12 */
#define LED2 5     // GPIO18
int switchControl()
{
   int i;
   int cnt=0;

   pinMode(SW,  INPUT);                        /* Pin 모드를 입력으로 설정 */
   pinMode(LED, OUTPUT);
   pinMode(LED2, OUTPUT);
	
   
//   for (i = 0; i < 10000000; i++) {
//      if(digitalRead(SW) == LOW) {          /* Push 버튼이 눌러지면(LOW) */
//         digitalWrite(LED, HIGH);	 /* LED 켜기(On) */
//	 digitalWrite(LED2, HIGH);
//        delay(1000); 
//       digitalWrite(LED, LOW);	 /* LED 끄기(Off) */
//	 digitalWrite(LED2, LOW);
//      }
	
   while(20142355){
	   if(digitalRead(SW) ==LOW){
		   cnt++;
	   }

	   if(cnt%2==1){
		   digitalWrite(LED,LOW);
		   digitalWrite(LED2,HIGH);
	   }else if(cnt%2==0){
		   digitalWrite(LED,HIGH);
		   digitalWrite(LED2,LOW);
	   }

	
	
   };

   return 0 ;
}

int main(int argc, char** argv)
{
   wiringPiSetup();

   switchControl();                             /* 스위치 사용을 위한 함수 */
   return 0 ;
}

