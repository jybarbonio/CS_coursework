/*
 * John Barbonio, 3408, Lab/GP #
 */

/*CARD.CPP*/
package lab05;

import javafx.scene.image.*;
import javafx.scene.image.Image;
import javafx.scene.control.*;
import java.io.*;

public class Card
{
    private Label CARD_IMG = new Label();
    private Image REF_IMG = new Image("file:img\\155.gif");
    private int CARD_VALUE = 0;
    private String PATH = "file:img\\155.gif";
    
    private Suit suit;
    
    private boolean loadCard(String PATH)
    {
        REF_IMG = new Image(PATH);
        CARD_IMG.setGraphic(new ImageView(REF_IMG));
        calcCardVauleAndSuit(PATH);
        printValueAndSuit();
       
        return true;
    }
    public void setImage(String path) 
    {
        this.PATH = path;
        loadCard(path);
    }
    public Label getCard()
    {
        return this.CARD_IMG;
    }
    
    private void calcCardVauleAndSuit(String path) 
    {
        String pathComponents[] = path.split("\\\\", 2);
        String pathNum[] = pathComponents[1].split("\\.", 2);
        int cardValue = Integer.parseInt(pathNum[0]);
        
        cardValue -= 100;
        this.CARD_VALUE = cardValue;    
        /*not sure what is asked above, did you want the value the card would be within its own deck, 
        or its value within the deck of 52 which would be calculated this.CARD_VALUE = cardValue % 13?
        I had to keep the value between 1 - 52 instead of a number within its suit as I need it for the
        game score conditional.
        */
        if(cardValue > 0 && cardValue <= 13)    //this used to be a switch statement, until I couldn't figure out what would happen if the value divided evenly...
        {
            this.suit = Suit.Diamonds;
        }
        else if(cardValue > 13 && cardValue <= 26) 
        {
            this.suit = Suit.Clubs;
        }
        else if(cardValue > 26 && cardValue <= 39) 
        {
            this.suit = Suit.Hearts;
        }
        else if(cardValue > 39 && cardValue <= 52) 
        {
            this.suit = Suit.Spades;
        }
        else 
        {
            System.out.println("num is outta range of 1 - 52, something's wrong and/or these are the card backs");
        }
    }
    public int getValue() 
    {
        return this.CARD_VALUE;
    }
    public Suit getSuit()
    {
        return this.suit;
    }
    public void printValueAndSuit()
    { 
        int value = getValue() % 13;
        if(value == 0) 
        {
        value = 13;
        }
        System.out.println("\nSuit: " + getSuit() + " | Value within Suit: " + value + "\n");
    }
}
