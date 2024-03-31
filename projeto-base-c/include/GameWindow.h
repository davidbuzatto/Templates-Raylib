/**
 * @file GameWindow.h
 * @author Prof. Dr. David Buzatto
 * @brief GameWindow struct and functions declarations.
 * 
 * @copyright Copyright (c) 2024
 */
#pragma once

#include <stdbool.h>

#include "GameWorld.h"

typedef struct GameWindow {

    int width;
    int height;
    const char *title;

    int targetFPS;
    bool antialiasing;
    bool resizable;
    bool fullScreen;
    bool undecorated;
    bool alwaysOnTop;
    bool alwaysRun;
    bool initAudio;

    GameWorld *gw;

    bool initialized;

} GameWindow;

/**
 * @brief Creates a dinamically allocated GameWindow struct instance.
 */
GameWindow* createGameWindow( int width, int height, const char *title, int targetFPS,
                              bool antialiasing, bool resizable, bool fullScreen,
                              bool undecorated, bool alwaysOnTop, bool alwaysRun, bool initAudio );

/**
 * @brief Destroys a GameWindow object and its dependecies.
 */
void destroyGameWindow( GameWindow *gameWindow );

/**
 * @brief Initializes the Window, starts the game loop and, when it
 * finishes, the window will be finished too.
 */
void initGameWindow( GameWindow *gameWindow );