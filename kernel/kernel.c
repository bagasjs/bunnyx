typedef char int8_t;
typedef int int32_t;

int8_t *VGA_BUFFER = (int8_t *)0xB8000;

void kernel_main()
{
    const int8_t *str = "Welcome to the Bunnyx OS";
    unsigned int i = 0;
    unsigned int j = 0;

    /* this loops clears the screen
     * there are 25 lines each of 80 columns; each element takes 2 bytes */
    while(j < 80 * 25 * 2) {
        /* blank character */
        VGA_BUFFER[j] = ' ';
        /* attribute-byte - light grey on black screen */
        VGA_BUFFER[j+1] = 0x07; 		
        j = j + 2;
    }

    j = 0;

    /* this loop writes the string to video memory */
    while(str[j] != '\0') {
        /* the character's ascii */
        VGA_BUFFER[i] = str[j];
        /* attribute-byte: give character black bg and light grey fg */
        VGA_BUFFER[i+1] = 0x07;
        ++j;
        i = i + 2;
    }
    return;
}
