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
//       GET/SET METHODS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// Override Film::getReleaseDate()
std::string Classic::getReleaseDate() {

	// convert ints to string
	std::string rm = std::to_string(releaseMonth);
	std::string rd = std::to_string(releaseDate);
	std::string ret = rm + rd;

	return ret;
}


//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CONSTRUCTORS/DESTRUCTORS
//
//-------|---------|---------|---------|---------|---------|---------|---------|


Classic::Classic() {

}

Classic::Classic(std::string data) {
   // std::cerr << "creating Classic ";
   // std::cerr << data << std::endl;

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

   actors.push_back(items[0] + items[1]); // firstName + lastName
   releaseMonth = std::stoi(items[2]); // int
   releaseDate = std::stoi(items[3]); // int


   // std::cerr << "done creating Classic ";
}

Classic::~Classic() {
   // std::cerr << "destruct Classic" << std::endl;

}

// End of File - FilmClassic.cpp
