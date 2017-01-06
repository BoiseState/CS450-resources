/**
 * PA3whiledots.java
 * 
 * An example for the students to code up in AVR assembly for PA1.
 * The language features are from the PA3 grammar.
 *
 * MMS, 1/19/15
 */

import meggy.Meggy;

class PA3whiledots {

    public static void main(String[] whatever){
        while( Meggy.checkButton(Meggy.Button.A) ) {
            Meggy.setPixel( (byte)2, (byte)(4-3), Meggy.Color.GREEN );
            Meggy.delay( 100 );
            Meggy.setPixel( (byte)2, (byte)(4-3), Meggy.Color.DARK );
            Meggy.delay( 100 );
        }
        
    }
}
