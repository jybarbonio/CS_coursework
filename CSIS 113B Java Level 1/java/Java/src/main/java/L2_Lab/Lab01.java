/*
John Barbonio, 3408, Lab 01 Console Application
0518876
10/15/2019
CSIS 123B
 */
package L2_Lab;

import java.util.Scanner;
import java.util.stream.IntStream;

public class Lab01
{
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
    public static void main(String[]args)
    {
        Scanner in = new Scanner(System.in);
        Lab01 ob = new Lab01();
        
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