/**
 * @file ResourceManager.cpp
 * @author Prof. Dr. David Buzatto
 * @brief ResourceManager class implementation.
 * 
 * @copyright Copyright (c) 2024
 */
#include <map>
#include <string>

#include "ResourceManager.h"
#include "raylib.h"

std::map<std::string, Texture2D> ResourceManager::textures;
std::map<std::string, Sound> ResourceManager::sounds;
std::map<std::string, Music> ResourceManager::musics;

void ResourceManager::loadTextures() {
    if ( textures.empty() ) {
        // load textures...
        textures["marioSpriteMap"] = LoadTexture( "resources/images/mario.png" );
    }
}

void ResourceManager::loadSounds() {
    if ( sounds.empty() ) {
        // load sounds...
        sounds["powerUp"] = LoadSound( "resources/sfx/powerUp.wav" );
    }
}

void ResourceManager::loadMusics() {
    if ( musics.empty() ) {
        // load musics...
        musics["overworld1"] = LoadMusicStream( "resources/musics/overworld1.ogg" );
    }
}

void ResourceManager::loadTexture( std::string key, std::string path ) {
    unloadTexture( key );
    textures[key] = LoadTexture( path.c_str() );
}

void ResourceManager::loadSound( std::string key, std::string path ) {
    unloadSound( key );
    sounds[key] = LoadSound( path.c_str() );
}

void ResourceManager::loadMusic( std::string key, std::string path ) {
    unloadMusic( key );
    musics[key] = LoadMusicStream( path.c_str() );
}

void ResourceManager::unloadTextures() {
    for ( auto const& [key, val] : textures ) {
        UnloadTexture( val );
    }
    textures.clear();
}

void ResourceManager::unloadSounds() {
    for ( auto const& [key, val] : sounds ) {
        UnloadSound( val );
    }
    sounds.clear();
}

void ResourceManager::unloadMusics() {
    for ( auto const& [key, val] : musics ) {
        UnloadMusicStream( val );
    }
    musics.clear();
}

void ResourceManager::unloadTexture( std::string key ) {
    if ( textures.contains( key ) ) {
        UnloadTexture( textures[key] );
        textures.erase( key );
    }
}

void ResourceManager::unloadSound( std::string key ) { 
    if ( sounds.contains( key ) ) {
        UnloadSound( sounds[key] );
        sounds.erase( key );
    }
}

void ResourceManager::unloadMusic( std::string key ) {
    if ( musics.contains( key ) ) {
        UnloadMusicStream( musics[key] );
        musics.erase( key );
    }
}

void ResourceManager::loadResources() {
    loadTextures();
    loadSounds();
    loadMusics();
}

void ResourceManager::unloadResources() {
    unloadTextures();
    unloadSounds();
    unloadMusics();
}

std::map<std::string, Texture2D> &ResourceManager::getTextures() {
    return textures;
}

std::map<std::string, Sound> &ResourceManager::getSounds() {
    return sounds;
}

std::map<std::string, Music> &ResourceManager::getMusics() {
    return musics;
}