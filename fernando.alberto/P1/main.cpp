#include <iostream>
#include "EqualSequence.hpp"
#include "MonotonicIncreasing.hpp"

int main()
{
  int num = 0;
  alberto::EqualSequence count_equal;
  alberto::MonotonicIncreasing count_monotonic;
  size_t element_count = 0;

  while (std::cin >> num && num != 0)
  {
    if (std::cin.fail() && !std::cin.eof())
    {
      std::cerr << "Ошибка: неверный ввод." << "\n";
      return 1;
    }

    count_equal(num);
    count_monotonic(num);
    ++element_count;
  }

  // Verificar se houve erro na leitura (não foi devido a EOF)
  if (std::cin.fail() && !std::cin.eof())
  {
    std::cerr << "Ошибка: неверный ввод." << "\n";
    return 1;
  }

  // Para EQL-SEQ e MON-INC, sequência pode ter qualquer tamanho
  // Mas seguindo o modelo, verificamos se tem elementos suficientes
  if (element_count == 0)
  {
    // Sequência vazia é válida para EQL-SEQ e MON-INC
    std::cout << 0 << "\n" << 0 << "\n";
    return 0;
  }

  std::cout << count_equal() << "\n" << count_monotonic() << "\n";
  return 0;
}
