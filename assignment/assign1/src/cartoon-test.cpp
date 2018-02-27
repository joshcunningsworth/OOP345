#include <iostream>
using namespace std;
#include "cartoon.h"

#if 0
// how to use std::pair<-,-> x, x = std::make_pair(-,-), x.first, x.second
//http://www.cplusplus.com/reference/utility/make_pair/
//
// make_pair example
#include <utility>      // std::pair
#include <iostream>     // std::cout

int main () {
  std::pair <int,int> foo;
  std::pair <int,int> bar;

  foo = std::make_pair (10,20);
  bar = std::make_pair (10.5,'A'); // ok: implicit conversion from pair<double,char>

  std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
  std::cout << "bar: " << bar.first << ", " << bar.second << '\n';

  return 0;
}
#endif

int main(int argc, char** argv){

	std::vector<std::pair<std::string,std::string>> v1;
	
		//{
			//"type" , "cat"
			//"name" , "tom"
			//"likes" , "mice"
		//}
		//{
			//"type" , "mouse"
			//"name" , "jerry"
			//"likes" , "cheese"
		//}	

	v1.push_back (std::make_pair(std::string("type"),std::string("cat")));
	v1.push_back (std::make_pair(std::string("name"),std::string("tom")));
	v1.push_back (std::make_pair(std::string("likes"),std::string("mice")));
	
	std::vector<std::pair<std::string,std::string>> v2;

	v2.push_back (std::make_pair(std::string("type"),std::string("mouse")));
	v2.push_back (std::make_pair(std::string("name"),std::string("jerry")));
	v2.push_back (std::make_pair(std::string("likes"),std::string("cheese")));
	
	cout << "cartoon1:\n";
	cartoon cartoon1;
	cartoon1.set(v1);
	cout << "to_DSV returned = " << cartoon1.to_DSV();
	cout << "to_json returned = \n" << cartoon1.to_json();
	cout << "\n";
	
	cout << "cartoon2:\n";
	cartoon cartoon2;
	cartoon2.set(v2);
	cout << "to_DSV returned = " << cartoon2.to_DSV();
	cout << "to_json returned = \n" << cartoon2.to_json();
	cout << "\n";
}