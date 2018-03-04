//-------------------------------------|
// Begin Student Code
//-------------------------------------|

// Requisite in the .h file
#pragma once

// Necessary for customer operations
#include "Cust.h"

// Necessary for transaction operations
#include "../Trans/Trans.h"


//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CLASS CONSTANTS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// None for this class

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
// Desc:   The customer database
// Invars: 10000 valid customer IDs, so 2x and nearest prime size
   Cust* custTable[20011];



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
   bool isValid(std::string);

//-----------------|
// #hash(Cust*)
//-----------------|
// Desc:   Determines the appropriate index based on a customer pointer
// Invars: Returns either the hash location of that customer or an empty index
   int hash(Cust* CustPtr);

//-----------------|
// #probe(Cust*)
//-----------------|
// Desc:   In the event of a collision, probes to the next valid index
// Invars: Returns either the hash location of that customer or an empty index
   int probe(Cust* CustPtr);

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
// Desc:   NULL
// Invars: NULL
   std::string toString();

//-----------------|
// #display()
//-----------------|
// Desc:   NULL
// Invars: NULL
   void display();

//-----------------|
// #insertCustomer(int)
//-----------------|
// Desc:   NULL
// Invars: NULL
   void insertCustomer(Cust*);

//-----------------|
// #getCustomerAt(int)
//-----------------|
// Desc:   NULL
// Invars: NULL
   Cust* getCustomerAt(int);

//-----------------|
// #appendHistory(Trans)
//-----------------|
// Desc:   NULL
// Invars: NULL
   void appendHistory(Trans);



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
   CustDB();

//-----------------|
// #~CustDB()
//-----------------|
// Desc:   NULL
// Invars: NULL
   ~CustDB();

}; // Closing class CustDB {}

// End of file - CustDB.h
