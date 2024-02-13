/*
 * John Barbonio, 3408, Lab/GP #
 */
package Labs;

import java.util.Random;

/**
 *
 * @author itzdu
 */
public class Lab_82
{
    public static final int R_SIZE = 5;
    public static final int C_SIZE = 9;
    public int[][] create2DArray() 
    {
        Random rand = new Random();
        int[][] array = new int[R_SIZE][C_SIZE];
        for(int row = 0; row < array.length; row++) 
        {
            for(int col = 0; col < array[0].length; col++) 
            {
                array[row][col] = rand.nextInt(25);
            }
        }
        return array;
    }
    public void print2DArray(int[][] array) 
    {
        for(int row = 0; row < array.length; row++) 
        {
            for(int col = 0; col < array[0].length; col++) 
            {
                System.out.print(array[row][col] + "\t");
            }
                System.out.println("\n");
        }
    }
    public int []createTheList(int[][]array) 
    {
        int index = 1;  //[0] is reserved for the total count of numbers in the range of 11-14 within the array
        int total = 0; 
        int specifiedParameters[] = new int[20];    //im not sure how to create a dynamically scaling array
        
        for(int row = 0; row < array.length; row++) 
        {
            for(int col = 0; col < array[0].length; col++) 
            {
                if(array[row][col] >= 11 && array[row][col] <= 14) 
                {          
                    specifiedParameters[index] = array[row][col];       
                    index++;
                    total++;
                }
                specifiedParameters[0] = total;
            }
        }
        return specifiedParameters;
    }
    public void printTheList(int[] specifiedParameters) 
    {
        System.out.println("The " + specifiedParameters[0] + " numbers stored in  the list are:");
        
        for(int count = 1; count < specifiedParameters[0];count++)
        /*does not print the rest of the array which is of a fixed size and the rest of it is zeroes, so useless data.
        Only prints up to what was actually copied from the initial array, hence the count saved at specifiedParameters[0]*/
        //specifiedParameters[0] was reserved for the amt of numbers on the returned array
        {
                System.out.print(specifiedParameters[count] + " ");
        }
    }
    public static void main(String[]args) 
    {
        Lab_82 ob = new Lab_82();
        int[][] myArray = ob.create2DArray();
        ob.print2DArray(myArray);
        int[] specifiedParameters = ob.createTheList(myArray);
        ob.printTheList(specifiedParameters);
    }
}
