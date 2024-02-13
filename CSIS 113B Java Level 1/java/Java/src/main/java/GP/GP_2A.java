/*
John Barbonio, 3408, GP #2A
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

public class GP_2A
{
    public static void main(String[]args) 
    {
        Scanner in = new Scanner(System.in);
        
        System.out.println("Enter two values, this checks if the first number is greater than AND not equal to the second number: ");
        int x = in.nextInt();
        int y = in.nextInt();
        
        boolean truth = x > y && x != y;
        
        if(truth)
        {
            System.out.println("TRUE. " + x + " is greater than and not equal to y " + "(" + y + ")");
        }
        else 
        {
            System.out.println("FALSE. " + x + " is less than or equal to y " + "(" + y + ")");
        }
    }
}
