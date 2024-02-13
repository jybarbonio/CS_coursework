/*
John Barbonio, 3408, GP #8A
0518876
9/29/2019
CSIS 113B
 */
package GP;

import java.util.Scanner;

/**
 *
 * @author itzdu
 */
public class GP_8A
{
    public static void main(String[]args) 
    {
        Scanner in = new Scanner(System.in);
        
        Rectangle rect1 = new Rectangle();
        Rectangle rect2 = new Rectangle();
        Box box1 = new Box();
        Box box2 = new Box();
        
        rect1.setRectangle(4, 3);   //sends 2 parameters to other class then method within it, creates a result to be returned
        rect2.setRectangle(6, 5);
        box1.setBox(8, 4, 2);       //sends 3 parameters to other class then method within it, creates a result to be returned
        box2.setBox(5, 5, 5);
        
        System.out.println("The area of rect1 is " + rect1.area());     //calls the area method from within the Rectangle class, returns a value
        System.out.println("The area of rect2 is " + rect2.area());
        
        System.out.println("The volume of box1 is " + box1.boxVolume());    //calls the boxArea method within the Box class, returns a value
        System.out.println("The volume of box2 is " + box2.boxVolume());
        
        System.out.println("The area of box1 is " + box1.boxArea());
        System.out.println("The area of box2 is " + box2.boxArea());

    }
}
