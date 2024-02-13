/*
John Barbonio, 3408, GP #8B dependency
0518876
9/29/2019
CSIS 113B
 */
package GP;

/**
 *
 * @author itzdu
 */
public class Rectangle8B
{
    private int length;
    private int width;

    public Rectangle8B(int length, int width)     //remember, one code path, this goes to setrectangle, 
    {
        this.setRectangle(length, width);
    }
    public Rectangle8B() 
    {
        this(1, 1);
    }
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

