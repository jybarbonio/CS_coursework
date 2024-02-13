/*
John Barbonio, 3408, Lab #92
0518876
9/21/2019
CSIS 113B
 */
package Labs;

import java.awt.Component;
import java.awt.Container;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.FieldPosition;
import java.text.NumberFormat;
import java.text.ParsePosition;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.SwingConstants;

/**
 *
 * @author John
*/
public class Lab_92 extends JFrame implements ActionListener    
/*extends JFrame utilizes JFrame properties for your program, implements ActionListener tells JButton that
this application is able to take notifications*/
{
    Container content = this.getContentPane();
    
    JLabel lblBorrowed = new JLabel("Amount Borrowed", SwingConstants.RIGHT); //two arguments
    JLabel lblInterestYearly = new JLabel("Interest Rate (i.e. 5.0%)", SwingConstants.RIGHT);
    JLabel lblYearsToPay = new JLabel("Years to Pay", SwingConstants.RIGHT);
    JLabel lblMonthlyPayment = new JLabel("Monthly Payment", SwingConstants.RIGHT);
    JLabel lblMPaymentResult = new JLabel("", SwingConstants.RIGHT);
    JLabel lblTotalPCost = new JLabel("Total Purchase Cost", SwingConstants.RIGHT);
    JLabel lblTCostResult = new JLabel("", SwingConstants.RIGHT);
    
    JTextField tfBorrowed = new JTextField();
    JTextField tfInterestYearly = new JTextField();
    JTextField tfYearsTime = new JTextField();
    
    JButton jbGetResults = new JButton("Calculate");
    
    public Lab_92() 
    {
        content.setLayout(new GridLayout(0, 2, 5, 5));
        content.add(lblBorrowed);
        content.add(tfBorrowed);
        
        content.add(lblInterestYearly);
        content.add(tfInterestYearly);
        
        content.add(lblYearsToPay);
        content.add(tfYearsTime);
        
        content.add(lblMonthlyPayment);
        content.add(lblMPaymentResult);
        
        content.add(lblTotalPCost);
        content.add(lblTCostResult);
        
        content.add(jbGetResults);
        jbGetResults.addActionListener(this);
        
        this.setVisible(true);
        this.setSize(350, 300);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setTitle("Lab 92 How Much");
    }
    
    @Override
    public void actionPerformed(ActionEvent e)
    {
        String sBorrowed;
        String sInterestYearly;
        String sYearsTime;
        
        sBorrowed = tfBorrowed.getText();
        sInterestYearly = tfInterestYearly.getText();
        sYearsTime = tfYearsTime.getText();
        
        Double dBorrowedOb = new Double(sBorrowed);
        Double dInterestYearlyOb = new Double(sInterestYearly);
        Double dYearsTimeOb = new Double(sYearsTime);
        
        double dBorrowed = dBorrowedOb.doubleValue();
        double dInterestYearly = dInterestYearlyOb.doubleValue();
        double dYearsTime = dYearsTimeOb.doubleValue();
        
        dInterestYearly = (dInterestYearly / 100) / 12;     //actual interest rate converted to monthly, adds decimal place
        //monthly interest rate and not yearly
        
        //double payment = (1 - (Math.pow(1/(1 + dInterestYearly), dYearsTime * 12)));
        double payment = (dBorrowed * dInterestYearly) / (1 - (Math.pow(1 / (1 + dInterestYearly), dYearsTime * 12)));
    
        this.getCurrencyInstance(payment, dYearsTime);
    }
    
    public void getCurrencyInstance(double toConvert, double dYearsTime) 
    {
        NumberFormat nfObject = NumberFormat.getInstance();

        String result1 = nfObject.format(toConvert);
        String result2 = nfObject.format(toConvert * 12 * dYearsTime);
        
        lblMPaymentResult.setText(result1);
        lblTCostResult.setText(result2);
    }
    public static void main(String[]args) 
    {
        Lab_92 gui = new Lab_92();
    }
}
