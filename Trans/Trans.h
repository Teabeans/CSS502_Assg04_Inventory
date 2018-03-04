//-------------------------------------|
// Begin Student Code
//-------------------------------------|

// Requisite in the .h file
#pragma once

// Necessary for string operations
#include <string>

//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CLASS CONSTANTS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// None for this class



class Trans {

private:
//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PRIVATE FIELDS (-)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

//-----------------|
// #type
//-----------------|
// Desc:   The transaction type (borrow or return)
// Invars: Initializes to junk values
   char type;

//-----------------|
// #genre
//-----------------|
// Desc:   Genre of the thing transacted
// Invars: Initializes to junk values
   std::string genre;

//-----------------|
// #title
//-----------------|
// Desc:   Identifier of the thing transacted
// Invars: Initializes to junk values
   std::string title;

//-----------------|
// #identifier1
// #identifier2
//-----------------|
// Desc:   Unique identifiers of the transaction
// Invars: Initializes to junk values
   std::string identifier1; //first identifier (eg. title or major actor)
   std::string identifier2; //second identifier (eg. year or release date)

//-----------------|
// #customerID
//-----------------|
// Desc:   The transaction type
// Invars: Initializes to junk values
   int customerID; // To whom it was transacted

//-----------------|
// #qty
//-----------------|
// Desc:   The quantity of the transaction
// Invars: Initializes to junk values
   int qty;



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PRIVATE METHODS (-)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// None for this class



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

// Full comments in Cust.cpp - omitted here for clarity

//-----------------|
// #toString();
//-----------------|
// Desc:   Converts this transaction to a string representation
// Invars: GIGO - No error checking is performed by toString()
   std::string toString();



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       GETTERS / SETTERS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// Full comments in Cust.cpp - omitted here for clarity

//-----------------|
// #getType()
// #getGenre()
// #getTitle()
// #getIdentifier1()
// #getIdentifier2()
// #getCustID()
// #getQty()
//-----------------|
// Desc:   Returns transaction data fields
// Invars: None
   char        getType();
   std::string getGenre();
   std::string getTitle();
   std::string getIdentifier1();
   std::string getIdentifier2();
   int         getCustID();
   int         getQty();

//-----------------|
// #setType()
// #setGenre()
// #setTitle()
// #setIdentifier1()
// #setIdentifier2()
// #setCustID()
// #setQty()
//-----------------|
// Desc:   Returns transaction data fields
// Invars: None
   void setType(char transType);
   void setGenre(std::string genre);
   void setTitle(std::string title);
   void setIdentifier1(std::string trait);
   void setIdentifier2(std::string trait);
   void setCustID(int IDnum);
   void setQty(int quantity);


 
//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CONSTRUCTORS / DESTRUCTORS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// Full comments in Cust.cpp - omitted here for clarity

//-----------------|
// #factory(string);
//-----------------|
// Desc:   Factory constructor
// Invars: GIGO - No error checking is performed by factory()
   Trans* factory(std::string);

//-----------------|
// #Trans()
//-----------------|
// Desc:   Default Transaction constructor. Should not be used.
// Invars: None
   Trans();

//-----------------|
// #Trans(string)
//-----------------|
// Desc:   Transaction constructor by string
// Invars: GIGO - No error checking is performed by the constructor
   Trans(std::string);

//-----------------|
// #~Trans()
//-----------------|
// Desc:   Transaction deconstructor
// Invars: None
   ~Trans();
};
