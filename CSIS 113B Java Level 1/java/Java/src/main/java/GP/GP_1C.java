/*
 * John Barbonio, 3408, GP #1C
0518876
08/18/2019
CSIS 113B
 */
package GP;

import java.util.Scanner;

/**
 *
 * @author itzdu
 */
public class GP_1C
{
    public static void main(String[]args) 
    {
        Scanner in = new Scanner(System.in);
        
        System.out.println("How many nickels do you have?");
        int nickel = in.nextInt();
        
        int dollar = nickel / 20;
        double change = nickel % 20 * .05; //no need to cast but is probably recommended
        
        System.out.print("You have $");
        System.out.print(dollar + change);

    }
}