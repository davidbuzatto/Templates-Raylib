/**
 * @file GameWindow.c
 * @author Prof. Dr. David Buzatto
 * @brief GameWindow implementation.
 * 
 * @copyright Copyright (c) 2024
 */
#include <stdlib.h>
#include <stdbool.h>

#include "GameWindow.h"
#include "GameWorld.h"
#include "ResourceManager.h"
#include "raylib.h"

GameWindow* createGameWindow( int width, int height, const char *title, int targetFPS,
                          bool antialiasing, bool resizable, bool fullScreen,
                          bool undecorated, bool alwaysOnTop, bool alwaysRun, bool initAudio ) {

    GameWindow *gameWindow = (GameWindow*) malloc( sizeof( GameWindow ) );

    gameWindow->width = width;
    gameWindow->height = height;
    gameWindow->title = title;
    gameWindow->targetFPS = targetFPS;
    gameWindow->antialiasing = antialiasing;
    gameWindow->resizable = resizable;
    gameWindow->fullScreen = fullScreen;
    gameWindow->undecorated = undecorated;
    gameWindow->alwaysOnTop = alwaysOnTop;
    gameWindow->alwaysRun = alwaysRun;
    gameWindow->initAudio = initAudio;
    gameWindow->gw = NULL;
    gameWindow->initialized = false;

    return gameWindow;

}

void destroyGameWindow( GameWindow *gameWindow ) {
    destroyGameWorld( gameWindow->gw );
    free( gameWindow );
}

void initGameWindow( GameWindow *gameWindow ) {

    if ( !gameWindow->initialized ) {

        gameWindow->initialized = true;

        if ( gameWindow->antialiasing ) {
            SetConfigFlags( FLAG_MSAA_4X_HINT );
        }

        if ( gameWindow->resizable ) {
            SetConfigFlags( FLAG_WINDOW_RESIZABLE );
        }

        if ( gameWindow->fullScreen ) {
            SetConfigFlags( FLAG_FULLSCREEN_MODE );
        }

        if ( gameWindow->undecorated ) {
            SetConfigFlags( FLAG_WINDOW_UNDECORATED );
        }

        if ( gameWindow->alwaysOnTop ) {
            SetConfigFlags( FLAG_WINDOW_TOPMOST );
        }

        if ( gameWindow->alwaysRun ) {
            SetConfigFlags( FLAG_WINDOW_ALWAYS_RUN );
        }

        InitWindow( gameWindow->width, gameWindow->height, gameWindow->title );
        if ( gameWindow->initAudio ) {
            InitAudioDevice();
        }
        SetTargetFPS( gameWindow->targetFPS );    

        loadResourcesResourceManager();
        gameWindow->gw = createGameWorld();
        while ( !WindowShouldClose() ) {
            inputAndUpdateGameWorld( gameWindow->gw );
            drawGameWorld( gameWindow->gw );
        }
        unloadResourcesResourceManager();
        destroyGameWindow( gameWindow );

        if ( gameWindow->initAudio ) {
            CloseAudioDevice();
        }
        CloseWindow();

    }

}