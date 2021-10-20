#include <iostream>
#include <string>
#include <vector>

class Akasztofa {
  private:
    std::string feladvany;
    std::vector<bool> allapot;
    int rejtve;
    int hatra;
  public:
    Akasztofa(const std::string& feladvany, int maxProba = -1) {
      this->feladvany = feladvany;
      allapot.resize(feladvany.length());
      rejtve = 0;
      for (unsigned i = 0; i < feladvany.length(); i++)
      {
        if(feladvany[i] == ' ') {
          allapot[i] = true;
        } else {
          allapot[i] = false;
          rejtve++;
        }
      }
      hatra = maxProba==-1 ? feladvany.length() : maxProba;
    }
    
    int tipp(char c);
    int getHatra() const;
    
    friend std::ostream& operator<<(std::ostream& os, const Akasztofa& a);
};
