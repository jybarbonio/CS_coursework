/*
John Barbonio, 3408, GP #2C
0518876
08/23/2019
CSIS 113B
 */
package GP;

/**
 *
 * @author itzdu
 */
import java.util.Scanner;

public class GP_2C
{
    public static void main(String[]args) 
    {
        Scanner in = new Scanner(System.in);
        
        System.out.println("Enter a value ");
        int x = in.nextInt();
        System.out.println("Enter another value ");
        int y = in.nextInt();
        
        System.out.println("Enter an operation ");
        System.out.println("1. Add");
        System.out.println("2. Subtract");
        System.out.println("3. Multiply");
        System.out.println("4. Divide");
        System.out.println("5. Modulus");
        
        int choice = in.nextInt();
        switch(choice) 
        {
            case 1:
                System.out.println("The sum is " + (x + y));
                break;
            case 2:
                System.out.println("The difference is " + (x - y));
                break;
            case 3:
                System.out.println("The product is " + (x * y));
                break;
            case 4:
                System.out.println("The quotient is " + (x / y) + " r " + (x % y));
                break;
            case 5:
                System.out.println("The modulus is " + (x % y));
                break;
            default:
                System.out.println("Invalid Operation");
                //break; break unnecessary in this use case
        }
    }
}
