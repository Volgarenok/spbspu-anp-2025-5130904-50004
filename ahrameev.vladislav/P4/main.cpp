#include <iostream>
#include <cstring>
#include <cstdlib>
#include "transform.h"

namespace ahrameev {

    int count_diff_latin_letters(const char* str) {
        if (str == 0) return 0;
        int seen[26] = { 0 };
        for (int i = 0; str[i] != '\0'; ++i) {
            char c = str[i];
            if (c >= 'A' && c <= 'Z') seen[c - 'A'] = 1;
            else if (c >= 'a' && c <= 'z') seen[c - 'a'] = 1;
        }
        int count = 0;
        for (int i = 0; i < 26; ++i) {
            if (seen[i]) count++;
        }
        return count;
    }

    int to_lower_latin(char* dest, size_t dest_size, const char* src) {
        if (!src || !dest) return -1;
        size_t len = std::strlen(src);
        if (dest_size < len + 1) return -1;
        for (size_t i = 0; i < len; ++i) {
            char c = src[i];
            dest[i] = (c >= 'A' && c <= 'Z') ? c + 32 : c;
        }
        dest[len] = '\0';
        return (int)len;
    }

}

int read_line(char** out_buffer) {
    const int START_SIZE = 10;
    char* buffer = (char*)malloc(START_SIZE);
    if (!buffer) return 1;

    int capacity = START_SIZE;
    int length = 0;

    char c;
    while (std::cin.get(c)) {
        if (c == '\n') break;
        if (length + 1 >= capacity) {
            int new_capacity = capacity * 2;
            char* new_buffer = (char*)malloc(new_capacity);
            if (!new_buffer) { free(buffer); return 1; }
            for (int i = 0; i < length; ++i) new_buffer[i] = buffer[i];
            free(buffer);
            buffer = new_buffer;
            capacity = new_capacity;
        }
        buffer[length++] = c;
    }
    buffer[length] = '\0';
    *out_buffer = buffer;
    return 0;
}

int main() {
    char* input_str = nullptr;

    if (read_line(&input_str) != 0) {
        std::cerr << "Error: cannot allocate memory\n";
        return 1;
    }

    int diff_count = ahrameev::count_diff_latin_letters(input_str);
    std::cout << diff_count << '\n';

    int len = std::strlen(input_str);
    char* dest = (char*)malloc(len + 1);
    if (!dest) {
        std::cerr << "Error: cannot allocate output buffer\n";
        free(input_str);
        return 1;
    }

    int result_len = ahrameev::to_lower_latin(dest, len + 1, input_str);
    if (result_len == -1) {
        std::cerr << "Error: conversion failed\n";
        free(input_str);
        free(dest);
        return 1;
    }

    std::cout << dest << '\n';

    free(input_str);
    free(dest);
    return 0;
}
