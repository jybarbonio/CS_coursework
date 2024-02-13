/*
John Barbonio, 3408, Lab 51
0518876
9/1/2019
CSIS 113B
 */
package Labs;

import java.util.Scanner;

/**
 *
 * @author itzdu
 */
public class Lab_51
{
    public static void main(String[]args) 
    {
        Scanner in = new Scanner(System.in);
        int maxBase = in.nextInt();
        int maxExponent = in.nextInt();
        
        
        for(int count = 1; count <= maxBase; count++)   //range is shifted up by 1 as zeroes are not shown in the sample output
        {
            for(int countExp = 1; countExp <= maxExponent; countExp++)     //range is shifted up by 1 as zeroes are not shown in the sample output
            {
                double answer = Math.pow(count, countExp);
                System.out.print(count + "^" + countExp + " = " + answer + "  ");   //don't use tabs because of number size
            }
            System.out.println(""); //next row and base integer
        }
    }
}
