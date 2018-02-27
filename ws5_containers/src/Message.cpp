/*
 * Message.cpp
 *
 *  Created on: Oct 13, 2015
 *      Author: Josh
 */


#include <iostream>
#include <fstream>
#include "Message.h"

using namespace std;

namespace w5{

Message::Message(){}

Message::Message(std::ifstream& in, char c){
	std::string user;
	std::string reply;
	std::string tweet;
	char t;

	in >> user;
	if (!in.fail()){
		t = in.get();

		if (t != c){
			t = in.get();

			if (t == '@'){
				in >> reply;
				in.ignore();
				getline(in, tweet, c);
			}
			else{
				getline(in, tweet, c);
				tweet = t + tweet;
			}

			if (tweet.size() > 0){
				m_user  = user;
				m_reply = reply;
				m_tweet = tweet;
			}
		}
	}
}

bool Message::empty() const{
	return m_tweet.size() == 0;
}

void Message::display(std::ostream& os) const{
	os << "Message\n";
	os << "User  : " << m_user << "\n";
	if (m_reply.size() > 0){
	   os << "Reply : " << m_reply << "\n";
	}
	os << "Tweet : " << m_tweet << "\n";
}

} //end of namespace


