/*
 * Contact.h
 *
 *  Created on: Oct 4, 2017
 *      Author: ferdinandtembo
 */

#ifndef CONTACT_H_
#define CONTACT_H_

#include <iostream>
using namespace std;


class Contact {
private:
	string firstname;
	string lastname;
	int phoneNumber;
public:
	Contact();
	Contact(string firstname, string lastname , int number);

	void setPhoneNumber(int number);
	string getFirstName();
	string getLastName();
	int getNumber();
	friend void displayContactDetail(Contact contact);
    Contact& operator=(const Contact &other);
	//friend toString();
	virtual ~Contact();
};

#endif /* CONTACT_H_ */
