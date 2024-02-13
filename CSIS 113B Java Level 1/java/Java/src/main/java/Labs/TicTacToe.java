/*
John Barbonio, 3408, Lab #17
0518876
9/22/2019
CSIS 113B
 */
package Labs;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

/**
 *
 * @author itzdu
 */
public class TicTacToe extends JFrame implements ActionListener, MouseListener
{
    Container content = new Container();
    
    JLabel [][] grid = new JLabel[2][2];
    char [][] game = new char[2][2];    
    
    public TicTacToe() 
    {
        this.setVisible(true);
        this.setSize(300, 300);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setTitle("Tic Tac Toe");
    }
    
    public static void main(String[]args) 
    {
        
    }

    @Override
    public void actionPerformed(ActionEvent arg0)
    {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public void mouseClicked(MouseEvent arg0)
    {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public void mousePressed(MouseEvent arg0)
    {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public void mouseReleased(MouseEvent arg0)
    {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public void mouseEntered(MouseEvent arg0)
    {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public void mouseExited(MouseEvent arg0)
    {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
}
