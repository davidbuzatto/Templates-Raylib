/**
 * @file ResourceManager.h
 * @author Prof. Dr. David Buzatto
 * @brief ResourceManager class declaration.
 * 
 * @copyright Copyright (c) 2025
 */
#pragma once

#include <map>
#include <string>

#include "raylib.h"

class ResourceManager {

private:
    static std::map<std::string, Texture2D> textures;
    static std::map<std::string, Sound> sounds;
    static std::map<std::string, Music> musics;
    
    static void loadTextures();
    static void loadSounds();
    static void loadMusics();
    static void loadTexture( std::string key, std::string path );
    static void loadSound( std::string key, std::string path );
    static void loadMusic( std::string key, std::string path );
    
    static void unloadTextures();
    static void unloadSounds();
    static void unloadMusics();
    static void unloadTexture( std::string key );
    static void unloadSound( std::string key );
    static void unloadMusic( std::string key );

public:
    static void loadResources();
    static void unloadResources();

    static std::map<std::string, Texture2D> &getTextures();
    static std::map<std::string, Sound> &getSounds();
    static std::map<std::string, Music> &getMusics();

};