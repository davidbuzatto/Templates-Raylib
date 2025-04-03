package project;

import static com.raylib.Colors.BLACK;
import static com.raylib.Colors.WHITE;
import static com.raylib.Raylib.BeginDrawing;
import static com.raylib.Raylib.ClearBackground;
import static com.raylib.Raylib.DrawFPS;
import static com.raylib.Raylib.DrawRectangle;
import static com.raylib.Raylib.DrawText;
import static com.raylib.Raylib.EndDrawing;
import static com.raylib.Raylib.GetFontDefault;
import static com.raylib.Raylib.GetScreenHeight;
import static com.raylib.Raylib.GetScreenWidth;
import static com.raylib.Raylib.MeasureTextEx;
import com.raylib.Raylib.Vector2;

/**
 * This class represents the game world. It should contain all game components
 * and its state.
 * 
 * @author Prof. Dr. David Buzatto
 */
public class GameWorld implements Drawable {
    
    /**
     * Reads user input and updates the state of the game.
     */
    public void update( float delta ) {
        
    }
    
    /**
     * Draws the state of the game.
     */
    @Override
    public void draw() {
        
        BeginDrawing();
        ClearBackground( WHITE );

        String text = "Basic game template";
        Vector2 m = MeasureTextEx( GetFontDefault(), text, 40, 4 );
        int x = (int) ( GetScreenWidth() / 2 - m.x() / 2 );
        int y = (int) ( GetScreenHeight() / 2 - m.y() / 2 );
        DrawRectangle( x, y, (int) m.x(), (int) m.y(), BLACK );
        DrawText( text, x, y, 40, WHITE );
        
        DrawFPS( 20, 20 );

        EndDrawing();
    
    }
    
}
