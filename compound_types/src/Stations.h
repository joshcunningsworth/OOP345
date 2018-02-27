/*
 * Stations.h
 *
 *  Created on: Sep 22, 2015
 *      Author: Josh
 */


#include "Station.h"

namespace w2{


class Stations{
	int stationCount;
	Station **stationTable;

public:
	Stations ();
	Stations (char *);
	void update() const;
	void restock() const;
	void report() const;

};

}
