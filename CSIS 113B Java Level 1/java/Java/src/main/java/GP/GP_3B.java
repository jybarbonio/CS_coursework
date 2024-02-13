/*
John Barbonio, 3408, GP #3B
0518876
9/1/2019
CSIS 113B
 */
package GP;

import java.util.Random;
import java.util.Scanner;

/**
 *
 * @author itzdu
 */
public class GP_3B
{
    public static void main(String[]args) 
    {
        
        Scanner in = new Scanner(System.in);
        Random rnd = new Random();

        int min = 98;   //wants between a and z, not a range with a and z hence both are incremented/decremented by 1
        int max = 121;
        for(int count = 1; count <= 100; count++) 
        {
            char randLetter = (char)(rnd.nextInt((max - min) + 1) + min);   //between a and z ascii characters, casting to prevent loss
            System.out.print(randLetter);
                    
    
            if(count % 10 == 0)
                System.out.println("");
        }
    }
}
