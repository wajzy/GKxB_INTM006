#include "akasztofa.h"

int Akasztofa::tipp(char c) {
  if(hatra == 0) {
    throw "Nem probalkozhat tobbszor.";
  }
  for (unsigned i = 0; i < feladvany.length(); i++) {
    if(not allapot[i] and feladvany[i]==c) {
      allapot[i] = true;
      rejtve--;
    }
  }
  hatra--;
  return rejtve;
}

int Akasztofa::getHatra() const {
  return hatra;
}

std::ostream& operator<<(std::ostream& os, const Akasztofa& a)
{
    for (unsigned i = 0; i < a.feladvany.length(); i++) {
      os << (a.allapot[i] ? a.feladvany[i] : '*');
    }
    return os;
}
