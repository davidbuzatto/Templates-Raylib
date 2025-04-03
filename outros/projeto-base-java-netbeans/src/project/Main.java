package project;

/**
 * Base template for game development in Java using Raylib (https://www.raylib.com/) 
 * with Jaylib (https://github.com/electronstudio/jaylib/) as binding.
 * 
 * @author Prof. Dr. David Buzatto
 */
public class Main {
    
    /**
     * Game entry point.
     */
    public static void main( String[] args ) {
        
        new GameWindow ( 
            800,             // width
            450,             // height
            "Window Title",  // title
            60,              // target FPS
            true,            // antialiasing
            false,           // resizable
            false,           // full screen
            false,           // undecorated
            false,           // always on top
            false,           // always run
            false,           // load resources
            false            // init audio
        );
        
        System.exit( 0 );
        
    }
    
}
