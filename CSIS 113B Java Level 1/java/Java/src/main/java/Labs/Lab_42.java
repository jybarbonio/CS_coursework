/*
John Barbonio, 3408, Lab 42
0518876
08/23/2019
CSIS 113B
 */
package Labs;

/**
 *
 * @author itzdu
 */
import java.util.Scanner;

public class Lab_42
{
    public static void main(String[]args) 
    {
        Scanner in = new Scanner(System.in);
        
        System.out.println("Please input a radius");
        double radius = in.nextDouble();
        
        System.out.println("1. Calculate Diameter");
        System.out.println("2. Calculate Circumfrence");
        System.out.println("3. Calculate Area");
        System.out.print("Please Choose (1-3): ");
        
        byte op = in.nextByte();
        
        switch(op) 
        {
            case 1:
                System.out.println(radius * 2);     //unrounded, no printf
                break;
            case 2:
                System.out.println(radius * 2 * Math.PI);
                break;
            case 3:
                System.out.println(radius * radius * Math.PI);
                break;
            default:
                System.out.println("Invalid input. Selection must be between 1 and 3!");
        }
    }
}
