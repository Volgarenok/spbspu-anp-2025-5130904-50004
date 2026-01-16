#include <iostream>
#include <cstring>
#include <new>
#include "string_operations.h"

using namespace std;

int main() {
    // Ler string da entrada padrão
    const size_t MAX_INPUT_SIZE = 1024;
    char* input = new (nothrow) char[MAX_INPUT_SIZE];

    if (input == nullptr) {
        cerr << "Erro: Não foi possível alocar memória para a entrada" << endl;
        return 1;
    }

    if (!cin.getline(input, MAX_INPUT_SIZE)) {
        cerr << "Erro: Falha ao ler entrada" << endl;
        delete[] input;
        return 1;
    }

    // Alocar buffers para os resultados
    const size_t input_len = strlen(input);
    char* result1 = new (nothrow) char[input_len + 1];
    char* result2 = new (nothrow) char[input_len + 1];

    if (result1 == nullptr || result2 == nullptr) {
        cerr << "Erro: Não foi possível alocar memória para os resultados" << endl;
        delete[] input;
        if (result1) delete[] result1;
        if (result2) delete[] result2;
        return 1;
    }

    // Aplicar as transformações
    rmv_vow(input, result1, input_len + 1);
    exc_snd(input, result2, input_len + 1);

    // Output dos resultados
    cout << result1 << endl;
    cout << result2 << endl;

    // Liberar memória
    delete[] input;
    delete[] result1;
    delete[] result2;

    return 0;
}
