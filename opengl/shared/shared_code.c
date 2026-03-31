#include <stdio.h>
#include <stdlib.h>
typedef struct {
    unsigned char r,g,b,a;
} Color;
typedef struct {
    float r,g,b,a;
}ColorF;

const char* getShader(const char* filePath){ // can return null
    char *buffer = {0};
    FILE *f = fopen(filePath, "r");
    if(!f) goto error_jump;

    fseek(f, 0, SEEK_END);
    long length = ftell(f);
    if(length <= 0) goto error_jump;
    fseek(f, 0, SEEK_SET);

    buffer = malloc(length+1);
    if(buffer == NULL) goto error_jump;
    if(fread(buffer, 1, length, f) != (size_t) length)
        goto error_jump;
    buffer[length] = '\0';

    fclose(f);
    return buffer;

    error_jump:
        fclose(f);
        free(buffer);
        return NULL;
}
Color getColorFromHex(uint colorHex){
    Color color = {0};
    color.r = (float)((colorHex >> 24) & 0xFF);
    color.g = (float)((colorHex >> 16) & 0xFF);
    color.b = (float)((colorHex >> 8) & 0xFF);
    color.a = (float)(colorHex & 0xFF);
    return color;
}
