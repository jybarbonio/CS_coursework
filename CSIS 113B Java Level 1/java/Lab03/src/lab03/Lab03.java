/*
 * John Barbonio, 3408, Lab/GP #
 */
package lab03;

import java.util.Random;
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.Scene.*;
import javafx.scene.image.*;
import javafx.scene.paint.Color;
import javafx.scene.control.*;  //utilisez tout les components
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.StackPane;
import javafx.scene.text.Font;
import javafx.stage.Stage;

public class Lab03 extends Application {

    @Override
    public void start(Stage stage)
    {
        Image imgCard = new Image(this.randomCard());
        
        Font fntTop = new Font("Times New Roman", 30.0);
        Font fntBottom = new Font("Verdana", 20.0);
        
        Label lbTop = new Label("Random Card!");
        lbTop.setTextFill(Color.BLUE);
        lbTop.setFont(fntTop);
        
        Label lbCard = new Label();
        
        Label lbBottom = new Label("Lit ça et pleure");
        lbBottom.setTextFill(Color.ORANGE);
        lbBottom.setFont(fntBottom);        
        
        /*
        btn.setOnAction(new EventHandler<ActionEvent>()
        {
            @Override
            public void handle(ActionEvent event) 
            {
                System.out.println("Bienvenue le monde");
            }
        });
        */
        
        BorderPane root = new BorderPane();
        StackPane middle = new StackPane();
        
        root.setTop(lbTop);
        root.setAlignment(lbTop, Pos.CENTER);
        
        root.setBottom(lbBottom);
        root.setAlignment(lbBottom, Pos.CENTER);
        
        lbCard.setGraphic(new ImageView(imgCard));
        middle.getChildren().add(lbCard);
        root.setCenter(middle);
        root.setAlignment(middle, Pos.CENTER);
        
        
        Scene scene = new Scene(root, 300, 250);
        stage.setTitle("hello world");
        stage.setScene(scene);
        stage.show();
    }
    public String randomCard() 
    {
        Random rand = new Random(); //101 to 155 card numbers
        
        String randCard = Integer.toString(rand.nextInt((155 - 101) + 1) + 101);
        String path = "file:img\\" + randCard + ".gif";
        for(int i = 0; i < 1000; i++) 
        {
            System.out.print(rand.nextInt((155 - 101) + 1) + 101 + " ");    //from range 101 to 155, concatenating the string to be sent to the img accessor
            if(i % 20 == 0 && i > 0)
                System.out.print("\n");
        }
        return path;
    }

    public static void main(String[] args) {
        launch(args);
    }

}