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

#include <string>
#include <iostream>
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
   std::cerr << "Classic:equals" << std::endl;

   if (releaseMonth == rhs.getReleaseYear() && releaseYear == rhs.getReleaseMonth()
       && actor == rhs.getActor()) {
      return true;
   }
   else {
      return false;
   }
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

   if (releaseYear > rhs.getReleaseYear()) {
      return true;
   }
   // if the year is the same, check the month
   else if (releaseYear == rhs.getReleaseYear() && releaseMonth > rhs.getReleaseMonth()) {
      return true;
   }
   // if the year and month are the same, check the major actor
   else if (releaseYear == rhs.getReleaseYear() && releaseMonth == rhs.getReleaseMonth()
            && actor > rhs.getActor()) {
      return true;
   }
   else {
      return false;
   }
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
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
Classic::Classic(std::string data) {

   // split the regular film data items by commans and insert those to 
   // the appropriate data members
   std::string delim = ", ";
   std::string items[4];

   for (int i = 0; i < 4; i++) {
      items[i] = data.substr(0, data.find(delim));
      data.erase(0, data.find(delim) + delim.length());
   }

   genre = items[0][0]; // char
   stock = std::stoi(items[1]); // int
   director = items[2];
   title = items[3];

   // split the last two items by spaces to incorprate the major actor and date
   delim = " ";

   for (int i = 0; i < 4; i++) {
      items[i] = data.substr(0, data.find(delim));
      data.erase(0, data.find(delim) + delim.length());
   }

   actor = items[0] + " " + items[1]; // strings: firstName lastName
   releaseMonth = std::stoi(items[2]); // int
   releaseYear = std::stoi(items[3]); // int
}

// (+) --------------------------------|
// #~Classic()
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
Classic::~Classic() {

}

// End of File - FilmClassic.cpp
