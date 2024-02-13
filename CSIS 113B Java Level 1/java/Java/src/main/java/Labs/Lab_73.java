/*
John Barbonio, 3408, Lab #73
0518876
9/5/2019
CSIS 113B
 */
package Labs;

import java.util.Scanner;

/**
 *
 * @author itzdu
 */
public class Lab_73
{
    public static final long AVG_BY_2 = 2;
    public static final long AVG_BY_3 = 3;
    public static final double D_AVG_BY_2 = 2;
    
    public long average(long n1, long n2) 
    {
        long avg = (n1 + n2) / AVG_BY_2;
        return avg;
    }
    public long average(long n1, long n2, long n3) 
    {
        long avg = (n1 + n2 + n3) / AVG_BY_3;
        return avg;
    }
    public double average(double d1, double d2) 
    {
        double getAvg = (d1 + d2) / D_AVG_BY_2;
        return getAvg;
    }
    public static void main(String[]args) 
    {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter three longs.");
        long num1 = in.nextLong();
        long num2 = in.nextLong();
        
        long num3 = in.nextLong();
        
        Lab_73 ob = new Lab_73();
        long avg = ob.average(num1, num2);
        System.out.println("The average of " + num1 + " and " + num2 + " is " + avg);
    
        avg = ob.average(num1, num2, num3);
        System.out.println("The average of " + num1 + ", " + num2 + ", and " + num3 + " is " + avg + "\n");
        
        System.out.println("Enter two doubles.");
        double dnum1 = in.nextDouble();
        double dnum2 = in.nextDouble();
        
        double d_avg = ob.average(dnum1, dnum2);
        System.out.println("The average of " + dnum1 + " and " + dnum2 + " is " + d_avg);
    }
}