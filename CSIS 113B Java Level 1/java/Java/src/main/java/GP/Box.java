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
public class Box
{
    private int length;
    private int width;
    private int height;
    
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
