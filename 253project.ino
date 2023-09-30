#include<ezButton.h>

const int btn1 = 4;
const int btn2 = 22;

int count = 0;
ezButton push_btn1(btn1);
ezButton push_btn2(btn2);


void setup()
{
  Serial.begin(115200);
  push_btn1.setDebounceTime(50);
  push_btn2.setDebounceTime(50);
}

void loop()
{
  push_btn1.loop();
  push_btn2.loop();
  
  if (push_btn1.isPressed())
  {
    count++;
    Serial.print("Number : ");
    Serial.println(count);
  }

  else if (push_btn2.isPressed())
  {
    Serial.print("Table of ");
    Serial.println(count);
    for (int i = 1; i <= 10; i++)
    {
      Serial.print(count);
      Serial.print('*');
      Serial.print(i);
      Serial.print('\t');
      Serial.print('=');
      Serial.print('\t');
      Serial.println(count*i);
    }
    count = 0;
  }
 
}
