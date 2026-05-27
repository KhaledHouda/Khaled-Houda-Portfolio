#include "Counter.h"
#include <iostream>

// TODO: Hier Klasse SecondsCounter mit Vererbung oder Komposition implementieren
class SecondsCounter: public ModuloCounter{
    bool overflow;
    public:
        bool didOverflow(){
            return overflow;
        }
        SecondsCounter():ModuloCounter(60){std::cout<<"created SecondsCounter";}
        int getSeconds(){
            return ModuloCounter::read();
        }
        void inc(){
            if(ModuloCounter::read()==59){overflow = true;}else{overflow=false;}
            ModuloCounter::inc();
        }



    friend std::ostream& operator<<(std::ostream &os, SecondsCounter& sc);



};

// TODO: Hier Ausgabeoperator überladen
// ACHTUNG: Damit std::ostream& operator<< auf private Member von SecondsCounter zugreifen kann
// muss folgende Zeile in die Klasse Seconds Counter eingefügt werden:
// friend std::ostream& operator<<(std::ostream &os, SecondsCounter& sc);
std::ostream& operator<<(std::ostream& os, SecondsCounter& sc) {
    os << sc.read();
  return os;
}

int main () {
  SecondsCounter sCtr;
  for(int i = 0; i < 75; i++){
    std::cout << "Time: " << sCtr << "s Overflow: " << sCtr.didOverflow() << "\n";
    sCtr.inc();
  }
  return 0;
}
