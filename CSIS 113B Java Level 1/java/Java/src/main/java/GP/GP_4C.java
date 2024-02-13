/*
John Barbonio, 3408, GP #4C
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
public class GP_4C
{
    Scanner in = new Scanner(System.in);
    
    public int getValue()   //return type is int, because it returns an int
    {
        System.out.println("Enter a number.");
        int val;
        val = in.nextInt();
        return val;
    }
    public int cubeIt(int cube) //formal paramter
    {
        return (int) Math.pow(cube, (int) 3); //trying out the java.Math stuff
    }
    public int sumIt(int val1, int val2) 
    {
        return val1 + val2;
    }
    
    public static void main(String[]args) 
    {
        GP_4C c = new GP_4C();
        int num1 = c.getValue();
        int num2 = c.getValue();
        System.out.println("The values you entered are " + num1 + ", " + num2);  //num being from getValue()
        
        int sum_result = c.sumIt(num1, num2);
        System.out.println("The sum of your numbers is: " + sum_result);
        
        int cube_result = c.cubeIt(sum_result);    //passed val to result, then to cubeIt(), so it gets back result^3
        System.out.println("The cube of " + sum_result + " is " + cube_result);

    }
}
