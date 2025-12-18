#include "string_operations.h"
#include <cstring>

// Definição da segunda string para EXC-SND
const char* SECOND_STR = "abc";

// Função para remover vogais (RMV-VOW)
size_t rmv_vow(const char* src, char* dst, size_t dst_len) {
    if (src == nullptr || dst == nullptr || dst_len == 0) {
        return 0;
    }

    size_t j = 0;
    for (size_t i = 0; src[i] != '\0'; i++) {
        if (j >= dst_len - 1) {
            break; // Buffer cheio
        }

        char c = src[i];
        // Verifica se NÃO é vogal (minúscula ou maiúscula)
        if (!(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
              c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')) {
            dst[j++] = c;
        }
    }
    dst[j] = '\0';
    return j;
}

// Função para excluir caracteres da segunda string (EXC-SND)
size_t exc_snd(const char* src, char* dst, size_t dst_len) {
    if (src == nullptr || dst == nullptr || dst_len == 0) {
        return 0;
    }

    size_t j = 0;
    for (size_t i = 0; src[i] != '\0'; i++) {
        if (j >= dst_len - 1) {
            break; // Buffer cheio
        }

        char c = src[i];
        const char* pos = SECOND_STR;
        bool found = false;
        
        // Procura o caractere na segunda string
        while (*pos != '\0') {
            if (*pos == c) {
                found = true;
                break;
            }
            pos++;
        }

        // Se não encontrou, adiciona ao resultado
        if (!found) {
            dst[j++] = c;
        }
    }
    dst[j] = '\0';
    return j;
}
