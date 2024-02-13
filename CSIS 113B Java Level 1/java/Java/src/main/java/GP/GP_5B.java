/*
John Barbonio, 3408, GP #5B
0518876
9/15/2019
CSIS 113B
 */
package GP;

/**
 *
 * @author itzdu
 */
import javax.swing.*;
import java.util.Random;
import java.util.Scanner;

public class GP_5B
{
    public int[][] createArray(int rSize, int cSize) 
    {
        Random rand = new Random();
        int[][] array = new int[rSize][cSize];
        for(int row = 0; row < array.length; row++) 
        {
            for(int col = 0; col < array[0].length; col++) 
            {
                array[row][col] = rand.nextInt((25 - 25) + 1);
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
    public int countInstance(int[][] array, int search) 
    {
        int count = 0;
        for(int row = 0; row < array.length; row++) 
        {
            for(int col = 0; col < array[0].length; col++) 
            {
                if(array[row][col] == search) 
                {
                    count++;
                    System.out.println("row (X): " + (row + 1) + ", " + "col (Y): " + (col + 1)); 
                    //+1 is added to each index for "human readability", onless it was intended to be like a graph chart 0-9
                }
            }
        }
        return count;
    }
    
    public static void main(String[]args) 
    {
        Scanner in = new Scanner(System.in);
        
        GP_5B ob = new GP_5B();
        int[][] myArray = ob.createArray(10, 10);
        ob.print2DArray(myArray);
        
        System.out.println("Enter a number to search for");
        int value = in.nextInt();
        System.out.println("Your number occured " + ob.countInstance(myArray, value)+ " times");
    }
}