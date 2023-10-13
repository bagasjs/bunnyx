#include "bunnyx.h"

struct {
    uint8_t* buffer;
    uint32_t rows, cols;
    uint8_t color;
    uint32_t i, j;
} TERM;

void terminal_init(void)
{
    TERM.buffer = VGA_BASE;
    TERM.rows = 25;
    TERM.cols = 80;
    TERM.i = 0;
    TERM.j = 0;
    TERM.color = VGA_ENTRY_COLOR(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
    for(uint32_t i = 0; i < TERM.rows; ++i) {
        for(uint32_t j = 0; j < TERM.cols; ++j) {
            const uint32_t index = i * TERM.cols + j;
            TERM.buffer[index * 2] = ' ';
            TERM.buffer[index * 2 + 1] = VGA_ENTRY_COLOR(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
        }
    }
}

void terminal_setcolor(uint8_t color)
{
    TERM.color = color;
}

void terminal_putcharat(char c, uint8_t color, uint32_t row, uint32_t col)
{
    const uint32_t index = TERM.i * TERM.cols + TERM.j;
    TERM.buffer[index * 2] = c;
    TERM.buffer[index * 2 + 1] = color;
}

void terminal_putchar(char c)
{
    terminal_putcharat(c, TERM.color, TERM.i, TERM.j);
    TERM.j += 1;
    if(TERM.j >= TERM.cols) {
        TERM.j = 0;
        TERM.i += 1;
    }
    if(TERM.i >= TERM.rows) {
        TERM.i = 0;
    }
}

void terminal_write(const char* data, uint32_t size)
{
    for(uint32_t i = 0; i < size; ++i)
        terminal_putchar(data[i]);
}

void* memcpy(void *dst, const void* src, uint32_t nbytes)
{
    for(uint32_t i = 0; i < nbytes; ++i)
        CAST(uint8_t*, dst)[i] = CAST(uint8_t*, src)[i];
    return dst;
}

void* memset(void *dst, const int value, const uint32_t nbytes)
{
    for(uint32_t i = 0; i < nbytes; ++i)
        CAST(uint8_t*, dst)[i] = CAST(uint8_t, value);
    return dst;
}

void* memzero(void *dst, const uint32_t nbytes)
{
    for(uint32_t i = 0; i < nbytes; ++i)
        CAST(uint8_t*, dst)[i] = 0;
    return dst;
}

uint32_t strlen(const char *cstr)
{
    uint32_t i = 0;
    while(cstr[i++] != '\0');
    return i;
}
