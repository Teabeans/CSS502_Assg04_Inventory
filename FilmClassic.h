//-------|---------|---------|---------|---------|---------|---------|---------|
//
// UW CSS 502A - Assignment 4 - Inventory Management
// FilmClassic.h
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
// This is the header file for the Classic Film class, representing a Film
// subclass. It requires additional data, such as a release month and actor.
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

class Classic : public Film {

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
   // Desc:   Compares 'this' Film against another by it's release date and actor
   // Invars: Release year must be initialized
   //         Release month and actor will be referenced in the event of a tie
   bool equals(Film&);

   // (+) --------------------------------|
   // #isLessThan(Film&)
   //-------------------------------------|
   // Desc:   Compares 'this' Film against another by it's release date and actor
   // Invars: Release year must be initialized
   //         Release month and actor will be referenced in the event of a tie
   bool isLessThan(Film&);

   // (+) --------------------------------|
   // #isGreaterThan(Film&)
   //-------------------------------------|
   // Desc:   Compares 'this' Film against another by it's release date and actor
   // Invars: Release year must be initialized
   //         Release month and actor will be referenced in the event of a tie
   bool isGreaterThan(Film&);



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CONSTRUCTORS / DESTRUCTORS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

   //-----------------|
   // #Classic()
   //-----------------|
   // Desc:   Default constructor for the Classic class
   // Invars: None
   Classic();

   //-----------------|
   // #Classic(string)
   //-----------------|
   // Desc:   Classic constructor by string
   // Invars: GIGO - No error checking is performed by this method
   //         Command must be correctly formatted
   Classic(std::string);

   //-----------------|
   // #~Classic()
   //-----------------|
   // Desc:   Destructor for the Classic class
   // Invars: None
   ~Classic();

}; // Closing class Classic {}

//-------------------------------------|
// End Student Code
//-------------------------------------|

// End of File - FilmClassic.h
