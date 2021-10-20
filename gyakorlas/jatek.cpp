#include <iostream>
#include "akasztofa.h"

int main(void) {
  Akasztofa a("The quick brown fox jumps over the lazy dog");
  std::cout << "Akasztofa jatek. Probalja meg legfeljebb " 
            << a.getHatra()
            << " probalkozasbol kitalalni a feladvanyt.\n";
  try {
    char c;
    do {
      std::cout << a << std::endl;
      std::cout << "Tipp: ";
      std::cin >> c;
    } while(a.tipp(c));
    std::cout << "Gratulalok!\n";
  } catch(const char* hiba) {
    std::cerr << hiba << std::endl;
  }
}
