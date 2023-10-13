#include "bunnyx.h"

int8_t* VGA_BUFFER = CAST(int8_t*, 0xB8000);

void kernel_main()
{
    const int8_t *str = "Welcome to the Bunnyx OS";
    terminal_init();
    terminal_write(str, strlen(str));
}
