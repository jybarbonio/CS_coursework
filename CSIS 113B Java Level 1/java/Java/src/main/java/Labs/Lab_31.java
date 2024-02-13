/*
John Barbonio, 3408, Lab 31
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

public class Lab_31
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        
        System.out.println("Enter how many hours you've worked");
        double hours = in.nextDouble();
        double pay;
        
        if (hours >= 0 && hours <= 40)
        {
            pay = 10.50 * hours;
            System.out.println(pay);
        }
        else if (hours > 40)
        {
            pay = ((10.50 * 40) + ((hours - 40) * 15.75));   
            System.out.printf("The amount of overtime (hours over 40) you have is %.2f\n", hours - 40);

            System.out.printf("%.2f hours pays $%.2f.%n", hours, pay);
        }
        else
        {
            System.out.println("Invalid input. Please try again");
        }
    }
}
