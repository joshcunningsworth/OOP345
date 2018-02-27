//Q2. +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//What happens if a constructor throws in the middle of allocating many blocks of memory?

//Think about:

  #include <iostream>
  #include <vector>
  #include <exception>
#include <memory>

  class X {
    std::vector<long*> blockVector;
    size_t count;
    static const int BLOCK_SIZE = 10000;
  public:
    X(size_t c = 1000000) : count(c) { //going to make a vector 1 million long of pointers
      blockVector = std::vector<long*>(count,nullptr);// nullptr is zero
      for(size_t i = 0; i < count; i++)
        blockVector[i] = new long[BLOCK_SIZE];  // BYTES =  sizeof(long) * BLOCK_SIZE
        // 'new' may throw an std::bad_alloc (which is an std::exception)
    }
    ~X() { for( auto e : blockVector ) if(e) delete [] e; }
  };

  int main(int argc, char**argv)
  {
    try {
      X x;
      std::cout << "That worked!\n";
    } catch (const std::exception& e){
      std::cout << "Failure: " << e.what() << "\n";
    }
  }


//If the constructor throws, how can you fix it?
//Re-code the X() constructor. Fix it with try catch!!
