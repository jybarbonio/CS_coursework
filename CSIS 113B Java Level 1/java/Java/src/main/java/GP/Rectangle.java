/*
John Barbonio, 3408, GP #8A dependency
0518876
9/29/2019
CSIS 113B
 */
package GP;

/**
 *
 * @author itzdu
 */
public class Rectangle
{
    private int length;
    private int width;

    public void setRectangle(int length, int width) 
    {
        this.length = length;
        this.width = width;
    }
    public int area()   //a = b * h
    {
        return this.length * this.width;
    }
}

