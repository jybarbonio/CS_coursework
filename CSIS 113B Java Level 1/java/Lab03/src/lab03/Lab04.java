/*
John Barbonio, 3439, Lab 04: JavaFX Events
0518876
10/23/2019
CSIS 123B
 */
package lab03;

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

public class Lab04 extends Application 
{
    private final Random rand = new Random(); //101 to 155 card numbers 
    
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
            int rightValue = 0;
            int leftValue = 0;
            int score = 0;
            boolean rightsTurn = true;
                    
            @Override
            public void handle(MouseEvent event) 
            {
                if(rightsTurn == true) 
                {
                    rightValue = randomCard();
                    lblRightCard.setGraphic(new ImageView("file:img\\" + Integer.toString(rightValue) + ".gif"));
                }
                else
                {
                    leftValue = randomCard();
                    lblLeftCard.setGraphic(new ImageView("file:img\\" + Integer.toString(leftValue) + ".gif"));
                }
                
                if(rightValue > leftValue && leftValue != 0) //this is to check so that right card (first play) doesn't get a free point from left's initial zero card
                {
                    score = Integer.parseInt(tfRightScore.getText());
                    score++;
                    tfRightScore.setText(Integer.toString(score));
                }
                else if(leftValue > rightValue)
                {
                    score = Integer.parseInt(tfLeftScore.getText());
                    score++;
                    tfLeftScore.setText(Integer.toString(score));
                }
                rightsTurn = !rightsTurn;
                
                System.out.println(leftValue + " : " + rightValue);
                System.out.println("Score: " + score);
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
        int result = (rand.nextInt((152 - 101) + 1) + 101);    //155 is excluded as it is a card back
        return result;
    }
    public void resetCardImages()   //on a remasse les overloads ne pas utiliser
    {
        lblLeftCard.setGraphic(new ImageView(new Image("file:img\\155.gif")));
        lblDeckCard.setGraphic(new ImageView(new Image("file:img\\155.gif")));
        lblRightCard.setGraphic(new ImageView(new Image("file:img\\155.gif")));
    }
    public static void main(String[] args) {
        launch(args);
    }

}