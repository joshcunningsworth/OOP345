//Product.cpp

#include <iomanip>
#include "Product.h"

namespace w7{

 	std::ostream& operator<<(std::ostream& os, const iProduct& P){
 		P.display(os);
 		return os;
 	}

	iProduct* readProduct(std::ifstream& in){
		int number;
		double price;
		char taxable;

		//input the number then the price

		in >> number;
		if (in.fail()){
			return (iProduct*) 0;
		}

		in >> price;
		if(in.fail()){
			return (iProduct*) 0;
		}

		taxable = in.get();
		if (taxable == '\n'){
			return new Product(number, price);
		}

		else{
			in >> taxable;	
			return new TaxableProduct(number, price, taxable);
		}
	}

	//default ctor for Product
	Product::Product(int number, double price) : num(number), price(price){}

	double Product::getCharge() const{
		return price;
	}

	void Product::display(std::ostream& os) const{
		os << std::setw(10) << num << std::fixed << std::setprecision(2) << std::setw(10) << price;
	}

	//default ctor for TaxableProduct
	TaxableProduct::TaxableProduct(int number, double price, char taxable)
	: Product(number, price), tax(taxable){
		
	}

	double TaxableProduct::getCharge() const{
		double charge = Product::getCharge();

		//assigning the tax type, either HST or PST and calculating the tax
		if(tax == 'H'){
			charge = charge * 1.13;
		}
		else if(tax == 'P'){
			charge = charge * 1.08;
		}
		return charge;
	}

	void TaxableProduct::display(std::ostream& os) const{
		Product::display(os);

		//checking if the tax is HST or PST
		if(tax == 'H'){
			os << ' ' << tax;
		}
		else if(tax == 'P'){
			os << ' ' << tax;
		}
	}	
}
