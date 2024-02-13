/*
John Barbonio, 3408, GP #3A
0518876
9/1/2019
CSIS 113B
 */
package GP;

import java.util.Scanner;

/**
 *
 * @author itzdu
 */
public class GP_3A
{
    public static void main(String[]args) 
    {
        Scanner in = new Scanner(System.in);
        int baseRowNums = 0;        //used to establish 0-9 as reference numbers on the first row and column, like a real multiplication chart
        
        for(int row = 0; row < 10; row++) 
        {           
            for(int col = 0; col < 10; col++) 
            {
                if((col * row) == 0) //zero is reserved for the base reference numbers on the chart
                {
                    System.out.print(baseRowNums + "\t");
                    baseRowNums++;
                    
                    if(baseRowNums > 9)
                        baseRowNums = 1;
                }
                else 
                {
                    System.out.print(col * row + "\t");     
                    /*since this only works when row is greater than zero, it leaves space for the base numbers
                    and does not print a column or row full zeroes when col and row's product is zero*/
                }
            }
            System.out.print("\n");
        }
    }
}