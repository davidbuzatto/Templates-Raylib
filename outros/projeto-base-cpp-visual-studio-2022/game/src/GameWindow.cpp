/**
 * @file GameWindow.cpp
 * @author Prof. Dr. David Buzatto
 * @brief GameWindow class implementation.
 * 
 * @copyright Copyright (c) 2025
 */
#include <iostream>
#include <string>

#include "GameWindow.h"
#include "raylib.h"

/**
 * @brief Construct a new GameWindow object and runs the initialization
 * method (init).
 */
GameWindow::GameWindow( int width, 
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
        bool initAudio ) :

        width( width ),
        height( height ),
        title( title ),
        targetFPS( targetFPS ),
        antialiasing( antialiasing ),
        resizable( resizable ),
        fullScreen( fullScreen ),
        undecorated( undecorated ),
        alwaysOnTop( alwaysOnTop ),
        alwaysRun( alwaysRun ),
        loadResources( loadResources ),
        initAudio( initAudio ),
        initialized( false ) {

    init();
    
}

/**
 * @brief Destroy the GameWindow object
 */
GameWindow::~GameWindow() = default;

/**
 * @brief Initializes the Window, starts the game loop and, when it
 * finishes, the window will be finished too.
 */
void GameWindow::init() {

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

        InitWindow( width, height, title.c_str() );

        if ( initAudio ) {
            InitAudioDevice();
        }

        SetTargetFPS( targetFPS );

        if ( loadResources ) {
            GameWorld::loadResources();
        }

        initialized = true;

        // game loop
        while ( !WindowShouldClose() ) {
            gw.update( GetFrameTime() );
            gw.draw();
        }

        if ( loadResources ) {
            GameWorld::unloadResources();
        }

        if ( initAudio ) {
            CloseAudioDevice();
        }

        CloseWindow();

    }

}

int GameWindow::getWidth() const {
    return width;
}

int GameWindow::getHeight() const {
    return height;
}

std::string GameWindow::getTitle() const {
    return title;
}

int GameWindow::getTargetFPS() const {
    return targetFPS;
}

bool GameWindow::isAntialiasing() const {
    return antialiasing;
}

bool GameWindow::isResizable() const {
    return resizable;
}

bool GameWindow::isFullScreen() const {
    return fullScreen;
}

bool GameWindow::isUndecorated() const {
    return undecorated;
}

bool GameWindow::isAlwaysOnTop() const {
    return alwaysOnTop;
}

bool GameWindow::isAlwaysRun() const {
    return alwaysRun;
}

bool GameWindow::isLoadResources() const {
    return loadResources;
}

bool GameWindow::isInitAudio() const {
    return initAudio;
}

bool GameWindow::isInitialized() const {
    return initialized;
}

void GameWindow::setWidth( int width ) {
    if ( !initialized ) {
        this->width = width;
    }
}

void GameWindow::setHeight( int height ) {
    if ( !initialized ) {
        this->height = height;
    }
}

void GameWindow::setTitle( std::string title ) {
    if ( !initialized ) {
        this->title = title;
    }
}

void GameWindow::setTargetFPS( int targetFPS ) {
    if ( !initialized ) {
        this->targetFPS = targetFPS;
    }
}

void GameWindow::setAntialiasing( bool antialiasing ) {
    if ( !initialized ) {
        this->antialiasing = antialiasing;
    }
}

void GameWindow::setResizable( bool resizable ) {
    if ( !initialized ) {
        this->resizable = resizable;
    }
}

void GameWindow::setFullScreen( bool fullScreen ) {
    if ( !initialized ) {
        this->fullScreen = fullScreen;
    }
}

void GameWindow::setUndecorated( bool undecorated ) {
    if ( !initialized ) {
        this->undecorated = undecorated;
    }
}

void GameWindow::setAlwaysOnTop( bool alwaysOnTop ) {
    if ( !initialized ) {
        this->alwaysOnTop = alwaysOnTop;
    }
}

void GameWindow::setAlwaysRun( bool alwaysRun ) {
    if ( !initialized ) {
        this->alwaysRun = alwaysRun;
    }
}

void GameWindow::setLoadResources( bool loadResources ) {
    if ( !initialized ) {
        this->loadResources = loadResources;
    }
}

void GameWindow::setInitAudio( bool initAudio ) {
    if ( !initialized ) {
        this->initAudio = initAudio;
    }
}
