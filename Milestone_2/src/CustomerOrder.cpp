// CustomerOrder.cpp


#include "CustomerOrder.h"
#include "Item.h"
#include "ItemOrder.h"
#include "Utilities.h"
#include <iomanip>
#include <vector>

char CustomerOrder::delimiter = '\0';
size_t CustomerOrder::field_width = 1;

CustomerOrder::CustomerOrder(const std::string& record)
: name(""), product(""), order(nullptr), nOrders(0){
	size_t pos = 0;
	bool repeat = true;

	Utilities util(field_width);
	name = util.nextToken(record, pos, repeat);
	if (!name.empty()){
		if (repeat != false){
		product = util.nextToken(record, pos, repeat);
		}

		std::vector<std::string> vec;
		while(repeat != false) {
			std::string t = util.nextToken(record, pos, repeat);
			if (t.size() > 0){
				vec.push_back(t);
			}
		}

		nOrders = vec.size();
		order = new ItemOrder[nOrders];
		for (int i = 0; i < nOrders; i++)
			order[i] = ItemOrder(vec[i]);

		field_width = util.getFieldWidth();		
	}
}

CustomerOrder::CustomerOrder(const CustomerOrder& rhs){

	name = rhs.name;
    product = rhs.product;
    nOrders = rhs.nOrders;



    if(rhs.order){
    	order = new ItemOrder[nOrders]; 
    	for (int i = 0; i < nOrders; i++)
			order[i] = rhs.order[i];
    }
    else{
    	order = nullptr;
    }
}

CustomerOrder::CustomerOrder(CustomerOrder&& rhs){
	order = nullptr;
	*this = std::move(rhs);
}


//maybe
CustomerOrder&& CustomerOrder::operator=(CustomerOrder&& rhs){
	if (this != &rhs){
		if (order){
			delete [] order;
		}

		name = rhs.name;
		product = rhs.product;
		nOrders = rhs.nOrders;
		order = rhs.order;

		rhs.name.clear();
		rhs.product.clear();
		rhs.nOrders = 0;
		rhs.order = nullptr;
	}
	return std::move(*this);
}

CustomerOrder::~CustomerOrder(){
	if (order){
		//std::cout << "dtor" << std::endl;
		delete [] order;
	}
}

unsigned int CustomerOrder::noOrders() const{
	return nOrders;
}

const std::string& CustomerOrder::operator[](unsigned int i) const{
	if (i >= nOrders){
		throw std::string("throwing");
	}
	
	return order[i].getName();
}

void CustomerOrder::fill(Item& item){
	for (int i = 0; i < nOrders; i++){
		if (order[i].asksFor(item) && !order[i].isFilled()){
			order[i].fill(item.getCode());
			item++;
		}
	}
}

void CustomerOrder::remove(Item& item){
	for (int i = 0; i < nOrders; i++){
		if (!order[i].getName().compare(item.getName())){
			order[i].clear();
		}
	}
}

bool CustomerOrder::empty() const{
	return name.empty();
}

void CustomerOrder::display(std::ostream& os) const{
	os << std::left;
	os << std::setw(field_width) << name << " : ";
	os << std::setw(field_width) << product;
	os << std::endl;

	for(unsigned int x = 0; x < nOrders; x++){
		order[x].display(os);
	}
}
    
void CustomerOrder::setDelimiter(const char c){
	delimiter = c;
}
