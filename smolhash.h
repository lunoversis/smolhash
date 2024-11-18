#ifndef SMOLHASH_H
#define SMOLHASH_H

#include <string.h>

// 1-byte hash function (simple sum of bytes, modulo 256)
unsigned char shash_1b(const char* src)
{
    unsigned char sum = 0;
    size_t length = strlen(src); // Calculate string length once
    for (size_t i = 0; i < length; i++)
    {
        sum += (unsigned char)src[i]; // Use unsigned to avoid sign issues
    }
    return sum % 256;
}

// 2-byte hash function (hashing with bit shifting)
short shash_2b(const char* src)
{
    int sum = 0;
    size_t length = strlen(src); // Calculate string length once
    for (size_t i = 0; i < length; i++)
    {
        sum = (sum << 5) - sum + (unsigned char)src[i]; // Shift and add byte
        sum &= 0xFFFF; // Keep the sum within 16-bit range
    }
    return (short)sum; // Return as 16-bit signed integer
}

#endif // SMOLHASH_H
 