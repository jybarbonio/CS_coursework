/*
John Barbonio, 3408, GP #6B
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

public class GP_6B extends JFrame
{
    Container content = this.getContentPane();
    
    //JLabel label = new JLabel("Hello World!");
    
    public GP_6B() 
    {
        content.setLayout(new GridLayout(3, 1));    //BorderLayout, FlowLayout, and GridLayout
        //row, col, horizontal, vertical
        //content.add(label);
        content.add(new JLabel("John"));
        content.add(new JLabel("Barbonio"));
        content.add(new JLabel("September 20th, 2019"));
        
        this.setVisible(true);
        this.setSize(300, 400);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setTitle("GUI App");
    }
    public static void main(String[]args) 
    {
        GP_6B gui = new GP_6B();
    }
}
