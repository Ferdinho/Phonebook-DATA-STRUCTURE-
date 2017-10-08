//============================================================================
// Name        : PhoneBook.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include "PhonebookOptions.h"
#include "Contact.h"

using namespace std;


int size =0;
int capacity = 0;
Contact* contacts;



int main() {


    capacity = getLineCount("phonebook.txt");
	contacts = new Contact[capacity];
	readData("phonebook.txt");


	char answer = ' ';

	cout<< "***MY PHONEBOOK APPLICATION***\n"
			"Please choose an operation:\n";
do{
	cout<<"A(Add) | S (Search) | D(Delete) |L(List) |Q(Quit): ";
	cin >> answer;
	cout<<endl;
	answer = tolower(answer);

	switch(answer){
	case 'a': {string name = getName();
			   string firstname = parseName(name)[0];
			   string lastname = parseName(name)[1];
				//cout<<firstname<<lastname<<endl;
			   int phone = getNumber();
			   Contact newContact(firstname, lastname, phone);
			   if(size == capacity){
				   resize();
			   }
			   contacts[size] = newContact;
			   size +=1;;
			   break;
	}

	case 'l': {listContact(contacts, size);
			break;
			}

	case 'd':{string name = getName();
			   deleteContact(name);


			break;
			}
	case 's':{string name = getName();
	          int number = search(name);
	          if( number != -1){ // dans ma function si je trouve pas le num, je retourne -1
	        	    cout<<"Phone: "<<number<<endl;
	          }
	          else{
	        	  cout<<"Contact not found"<<endl;
	          }

	}

	default: break;

	}
}while (answer!='q');

	cout<<"Thank you for using the software!"<< endl;

	return 0;
	}

int search(string name){
	string firstname = parseName(name)[0];
	string lastname = parseName(name)[1];
	for(int i =0 ; i < size ; i ++){
		if(contacts[i].getFirstName() == firstname && contacts[i].getLastName() ==lastname){
			return contacts[i].getNumber();
		}
	}
	return -1;

}

void resize(){
   Contact* biggerArray = new Contact[capacity + 20];
   for(int i = 0 ; i < size ; i ++){
	   biggerArray[i] = contacts[i];
   }
   contacts = biggerArray;
   delete [] biggerArray;
}


string* parseName(string name){
    string namedetails[2]; // le "2" c la taille de mon array

	int blank = name.find(" ");
	string firstname = name.substr(0,blank);
	namedetails[0] = firstname; // a la premiere position
	name = name.substr(blank+1);
	blank = name.find(" ");
	string lastname = name.substr(0,blank);
	namedetails[1] = lastname; // a la deuxieme position

	return namedetails;
}

int getLineCount(string filename){
	int lines =0;
	ifstream infile;
		infile.open(filename);

		string s;

		while (getline(infile,s)){
			int blank = s.find(" ");
			string firstname = s.substr(0,blank);
			s = s.substr(blank+1);
			blank = s.find(" ");
			string lastname = s.substr(0,blank);
			s = s.substr(blank+1);
			int number = stoi(s);
	//		cout<<"Fistname is "<<firstname<<" Lastname is "<< lastname <<" Number is "<< number<<endl;
			lines ++;
		}
		return lines;
}

void readData(string filename){

	ifstream infile;
			infile.open(filename);

			string s;
	while (getline(infile,s)){
		int blank = s.find(" ");
		string firstname = s.substr(0,blank);
		s = s.substr(blank+1);
		blank = s.find(" ");
		string lastname = s.substr(0,blank);
		s = s.substr(blank+1);
		int number = stoi(s);
     	//cout<<"Fistname is "<<firstname<<" Lastname is "<< lastname <<" Number is "<< number<<endl;
		Contact contact(firstname, lastname, number);
		contacts[size] = contact;
		size ++;
	}
}
string getName(){
	string name = "";
	cout<<"Please enter a Name "<<endl;
	cin.ignore();
	getline(cin,name);
	return name;
}


int getNumber(){
	int number;
	cout<<"Please enter your number"<<endl;;
	cin>>number;
	return number;
}


void listContact(Contact contacts[], int listSize){ // what is listsize
    int i = 0;

	while( i < listSize){
		//cout<<"User: "<<contacts[i].getFirstName()<<" "<<contacts[i].getLastName()<<"  Phone: "<<contacts[i].getNumber()<<endl;
		displayContactDetail(contacts[i]);
		i += 1;

	}
}

int getIndex(string name){
	string firstname = parseName(name)[0];
	string lastname = parseName(name)[1];
	for(int i =0 ; i < size ; i ++){ //le size etait 0 , mais il a changer pck on ajouter +1 a chak foi
		if(contacts[i].getFirstName() == firstname && contacts[i].getLastName() ==lastname){
			return i;
		}
	}
	return -1;
}
void deleteContact(string name){
     int index = getIndex(name);
     string contactToDelete="";
   //  cout<<"Index to delete is "<<index<<endl;
     if(index != -1){

    	 contactToDelete = contacts[index].getFirstName();

    	   for(int i = index ; i<size ; i++){
    		   contacts[i]=contacts[i+1];
    	   }
     }
     if(contactToDelete!=""){
    	     size -=1;
    	 	 cout<<"deleted "<<contactToDelete<<endl;
     }

}

