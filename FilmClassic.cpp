//-------|---------|---------|---------|---------|---------|---------|---------|
//
// UW CSS 502A - Assignment 4 - Inventory Management
// Classic.cpp
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
// This is the implementation file for the Classic.h header.
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

// Necessary for string operations
#include <string>

// Necessary for input-output operations
#include <iostream>

// Field and method declarations for the Classic class
#include "FilmClassic.h"



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
bool Classic::equals(Film& rhs) {

   return (releaseMonth == rhs.getReleaseYear() 
           && releaseYear == rhs.getReleaseMonth()
           && actor == rhs.getActor());
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
bool Classic::isLessThan(Film& rhs) {

   if (releaseYear < rhs.getReleaseYear()) {
      return true;
   }
   // if the year is the same, check the month
   else if (releaseYear == rhs.getReleaseYear() && releaseMonth < rhs.getReleaseMonth()) {
      return true;
   }
   // if the year and month are the same, check the major actor
   else if (releaseYear == rhs.getReleaseYear() && releaseMonth == rhs.getReleaseMonth()
            && actor < rhs.getActor()) {
      return true;
   }
   else {
      return false;
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
bool Classic::isGreaterThan(Film& rhs) {

   return (!isLessThan(rhs) && !equals(rhs));
}


//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CONSTRUCTORS/DESTRUCTORS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// (+) --------------------------------|
// #Classic()
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
Classic::Classic() {

}

// (+) --------------------------------|
// #Classic(string)
//-------------------------------------|
// Desc:    Overrides the Film(string) constructor, adding logic to parse actors
// Params:  string arg1 - 
// PreCons: GIGO - No error checking is performed by this method
//          Command must be correctly formatted
// PosCons: The inventory command has been parsed and integrated to 'this' Film
// RetVal:  None
// MetCall: std::string.substr()
//          std::string.find()
//          std::string.erase()
//          std::string.find()
//          std::string.length()
//          std::stoi()
Classic::Classic(std::string command) {
   // Sample input:
   // C, 10, George Cukor, Holiday, Katherine Hepburn 9 1938

   // For the first 4 elements...
   // Split the regular film data items by commans and insert those to 
   // the appropriate data members
   std::string delim = ", ";
   std::string items[4];

   // Capture 4 elements
   for (int i = 0; i < 4; i++) {
      items[i] = command.substr(0, command.find(delim));
      command.erase(0, command.find(delim) + delim.length());
   }

   // Assign to variables
   this->genre    = items[0][0]; // char
   this->stock    = std::stoi(items[1]); // int
   this->director = items[2];
   this->title    = items[3];

   // Change the delimiter for the last 4 elements
   // Split the last two items by spaces to incorprate the major actor and date
   delim = " ";

   // Capture 4 elements
   for (int i = 0; i < 4; i++) {
      items[i] = command.substr(0, command.find(delim));
      command.erase(0, command.find(delim) + delim.length());
   }

   // Assign to variables
   this->actor = items[0] + " " + items[1]; // strings: firstName lastName
   this->releaseMonth = std::stoi(items[2]); // int
   this->releaseYear = std::stoi(items[3]); // int
} // Closing Classic(string)

// (+) --------------------------------|
// #~Classic()
//-------------------------------------|
// Desc:    Destructor for the Classic class
// Params:  None
// PreCons: None
// PosCons: Fields have been zeroed
// RetVal:  None
// MetCall: None
Classic::~Classic() {
   // None specific to this subclass
} // Closing ~Classic()

//-------------------------------------|
// End Student Code
//-------------------------------------|

// End of File - FilmClassic.cpp
