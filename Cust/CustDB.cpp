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
#include "custDB.h"

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
// #custTable
//-----------------|
// Desc:   The customer database
// Invars: 10000 valid customer IDs, so 2x and nearest prime size
///   Cust* custTable[20011];



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PRIVATE METHODS (-)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

//-----------------|
// #isValid(string)
//-----------------|
// Desc:   Determines whether this string is a valid customerDB command
// Invars: Return value is variable based on state of DB
bool CustDB::isValid(std::string) {

}

//-----------------|
// #hash(Cust*)
//-----------------|
// Desc:   Determines the appropriate index based on a customer pointer
// Invars: Returns either the hash location of that customer or an empty index
int CustDB::hash(Cust* CustPtr) {
   
}

//-----------------|
// #probe(Cust*)
//-----------------|
// Desc:   In the event of a collision, probes to the next valid index
// Invars: Returns either the hash location of that customer or an empty index
int CustDB::probe(Cust* CustPtr) {
   
}

//-----------------|
// #obliviate()
//-----------------|
// Desc:   Deallocates all memory
// Invars: None
void CustDB::obliviate() {
   
}



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
// #toString()
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
std::string CustDB::toString() {
   std::string retString = "CustDB::toString()";
   return (retString);
} // Closing toString()

// (+) --------------------------------|
// #display()
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
void CustDB::display() {
   std::cout << "CustDB::display()";
} // Closing display()

// (+) --------------------------------|
// #insertCustomer(Cust&)
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
void CustDB::insertCustomer(Cust* CustPtr) {
   int indexToInsertAt = this->hash(CustPtr);
   this->custTable[indexToInsertAt] = CustPtr;
} // Closing insertCustomer()

// (+) --------------------------------|
// #getCustomerAt(int)
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
Cust* CustDB::getCustomerAt(int query) {
   return (this->custTable[query]);
} // Closing getCustomerAt()

// (+) --------------------------------|
// #appendHistory(Trans)
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
   void CustDB::appendHistory(Trans someTransaction) {
   
   }



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       GETTERS / SETTERS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

//-----------------|
// #CustDB()
//-----------------|
// Desc:   NULL
// Invars: NULL
   CustDB::CustDB() {
   
   }

//-----------------|
// #~CustDB()
//-----------------|
// Desc:   NULL
// Invars: NULL
   CustDB::~CustDB() {

   }

// End of file - CustDB.cpp
