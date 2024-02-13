/*
John Barbonio, 3408, Lab #72
0518876
9/5/2019
CSIS 113B
 */
package Labs;

import java.util.Scanner;

/**
 *
 * @author itzdu
 */
public class Lab_72
{
    public int sumTheNumbers(int n1, int n2) 
    {
        int low = (n1 < n2) ? n1 : n2;      //basic low/high number filter
        int high = (n1 > n2) ? n1 : n2;
        
        int result = 0;
        
        for(/*low = low?*/; low <= high; low++) 
        {
            //System.out.println(low + ", " + high);
            //System.out.println(result);
            result = result + low;
        }
        /*There is an alternate method of doing this that involves starting with the low number and then adding all numbers immediately
        above it up to the high itself, but I opted for the result starting from zero and adding the low, then everything up to high*/
        return result;
    }
    public static void main(String[]args) 
    {
        Scanner in = new Scanner(System.in);
        System.out.println("Input a number.");
        int num1 = in.nextInt();
        System.out.println("Input another number.");
        int num2 = in.nextInt();
        
        Lab_72 ob = new Lab_72();
        int result = ob.sumTheNumbers(num1, num2);
        System.out.println("The sum of all numbers of range " + num1 + " to " + num2 + " is " + result);
    }
}