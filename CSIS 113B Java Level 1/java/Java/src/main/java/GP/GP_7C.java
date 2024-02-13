/*
John Barbonio, 3408, GP #7C
0518876
9/22/2019
CSIS 113B
 */
package GP;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class GP_7C extends JFrame implements ItemListener
{
    Container content = this.getContentPane();
    JCheckBox chkApple = new JCheckBox("Apples");
    JCheckBox chkOrange = new JCheckBox("Oranges");
    JCheckBox chkGrape = new JCheckBox("Grapes");
    JCheckBox chkPineapple = new JCheckBox("Pineapples");
    JLabel lblOutput = new JLabel(" ");
    JPanel panel = new JPanel();
    
    public GP_7C() 
    {
        this.setVisible(true);
        this.setSize(300, 300);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setTitle("Using JPanels App");
        
        panel.setLayout(new GridLayout(4, 1, 5, 5));
        panel.add(chkApple);
        panel.add(chkOrange);
        panel.add(chkGrape);
        panel.add(chkPineapple);
        content.add(panel, BorderLayout.SOUTH);
        content.add(lblOutput, BorderLayout.NORTH);
        chkApple.addItemListener(this);
        chkOrange.addItemListener(this);
        chkGrape.addItemListener(this);
        chkPineapple.addItemListener(this);
    }

    @Override
    public void itemStateChanged(ItemEvent arg0)
    {
        JCheckBox chk = (JCheckBox) arg0.getSource();
        if(chk == chkApple) 
        {
            if(chk.isSelected()) 
            {
                lblOutput.setText("Apples Selected");
            }
        }
        else if(chk == chkOrange) 
        {
            if(chk.isSelected()) 
            {
                lblOutput.setText("Oranges Selected");
            }    
        }
        else if(chk == chkGrape) 
        {
            if(chk.isSelected())
            {
                lblOutput.setText("Grapes Selected");
            }
        }
        else if(chk == chkPineapple)
        {
            if(chk.isSelected())
            {
                lblOutput.setText("Pineapples Selected");
            }
        }
        else 
        {
            if(chk.isSelected())
            {
                lblOutput.setText("None Selected");
            }
        }
    }    

    public static void main(String[]args) 
    {
        GP_7C gui = new GP_7C();
    }
}
