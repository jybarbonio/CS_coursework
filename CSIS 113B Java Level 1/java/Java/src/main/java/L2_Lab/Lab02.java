/*
John Barbonio, 3408, Lab 02 Swing Review
0518876
10/15/2019
CSIS 123B
 */
package L2_Lab;

import java.awt.*;
import java.awt.event.*;
import java.util.Scanner;
import java.util.stream.IntStream;
import javax.swing.*;

public class Lab02 extends JFrame implements ActionListener, ItemListener
{
    Container content = this.getContentPane();
    
    JTextField tfNum = new JTextField(3);   //why need more than 3 spaces?
    
    JLabel lbNum = new JLabel("Enter a 3-Digit Number:");
    JLabel lbSum = new JLabel("Sum:");
    JLabel lbRev = new JLabel("Reverse");
    JLabel lbArr = new JLabel("Array");    
    JLabel lbClr = new JLabel("Text Color");
    
    JLabel lbSumRes = new JLabel("0");
    JLabel lbRevRes = new JLabel("1");
    JLabel lbArrRes_1 = new JLabel("2");
    JLabel lbArrRes_2 = new JLabel("3");
    JLabel lbArrRes_3 = new JLabel("4");
    JRadioButton rbRed = new JRadioButton("Red");
    JRadioButton rbGreen = new JRadioButton("Green");
    JRadioButton rbBlue = new JRadioButton("Blue");
    
    JButton btnCompute = new JButton("Compute");
    
    //need a jcheckbox or whateever the fill in the blank bubble is called
    
