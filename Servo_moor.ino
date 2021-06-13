#include <Servo.h>

Servo motor;
int p =0;
// the setup function runs once when you press reset or power the board
void setup() {
motor.attach(10);
motor.write(180);
}

// the loop function runs over and over again forever
void loop() {
for(p=0;p<180;p++)
{
 motor.write(180);
 delay(10);
}

for(p=0;p<=360;p++)
{
 motor.write(p);
 delay(10);
}

for(p=180;p>=1;p--)
{
 motor.write(p);
 delay(10);
}
}
