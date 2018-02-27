/*
 * KVList.h
 *
 *  Created on: Feb 5, 2015
 *      Author: Josh
 */
#pragma once
#ifndef KVLIST_H_
#define KVLIST_H_

template <class K, class V, int N>

class KVList{
		K k[N];
		V v[N];
	size_t count; 	//the number of entries in the key value list

public:
	KVList() : count(0) { }		//default inline constructor, adopts safe empty state


	size_t size() const{ 		//returns number of entries in the key value list
		return count;
	}
	const K& key(int i) const{ 	//returns unmodifiable (constant) reference to the element i in the list
		if(i < count){
			return k[i];
		}
	}

	const V& value(int i) const{
		if(i < count){
			return v[i];
		}
	}

	KVList& add(const K& kk, const V& vv){
		if(count < N){
			k[count] = kk;
			v[count] = vv;
		}
		return *this;
	}

	int find(const K& key) const{	//returns the index of the first element in the list and default to zero
		for(int i = 0; i < count; i++){
			if(k[i] == key){
				return i;
			}
		}
		return 0;
	}

	KVList& replace(int i, const K& key, const V& val){
		if(i < count){
			k[i] = key;
			v[i] = val;
		}
		return *this;
	}
};


#endif /* KVLIST_H_ */
