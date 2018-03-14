//-------|---------|---------|---------|---------|---------|---------|---------|
//
// UW CSS 502A - Assignment 4 - Inventory Management
// FilmComedy.h
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
// This is the header file for the Comedy Film class, representing a single film
// of the comedy type, primarily separated from the generic film by identifying
// title and year as the relevant sorting criteria
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

// necessary for string operations
#include <string>

// parent class declaration
#include "Film.h"

class Comedy : public Film {

private:
//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PRIVATE FIELDS (-)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// None for this class



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

// Full comments in Film.cpp - omitted here for clarity

   // (+) --------------------------------|
   // #equals(Film&)
   //-------------------------------------|
   // Desc:   Compares 'this' Film against another by it's title and year
   // Invars: Release year and title must be initialized
   bool equals(Film&);

   // (+) --------------------------------|
   // #isLessThan(Film&)
   //-------------------------------------|
   // Desc:   Compares 'this' Film against another by it's title and year
   // Invars: Release year and title must be initialized
   bool isLessThan(Film&);

   // (+) --------------------------------|
   // #isGreaterThan(Film&)
   //-------------------------------------|
   // Desc:   Compares 'this' Film against another by it's title and year
   // Invars: Release year and title must be initialized
   bool isGreaterThan(Film&);



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CONSTRUCTORS / DESTRUCTORS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

   //-----------------|
   // #Comedy()
   //-----------------|
   // Desc:   Default constructor for the Comedy class
   // Invars: Fields are zeroed by Film superclass constructor
   Comedy();

   //-----------------|
   // #Comedy(string)
   //-----------------|
   // Desc:   Comedy constructor by string
   // Invars: GIGO - No error checking is performed by this method
   //         Command must be correctly formatted
   Comedy(std::string);

   //-----------------|
   // #~Comedy()
   //-----------------|
   // Desc:   Destructor for the Comedy class
   // Invars: None
   ~Comedy();

}; // Closing class Comedy {}

//-------------------------------------|
// End Student Code
//-------------------------------------|

// End of File - FilmComedy.h
