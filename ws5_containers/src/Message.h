/*
 * Message.h
 *
 *  Created on: Oct 13, 2015
 *      Author: Josh
 */

#ifndef _MESSAGE_H_
#define _MESSAGE_H_

namespace w5
{
	class Message
	{
		std::string m_user;
		std::string m_reply;
		std::string m_tweet;

	public:

		Message();

		Message(std::ifstream& in, char c);

		bool empty() const;

		void display(std::ostream& os) const;
	};
}

#endif 	// _MESSAGE_H_
