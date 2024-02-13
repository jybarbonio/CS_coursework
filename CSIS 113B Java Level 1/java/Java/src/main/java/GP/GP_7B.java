/*
John Barbonio, 3408, GP #7B
0518876
9/22/2019
CSIS 113B
 */
package GP;

import java.awt.*;
import java.awt.event.*;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;

/**
 *
 * @author itzdu
 */
public class GP_7B extends JFrame implements ActionListener
{
    Container content = this.getContentPane();
    
    JButton btnGreen = new JButton("Green");
    JButton btnBlue = new JButton("Blue");
    
    JPanel panel = new JPanel();
    JPanel panel2 = new JPanel();
    
    JTextField text1 = new JTextField("Atari VCS");
    JTextField text2 = new JTextField("6507 CPU");
    JTextField text3 = new JTextField("TIA Display Chip");
    
    public GP_7B() 
    {
        this.setVisible(true);
        this.setSize(300, 300);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setTitle("Using JPanels App");
        
        panel.setLayout(new GridLayout(1, 3, 5, 5));
        panel.add(btnGreen);
        panel.add(btnBlue);
        content.add(panel, BorderLayout.SOUTH);
        content.add(panel2, BorderLayout.NORTH);
        
        panel2.add(text1);
        panel2.add(text2);
        panel2.add(text3);
        
        btnBlue.addActionListener(this);
        btnGreen.addActionListener(this);
        
        panel2.setBackground(Color.white); 
    }
    
    public void actionPerformed(ActionEvent arg0)
    {
        JButton btn = (JButton) arg0.getSource();       //referencing ActionEvent arg0 above, did not want to use ae
        if(btn == btnBlue) 
        {
            panel2.setBackground(Color.BLUE);   //changed to panels from content
        }
        else 
        {
            panel2.setBackground(Color.GREEN);
        }
    }
    
    public static void main(String[]args) 
    {
        GP_7B gui = new GP_7B();
    }
}
