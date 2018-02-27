  // File stlbaseclass.cpp

  #include <list>
  #include <string>
  #include <iostream>
  using namespace std;

  class X{
  private:

  public:
	  X();

  };



  int main()
  {
    class X { //inherit from stl
      void operator+= (std::string str) {
        // write this function which will add to the string (push back) ...
      }
      X& operator+ (const X rhs) {
        // write this function operator that will add two instances of class X ...
      }
      std::string stringDump(char delimeter = '/') {
        // write this function prints the string with slashes in between ...
      }
    };

    X x;//instance of class X name x

    //adding strings to instance x
    x += "hello";
    x += "there";
    x += "OOP345";

    std::cout << "x.size()  = "    << x.size()  << “\n”; //prints size
    std::cout << "x.front() = "    << x.front() << "\n";
    std::cout << "x.back()  = "    << x.back()  << "\n";
    std::cout << x.stringDump()    << "\n"; //default string dump
    std::cout << x.stringDump(':') << "\n"; //string dump with a colon

    X xx = x + x; //create instance of class X named xx and stores x + x
    std::cout << xx.stringDump('~') << "\n"; //string dump with tilda

    std::cout << "xx.size()  = " << xx.size()  << "\n";
    std::cout << "xx.front() = " << xx.front() << “\n”;
    std::cout << "xx.back()  = " << xx.back()  << “\n”;
    std::cout << "xx.size()  = " << xx.size()  << "\n"; //prints size
    std::cout << xx.stringDump('+') << "\n";

    xx.pop_front(); //removes front
    xx.pop_back(); //removes back
    std::cout << "xx.size()  = " << xx.size()  << "\n";
    std::cout << xx.stringDump('-') << "\n";

    xx.push_front("(head)");
    xx.push_back("(tail)");

    std::cout << "xx.size()  = " << xx.size()  << "\n";
    std::cout << "xx.front() = " << xx.front() << "\n";
    std::cout << "xx.back()  = " << xx.back()  << "\n";
    std::cout << xx.stringDump('&') << "\n"; //string dump with ampersand

    return 0;
  }
