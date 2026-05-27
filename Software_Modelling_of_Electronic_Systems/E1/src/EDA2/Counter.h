#include <iostream>

class Counter {
  int value;
 public:
  void reset() { 
    value = 0; 
  }
  
  void inc() { 
    value++; 
  }

  int read() { 
    return value;
  }

  Counter() {
    value = 0;
    std::cout << "Default Constructor (Counter)\n";
  }

  Counter(int arg) {
    value = arg;
    std::cout << "Overloaded Constructor (Counter)\n";
  }
};

class ModuloCounter {
  
  Counter ctr;
 public:
  int moduloValue;
  void reset() {
    ctr.reset(); 
  }
  
  void inc() {
  	if (ctr.read() < moduloValue-1) {
  		ctr.inc();
  	} else {
  		ctr.reset();
  	}
  }
  
  int read() { 
    return ctr.read(); 
  }
  void setModulo(int val){
    this->moduloValue = val;
  }
  
  ModuloCounter(int mv) : ctr(0), moduloValue(mv) {
  	std::cout << "Overloaded Constructor (ModuloCounter)\n";
  }
};


