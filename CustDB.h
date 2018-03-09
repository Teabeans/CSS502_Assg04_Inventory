//-------------------------------------|
// Begin Student Code
//-------------------------------------|

// Requisite in the .h file
#pragma once

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
// Desc:   The customer database
// Invars: Table size must not exceed 9999, nearest prime is 9973
   Cust* custTable[MAXCUSTOMERS];

//-----------------|
// #custTableByID
//-----------------|
// Desc:   The customer database, sorted by customer ID number
// Invars: Table size to accommodate 
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

// None for this class



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CONSTRUCTORS / DESTRUCTORS (+)
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
