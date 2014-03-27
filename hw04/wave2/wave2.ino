/*
  

 Author: Allen Downey 
 
 Based on http://arduino.cc/en/Tutorial/AnalogInput
 Created by David Cuartielles
 modified 30 Aug 2011
 By Tom Igoe

 License: Public Domain
 
 */
 
 
int ledPin = 5;       // select the pin for the LED
int buttonPin1 = 2;
int buttonPin2 = 3;
boolean toggle0 = 0;
boolean toggle1 = 0;
boolean togglebutton=0;

int low = 36;
int high = 255;
int stride = 5;
int counter = low;

void setup() {
  Serial.begin(9600);
  
  pinMode(buttonPin1, INPUT_PULLUP);  
  pinMode(buttonPin2, INPUT_PULLUP);  

  pinMode(ledPin, OUTPUT);
  
  DDRD = B11000000;  // digital pins 7,6,5,4,3,2,1,0
  DDRB = B00111111;  // digital pins -,-,13,12,11,10,9,8
  
  cli();//stop interrupts
  
  //set timer2 interrupt at 8kHz
  TCCR2A = 0;// set entire TCCR2A register to 0
  TCCR2B = 0;// same for TCCR2B
  TCNT2  = 0;//initialize counter value to 0
  // set compare match register for 8khz increments
  OCR2A = 249;// = (16*10^6) / (8000*8) - 1 (must be <256)
  // turn on CTC mode
  TCCR2A |= (1 << WGM21);
  // Set CS21 bit for 8 prescaler
  TCCR2B |= (1 << CS21);   
  // enable timer compare interrupt
  TIMSK2 |= (1 << OCIE2A);
  
  sei();//allow interrupts
  
}

void writeByte(int x) {
  int pin;
  
  for (pin=13; pin>=6; pin--) {
    digitalWrite(pin, x&1);
    x >>= 1;
  }
}

//I found this fn online because I don't like re-inventing the wheel
unsigned int reverseBits(unsigned int num)
{
    unsigned int  NO_OF_BITS = sizeof(num) * 8;
    unsigned int reverse_num = 0;
    int i;
    for (i = 0; i < NO_OF_BITS; i++)
    {
        if((num & (1 << i)))
           reverse_num |= 1 << ((NO_OF_BITS - 1) - i);  
   }
    return reverse_num;
}

  //delayMicroseconds(100);
ISR(TIMER2_COMPA_vect){//timer1 interrupt 8kHz toggles pin 9
//generates pulse wave of frequency 8kHz/2 = 4kHz (takes two cycles for full wave- toggle high then toggle low)
  if (toggle1){
    if(digitalRead(buttonPin1)){
      if(toggleButton){
        toggleButton = 0;
         counter += stride;
        if (counter > high) {
          counter = low;
        }
        writeByteBitwise(counter);
        toggle1 = 0;
      }
    }
  }
    else{
      toggleButton = 1;
    }
    
  }
  else{
    toggle1 = 1;
  }
}

void writeByteBitwise(int x){
  int pin; 
  int xRev;
  
  xRev = reverseBits(x);
  PORTD = xRev>>2 | B00000100;
  PORTB = xRev<<6;
  
}



void loop() {
  //int button1 = digitalRead(buttonPin1);
  //if (button1) return;

  
  //counter += stride;
  //if (counter > high) {
    //counter = low;
    //Serial.println(counter);
  //}

  // write to the digital pins  
  //writeByteBitwise(counter);
  

  
  //delayMicroseconds(10);
  
}