    public Lab02()
    {
        this.setVisible(true);
        this.setSize(400, 300);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setTitle("Lab 02: Number Manipulation");
        
        SpringLayout sl = new SpringLayout();
        content.setLayout(sl);
        content.add(lbNum);
        content.add(tfNum);
        content.add(lbSum);
        content.add(lbSumRes);
        content.add(lbRev);
        content.add(lbRevRes);
        content.add(lbArr);
        content.add(lbArrRes_1);
        content.add(lbArrRes_2);
        content.add(lbArrRes_3);
        content.add(lbClr);
        content.add(rbRed);
        content.add(rbGreen);
        content.add(rbBlue);
        
        content.add(btnCompute);
        
        
        sl.putConstraint(SpringLayout.WEST, lbNum, 20, SpringLayout.WEST, content);
        sl.putConstraint(SpringLayout.NORTH, lbNum, 15, SpringLayout.NORTH, content);
        sl.putConstraint(SpringLayout.WEST, tfNum, 40, SpringLayout.EAST, lbNum);
        sl.putConstraint(SpringLayout.NORTH, tfNum, 15, SpringLayout.NORTH, content);

        sl.putConstraint(SpringLayout.WEST, lbSum, 20, SpringLayout.WEST, content);
        sl.putConstraint(SpringLayout.NORTH, lbSum, 40, SpringLayout.NORTH, lbNum);
        sl.putConstraint(SpringLayout.WEST, lbSumRes, 40, SpringLayout.EAST, lbNum);
        sl.putConstraint(SpringLayout.NORTH, lbSumRes, 40, SpringLayout.NORTH, tfNum);
        
        sl.putConstraint(SpringLayout.WEST, lbRev, 20, SpringLayout.WEST, content);
        sl.putConstraint(SpringLayout.NORTH, lbRev, 40, SpringLayout.NORTH, lbSum);
        sl.putConstraint(SpringLayout.WEST, lbRevRes, 40, SpringLayout.EAST, lbNum);
        sl.putConstraint(SpringLayout.NORTH, lbRevRes, 40, SpringLayout.NORTH, lbSumRes);
        
        sl.putConstraint(SpringLayout.WEST, lbArr, 20, SpringLayout.WEST, content);
        sl.putConstraint(SpringLayout.NORTH, lbArr, 40, SpringLayout.NORTH, lbRev);
        sl.putConstraint(SpringLayout.WEST, lbArrRes_1, -40, SpringLayout.EAST, lbNum);
        sl.putConstraint(SpringLayout.NORTH, lbArrRes_1, 40, SpringLayout.NORTH, lbRevRes);
        sl.putConstraint(SpringLayout.WEST, lbArrRes_2, 40, SpringLayout.EAST, lbNum);
        sl.putConstraint(SpringLayout.NORTH, lbArrRes_2, 40, SpringLayout.NORTH, lbRevRes);
        sl.putConstraint(SpringLayout.WEST, lbArrRes_3, 120, SpringLayout.EAST, lbNum);
        sl.putConstraint(SpringLayout.NORTH, lbArrRes_3, 40, SpringLayout.NORTH, lbRevRes);
        
        sl.putConstraint(SpringLayout.WEST, lbClr, 20, SpringLayout.WEST, content);
        sl.putConstraint(SpringLayout.NORTH, lbClr, 40, SpringLayout.NORTH, lbArr);
        sl.putConstraint(SpringLayout.WEST, rbRed, 40, SpringLayout.EAST, lbArr);
        sl.putConstraint(SpringLayout.NORTH, rbRed, 40, SpringLayout.NORTH, lbArrRes_1);
        sl.putConstraint(SpringLayout.WEST, rbGreen, 40, SpringLayout.EAST, rbRed);
        sl.putConstraint(SpringLayout.NORTH, rbGreen, 40, SpringLayout.NORTH, lbArrRes_2);
        sl.putConstraint(SpringLayout.WEST, rbBlue, 40, SpringLayout.EAST, rbGreen);
        sl.putConstraint(SpringLayout.NORTH, rbBlue, 40, SpringLayout.NORTH, lbArrRes_3);
        
        sl.putConstraint(SpringLayout.EAST, btnCompute, -150, SpringLayout.EAST, content);   //demonstrating understanding of springlayout directional system
        sl.putConstraint(SpringLayout.SOUTH, btnCompute, -25, SpringLayout.SOUTH, content); /*this is a nightmare and I know I'll need to simplify it with a loop
        or something*/
        
        rbRed.addItemListener(this);
        rbGreen.addItemListener(this);
        rbBlue.addItemListener(this);
        btnCompute.addActionListener(this);
    }
    public short sumTheDigits(short baseTriNum)
    {
        int numArr[] = this.createArrayFrom(baseTriNum);
        baseTriNum = (short) IntStream.of(numArr).sum();    //note this is java 8 and beyond

        return baseTriNum;
    }
    public String reverseTheOrder(short baseTriNum) 
    {
        int numArr[] = this.createArrayFrom(baseTriNum);
        
        StringBuffer sb = new StringBuffer();   //why does the IDE recommend I replace this with StringBuilder, what is that?
        sb.append(numArr[2]);
        sb.append(numArr[1]);
        sb.append(numArr[0]);
        
        String reverseNum = sb.toString();  /*I don't want to return a StringBuffer even though I could make the method 
        a StringBuffer instead of String, keep it simple and not janky by returning a string*/
        return reverseNum;
    }
    public int[] createArrayFrom(short baseTriNum)
    {
        int numArr[] = new int[3];
        numArr[0] = (baseTriNum / 100);
        numArr[1] = (short) (((baseTriNum % 100) - (numArr[2])) / 10);
        numArr[2] = (short) (baseTriNum % 10);
        return numArr;
    }
    @Override
    public void actionPerformed(ActionEvent e)
    {
        JButton getBtn = (JButton) e.getSource();
        
        if(getBtn == btnCompute)
        {
            short getTriVal = (short) Integer.parseInt(tfNum.getText());      //textfield gives a string so it must be converted with this code
            short digitsSum = this.sumTheDigits(getTriVal);
            String reverseNum = this.reverseTheOrder(getTriVal);
            int numArr[] = this.createArrayFrom(getTriVal);  //assignment wanted int, not short, but I used short for memory efficiency purposes
            
            lbSumRes.setText(Integer.toString(digitsSum));
            lbRevRes.setText(reverseNum);
            lbArrRes_1.setText(Integer.toString(numArr[0]));
            lbArrRes_2.setText(Integer.toString(numArr[1]));
            lbArrRes_3.setText(Integer.toString(numArr[2]));
        }
        else
        {
        }
    }
    public void itemStateChanged(ItemEvent e) 
    {
        JRadioButton rbOption = (JRadioButton) e.getSource();
        
        if(rbOption == rbRed)
        {
            if(rbOption.isSelected()) 
            {
                rbGreen.setSelected(false);
                rbBlue.setSelected(false);
                
                lbSumRes.setForeground(Color.RED);
                lbRevRes.setForeground(Color.RED);
                lbArrRes_1.setForeground(Color.RED);
                lbArrRes_2.setForeground(Color.RED);
                lbArrRes_3.setForeground(Color.RED); 
            }
        }
        else if(rbOption == rbGreen) 
        {
            if(rbOption.isSelected()) 
            {
                rbBlue.setSelected(false);
                rbRed.setSelected(false);

                lbSumRes.setForeground(Color.BLUE);
                lbRevRes.setForeground(Color.BLUE);
                lbArrRes_1.setForeground(Color.BLUE);
                lbArrRes_2.setForeground(Color.BLUE);
                lbArrRes_3.setForeground(Color.BLUE); 
            }
        }
        else if(rbOption == rbBlue)
        {
            if(rbOption.isSelected())
            {
                rbGreen.setSelected(false);
                rbRed.setSelected(false);

                lbSumRes.setForeground(Color.GREEN);
                lbRevRes.setForeground(Color.GREEN);
                lbArrRes_1.setForeground(Color.GREEN);
                lbArrRes_2.setForeground(Color.GREEN);
                lbArrRes_3.setForeground(Color.GREEN); 
            }
        }
    }
    public static void main(String[]args)
    {
        Lab02 ob = new Lab02();
        Scanner in = new Scanner(System.in);
        
        System.out.println("please enter a three digit number");
        short baseTriNum = in.nextShort();
        
        short digitsSum = ob.sumTheDigits(baseTriNum);
        String reverseNum = ob.reverseTheOrder(baseTriNum);
        int numArr[] = ob.createArrayFrom(baseTriNum);  //assignment wanted int, not short, but I used short for memory efficiency purposes
        
        System.out.println("The sum of the digits " + baseTriNum + " equals " + digitsSum);     
        /*Did you want what the methods return printed in main, or in the methods? I remember someone saying it was bad coding practice to print in methods
        as it takes away from the concise job of a method
        */
        System.out.println(baseTriNum + " reversed is " + reverseNum);
        
        System.out.println("Printing Array:");
        for(int count = 0; count < numArr.length; count++)
        {
            System.out.println(numArr[count]);
        }
    }
}