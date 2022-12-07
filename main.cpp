#include <iostream>
using namespace std;

// Dynamic binding through yello dog.

class Dog {
public:
  Dog() { cout << "Dog born" << endl; }
  // if virtual function is called from Base constructor/destructor, the dynamic
  // binding will not work Dog() {cout << "Dog born"<<endl; bark();} Do not call
  // virtual function within Constructor/Destructor
  // Derived class gets destroyed before base class.

  // virtual keyword make the bark function dynamcially bind to it dervied
  // class.
  virtual void bark() { cout << " I am a just a dog" << endl; }
  void seeCat() { bark(); }
  // If virtual function is not deined in the derived class its base function is
  // called.
  virtual void barkTest() { cout << "barkTest()" << endl; }
  ~Dog() { cout << "Base destructor" << endl; }
};

class Yellodog : public Dog {
public:
  // It is okay to call virtual function from derived class constructor
  // Yellodog() { cout << " Yello dog born." << endl; seeCat();}
  Yellodog() { cout << " Yello dog born." << endl; }
  ~Yellodog() { cout << "Derived destructor" << endl; }
  virtual void bark() { cout << "I am a yellow dog" << endl; }
};

int main() {
  Yellodog d;
  // d.seeCat();
  // d.barkTest();
  return 0;
}