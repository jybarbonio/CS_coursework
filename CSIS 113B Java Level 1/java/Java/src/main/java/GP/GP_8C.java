/*
John Barbonio, 3408, GP #8C
0518876
9/29/2019
CSIS 113B
 */
package GP;

import java.util.Random;
import java.util.Scanner;

/**
 *
 * @author itzdu
 */
public class GP_8C
{
    public static void main(String[]args) 
    {
        Scanner in = new Scanner(System.in);
        Random rand = new Random();
        
        int min = 0;
        int max = 100;
        
        Integer[] integer = new Integer[10];
        
        for(int count = 0; count < integer.length; count++) 
        {
            int rnum = rand.nextInt((max - min) + 1) + min;
            integer[count] = new Integer(rnum);
        }
        System.out.println("Ten random integers will be printed");
        
        for(int count = 0; count < integer.length; count++) 
        {
            System.out.println(integer[count].toString());
        }
    }
}