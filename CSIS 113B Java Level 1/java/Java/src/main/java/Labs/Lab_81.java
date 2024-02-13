/*
John Barbonio, 3408, Lab 81
0518876
9/15/2019
CSIS 113B
 */
package Labs;

import java.util.Random;
import java.util.Scanner;

/**
 *
 * @author itzdu
 */
public class Lab_81
{
    public int[] createArray(int aSize) 
    {
        Random rand = new Random();
        int[] array = new int[aSize];
        
        for(int count = 0; count < array.length; count++) 
        {
                array[count] = rand.nextInt(25 + 25) - 25;
        }
        return array;
    }
    public void printArray(int[]array) //void as it doesn't need to return anything
    {
        for(int count = 0; count < array.length; count++) 
        {
            if(count % 10 == 0 && count != 0)
            {
                System.out.println("\n");
            }
            System.out.print(array[count] + "\t");
        }      
    }
    public int countThrees(int[]array) 
    {
        int DivBy3Total = 0;
        for(int count = 0; count < array.length; count++) 
        {
            if(array[count] % 3 == 0 && array[count] != 0)
            {
                //System.out.println("\n" + array[count]);
                DivBy3Total++;
            }
        }  
        return DivBy3Total;
    }
    public static void main(String[]args) 
    {
        Scanner in = new Scanner(System.in);
        Lab_81 ob = new Lab_81();
        
        System.out.println("Please enter the amt of rows");
        int count = in.nextInt();
        
        int []array = ob.createArray(count);
        ob.printArray(array);
        int DivBy3Total = ob.countThrees(array);
        System.out.println("\n\nThe total amt of numbers evenly divisible by 3 is " + DivBy3Total + " in the array.\n");
    }
}
