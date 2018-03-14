//-------|---------|---------|---------|---------|---------|---------|---------|
//
// UW CSS 502A - Assignment 4 - Inventory Management
// FilmDrama.h
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
// This is the header file for the Drama Film class, representing a single film
// of the drama type, primarily separated from the generic film by identifying
// director and title as the relevant sorting criteria
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

class Drama : public Film {

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
   // Desc:   Compares 'this' Film against another by it's director and title
   // Invars: Release year and title must be initialized
   bool equals(Film&);

   // (+) --------------------------------|
   // #isLessThan(Film&)
   //-------------------------------------|
   // Desc:   Compares 'this' Film against another by it's director and title
   // Invars: Release year and title must be initialized
   bool isLessThan(Film&);

   // (+) --------------------------------|
   // #isGreaterThan(Film&)
   //-------------------------------------|
   // Desc:   Compares 'this' Film against another by it's director and title
   // Invars: Release year and title must be initialized
   bool isGreaterThan(Film&);



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CONSTRUCTORS / DESTRUCTORS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

   //-----------------|
   // #Drama()
   //-----------------|
   // Desc:   Default constructor for the Drama class
   // Invars: Fields are zeroed by Film superclass constructor
   Drama();

   //-----------------|
   // #Drama(string)
   //-----------------|
   // Desc:   Drama constructor by string
   // Invars: GIGO - No error checking is performed by this method
   //         Command must be correctly formatted
   Drama(std::string);

   //-----------------|
   // #~Drama()
   //-----------------|
   // Desc:   Destructor for the Drama class
   // Invars: None
   ~Drama();

}; // Closing class Drama {}

//-------------------------------------|
// End Student Code
//-------------------------------------|

// End of File - FilmDrama.h
