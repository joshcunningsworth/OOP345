//Sale.h

//old method
#ifndef _SALE_H_
#define _SALE_H_

//new method
#pragma once

#include <vector>
#include "Product.h"

namespace w7{
	class Sale{
		std::vector<iProduct*> product;

	public:
		Sale(const char* filename);
		virtual ~Sale();
		void display(std::ostream& os) const;
	};
}

#endif 	// _SALE_H_
