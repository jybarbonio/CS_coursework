/*
John Barbonio, 3408, Lab 41
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

public class Lab_41
{
    public static final byte WORK_WEEK = 40;    //we don't need to cast bytes into doubles?
    public static final double HOURLY_RATE = 10.50;
    public static final double OVERTIME_RATE = 15.75;
    
    
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        
        System.out.println("Enter how many hours you've worked");
        double hours = in.nextDouble();
        double pay;

        if (hours >= 0 && hours <= WORK_WEEK)
        {
            pay = HOURLY_RATE * hours;
            System.out.printf("%.2f hours pays $%.2f.%n", hours, pay);
        }
        else if (hours > WORK_WEEK)
        {
            pay = (HOURLY_RATE * WORK_WEEK) + ((hours - WORK_WEEK) * (OVERTIME_RATE)); //could also be just 420 = ... modulus wouln't be correct beyond 80 in second operation
            System.out.printf("%.2f hours pays $%.2f.%n", hours, pay);
        }
        else
        {
            System.out.println("Invalid input. Please try again");
        }
    }
}