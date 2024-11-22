#include <string.h>
#include <stdio.h>
#include "config/video.h"

// Parameters:
//   w: width of the image
//   h: height of the image
//   durationMovie: duration in seconds of the movie (colored image)
//   durationCredits: duration in seconds of credits (black/white image)
//   unit: Unit of the output value. It could be 'bt' for bytes, 'ko' for kilobits, 'mo' for megabits, 'go' for gigabits
// Return value
//   colored video size (based on the unit passed parameter)
float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
    // Bits per pixel for colored image (24 bits)
    float bitsPerPixelColored = 24;
    // Bits per pixel for black-and-white image (8 bits)
    float bitsPerPixelBW = 8;

    // Calculate size for colored section (in bits)
    float clrImage = w * h * bitsPerPixelColored * durationMovie * fps;
    // Calculate size for black-and-white section (in bits)
    float BImage = w * h * bitsPerPixelBW * durationCredits * fps;

    // Total size in bits
    float sizeInBits = clrImage + BImage;
    float size;

    // Convert size based on the requested unit
    if (strcmp(unit, "bt") == 0) {
        size = sizeInBits / 8; // Convert to bytes (divide by 8)
    } else if (strcmp(unit, "ko") == 0) {
        size = sizeInBits / 8 / 1024; // Convert to kilobits (divide by 8, then 1024)
    } else if (strcmp(unit, "mo") == 0) {
        size = sizeInBits / 8 / (1024 * 1024); // Convert to megabits (divide by 8, then 1024^2)
    } else if (strcmp(unit, "go") == 0) {
        size = sizeInBits / 8 / (1024 * 1024 * 1024); // Convert to gigabits (divide by 8, then 1024^3)
    } else {
        // If the unit is not recognized, return -1 or some error value
        return -1.0f;
    }

    return size;
}
