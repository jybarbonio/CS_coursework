/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Other;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;

/**
 *
 * @author John
 */
public class JButtonExample extends JFrame implements ActionListener
{
    Container content = this.getContentPane();
    JLabel lblColor = new JLabel("Yellow");
    JButton myButton = new JButton("Click Me!");
    boolean toggle = false;
    
    public JButtonExample() 
    {
        content.setLayout(new FlowLayout());
        content.add(myButton);
        content.add(lblColor);
        
        this.setVisible(true);
        this.setSize(300, 300);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setTitle("First Button App");
        
        lblColor.setOpaque(true);
        lblColor.setBackground(Color.RED);
        
        myButton.addActionListener(this);
    }
    
    @Override
    public void actionPerformed(ActionEvent e)
    {
        if(toggle == false) 
        {
            lblColor.setBackground(Color.GREEN);
            lblColor.setText("Green");
        }
        else 
        {
            lblColor.setBackground(Color.YELLOW);
            lblColor.setText("Yellow");
        }
        toggle = !toggle;
    }
    
    public static void main(String[]args) 
    {
        JButtonExample gui = new JButtonExample();
    }
}
