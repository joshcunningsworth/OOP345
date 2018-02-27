/*
 * Notifications.h
 *
 *  Created on: Oct 13, 2015
 *      Author: Josh
 */

#pragma once

#ifndef _NOTIFICATIONS_H_
#define _NOTIFICATIONS_H_

#include "Message.h"

namespace w5{

	class Notifications
	{
		Message* messages;
		size_t size;

	public:
		Notifications();

		Notifications(const Notifications& other);

		Notifications& operator=(const Notifications& rhs);

		Notifications(Notifications&& other);

		Notifications&& operator=(Notifications&& rhs);

		~Notifications();

		void operator+=(const Message& msg);

		void display(std::ostream& os) const;
	};
}

#endif 	// _NOTIFICATIONS_H_
