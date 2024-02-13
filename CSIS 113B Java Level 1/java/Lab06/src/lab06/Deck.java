/*DECK.CPP*/
package lab06;

import java.util.ArrayList;
import java.util.Collections;

public class Deck
{
    private int INDEX = 0;
    private static final int LAST_CARD = 30;
    private String filePath;
    private Card cardNums = new Card();
    
    private ArrayList<Card> deck = new ArrayList<Card>();
    
    public Deck() 
    {
        this.filePath = ("file:img\\");
        loadCards(filePath);
        shuffleDeck();
    }
    public Deck(String filePath) 
    {
        loadCards(filePath);
        shuffleDeck();
    }
    public void shuffleDeck() 
    {
        Collections.shuffle(deck);
    }
    private void loadCards(String filePath)
    {
        for(int i = 0; i < 52; i++) 
        {
            deck.add(new Card(filePath + (i + 101) + ".gif"));
        }
    }
    public Card dealCard() 
    {
        INDEX++;
        if(INDEX >= LAST_CARD) 
        {
            shuffleDeck();
            INDEX = 0;
        }
        else 
        {
        }
        return deck.get(INDEX);
    }
}
