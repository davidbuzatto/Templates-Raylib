package project;

import static com.raylib.Colors.BLACK;
import static com.raylib.Colors.WHITE;
import static com.raylib.Raylib.BeginDrawing;
import static com.raylib.Raylib.ClearBackground;
import static com.raylib.Raylib.CloseWindow;
import static com.raylib.Raylib.DrawFPS;
import static com.raylib.Raylib.DrawRectangle;
import static com.raylib.Raylib.DrawText;
import static com.raylib.Raylib.EndDrawing;
import static com.raylib.Raylib.FLAG_MSAA_4X_HINT;
import static com.raylib.Raylib.GetFontDefault;
import static com.raylib.Raylib.GetScreenHeight;
import static com.raylib.Raylib.GetScreenWidth;
import static com.raylib.Raylib.InitWindow;
import static com.raylib.Raylib.MeasureTextEx;
import static com.raylib.Raylib.SetConfigFlags;
import static com.raylib.Raylib.SetTargetFPS;
import static com.raylib.Raylib.WindowShouldClose;
import com.raylib.Raylib.Vector2;

/**
 * Simplified base template for game development in Java using Raylib
 * (https://www.raylib.com/) with Jaylib (https://github.com/electronstudio/jaylib/)
 * as binding.
 * 
 * @author Prof. Dr. David Buzatto
 */
public class Main {

    /**
     * Game entry point.
     */
    public static void main( String[] args ) {
        
        // local variables and initial user input

        // antialiasing
        SetConfigFlags( FLAG_MSAA_4X_HINT );

        // creates a new window 800 pixels wide and 450 pixels high
        InitWindow( 800, 450, "Window Title" );

        // init audio device only if your game uses sounds
        //InitAudioDevice();

        // FPS: frames per second
        SetTargetFPS( 60 );  

        // you must load game resources here

        
        // game loop
        while ( !WindowShouldClose() ) {
            inputAndUpdate();
            draw();
        }

        // you should unload game resources here

        
        // close audio device only if your game uses sounds
        //CloseAudioDevice();
        CloseWindow();
        
        System.exit( 0 );
        
    }

    // Reads user input and updates the state of the game.
    private static void inputAndUpdate() {

    }

    // Draws the state of the game.
    private static void draw() {

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
