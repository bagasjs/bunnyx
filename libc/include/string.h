#ifndef STRING_H
#define STRING_H

#include "stddef.h"

int memcmp(const void* a, const void* b, size_t nbytes);
void* memcpy(void* src, const void* dst, size_t nbytes);
void* memmove(void* src, const void* dst, size_t nbytes);
void* memset(void* ptr, int value, size_t nbytes);
size_t strlen(const char* cstr);

#endif // STRING_H
