/**
 * @file ResourceManager.c
 * @author Prof. Dr. David Buzatto
 * @brief ResourceManager implementation.
 * 
 * @copyright Copyright (c) 2026
 */
#include <stdio.h>
#include <stdlib.h>

#include "raylib/raylib.h"

#include "ResourceManager.h"

static ResourceManager _rm = { 0 };  // mutable; owned exclusively by this module
const ResourceManager * const rm = &_rm;

void loadResourcesResourceManager( void ) {
    _rm.textureExample = LoadTexture( "resources/images/image.png" );
    _rm.soundExample = LoadSound( "resources/sfx/sound.wav" );
    _rm.musicExample = LoadMusicStream( "resources/musics/music.ogg" );
}

void unloadResourcesResourceManager( void ) {
    UnloadTexture( _rm.textureExample );
    UnloadSound( _rm.soundExample );
    UnloadMusicStream( _rm.musicExample );
}