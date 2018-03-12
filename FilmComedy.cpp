//-------|---------|---------|---------|---------|---------|---------|---------|
//
// UW CSS 502A - Assignment 4 - Inventory Management
// Comedy.cpp
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
// This is the implementation file for the Comedy.h header.
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

#include <string>
#include <sstream>
#include <iostream>
#include "FilmComedy.h"



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PUBLIC METHODS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// (+) --------------------------------|
// #equals(Film&)
//-------------------------------------|
// Desc:    Tests the film against another based on it's release date, then 
//          major actor
// Params:  None
// PreCon:  Release date and release month, and actor must be populated
// PosCons: NULL
// RetVal:  True or False
// MetCall: NULL
bool Comedy::equals(Film& rhs) {

   return (this->getTitle() == rhs.getTitle() 
           && this->getReleaseYear() == rhs.getReleaseYear());
}

// (+) --------------------------------|
// #isLessThan(Film&)
//-------------------------------------|
// Desc:    Tests the film against another based on it's release date, then 
//          major actor
// Params:  None
// PreCon:  Release date and release month, and actor must be populated
// PosCons: NULL
// RetVal:  True or False
// MetCall: NULL
bool Comedy::isLessThan(Film& rhs) {

   // If the director is lesser...
   if (this->getTitle() < rhs.getTitle()) {
      return(true);
   }
   // If the director matches
   else if (this->getTitle() == rhs.getTitle()) {
      // Then compare titles
      if (this->getReleaseYear() < rhs.getReleaseYear()) {
         return(true);
      }
      // Greater than or equal to case
      return(false);
   }
   // Director must by greater than
   else {
      return(false);
   }
}

// (+) --------------------------------|
// #isGreaterThan(Film&)
//-------------------------------------|
// Desc:    Tests the film against another based on it's release date, then 
//          major actor
// Params:  None
// PreCon:  Release date and release month, and actor must be populated
// PosCons: NULL
// RetVal:  True or False
// MetCall: NULL
bool Comedy::isGreaterThan(Film& rhs) {

   return (!isLessThan(rhs) && !equals(rhs));
}


//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CONSTRUCTORS/DESTRUCTORS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// (+) --------------------------------|
// #Comedy()
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
Comedy::Comedy() {

}

// (+) --------------------------------|
// #Comedy(string)
//-------------------------------------|
// Desc:    Overrides the Film(string) constructor, adding logic to parse director and title
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
Comedy::Comedy(std::string data) {
   // Sample input
   // "F, 10, Nora Ephron, You've Got Mail, 1998"
   // split the regular film data items by commans and insert those to 
   // the appropriate data members

   std::stringstream stream(data);
   stream>>std::noskipws;

   char temp;

   // Capture the first letter
   stream >> this->genre;
   // F, 10, Nora Ephron, You've Got Mail, 1998
   // ^

   // Remove the ", "
   stream >> temp;
   stream >> temp;
   // F, 10, Nora Ephron, You've Got Mail, 1998
   //   ^

   // Capture the stock amount
   stream >> this->stock;
   // F, 10, Nora Ephron, You've Got Mail, 1998
   //   ^  -

   // Remove the ", "
   stream >> temp;
   stream >> temp;
   // F, 10, Nora Ephron, You've Got Mail, 1998
   //       ^

   // Capture the first letter of the director
   stream >> temp;
   // F, 10, Nora Ephron, You've Got Mail, 1998
   //        ^

   // Capture the director
   std::string theDirector;
   while (temp != ',') {
     theDirector += temp;
     stream >> temp;
   }
   // Assign the director
   this->setDirector(theDirector);
   // F, 10, Nora Ephron, You've Got Mail, 1998
   //                   ^

   // Remove the ", "
   stream >> temp;
   stream >> temp;

   // F, 10, Nora Ephron, You've Got Mail, 1998
   //                     ^

   std::string theTitle;
   while (temp != ',') {
      theTitle += temp;
      stream >> temp;
   }
   // Assign the title
   this->setTitle(theTitle);
   // F, 10, Nora Ephron, You've Got Mail, 1998
   //                                    ^


   // Remove the ", "
   stream >> temp;
   // F, 10, Nora Ephron, You've Got Mail, 1998
   //                                     ^

   int theYear;
   stream >> theYear;

   //Capture the releaseYear
   this->setReleaseYear(theYear);
}

// (+) --------------------------------|
// #~Comedy()
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
Comedy::~Comedy() {

}

// End of File - FilmDrama.cpp
