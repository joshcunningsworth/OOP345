//Sale.cpp

#include <iomanip>
#include "Sale.h"

namespace w7{
	Sale::Sale(const char* filename){
		std::ifstream fs(filename);	
		if(!fs){ //if not file stream
			throw std::string("The File: (") + std::string(filename) + std::string(") could not be opened");
		}

		iProduct* p;
		while((p = readProduct(fs))){
			product.push_back(p);
		}											
		//closing the file
		fs.close();
	}

	Sale::~Sale(){
		for(int i = 0; i < product.size(); i++)
			delete product[i];
	}

	void Sale::display(std::ostream& os) const{
		std::cout << "Product No     Cost Taxable" << std::endl;
		
		//creating a double for displaying the cost
		double cost = 0.0;

		//for loop calculating the total cost and outputting the individual prices etc.
		for(int i = 0; i < product.size(); i++){
			os << *product[i] << std::endl; //eclipse gives a bug saying invalid overload of std::endl
			cost += product[i]->getCharge();//eclipse gives a bug saying getCharge() couldn't be resolved
		}

		//printing the calculated total
		std::cout << "\n" << std::setw(10) << "Total" << std::fixed << std::setprecision(2) << std::setw(10) << cost << std::endl;
	}
}
