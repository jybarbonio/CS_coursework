/*
John Barbonio, 3408, GP #6A
0518876
9/20/2019
CSIS 113B
 */

package GP;

/**
 *
 * @author John
 */
import javax.swing.*;
import java.util.Random;
import java.util.Scanner;
import java.awt.*;

public class GP_6A extends JFrame
{
    public GP_6A() 
    {
    String title = this.guiApp();    
    
    this.setVisible(true);
    this.setSize(300, 400);
    this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    this.setTitle(title);
    }
    public String guiApp()
    {
        System.out.println("Please enter a name for the window below");
        Scanner in = new Scanner(System.in);
        String title;
        title = in.nextLine();
        System.out.println("The name you entered: " + title);
        return title;
    }
    public static void main(String[]args) 
    {
        GP_6A gui = new GP_6A();
    }
}
