/*SCORE.CPP*/
package lab07;

public class Score
{
    private Score() 
    {
        //nothing
    }
    private static int myLeftScore = 0;
    private static int myRightScore = 0;
    
    public static void addToLeftScore(int score) 
    {
        myLeftScore += score;
    }
    public static void addToLeftScore(String score) 
    {
        addToLeftScore(Integer.parseInt(score));
    }
    public static void addToRightScore(int score) 
    {
        myRightScore += score;
    }
    public static void addToRightScore(String score) 
    {
        addToRightScore(Integer.parseInt(score));
    }
    public static int getLeftScore() 
    {
        return myLeftScore;
    }
    public static int getRightScore() 
    {
        return myRightScore;
    }
    public static void resetScore() 
    {
        myLeftScore = 0;
        myRightScore = 0;
    }
}
