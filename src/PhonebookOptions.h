/*
 * PhonebookOptions.h
 *
 *  Created on: Oct 3, 2017
 *      Author: ferdinandtembo
 */

#ifndef PHONEBOOKOPTIONS_H_
#define PHONEBOOKOPTIONS_H_

#include <iostream>
#include "Contact.h"
using namespace std;


void add();

string getName();
int getNumber();
void listContact(Contact array[], int size);
void deleteContact(string name);
int getIndex(string name);
int getLineCount(string filename);
void readData(string filename);
int search(string name);
string * parseName(string name);
void resize();
#endif /* PHONEBOOKOPTIONS_H_ */
