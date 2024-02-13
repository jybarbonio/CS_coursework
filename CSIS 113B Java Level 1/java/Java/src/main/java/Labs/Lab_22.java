/*
John Barbonio, 3408, Lab 22 Simple Math
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

public class Lab_22
{
    public static void main(String[]args) 
    {
        Scanner in = new Scanner(System.in);
        
        final byte FOOT_IN_INCHES = 12;
        
        System.out.println("This program converts feet to inches.");
        System.out.println("Please enter the feet:");
        byte feet = in.nextByte();
        System.out.println("Please enter the inches:");
        byte inch = in.nextByte();
        
        System.out.println(feet + "\' " + inch + "\" " + "is " + ((feet * FOOT_IN_INCHES) + inch) + "\"\n");
        
        System.out.println("This program converts inches to feet");
        System.out.println("Please enter the inches:");
        byte totalInches = in.nextByte();
        
        System.out.println(totalInches + "\" is " + (totalInches / FOOT_IN_INCHES) + "\' " + (totalInches % FOOT_IN_INCHES) + "\"");
    }
}
