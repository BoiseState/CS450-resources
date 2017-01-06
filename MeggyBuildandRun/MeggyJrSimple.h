/*
  MeggyJrSimple.h - Meggy Jr RGB library for Arduino
   The Meggy Jr Simplified Library (MJSL)
   
  Version 1.4 - 4/17/2010       http://www.evilmadscientist.com/
  Copyright (c) 2010 Windell H. Oskay.  All right reserved.

    This library is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this library.  If not, see <http://www.gnu.org/licenses/>.
	  
*/
/*
 * MMS, 1/23/11, put most of functionality in MeggyJrSimple.cpp
 * to enable simpler code gen for MeggyJava.
 */

#ifndef MeggyJrSimple_h
#define MeggyJrSimple_h
 
#include <MeggyJr.h>
#include <stdlib.h> // for malloc

extern byte Button_A;		 
extern byte Button_B;
extern byte Button_Up;
extern byte Button_Down;
extern byte Button_Left;
extern byte Button_Right;


#define MeggyCursorColor   15,15,15				// You can define color constants like this.

// Assign those colors names that we can use:
enum colors {
  Dark, Red, Orange, Yellow, Green, Blue, Violet, White, 
  DimRed,DimOrange,DimYellow,DimGreen,DimAqua,DimBlue,DimViolet,FullOn,
    CustomColor0, CustomColor1, CustomColor2, CustomColor3, CustomColor4,  
	CustomColor5, CustomColor6, CustomColor7, CustomColor8, CustomColor9
	};     

  
void CheckButtonsDown();
 
void CheckButtonsPress();
 
// Write a byte to the Auxiliary LED set at the top of the LED matrix display.  
void SetAuxLEDs(byte InputLEDs);
 

// Write a byte to the Auxiliary LED set at the top of the LED matrix display.  
// This version reverses bit order, so you can call it with an explicit binary number
void SetAuxLEDsBinary(byte n);


// Simple function to color in a pixel at position (x,y,color):
void DrawPx(byte xin, byte yin, byte color);

// Same as above, except checks to see if pixel is onscreen
// This function is new as of v 1.4
void SafeDrawPx(byte xin, byte yin, byte color);

// function to read color of pixel at position (x,y):
byte ReadPx(byte xin, byte yin);

//Empty the Game Slate:
void ClearSlate(void);

// DisplaySlate() :: Write the Game Slate to the Display Memory it.
// This function looks up each color number (name) stored in the Game Slate,
// retreives its R,G,B components from the color table, and writes them to the
// R,G,B parts of the display memory.

void DisplaySlate (void);

#endif
  
 
  // Pre-defined sound divisors:
 
#define ToneB2		64783 

#define ToneC3		61157	
#define ToneCs3		57724
#define ToneD3		54485	
#define ToneDs3		51427
#define ToneE3		48541	
#define ToneF3		45816	
#define ToneFs3		43243
#define ToneG3		40816	
#define ToneGs3		38526
#define ToneA3		36363
#define ToneAs3		34323
#define ToneB3		32397
 
#define ToneC4		30578
#define ToneCs4		28862
#define ToneD4		27242
#define ToneDs4		25713
#define ToneE4		24270
#define ToneF4		22908
#define ToneFs4		21622
#define ToneG4		20408
#define ToneGs4		19263
#define ToneA4		18182 
#define ToneAs4		17161
#define ToneB4		16198 

#define ToneC5		15289
#define ToneCs5		14431
#define ToneD5		13626
#define ToneDs5		12857
#define ToneE5		12135
#define ToneF5		11454
#define ToneFs5		10811
#define ToneG5		10204
#define ToneGs5		9631
#define ToneA5		9091 
#define ToneAs5		8581
#define ToneB5		8099 

#define ToneC6		7645
#define ToneCs6		7215
#define ToneD6		6810
#define ToneDs6		6428
#define ToneE6		6067
#define ToneF6		5727
#define ToneFs6		5405
#define ToneG6		5102
#define ToneGs6		4816
#define ToneA6		4545 
#define ToneAs6		4290
#define ToneB6		4050 

#define ToneC7		3822
#define ToneCs7		3608
#define ToneD7		3406
#define ToneDs7		3214
#define ToneE7		3034
#define ToneF7		2863
#define ToneFs7		2703
#define ToneG7		2551
#define ToneGs7		2408
#define ToneA7		2273 
#define ToneAs7		2145
#define ToneB7		2025 

#define ToneC8		1911
#define ToneCs8		1804
#define ToneD8		1703
#define ToneDs8		1607
#define ToneE8		1517
#define ToneF8		1432
#define ToneFs8		1351
#define ToneG8		1276
#define ToneGs8		1204
#define ToneA8		1136 
#define ToneAs8		1073
#define ToneB8		1012 

#define ToneC9		956
#define ToneCs9		902
#define ToneD9		851
#define ToneDs9		803

  /*
 Sound output:
 
 Frequency is given by the following formula:
 
 f= 8 MHz/divisor, so divisor = 8 MHz/f.   (Round to nearest.)
 Maximum divisor: 65535, so min. frequency is 122 Hz
 
 Example: for 440 Hz, divisor = 18182
  
 */
  
   // "Cheater" functions
 #define SoundOn()    Meg.SoundState(1)
 #define SoundOff()   Meg.SoundState(0) 
 #define MakingSound  (TCCR1B > 0)		
   
 
 
 
 // other sound functions:
void Tone_Start(unsigned int divisor, unsigned int duration_ms);

#define Tone_Update(); {}			// For backwards compatibility.

/*
  // Stop the note if its completion time has come.
void Tone_Update(void)
{
 // Obsolete with current version of library; sounds stop automatically.
 // please remove this function from your program if it is there.
}
*/


void EditColor(byte WhichColor, byte RedComponent, byte GreenComponent, byte BlueComponent);

void MeggyJrSimpleSetup(void);
 
  
void delay_ms(unsigned int time);

byte GetButtons();
