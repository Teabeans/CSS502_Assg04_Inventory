//-------|---------|---------|---------|---------|---------|---------|---------|
//
// UW CSS 502A - Assignment 4 - Inventory Management
// InvDB.h
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
// This is the header file for the InvDB class, representing a database of
// film objects
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

#pragma once

//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       INCLUDE STATEMENTS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

#include <iostream>
#include <string>
#include <vector>
#include "Trans.h"
#include "Film.h" // TODO: Omittable? Does the InvDB know about Films due to child classes?
#include "FilmClassic.h"
#include "FilmComedy.h"
#include "FilmDrama.h"

class InvDB {

private:
//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PRIVATE FIELDS (-)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

//-----------------|
// #comedies
//-----------------|
// Desc:   NULL
// Invars: NULL
std::vector<Comedy> comedies;

//-----------------|
// #dramas
//-----------------|
// Desc:   NULL
// Invars: NULL
std::vector<Drama> dramas;

//-----------------|
// #classics
//-----------------|
// Desc:   NULL
// Invars: NULL
std::vector<Classic> classics;



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PRIVATE METHODS (-)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

   int hashTitle(std::string);

   bool isValid(std::string);

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

   bool addClassic(Classic*);

   bool addComedy(Comedy*);

   bool addDrama(Drama*);

   void adjustStock(Trans&);

   bool contains(Film*);

   void display();

   bool isLegal(std::string);

   Film* retrieve(Film*);

   std::string toString();

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

   InvDB();

   InvDB(std::ifstream&);

   ~InvDB();


};
