#ifndef STRING_OPERATIONS_H
#define STRING_OPERATIONS_H

#include <cstddef>

// Declarações das funções
size_t rmv_vow(const char* src, char* dst, size_t dst_len);
size_t exc_snd(const char* src, char* dst, size_t dst_len);

// Constante para a segunda string do EXC-SND
extern const char* SECOND_STR;

#endif
