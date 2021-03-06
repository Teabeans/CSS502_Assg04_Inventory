//-------|---------|---------|---------|---------|---------|---------|---------|
//
// UW CSS 502A - Assignment 4 - Inventory Management
// Trans.h
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
// This is the declaration file for the Trans class, representing a
// transaction (attempted borrow or return) of a Film object
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
// #typeAsString
//-----------------|
// Desc:   The transaction type (borrow or return)
// Invars: Initializes to junk values
   char type;
   std::string typeAsString;

//-----------------|
// #genre
// #genreAsString
//-----------------|
// Desc:   Genre of the thing transacted
// Invars: Initializes to junk values
   char genre;
   std::string genreAsString;

//-----------------|
// #title
//-----------------|
// Desc:   Identifier of the thing transacted
// Invars: Initializes to junk values
   std::string title;

//-----------------|
// #director
// #actor
//-----------------|
// Desc:   Unique identifiers of the transaction
// Invars: Initializes to junk values
   std::string director; // Director
   std::string actor; // Note, one transaction can only hold one actor

//-----------------|
// #release
//-----------------|
// Desc:   A string representation of the release date
// Invars: Initializes to junk values
   int releaseMonth;
   int releaseYear;

//-----------------|
// #customerID
//-----------------|
// Desc:   The transaction type
// Invars: Initializes to junk values
   int customerID; // To whom it was transacted



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
// #debug();
//-----------------|
// Desc:   Displays all internal states to cout
// Invars: None
   void debug() const;

//-----------------|
// #toString();
//-----------------|
// Desc:   Converts this transaction to a string representation
// Invars: GIGO - No error checking is performed by toString()
   std::string toString() const;



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
// #getDirector()
// #getActor()
// #getRelease()
// #getCustID()
//-----------------|
// Desc:   Returns transaction data fields
// Invars: None
   char        getType() const;
   std::string getTypeAsString() const;
   char        getGenre() const;
   std::string getGenreAsString() const;
   std::string getTitle() const;
   std::string getDirector() const;
   std::string getActor() const;
   int         getReleaseMonth() const;
   int         getReleaseYear() const;
   int         getCustID() const;

//-----------------|
// #setType()
// #setGenre()
// #setTitle()
// #getDirector()
// #getActor()
// #getRelease()
// #setCustID()
//-----------------|
// Desc:   Sets transaction data fields
// Invars: None
   void setType(char transType);
   void setTypeAsString(std::string transType);
   void setGenre(char theGenre);
   void setGenreAsString(std::string theGenre);
   void setTitle(std::string theTitle);
   void setDirector(std::string director);
   void setActor(std::string actor);
   void setReleaseMonth(int month);
   void setReleaseYear(int year);
   void setCustID(int IDnum);



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CONSTRUCTORS / DESTRUCTORS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// Full comments in Cust.cpp - omitted here for clarity

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

//-------------------------------------|
// End Student Code
//-------------------------------------|

// End of file - Trans.h
