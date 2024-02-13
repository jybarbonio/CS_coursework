/*
John Barbonio, 3408, GP #4A
0518876
9/5/2019
CSIS 113B
 */
package GP;

import java.util.Scanner;

/**
 *
 * @author itzdu
 */
public class GP_4A
{
    public void printName() 
    {
        System.out.println("Hello from John!");
    }
    public void SayHello()  //would it be fair to call this a nested method?
    {
        this.printName();
    }
    
    public static void main(String[]args) 
    {
        Scanner in = new Scanner(System.in);
        
        System.out.println("How many times would you like to print hello?");
        int prompt = in.nextInt();
        //int count;
        
        GP_4A c = new GP_4A();  //uses class name
        
        for(int count = 0; count < prompt; count++)
        /*declaring the count int in the for parameters is not bad coding practice, is it?
        As long as it's not in the actual loop?*/
        {
            c.SayHello();
        }
    }
}
