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
public class Box8B
{
    public static final int HEIGHT_CONST = 1;   //Stevenson wanted everything to be 1?
    
    private int length;
    private int width;
    private int height;
    
    public Box8B(int length, int width, int height) //height is defaulted to 1 per instructions?
    {
        height = HEIGHT_CONST;
        this.setBox(length, width, height);
    }
    public Box8B() //default constructor (must be same name as class)
    {
        this(1, 1, 1);
    }
    public void setBox(int length, int width, int height) //setCube, calculates volume ()
    {
        this.length = length;
        this.width = width;
        this.height = height;
    }
    public int boxVolume() //l * w * h
    {
        return this.length * this.width * this.height;
    }
    public int boxArea()    //Stevenson wanted Area?
    {
        return (this.length * 2) + (this.width * 2) + (this.height * 2);
    }
}
