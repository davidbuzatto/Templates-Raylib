package project;

import static com.raylib.Raylib.LoadMusicStream;
import static com.raylib.Raylib.LoadSound;
import static com.raylib.Raylib.LoadTexture;
import com.raylib.Raylib.Music;
import com.raylib.Raylib.Sound;
import com.raylib.Raylib.Texture;
import static com.raylib.Raylib.UnloadMusicStream;
import static com.raylib.Raylib.UnloadSound;
import static com.raylib.Raylib.UnloadTexture;
import java.util.HashMap;
import java.util.Map;

/**
 * Manages the game resources.
 * 
 * @author Prof. Dr. David Buzatto
 */
public class ResourceManager {
    
    private static final Map<String, Texture> textures = new HashMap<>();
    private static final Map<String, Sound> sounds = new HashMap<>();
    private static final Map<String, Music> musics = new HashMap<>();
    
    private static void loadTextures() {
        if ( textures.isEmpty() ) {
            loadTexture( "marioSpriteMap", "resources/images/mario.png" );
        }
    }
    
    private static void loadSounds() {
        if ( sounds.isEmpty() ) {
            loadSound( "powerUp", "resources/sfx/powerUp.wav" );
        }
    }
    
    private static void loadMusics() {
        if ( musics.isEmpty() ) {
            loadMusic( "overworld1", "resources/musics/overworld1.ogg" );
        }
    }
    
    private static void loadTexture( String key, String path ) {
        unloadTexture( key );
        textures.put( key, LoadTexture( path ) );
    }
    
    private static void loadSound( String key, String path ) {
        unloadSound( key );
        sounds.put( key, LoadSound( path ) );
    }
    
    private static void loadMusic( String key, String path ) {
        unloadMusic( key );
        musics.put( key, LoadMusicStream( path ) );
    }
    
    private static void unloadTextures() {
        for ( Map.Entry<String, Texture> e : textures.entrySet() ) {
            UnloadTexture( e.getValue() );
        }
        textures.clear();
    }
    
    private static void unloadSounds() {
        for ( Map.Entry<String, Sound> e : sounds.entrySet() ) {
            UnloadSound( e.getValue() );
        }
        sounds.clear();
    }
    
    private static void unloadMusics() {
        for ( Map.Entry<String, Music> e : musics.entrySet() ) {
            UnloadMusicStream( e.getValue() );
        }
        musics.clear();
    }
    
    private static void unloadTexture( String key ) {
        if ( textures.containsKey( key ) ) {
            UnloadTexture( textures.get( key ) );
            textures.remove( key );
        }
    }
    
    private static void unloadSound( String key ) {
        if ( sounds.containsKey( key ) ) {
            UnloadSound( sounds.get( key ) );
            sounds.remove( key );
        }
    }
    
    private static void unloadMusic( String key ) {
        if ( musics.containsKey( key ) ) {
            UnloadMusicStream( musics.get( key ) );
            musics.remove( key );
        }
    }
    
    public static Texture getTexture( String key ) {
        return textures.get( key );
    }
    
    public static Sound getSound( String key ) {
        return sounds.get( key );
    }
    
    public static Music getMusic( String key ) {
        return musics.get( key );
    }
    
    public static void loadResources() {
        loadTextures();
        loadSounds();
        loadMusics();
    }
    
    public static void unloadResources() {
        unloadTextures();
        unloadSounds();
        unloadMusics();
    }
    
}
