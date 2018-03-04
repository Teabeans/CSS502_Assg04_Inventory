//-------|---------|---------|---------|---------|---------|---------|---------|
//
// UW CSS 502A - Assignment 4 - Inventory Management
// Cust.cpp
//
//-------|---------|---------|---------|---------|---------|---------|---------|

//-----------------------------------------------------------------------------|
// Authorship
//-----------------------------------------------------------------------------|
//
// Matt Gross & Tim Lum
// mattgrosspersonal@gmail.com + twhlum@gmail.com
// Created:  2018.03.03
// Modified: 2018.03.--
// For the University of Washington Bothell, CSS 502A
// Winter 2018, Graduate Certificate in Software Design & Development (GCSDD)
//

//-----------------------------------------------------------------------------|
// File Description
//-----------------------------------------------------------------------------|
//
// This is the implementation file for the Cust.h header.
//

//-----------------------------------------------------------------------------|
// Package Files
//-----------------------------------------------------------------------------|
//
// See Github repository
// https://github.com/Teabeans/CSS502_Assg04_Inventory
//

//-------------------------------------|
// Begin Student Code
//-------------------------------------|

//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       INCLUDE STATEMENTS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// Necessary for input-output operations
#include <iostream>

// Necessary for string formatting operations
#include <iomanip>

// Necessary for string stream buffering operations
#include <sstream>

// Necessary for string operations
#include <string>

// Necessary for breadth-first tree traversal
#include <queue>

// For tracing visitation routes
#include <stack>

// Field and method declarations for the Cust (Customer) class
#include "cust.h"

//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CLASS CONSTANTS
//
//-------|---------|---------|---------|---------|---------|---------|---------|
//
// Do not redeclare these variables in the .cpp.
// Included here only for reference
// See associated .h file for variable declarations
//
// None for this class
//

//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PRIVATE FIELDS (-)
//
//-------|---------|---------|---------|---------|---------|---------|---------|
//
// Do not redeclare these variables in the .cpp.
// Included here only for reference
// See associated .h file for variable declarations

//-----------------|
// #firstName
//-----------------|
// Desc:   The customer's first name
// Invars: Must contain at least one character
///   std::string firstName;

//-----------------|
// #lastName
//-----------------|
// Desc:   The customer's last name
// Invars: Must contain at least one character
///   std::string lastName;

//-----------------|
// #custID
//-----------------|
// Desc:   The customer's ID number
// Invars: Initializes to junk values - set by hashing
///   int custID;

//-----------------|
// #history
//-----------------|
// Desc:   The customer's history
// Invars: May be an empty string
///   std::string history;

//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PUBLIC FIELDS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// None for this class

//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PUBLIC METHODS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// (+) --------------------------------|
// #appendHistory(String)
//-------------------------------------|
// Desc:    Appends values to the customer history
// Params:  string arg1 - The transaction to append
// PreCons: String configuration should be handled by the Trans::toString() method
//          May be called with faulty transaction information
//          GIGO - No error checking is performed by appendHistory()
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
void Cust::appendHistory(std::string someTransaction){
   this->history += someTransaction;
   this->history += "\n";
}

// (+) --------------------------------|
// #NULL()
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
std::string Cust::toString() {
   std::string retString = "";
   return (retString);
}



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       GETTERS / SETTERS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// (+) --------------------------------|
// #getFirstName()
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
std::string Cust::getFirstName() {
   return (this->firstName);
} // Closing getFirstName()

// (+) --------------------------------|
// #getLastName()
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
std::string Cust::getLastName() {
   return (this->lastName);
} // Closing getLastName()

// (+) --------------------------------|
// #getName()
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
std::string Cust::getName() {
   std::string retString = "";
   retString += this->firstName;
   retString += " ";
   retString += this->lastName;
   return (retString);
} // Closing getName()

// (+) --------------------------------|
// #getID()
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
int Cust::getID() {
   return (this->custID);
} // Closing getID()

// (+) --------------------------------|
// #getHistory()
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
std::string Cust::getHistory() {
   return (this->history);
} // Closing getHistory()

// (+) --------------------------------|
// #setFirstName(string)
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
void Cust::setFirstName(std::string nameF) {
   this->firstName = nameF;
}

// (+) --------------------------------|
// #setFirstName(string)
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
void Cust::setLastName(std::string nameL) {
   this->lastName = nameL;
}

// (+) --------------------------------|
// #setName(string)
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
void Cust::setName(std::string nameF, std::string nameL) {
   this->setFirstName(nameF);
   this->setLastName(nameL);
}

// (+) --------------------------------|
// #setID(int)
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
void Cust::setID(int IDnum) {
   this->custID = IDnum;
}



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CONSTRUCTORS / DESTRUCTORS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// (+) --------------------------------|
// #Cust()
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
Cust::Cust() {
   std::cout << "(ERROR! Default customer constructor called)";
   this->firstName = "(firstName == NULL)";
   this->lastName  =  "(lastName == NULL)";
   this->history   =   "(history == NULL)";
   this->custID    = 99999; // Number out-of-bounds
}

//-----------------|
// #Cust(string, string, int)
//-----------------|
// Desc:   Customer constructor by name and ID
// Invars: None
Cust::Cust(std::string nameF, std::string nameL, int IDnum) {
   this->firstName = nameF;
   this->lastName  = nameL;
   this->custID    = IDnum;
   this->history   = "Transaction history for ";
   this->history += this->firstName + " " + this->lastName + "(ID ";
   // Convert the ID integer to a 4-wide formatted string
   std::ostringstream tempStream;
   tempStream << std::setw(4) << std::setfill('0') << custID;
   std::string tempString(tempStream.str());
   // Append that string to the history header
   this->history += tempString + "): \n";
}

//-----------------|
// #~Cust()
//-----------------|
// Desc:   Customer deconstructor
// Invars: None
Cust::~Cust() {
   this->firstName = "";
   this->lastName  = "";
   this->history   = "";
   this->custID    = 99999; // Number out-of-bounds
}

// End of file - Cust.cpp
