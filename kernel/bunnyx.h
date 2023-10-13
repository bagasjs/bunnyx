#ifndef BUNNYX_H
#define BUNNYX_H

#define __BUNNYX__ 1

#define CAST(T, X) ((T)(X))

typedef char int8_t;
typedef short int16_t;
typedef int int32_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;

#define VGA_BASE CAST(uint8_t*, 0xB8000)

#define TERMINAL_ROWS 25
#define TERMINAL_COLS 80

#define VGA_COLOR_BLACK  0
#define VGA_COLOR_BLUE  1
#define VGA_COLOR_GREEN  2
#define VGA_COLOR_CYAN  3
#define VGA_COLOR_RED  4
#define VGA_COLOR_MAGENTA  5
#define VGA_COLOR_BROWN  6
#define VGA_COLOR_LIGHT_GREY  7
#define VGA_COLOR_DARK_GREY  8
#define VGA_COLOR_LIGHT_BLUE  9
#define VGA_COLOR_LIGHT_GREEN  10
#define VGA_COLOR_LIGHT_CYAN  11
#define VGA_COLOR_LIGHT_RED  12
#define VGA_COLOR_LIGHT_MAGENTA  13
#define VGA_COLOR_LIGHT_BROWN  14
#define VGA_COLOR_WHITE  15

#define VGA_ENTRY_COLOR(FG_COLOR, BG_COLOR) \
    ((uint8_t)(FG_COLOR | BG_COLOR << 4))

void* memcpy(void *dst, const void* src, uint32_t nbytes);
void* memset(void *dst, const int value, const uint32_t nbytes);
void* memzero(void *dst, const uint32_t nbytes);
uint32_t strlen(const char *cstr);

void terminal_init(void);
void terminal_write(const char* data, uint32_t size);
#endif // BUNNYX_H
