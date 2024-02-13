/*
John Barbonio, 3408, Lab 61
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
public class Lab_61
{
    public static final short LOW_TEMP = -130;
    public static final short HIGH_TEMP = 130;
    public static final short SENTINEL = 999;
    
    public static void main(String[]args) 
    {
        Scanner in = new Scanner(System.in);
        int temperature;
        int tempsCount = 0;
        int totalTemp = 0;
        
        System.out.println("Hello. This program calculates average temperature inputs between -130 and 130. 999 is reserved for EXIT");
        
        do 
        {
            System.out.println("Please enter the temperature(999 to quit): ");
            temperature = in.nextShort();      
            
            if(temperature >= LOW_TEMP && temperature <= HIGH_TEMP && temperature != SENTINEL)
            //if input is 999, it will not count towards the number of temperatures recorded, must also be within specified constant range
            {
                tempsCount++;
            }
            else if(temperature == SENTINEL) 
            {
                System.out.println("Calculating average temperature...");
            }
            else 
            {
                System.out.println(temperature + " is not a valid input! Please try again.");
            }
            
            //tempsCount = (temperature >= LOW_TEMP && temperature <= HIGH_TEMP && temperature != 999) ? tempsCount++ : tempsCount;
            totalTemp = (temperature == SENTINEL) ? totalTemp: totalTemp + temperature; //if input is 999, it will not be added to calculations
        }
        while(temperature != SENTINEL);
        
        if(totalTemp != 0 && tempsCount != 0)   //java crashes if there is a divide by zero
        {
            double average = ((double) totalTemp / (double) tempsCount);    //casting (converting) int whole numbers to malleable doubles
            System.out.print(tempsCount + " temperatures entered. The average is ");
            System.out.print(average);
        }
        else 
        {
            System.out.println(tempsCount + " temperatures entered, so there is no average temperature to calculate.");
        }
    }
}
