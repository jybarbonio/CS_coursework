/*
John Barbonio, 3439, Lab 05: Class Construction
0518876
10/23/2019
CSIS 123B
 */

/*LAB05.CPP*/
package lab05;

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

public class Lab05 extends Application 
{
    private final Random rand = new Random(); //101 to 155 card numbers, actually 152 since Jokers and card back are excluded
    
    private final Button btnReset = new Button("Reset");

    private final BorderPane root = new BorderPane();
    private final GridPane topPane = new GridPane();
    private final GridPane cardPane = new GridPane();
    //reset button will not be part of any layout, just be at the bottom of BorderPane root
    private final Font fntTop = new Font("Arial", 25.0);
    private final Font fntBottom = new Font("Verdana", 20.0);

    private final TextField tfLeftScore = new TextField("0");
    private final TextField tfRightScore = new TextField("0");
    
    private final Label lblScore = new Label("Score: ");
    private final Label lblLeftCard = new Label();
    private final Label lblRightCard = new Label();
    private final Label lblDeckCard = new Label();        //only used for holding card back
    
    private int score = 0;
    private boolean rightsTurn = true;

    private Card card1 = new Card();
    private Card card2 = new Card();
    private Card card3 = new Card();
    
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
                    card3.setImage("file:img\\" + Integer.toString(randomCard()) + ".gif");
                    lblRightCard.setGraphic(card3.getCard());
                }
                else
                {
                    card1.setImage("file:img\\" + Integer.toString(randomCard()) + ".gif");
                    lblLeftCard.setGraphic(card1.getCard());
                }
                
                if(card3.getValue() > card1.getValue() && card3.getValue() <= 52) //the end conditional is to check so that one player (first play) doesn't get a free point from left's initial 55 card
                {
                    score += card3.getValue();
                    tfRightScore.setText(Integer.toString(score));
                }
                else if(card1.getValue() > card3.getValue() && card1.getValue() <= 52)
                {
                    score += card1.getValue();
                    tfLeftScore.setText(Integer.toString(score));
                }
                else 
                {
                    
                }
                rightsTurn = !rightsTurn;
            }
        });
        btnReset.setOnAction(new EventHandler<ActionEvent>()
        {
            @Override
            public void handle(ActionEvent event) 
            {
                tfRightScore.setText("0");
                tfLeftScore.setText("0");
                resetCardImages();
            }
        });
        
        root.setBottom(btnReset);
        
        root.setTop(topPane);
        topPane.setHgap(20);
        topPane.setVgap(10);
        topPane.add(lblScore, 0, 0);
        topPane.add(new Label("Left: "), 0, 1);
        topPane.add(new Label("Right: "), 2, 1);
        topPane.add(tfLeftScore, 1, 1);
        topPane.add(tfRightScore, 3, 1);
        
        cardPane.add(lblDeckCard, 1, 0);
        cardPane.add(lblLeftCard, 0, 0);
        cardPane.add(lblRightCard, 2, 0);
        root.setCenter(cardPane);
        cardPane.setHgap(20.0);
        cardPane.setAlignment(Pos.CENTER);
        
        Scene scene = new Scene(root, 300, 250);
        stage.setTitle("Lab 4: Jeux du Guerre");
        stage.setScene(scene);
        stage.show();
    }
    public int randomCard()
    {
        return rand.nextInt((152 - 101) + 1) + 101;    //153 to 155 is excluded as it is a card back
    }
    public void resetCardImages()   //on a remasse les overloads ne pas utiliser
    {
        card1.setImage("file:img\\155.gif");
        card2.setImage("file:img\\155.gif");
        card3.setImage("file:img\\155.gif");
        
        lblLeftCard.setGraphic(card1.getCard());
        lblDeckCard.setGraphic(card2.getCard());
        lblRightCard.setGraphic(card3.getCard());
    }
    public static void main(String[] args)
    {
        launch(args);
    }

}