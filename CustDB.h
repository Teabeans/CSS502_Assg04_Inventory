//-------|---------|---------|---------|---------|---------|---------|---------|
//
// UW CSS 502A - Assignment 4 - Inventory Management
// CustDB.h
//
//-------|---------|---------|---------|---------|---------|---------|---------|

//-----------------------------------------------------------------------------|
// Authorship
//-----------------------------------------------------------------------------|
//
// Matt Gross & Tim Lum
// mattgrosspersonal@gmail.com + twhlum@gmail.com
// Created:  2018.03.03
// Modified: 2018.03.14
// For the University of Washington Bothell, CSS 502A
// Winter 2018, Graduate Certificate in Software Design & Development (GCSDD)
//

//-----------------------------------------------------------------------------|
// File Description
//-----------------------------------------------------------------------------|
//
// This is the header file for the CustDB class, representing a database of
// customer objects
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

// Requisite in the .h file
#pragma once

//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       INCLUDE STATEMENTS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// Necessary for customer operations
#include "Cust.h"

// Necessary for transaction operations
#include "Trans.h"



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CLASS CONSTANTS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// (+) ------------|
// #MAXCUSTOMERS
//-----------------|
// Desc:   The maximum anticipated number customer spots needed
// Invars: Set to 20011
const static int MAXCUSTOMERS = 20011;



class CustDB {

private:
//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PRIVATE FIELDS (-)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

//-----------------|
// #custTable
//-----------------|
// Desc:   The customer database, sorted by customer hash
// Invars: None
   Cust* custTable[MAXCUSTOMERS];

//-----------------|
// #custTableByID
//-----------------|
// Desc:   The customer database, sorted by customer ID number
// Invars: Table size to accommodate 0000-9999
   Cust* custTableByID[10000];



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PRIVATE METHODS (-)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

//-----------------|
// #doesConflict(Cust*, int)
//-----------------|
// Desc:   Determines whether this customer and index creates a collision
// Invars: Returns false if the customer pointer matches the one at the index
   bool doesConflict(Cust* custPtr, int query);

//-----------------|
// #hash(Cust*)
//-----------------|
// Desc:   Determines the appropriate index based on a customer pointer
// Invars: Returns either the hash location of that customer or an empty index
   int hash(Cust* custPtr);

//-----------------|
// #probe(Cust*)
//-----------------|
// Desc:   In the event of a collision, probes to the next valid index
// Invars: Returns either the hash location of that customer or an empty index
   int probe(Cust* CustPtr, int query);

//-----------------|
// #obliviate()
//-----------------|
// Desc:   Deallocates all memory
// Invars: None
   void obliviate();



public:
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

//-----------------|
// #toString()
//-----------------|
// Desc:   Generates a string representation of the database
// Invars: None
   std::string toString();

//-----------------|
// #display()
//-----------------|
// Desc:   Displays the toString() representation of this database
// Invars: None
   void display();

//-----------------|
// #doesContain()
//-----------------|
// Desc:   Confirms whether a customer exists (by Cust ID)
// Invars: None
   bool const doesContain(int custID);

//-----------------|
// #insertCustomer(int)
//-----------------|
// Desc:   Inserts a customer to the database
// Invars: GIGO - No error checking is performed by this method
   void insertCustomer(Cust*);

//-----------------|
// #isValid(string)
//-----------------|
// Desc:   Examine a command and confirm whether it is legal or not
// Invars: Return value is variable based on state of DB
   bool isValid(std::string someCommand);

//-----------------|
// #isValidTransCmd(string)
//-----------------|
// Desc:   Determines whether this transaction is in conflict with the Database state
// Invars: Return value is variable based on state of DB
   bool isValidTransCmd(int custID, std::string title, char type);

//-----------------|
// #getCustomerAt(int)
//-----------------|
// Desc:   Returns a customer, searched by customer ID
// Invars: None
   Cust* getCustomerAt(int);

//-----------------|
// #appendHistory(Trans)
//-----------------|
// Desc:   Appends a transaction to the history of the involved customer
// Invars: GIGO - No error checking is performed by this function
//         Transaction must be legal and properly formatted upon receipt
   void appendHistory(Trans);



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       GETTERS / SETTERS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// None for this class



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CONSTRUCTORS / DESTRUCTORS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

//-----------------|
// #CustDB()
//-----------------|
// Desc:   Default constructor for a Customer Database
// Invars: All table entries initialized to nullptr
   CustDB();

//-----------------|
// #~CustDB()
//-----------------|
// Desc:   Deallocates memory and zeroes fields
// Invars: All memory has been deallocated
   ~CustDB();

}; // Closing class CustDB {}

//-------------------------------------|
// End Student Code
//-------------------------------------|

// End of file - CustDB.h
