/**
 * PA2twodots
 * 
 * Lights up two pixels.
 * 
 * MMS, 2/5/13
 */
import meggy.Meggy;

class PA2twodots {
       public static void main(String[] whatever){
               Meggy.setPixel( (byte)0, (byte)0, Meggy.Color.RED );
               Meggy.setPixel( (byte)7, (byte)7, Meggy.Color.WHITE );
        }
}
