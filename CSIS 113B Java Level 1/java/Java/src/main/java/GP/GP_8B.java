/*
John Barbonio, 3408, GP #8B
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
public class GP_8B
{
    public static void main(String[]args) 
    {
        Scanner in = new Scanner(System.in);
        
        Rectangle8B rect1 = new Rectangle8B(4, 3);
        Rectangle8B rect2 = new Rectangle8B(6, 5);
        
        Box8B box1 = new Box8B(2, 4, 6);
        Box8B box2 = new Box8B(9, 6, 1);
        Box8B box3 = new Box8B();
        
        System.out.println("The area of rect1 is " + rect1.area());
        System.out.println("The area of rect2 is " + rect2.area());
        System.out.println("The volume of box1 is " + box1.boxVolume());
        System.out.println("The volume of box2 is " + box2.boxVolume());
        System.out.println("The volume of box3 is " + box3.boxVolume());
    }
}
