/*
John Barbonio, 3408, Lab #19
0518876
9/29/2019
CSIS 113B
 */
package Labs;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.GridLayout;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

/**
 *
 * @author itzdu
 */
public class Concentration extends JFrame
{
    Container content = this.getContentPane();
    
    JLabel[] lblBoard = new JLabel[16];
    int[] nums = {1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8};
    
    int firstChoice = -1;
    int tries = 0;
    JLabel lblFirst = new JLabel();
    
    JButton btnGame = new JButton("New Game");
    JLabel lblTries = new JLabel("0");
    JPanel pnlControls = new JPanel();
    JPanel pnlBoard = new JPanel();
    
    public Concentration()
    {
        this.setVisible(true);
        this.setSize(1024, 1024);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setTitle("Concentration Game");
        
        content.add(pnlBoard, BorderLayout.NORTH);
        content.add(pnlControls, BorderLayout.SOUTH);
        pnlBoard.setBackground(Color.white);
        
    }
    public void createLabels(JLabel[] lblBoard) 
    {
        pnlBoard.setLayout(new GridLayout(4, 4, 5, 5));  
        
        for(int count = 0; count < lblBoard.length; count++) 
        {
            content.add(lblBoard[count], BorderLayout.NORTH);
            //lblBoard.setText(nums[count]);
        }
    }
    public static void main(String[]args) 
    {
        Concentration gui = new Concentration();
    }
}