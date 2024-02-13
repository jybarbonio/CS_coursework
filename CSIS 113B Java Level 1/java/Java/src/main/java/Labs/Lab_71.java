/*
John Barbonio, 3408, Lab #71
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
public class Lab_71
{    
    public static final double INCH_TO_CM = 2.54;
    public static final double INCH_TO_MM = 25.4;
    public static final double CM_TO_INCH = 0.393700787;
    public static final double MM_TO_INCH = 0.0393700787;
    
    public double inch_to_cm(double measurement) 
    {
        return measurement * INCH_TO_CM;
    }
    public double inch_to_mm(double measurement)
    {
        return measurement * INCH_TO_MM;
    }
    public double cm_to_inch(double measurement) 
    {
        return measurement * CM_TO_INCH;
    }
    public double mm_to_inch(double measurement) 
    {
        return measurement * MM_TO_INCH;
    }
    
    public static void main(String[]args) 
    {
        Scanner in = new Scanner(System.in);
        double input = 0; //measurement inputted
        double result = 0;
        
        Lab_71 ob = new Lab_71();   //ob for object, object must be named after class
        System.out.print
        ("Choose one:\n" + "\t1] Inches to cm\n" + "\t2] Inches to mm\n" + "\t3] cm to inches\n" + "\t4] mm to inches\n" + "Choose 1-4: ");
        byte choice = in.nextByte();

        switch(choice)
        {
            case 1:
                input = in.nextDouble();
                result = ob.inch_to_cm(input);
                System.out.println(input + " inches is " + result + " cm");
                break;
            case 2:
                input = in.nextDouble();
                result = ob.inch_to_mm(input);
                System.out.println(input + " inches is " + result + " mm");
                break;
            case 3:
                input = in.nextDouble();
                result = ob.cm_to_inch(input);
                System.out.println(input + " cm is " + result + " inches");
                break;
            case 4:
                input = in.nextDouble();
                result = ob.mm_to_inch(input);
                System.out.println(input + " mm is " + result + " inches");
                break;
            default:
                System.out.println("Invalid input, please run and try again.");
        }
    }
}

/*For the initial file I turned in, I created functions for getting the switch option input and the number to be converted and was told that having
print statements in functions was bad practice. Also, the Scanner in = new Scanner(System.in) needed to be right below the class definition in order
to let the in.nextDouble() below it work when it was up there in those (now deleted) methods. Why are these bad practices exactly?*/