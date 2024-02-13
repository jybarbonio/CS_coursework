/*
John Barbonio, 3408, Lab 62
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
public class Lab_62
{
    public static void main(String[]args) 
    {
        Scanner in = new Scanner(System.in);
        
        int b = 0, g = 0, attendees = 0;
        
        System.out.println("Start counting tickets? (Y/N)");
        String option = in.nextLine();
        
        while(option.equals("y") || option.equals("Y")) 
        {
            System.out.print("Enter B for blue or G for green: ");
            option = in.nextLine();
            
            if(option.equals("b") || option.equals("B")) 
            {
                b++;
                attendees++;
            }
            else if(option.equals("g") || option.equals("G")) 
            {
                g++;
                attendees++;
            }
            else 
            {
                System.out.println("Invalid input. Please enter a B or a G.");
            }
            System.out.println("Count another ticket? (Y/N)");
            option = in.nextLine();
            
            if(!"y".equals(option) && !"Y".equals(option) && !"n".equals(option) && !"N".equals(option))      //interesting how the != with strings in inverted. Why is there no .notequal?
            {
                option = "y"; //assume the user mis-inputed if the letter is not a y or an n and continue asking for input
                System.out.println("It is assumed you meant yes. To close this program, press n.");
            }
            else 
            {
            
            }
        }
        System.out.println("There were " + attendees + " attendees. " + b + " had blue tickets and " + g + " had green tickets");
    }
}
