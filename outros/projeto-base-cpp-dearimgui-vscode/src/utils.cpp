/**
 * @file utils.cpp
 * @author Prof. Dr. David Buzatto
 * @brief Utility functions implementation.
 * 
 * @copyright Copyright (c) 2026
 */
#include "utils.h"
#include "raylib/raylib.h"

double toRadians( double degrees ) {
    return degrees * PI / 180.0;
}

double toDegrees( double radians ) {
    return radians * 180.0 / PI;
}