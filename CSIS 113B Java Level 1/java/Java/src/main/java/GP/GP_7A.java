/*
John Barbonio, 3408, GP #7A
0518876
9/22/2019
CSIS 113B
 */
package GP;

import java.awt.*;
import java.awt.event.*;
import javax.swing.JButton;
import javax.swing.JFrame;

/**
 *
 * @author itzdu
 */
public class GP_7A extends JFrame implements ActionListener
{
    Container content = this.getContentPane();
    JButton btnGreen = new JButton("Green");
    JButton btnBlue = new JButton("Blue");
    JButton btnRed = new JButton("Red");
    
    public GP_7A() 
    {
        content.setLayout(new FlowLayout());
        this.setVisible(true);
        this.setSize(300, 300);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setTitle("First GUI App");
        
        content.add(btnBlue, BorderLayout.SOUTH);
        content.add(btnGreen, BorderLayout.SOUTH);
        content.add(btnRed, BorderLayout.SOUTH);
        
        btnBlue.addActionListener(this);
        btnGreen.addActionListener(this);
        btnRed.addActionListener(this);
        
    }
    
    public static void main(String[]args) 
    {
        GP_7A gui = new GP_7A();
    }

    @Override
    public void actionPerformed(ActionEvent arg0)
    {
        JButton btn = (JButton) arg0.getSource();       //referencing ActionEvent arg0 above, did not want to use ae
        if(btn == btnBlue) 
        {
            content.setBackground(Color.BLUE);
        }
        else if(btn == btnRed) 
        {
            content.setBackground(Color.RED);
        }
        else 
        {
            content.setBackground(Color.GREEN);
        }
    }
}
