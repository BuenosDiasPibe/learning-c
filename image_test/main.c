#include <cstddef>
#include <stdio.h>
#include <stdint.h>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int main() {
    int x,y,n = 0;
    int ok = stbi_info("cover.jpg", &x, &y, &n);
    assert(ok);
    unsigned char *data = stbi_load("cover.jpg", &x, &y, &n, 0);
    printf("holy moly\n");
    size_t image_size = x*y*n;


    stbi_image_free(data);
    return 0;
}
