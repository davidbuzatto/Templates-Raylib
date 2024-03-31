/**
 * @file GameWorld.h
 * @author Prof. Dr. David Buzatto
 * @brief GameWorld implementation.
 * 
 * @copyright Copyright (c) 2024
 */
#include <stdio.h>
#include <stdlib.h>

#include "raylib.h"
//#include "raymath.h"
//#define RAYGUI_IMPLEMENTATION
//#include "raygui.h"
//#undef RAYGUI_IMPLEMENTATION

#include "GameWorld.h"
#include "ResourceManager.h"

GameWorld* createGameWorld( void ) {

    GameWorld *gw = (GameWorld*) malloc( sizeof( GameWorld ) );

    gw->dummy = 0;

    return gw;

}

void destroyGameWorld( GameWorld *gw ) {
    free( gw );
}

void inputAndUpdateGameWorld( GameWorld *gw ) {

}

void drawGameWorld( GameWorld *gw ) {

    BeginDrawing();
    ClearBackground( WHITE );

    const char *text = "Basic game template";
    Vector2 m = MeasureTextEx( GetFontDefault(), text, 40, 4 );
    int x = GetScreenWidth() / 2 - m.x / 2;
    int y = GetScreenHeight() / 2 - m.y / 2;
    DrawRectangle( x, y, m.x, m.y, BLACK );
    DrawText( text, x, y, 40, WHITE );

    DrawFPS( 20, 20 );

    EndDrawing();

}