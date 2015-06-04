#include <Adafruit_GFX.h>
#include <Adafruit_ssd1306syp.h>

// Simple Motor Shield sketch
// -----------------------------------
//
// By arduino.cc user "Krodal".
// June 2012
// Open Source / Public Domain
//
// Using Arduino 1.0.1
//
// A simple sketch for the motor shield,
// without using the Adafruit library.
//
// The outputs can be used for DC-motors 
// (either full H-bridge or just On and Off), lights, 
// relays, solenoids, etc.
// But stepper motors can not be used !
// Servo motors can be used with the default Servo library.
//
// A maximum of 4 DC motors can be used with full-bridge,
// or a maximum of 8 normal outputs, or a combination.
// Two servo motors can always be used, they use the +5V 
// of the Arduino board, so the voltage regulator could 
// get hot.
//
// Tested with an Ebay clone with the Arduino Uno.
//
// Parts of the code are from an old Adafruit Motor Shield
// library, which was public domain at that time.
// This code is also public domain
//
// This simplified program is using the normal 
// Arduino library functions as much as possible.
//
// The motors will make a whistling sound, 
// due to the analogWrite() PWM frequency.
// The Adafruit library is specifically designed to avoid
// this, so use the Adafruit library for a better result.
//
//
//
// Connector usage
// ---------------
// The order is different than what you would expect.
// If the Arduino (Uno) board is held with the USB
// connector to the left, the positive (A) side is 
// at the top (north), and the negative (B) side is 
// the bottom (south) for both headers.
//
//   Connector X1:
//     M1 on outside = MOTOR1_A   (+) north
//     M1 on inside  = MOTOR1_B   (-)
//     middle        = GND
//     M2 on inside  = MOTOR2_A   (+)
//     M2 on outside = MOTOR2_B   (-) south
//
//   Connector X2:
//     M3 on outside = MOTOR3_B   (-) south
//     M3 on inside  = MOTOR3_A   (+)
//     middle        = GND
//     M4 on inside  = MOTOR4_B   (-)
//     M4 on outside = MOTOR4_A   (+) north
//
//
//         -------------------------------
//         | -+s                         |
//         | -+s                         |
//    M1 A |                             | M4 A
//    M1 B |                             | M4 B
//    GND  |                             | GND
//    M2 A |                             | M3 A
//    M2 B |                             | M3 B
//         |                       ..... |
//         -------------------------------
//                + - 
//
//
//
// Pin usage with the Motorshield
// ---------------------------------------
// Analog pins: not used at all
//     A0 ... A5 are still available
//     They all can also be used as digital pins.
//     Also I2C (A4=SDA and A5=SCL) can be used.
//     These pins have a breadboard area on the shield.
// Digital pins: used: 3,4,5,6,7,8,9,10,11,12
//     Pin 9 and 10 are only used for the servo motors.
//     Already in use: 0 (RX) and 1 (TX).
//     Unused: 2,13
//     Pin 2 has an soldering hole on the board, 
//           easy to connect a wire.
//     Pin 13 is also connected to the system led.
// I2C is possible, but SPI is not possible since 
// those pins are used.
//


#include <Servo.h>

//Ping pins
#define PINGVCC_1 41
#define PINGTRIG_1 39
#define PINGECHO_1 37
#define PINGGND_1 35
//Ping pins
#define PINGVCC_2 33
#define PINGTRIG_2 31
#define PINGECHO_2 29
#define PINGGND_2 27


// Arduino pins for the shift register
#define MOTORLATCH 12
#define MOTORCLK 4
#define MOTORENABLE 7
#define MOTORDATA 8

// 8-bit bus after the 74HC595 shift register 
// (not Arduino pins)
// These are used to set the direction of the bridge driver.
#define MOTOR1_A 2
#define MOTOR1_B 3
#define MOTOR2_A 1
#define MOTOR2_B 4
#define MOTOR3_A 5
#define MOTOR3_B 7
#define MOTOR4_A 0
#define MOTOR4_B 6

// Arduino pins for the PWM signals.
#define MOTOR1_PWM 11
#define MOTOR2_PWM 3
#define MOTOR3_PWM 6
#define MOTOR4_PWM 5
#define SERVO1_PWM 10
#define SERVO2_PWM 9

// Codes for the motor function.
#define FORWARD 1
#define BACKWARD 2
#define BRAKE 3
#define RELEASE 4
//long randNumber;
//randNumber = random(10, 29);

//oled screen
#define SDA_PIN 25
#define SCL_PIN 23
Adafruit_ssd1306syp display(SDA_PIN,SCL_PIN);

void setup()
{
  Serial.begin(9600);
  Serial.println("Simple Motor Shield sketch");

  // Use the default "Servo" library of Arduino.
  // Attach the pin number to the servo library.
  // This might also set the servo in the middle position.
//  servo_1.attach(SERVO1_PWM);
//  servo_2.attach(SERVO2_PWM);
  speakerSetup();
  playToneInit();
  display.initialize();
  
}


void loop()
{

pingInit();
audioInit();

}

