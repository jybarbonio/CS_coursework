/*
John Barbonio, 3408, Lab 21 Variables and Shortcut Operators
0518876
08/18/2019
CSIS 113B
 */
package Labs;

/**
 *
 * @author itzdu
 */
import java.util.Scanner;

public class Lab_21
{
    public static void main(String[]args) 
    {
        Scanner in = new Scanner(System.in);
        
        System.out.println("Inpute a byte: ");
        byte myByte = in.nextByte();
        System.out.println("Inpute a short: ");
        short myShort = in.nextShort();
        System.out.println("Inpute a float: ");
        float myFloat = in.nextFloat();
        
        System.out.print("\nBefore: " + myByte);
        System.out.println(" After: " + (++myByte));
        
        System.out.print("Before: " + myShort);
        System.out.println(" After: " + (myShort * 2));
        
        System.out.print("Before: " + myFloat);
        System.out.println(" After: " + (--myFloat));
        
    }
}
