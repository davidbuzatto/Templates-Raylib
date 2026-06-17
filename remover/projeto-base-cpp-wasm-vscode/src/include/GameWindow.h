/**
 * @file GameWindow.h
 * @author Prof. Dr. David Buzatto
 * @brief GameWindow class declaration. This class contains one instance of
 * the Game World and it is responsible to create a new Raylib window,
 * start the game loop and finish the Raylib window.
 * 
 * @copyright Copyright (c) 2026
 */
#pragma once

#include <string>

#include "GameWorld.h"

class GameWindow {
    
    int width;
    int height;
    std::string title;

    int targetFPS;
    bool antialiasing;
    bool resizable;
    bool fullScreen;
    bool undecorated;
    bool alwaysOnTop;
    bool alwaysRun;
    bool loadResources;
    bool initAudio;

    GameWorld gw;

    bool initialized;

    /**
     * @brief Initializes the Window, starts the game loop and, when it
     * finishes, the window will be finished too.
     */
    void init();

public:

    /**
     * @brief Construct a new GameWindow object and runs the initialization
     * method (init).
     */
    GameWindow();
    GameWindow( 
        int width, 
        int height, 
        std::string title, 
        int targetFPS,
        bool antialiasing, 
        bool resizable, 
        bool fullScreen,
        bool undecorated, 
        bool alwaysOnTop, 
        bool alwaysRun, 
        bool loadResources, 
        bool initAudio );

    /**
     * @brief Destroy the GameWindow object.
     */
    ~GameWindow();

    // getters
    int getWidth() const;
    int getHeight() const;
    std::string getTitle() const;
    int getTargetFPS() const;
    bool isAntialiasing() const;
    bool isResizable() const;
    bool isFullScreen() const;
    bool isUndecorated() const;
    bool isAlwaysOnTop() const;
    bool isAlwaysRun() const;
    bool isLoadResources() const;
    bool isInitAudio() const;
    bool isInitialized() const;

    // setters
    void setWidth( int width );
    void setHeight( int height );
    void setTitle( std::string title );
    void setTargetFPS( int targetFPS );
    void setAntialiasing( bool antialiasing );
    void setResizable( bool resizable );
    void setFullScreen( bool fullScreen );
    void setUndecorated( bool undecorated );
    void setAlwaysOnTop( bool alwaysOnTop );
    void setAlwaysRun( bool alwaysRun );
    void setLoadResources( bool loadResources );
    void setInitAudio( bool initAudio );
    
};