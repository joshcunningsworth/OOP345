//Product.h

#pragma once

#include "iProduct.h"

namespace w7{
	class Product : public iProduct{
		int num;
		double price;

	public:
		Product(int number, double price);
		virtual double getCharge() const;
		virtual void display(std::ostream& os) const;
	};

	class TaxableProduct : public Product{
		char tax; //the type of tax, HST or PST

	public:	
		TaxableProduct(int number, double price, char taxable);
		virtual double getCharge() const;
		virtual void display(std::ostream& os) const;
	};
}
