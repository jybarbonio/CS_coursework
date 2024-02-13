/*
John Barbonio, 3408, Lab #91
0518876
9/21/2019
CSIS 113B
 */
package Labs;

import java.awt.Color;
import java.awt.Container;
import java.awt.Font;
import java.awt.GridLayout;
import javax.swing.JFrame;
import javax.swing.JLabel;

/**
 *
 * @author John
 */
public class Lab_91 extends JFrame
{
    Container content = this.getContentPane();
    Font font1 = new Font("tart au pomme", Font.TYPE1_FONT, 40);   //font, font style, size
    Font font2 = new Font("fruits du mer", Font.CENTER_BASELINE, 15);
    
    Color clrName = new Color(200, 170, 78);  //can also use #.#F for color amount, 1.0F being = to 255
    Color clrDate = new Color(0.1F, 0.8F, 0.5F);
    
    JLabel lblFirstName = new JLabel("John");
    JLabel lblLastName = new JLabel("Barbonio");
    JLabel lblDate = new JLabel("September 20th, 2019");
    
    public Lab_91() 
    {
        content.setLayout(new GridLayout(3, 1));
        content.add(lblFirstName);
        content.add(lblLastName);
        content.add(lblDate);
        
        lblFirstName.setFont(font1);
        lblFirstName.setForeground(clrName); //can also use built-in color set i.e. color.RED
        lblFirstName.setBackground(Color.RED);
        lblFirstName.setOpaque(true);
        
        lblLastName.setFont(font1);
        lblLastName.setForeground(clrName); //can also use built-in color set i.e. color.RED
        lblLastName.setBackground(Color.YELLOW);
        lblLastName.setOpaque(true);
        
        lblDate.setFont(font2);
        lblDate.setForeground(clrDate); //can also use built-in color set i.e. color.RED
        lblDate.setBackground(Color.BLUE);
        lblDate.setOpaque(true);
        
        this.setVisible(true);
        this.setSize(300, 300);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setTitle("First GUI App");
    }
    public static void main(String[]args) 
    {
        Lab_91 gui = new Lab_91();
    }
}
