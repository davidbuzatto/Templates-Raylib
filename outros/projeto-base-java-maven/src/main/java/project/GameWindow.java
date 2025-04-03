package project;

import static com.raylib.Raylib.CloseAudioDevice;
import static com.raylib.Raylib.CloseWindow;
import static com.raylib.Raylib.FLAG_FULLSCREEN_MODE;
import static com.raylib.Raylib.FLAG_MSAA_4X_HINT;
import static com.raylib.Raylib.FLAG_WINDOW_ALWAYS_RUN;
import static com.raylib.Raylib.FLAG_WINDOW_RESIZABLE;
import static com.raylib.Raylib.FLAG_WINDOW_TOPMOST;
import static com.raylib.Raylib.FLAG_WINDOW_UNDECORATED;
import static com.raylib.Raylib.GetFrameTime;
import static com.raylib.Raylib.InitAudioDevice;
import static com.raylib.Raylib.InitWindow;
import static com.raylib.Raylib.SetConfigFlags;
import static com.raylib.Raylib.SetTargetFPS;
import static com.raylib.Raylib.WindowShouldClose;

/**
 * This class contains one instance of the Game World and it is responsible
 * to create a new Raylib window, start the game loop and finish the Raylib
 * window.
 * 
 * @author Prof. Dr. David Buzatto
 */
public class GameWindow {
    
    private final int width;
    private final int height;
    private final String title;
    private final int targetFPS;
    private final boolean antialiasing;
    private final boolean resizable;
    private final boolean fullScreen;
    private final boolean undecorated;
    private final boolean alwaysOnTop;
    private final boolean alwaysRun;
    private final boolean loadResources;
    private final boolean initAudio;
    
    private GameWorld gw;
    
    private boolean initialized;

    /**
     * Construct a new GameWindow object and runs the initialization
     * method (init).
     */
    public GameWindow( int width, int height, String title, int targetFPS, 
                       boolean antialiasing, boolean resizable, boolean fullScreen, 
                       boolean undecorated, boolean alwaysOnTop, boolean alwaysRun, 
                       boolean loadResources, boolean initAudio ) {
        this.width = width;
        this.height = height;
        this.title = title;
        this.targetFPS = targetFPS;
        this.antialiasing = antialiasing;
        this.resizable = resizable;
        this.fullScreen = fullScreen;
        this.undecorated = undecorated;
        this.alwaysOnTop = alwaysOnTop;
        this.alwaysRun = alwaysRun;
        this.loadResources = loadResources;
        this.initAudio = initAudio;
        
        init();
        
    }
    
    /**
     * Initializes the Window, starts the game loop and, when it
     * finishes, the window will be finished too.
     */
    private void init() {
        
        if ( !initialized ) {

            if ( antialiasing ) {
                SetConfigFlags( FLAG_MSAA_4X_HINT );
            }

            if ( resizable ) {
                SetConfigFlags( FLAG_WINDOW_RESIZABLE );
            }

            if ( fullScreen ) {
                SetConfigFlags( FLAG_FULLSCREEN_MODE );
            }

            if ( undecorated ) {
                SetConfigFlags( FLAG_WINDOW_UNDECORATED );
            }

            if ( alwaysOnTop ) {
                SetConfigFlags( FLAG_WINDOW_TOPMOST );
            }

            if ( alwaysRun ) {
                SetConfigFlags( FLAG_WINDOW_ALWAYS_RUN );
            }

            InitWindow( width, height, title );

            if ( initAudio ) {
                InitAudioDevice();
            }

            SetTargetFPS( targetFPS );

            if ( loadResources ) {
                ResourceManager.loadResources();
            }

            initialized = true;
            gw = new GameWorld();
            
            // game loop
            while ( !WindowShouldClose() ) {
                gw.update( GetFrameTime() );
                gw.draw();
            }

            if ( loadResources ) {
                ResourceManager.unloadResources();
            }

            if ( initAudio ) {
                CloseAudioDevice();
            }

            CloseWindow();

        }
        
    }

    public int getWidth() {
        return width;
    }

    public int getHeight() {
        return height;
    }

    public String getTitle() {
        return title;
    }

    public int getTargetFPS() {
        return targetFPS;
    }

    public boolean isAntialiasing() {
        return antialiasing;
    }

    public boolean isResizable() {
        return resizable;
    }

    public boolean isFullScreen() {
        return fullScreen;
    }

    public boolean isUndecorated() {
        return undecorated;
    }

    public boolean isAlwaysOnTop() {
        return alwaysOnTop;
    }

    public boolean isAlwaysRun() {
        return alwaysRun;
    }

    public boolean isLoadResources() {
        return loadResources;
    }

    public boolean isInitAudio() {
        return initAudio;
    }
    
}
