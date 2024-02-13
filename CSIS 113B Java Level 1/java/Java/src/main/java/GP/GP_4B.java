/*
John Barbonio, 3408, GP #4B
0518876
9/5/2019
CSIS 113B
 */
package GP;

import java.util.Scanner;

/**
 *
 * @author itzdu
 */
public class GP_4B
{
    Scanner in = new Scanner(System.in);
    
    public int getValue()   //return type is int, because it returns an int
    {
        System.out.println("Enter a number.");
        int val;
        val = in.nextInt();
        return val;
    }
    public int getEvenValue()
    {
        int even_val = 1;       //zero is an even number therefore it cannot be excluded, set to one to invalidate the if statement
        System.out.println("Now enter an even number.");
        
        while(even_val % 2 != 0)
        {
            in.nextLine();  //a sort of buffer clear?
            even_val = in.nextInt();
                    
            if(even_val % 2 != 0) 
            {
                System.out.println("Invalid Input. Please enter an even number.");
            }
        }
        return even_val;
    }
    
    public static void main(String[]args) 
    {
        GP_4B c = new GP_4B();
        int num = c.getValue();
        System.out.println("The value you entered is " + num);  //num being from getValue()
    
        int num2 = c.getEvenValue();
        System.out.println("The even value you entered is " + num2);    //num2 being the even value from getEvenValue()
    }
}
