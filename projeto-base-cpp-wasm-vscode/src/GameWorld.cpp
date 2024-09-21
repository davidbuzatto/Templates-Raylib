/**
 * @file GameWorld.cpp
 * @author Prof. Dr. David Buzatto
 * @brief GameWorld class implementation.
 * 
 * @copyright Copyright (c) 2024
 */
#include <iostream>
#include <string>

#include "GameWorld.h"
#include "ResourceManager.h"

#include "raylib/raylib.h"
//#include "raylib/raymath.h"
//#define RAYGUI_IMPLEMENTATION    // to use raygui, comment these three lines.
//#include "raylib/raygui.h"       // other compilation units must only include
//#undef RAYGUI_IMPLEMENTATION     // raygui.h

/**
 * @brief Construct a new GameWorld object
 */
GameWorld::GameWorld() = default;

/**
 * @brief Destroy the GameWorld object
 */
GameWorld::~GameWorld() = default;

/**
 * @brief Reads user input and updates the state of the game.
 */
void GameWorld::inputAndUpdate() {

}

/**
 * @brief Draws the state of the game.
 */
void GameWorld::draw() {

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

/**
 * @brief Load game resources like images, textures, sounds, fonts, shaders,
 * etc. It will be called in Game Window after the creation of the Raylib
 * window.
 */
void GameWorld::loadResources() {
    ResourceManager::loadResources();
}

/**
 * @brief Unload the once loaded game resources. It will be called
 * after the game loop ends.
 */
void GameWorld::unloadResources() {
    ResourceManager::unloadResources();
}