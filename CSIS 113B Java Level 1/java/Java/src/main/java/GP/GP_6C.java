/*
John Barbonio, 3408, GP #6C
0518876
9/20/2019
CSIS 113B
 */
package GP;

import java.awt.Color;
import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.GridLayout;
import javax.swing.JFrame;
import javax.swing.JLabel;

/**
 *
 * @author John
 */
public class GP_6C extends JFrame
{
    Container content = this.getContentPane();
    Font font1 = new Font("soy sauce", Font.CENTER_BASELINE, 24);   //font, font style, size
    Font font2 = new Font("french dip", Font.ITALIC, 20);
    Font font3 = new Font("wasabi", Font.ROMAN_BASELINE, 20);

    Color foreColor1 = new Color(200, 170, 78);  //can also use #.#F for color amount 
    Color foreColor2 = new Color(150, 80, 110); 
    Color foreColor3 = new Color(220, 78, 90); 
 
    JLabel label1 = new JLabel("John");
    JLabel label2 = new JLabel("Barbonio");
    JLabel label3 = new JLabel("September 20th, 2019");
    
    public GP_6C() 
    {
        content.setLayout(new GridLayout(3, 1));
        content.add(label1);
        content.add(label2);
        content.add(label3);
        
        label1.setFont(font1);
        label1.setForeground(Color.RED); //can also use built-in color set i.e. color.RED
        label1.setBackground(foreColor1);
        label1.setOpaque(true);
        
        label2.setFont(font2);
        label2.setForeground(Color.WHITE);
        label2.setBackground(foreColor2);
        label2.setOpaque(true);        
        
        label3.setFont(font3);
        label3.setForeground(Color.BLUE); //can also use built-in color set i.e. color.RED
        label3.setBackground(foreColor3);
        label3.setOpaque(true);  

        this.setVisible(true);
        this.setSize(300, 300);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setTitle("GUI App");
    }
    public static void main(String[]args) 
    {
        GP_6C gui = new GP_6C();
    }
}
