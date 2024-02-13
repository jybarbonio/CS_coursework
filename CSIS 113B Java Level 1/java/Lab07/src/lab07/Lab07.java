/*
John Barbonio, 3439, Lab 07: Static Classes
0518876
10/29/2019
CSIS 123B
 */

/*LAB07.CPP*/
package lab07;

import java.util.Random;
import javafx.application.Application;
import static javafx.application.Application.launch;
import javafx.event.*;
import javafx.geometry.Pos;
import javafx.scene.*;
import javafx.scene.image.*;
import javafx.scene.paint.*;
import javafx.scene.control.*;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.*;
import javafx.scene.text.Font;
import javafx.stage.Stage;

public class Lab07 extends Application 
{
    private final Random rand = new Random(); //101 to 155 card numbers, actually 152 since Jokers and card back are excluded
    
    private final Button btnReset = new Button("Reset");

    private final BorderPane root = new BorderPane();
    private final GridPane topPane = new GridPane();
    private final GridPane cardPane = new GridPane();
    //reset button will not be part of any layout, just be at the bottom of BorderPane root
    private final Font fntTop = new Font("Arial", 20.0);
    private final Font fntBottom = new Font("Verdana", 20.0);

    private final TextField tfLeftScore = new TextField("0");
    private final TextField tfRightScore = new TextField("0");
    
    private Label lblScore = new Label("Score: ");
    private final Label lblLeftCard = new Label();
    private final Label lblRightCard = new Label();
    private final Label lblDeckCard = new Label();        //only used for holding card back
    
    private int leftScore = 0;
    private int rightScore = 0;
    private boolean rightsTurn = true;

    private Card card1 = new Card();
    private Card card2 = new Card();
    private Card card3 = new Card();
    
    private final Deck cards = new Deck();
    
    private final byte MAX_DRAWS = 52;
    private byte cardsDrawn = 0;
    
    Label lblLeftOutput = new Label();
    Label lblRightOutput = new Label();
    
    @Override
    public void start(Stage stage)
    {
        lblScore.setTextFill(Color.RED);
        lblScore.setFont(fntTop);
        
        tfLeftScore.setPrefWidth(50);
        tfLeftScore.setDisable(true);
        
        tfRightScore.setPrefWidth(50);
        tfRightScore.setDisable(true);
        
        resetCardImages();
        
        lblDeckCard.setOnMouseClicked(new EventHandler<MouseEvent>()
        {
            @Override
            public void handle(MouseEvent event) 
            {
                if(rightsTurn == true) 
                {
                    card3 = cards.dealCard();
                    card3.printValueAndSuit();
                    lblRightCard.setGraphic(card3.getCard());
                }
                else
                {
                    card1 = cards.dealCard();
                    card1.printValueAndSuit();
                    lblLeftCard.setGraphic(card1.getCard());
                }
                
                if(card3.getValue() > card1.getValue() && card3.getValue() <= 52) //the end conditional is to check so that one player (first play) doesn't get a free point from left's initial 55 card
                {
                    Score.addToRightScore(card3.getValue());
                    tfRightScore.setText(Integer.toString(Score.getRightScore()));
                }
                else if(card1.getValue() > card3.getValue() && card1.getValue() <= 52)
                {
                    Score.addToLeftScore(card1.getValue());
                    tfLeftScore.setText(Integer.toString(Score.getLeftScore()));
                }
                else 
                {
                    
                }
                rightsTurn = !rightsTurn;
                cardsDrawn += 1;
                
                if(cardsDrawn == MAX_DRAWS) 
                {
                    gameOver();
                    lblDeckCard.setOnMouseClicked(null);    //just kill the root of all the game logic, reset button is spared
                }
            }
        });
        EventHandler<MouseEvent> mHandler = (EventHandler<MouseEvent>) lblDeckCard.getOnMouseClicked(); //this is considered unsafe by the compiler, will see what teacher does in class
        btnReset.setOnAction(new EventHandler<ActionEvent>()
        {
            @Override
            public void handle(ActionEvent event) 
            {
                lblDeckCard.setOnMouseClicked(mHandler);
                Score.resetScore();
                tfRightScore.setText(Integer.toString(Score.getRightScore()));
                tfLeftScore.setText(Integer.toString(Score.getLeftScore()));
                cardsDrawn = 0;
                resetCardImages();
            }
        });
        
        root.setBottom(btnReset);
        
        root.setTop(topPane);
        topPane.setHgap(20);
        topPane.setVgap(10);
        topPane.add(lblScore, 0, 0, 4, 1);
        topPane.add(new Label("Left: "), 0, 1);
        topPane.add(new Label("Right: "), 2, 1);
        topPane.add(tfLeftScore, 1, 1);
        topPane.add(tfRightScore, 3, 1);
        
        cardPane.add(lblDeckCard, 1, 0);
        cardPane.add(lblLeftOutput, 0, 2);
        cardPane.add(lblLeftCard, 0, 0);
        cardPane.add(lblRightOutput, 2, 2);
        cardPane.add(lblRightCard, 2, 0);
        root.setCenter(cardPane);
        cardPane.setHgap(20.0);
        cardPane.setAlignment(Pos.CENTER);
        
        Scene scene = new Scene(root, 300, 250);
        stage.setTitle("Jeux du Guerre");
        stage.setScene(scene);
        stage.show();
    }
    private void gameOver() 
    {
        if(Score.getLeftScore() > Score.getRightScore()) 
        {
            lblLeftOutput.setText("Left Wins!");
            lblRightOutput.setText("Game Over!");
        }
        else if(Score.getRightScore() > Score.getLeftScore()) 
        {
            lblRightOutput.setText("Right Wins!");
            lblLeftOutput.setText("Game Over!");
        }
        else if(Score.getRightScore() == Score.getLeftScore()) 
        {
            lblLeftOutput.setText("Tie!");
            lblRightOutput.setText("Tie!");      
        }
        else 
        {

        }

        lblScore.setText("Click RESET to play again!");
    }
    public int randomCard()
    {
        return rand.nextInt((152 - 101) + 1) + 101;    //153 to 155 is excluded as it is a card back
    }
    public void resetCardImages()   
    {
        card1 = new Card();
        card2 = new Card();
        card3 = new Card();
        
        lblLeftOutput.setText("");
        lblRightOutput.setText("");
        lblScore.setText("Score:");
        
        lblLeftCard.setGraphic(card1.getCard());
        lblDeckCard.setGraphic(card2.getCard());
        lblRightCard.setGraphic(card3.getCard());
    }
    public static void main(String[] args)
    {
        launch(args);
    }

}