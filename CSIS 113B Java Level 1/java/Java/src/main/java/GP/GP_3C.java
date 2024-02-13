/*
John Barbonio, 3408, GP #3C
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
public class GP_3C
{
    public static void main(String[]args) 
    {
        Scanner in = new Scanner(System.in);
        Random rnd = new Random();
        
        System.out.println("Would you like to play? (Y/N)");
        String answer = in.nextLine();
        
        while(answer.equals("y")) 
        {
            System.out.println("Guess a number between 1 and 10");
            int count = 1;
            int guess = in.nextInt();
            int num = rnd.nextInt(10) + 1;
            
            while(guess != num) 
            {
                System.out.println("Guess a number between 1 and 10");
                guess = in.nextInt();
                in.nextLine();  //clears data in buffer
                count++;
                
                System.out.println("It took " + count + " guesses to guess correctly.");
                System.out.println("Would you like to play again? (Y/N)");
                answer = in.nextLine();
            }
        }      
    }
}