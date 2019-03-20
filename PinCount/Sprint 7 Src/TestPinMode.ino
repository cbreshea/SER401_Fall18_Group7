
/*

This is originally a TestPinMode.txt and now it is an .ino file
so that it now follows arduino file naming conventions. 
We are talking about pinMode
pinMode should not be counted 
Here so the only pinMode that 
should be counted are the two are below
*/

void setup(){
pinMode = (11,OUTPUT)

pinMode = (13,OUTPUT)
}
void loop(){
digitalWrite(11, HIGH);
delay(1000);
digitalWrite(13, HIGH);
delay(1000);
digitalWrite(11, LOW);
delay(1000);
digitalWrite(13, LOW);
delay(1000);

// End of the file
