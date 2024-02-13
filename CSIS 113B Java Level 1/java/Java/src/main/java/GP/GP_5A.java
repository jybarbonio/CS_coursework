/*
John Barbonio, 3408, GP #5A
0518876
9/15/2019
CSIS 113B
 */
package GP;

import java.util.Random;

/**
 *
 * @author itzdu
 */
public class GP_5A
{
    public int[] createArray(int size) 
    {
        int[]array = new int[size];
        Random rand = new Random();
        for(int count = 0; count < array.length; count++) 
        {
            array[count] = rand.nextInt(101);
        }
        return array;
    }
    public void printArray(int []myArray) 
    {
        for(int count = 0; count < myArray.length; count++) 
        {
            System.out.println(myArray[count]);
        }
    }
    public int DivBy10(int []myArray) 
    {
        int evenDivNums = 0;
        for(int count = 0; count < myArray.length; count++) 
        {
            if(myArray[count] % 10 == 0 && myArray[count] != 0) 
            {
                evenDivNums++;
            }
        }
        return evenDivNums;
    }
    
    public static void main(String[]args) 
    {
        GP_5A ob = new GP_5A();
        int[]myArray = ob.createArray(10);
        ob.printArray(myArray);
        
        int evenDivNums = ob.DivBy10(myArray);
        System.out.println("The total amt of evenly divisible numbers by 10 is " + evenDivNums);
        
    }
}
