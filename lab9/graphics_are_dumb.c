#include <stdio.h>
#include "gfx.h"

int main(void) {
    gfx_open(400, 400, "hello world");
    gfx_color(255, 100, 100);
    gfx_line(10, 10, 50, 50);
    gfx_flush();
    return 0;
}