/*
John Barbonio, 3408, GP #2B
0518876
08/23/2019
CSIS 113B
 */
package GP;

/**
 *
 * @author itzdu
 */
import java.util.Scanner;

public class GP_2B
{
    public static void main(String[]args) 
    {
        Scanner in = new Scanner(System.in);
        int score = 0;
        
        System.out.println("Enter your score");
        score = in.nextInt();
        if(score > 100) 
        {
            System.out.println("You got over a 100 on the test! Yee haw!");
        }
        else if(score >= 90 && score <= 100)
        {
            System.out.println("You got an A. Good job!");
        }
        else if(score >= 80)
        {
            System.out.println("You got a B. Ok!");
        }
        else if(score >= 70) 
        {
            System.out.println("You got a C");
        }
        else if(score >= 60) 
        {
            System.out.println("You got a D.");
        }
        else if(score < 60 && score >= 0)
        {
            System.out.println("You got an F.");
        }
        else 
        {
            System.out.println("Invalid input. Must be above 0 and a numeral.");
        }
    }
}