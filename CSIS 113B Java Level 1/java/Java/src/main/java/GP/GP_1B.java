/*
 * John Barbonio, 3408, GP #1B
0518876
08/18/2019
CSIS 113B
 */
package GP;

/**
 *
 * @author itzdu
 */
import java.util.Scanner;

public class GP_1B
{
    public static void main(String[]args) 
    {
        Scanner in = new Scanner(System.in);
        int num1, num2;
        
        System.out.println("Enter two values: ");
        num1 = in.nextInt();
        num2 = in.nextInt();
        
        //int ans = num1 + num2;
        
        System.out.println("The sum is: " + (num1 + num2));
        System.out.println("The difference is: " + (num1 - num2));
        System.out.println("The product is: " + (num1 * num2));
        System.out.println("The quotient (with remainder) is: " + (num1 / num2) + " r " + (num1 % num2));
        System.out.println("The modulus is: " + (num1 % num2));
    }
}
