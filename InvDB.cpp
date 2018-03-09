//-------|---------|---------|---------|---------|---------|---------|---------|
//
// UW CSS 502A - Assignment 4 - Inventory Management
// InvDB.cpp
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
// This is the implementation file for the InvDB.h header, representing a
// database of film objects
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

#include "InvDB.h"

// film types
#include "Film.h"
#include "FilmClassic.h"
#include "FilmDrama.h"
#include "FilmComedy.h"

// transactions
#include "Trans.h"
#include "TransBorrow.h"
#include "TransReturn.h"

// Necessary for file stream object handling
#include <fstream>
#include <string>



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PRIVATE FIELDS (-)
//
//-------|---------|---------|---------|---------|---------|---------|---------|
//
// Do not redeclare these variables in the .cpp.
// Included here only for reference
// See associated .h file for variable declarations

//-----------------|
// #comedies
//-----------------|
// Desc:   NULL
// Invars: NULL
/// std::vector<Comedy> comedies;

//-----------------|
// #dramas
//-----------------|
// Desc:   NULL
// Invars: NULL
/// std::vector<Drama> dramas;

//-----------------|
// #classics
//-----------------|
// Desc:   NULL
// Invars: NULL
/// std::vector<Classic> classics;



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PRIVATE METHODS (-)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

int InvDB::hashTitle(std::string someTitle) {
   // TODO: Implement or discard?
   return(0);
}



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PUBLIC FIELDS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// (+) --------------------------------|
// #addClassic(Classic*)
//-------------------------------------|
// Desc:    Adds a new film onject to the list
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
bool InvDB::addClassic(Classic* film) {
   // sorted by release date, then actor -- 

   // TODO: Update film objects to support actor as just a string
   // update classic constructor with actor as a string
   // update display method to just display a list of all classic films sorted by the new actor field
   // update adjustStock to handle sharing invetory between classic films with the same title and release date


   classics.push_back(*film);
   return true;
}

// (+) --------------------------------|
// #addComedy(Comedy*)
//-------------------------------------|
// Desc:    Adds a new film onject to the list
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
bool InvDB::addComedy(Comedy* film) {

   int index = 0;
   auto iterator = comedies.begin();

   for (int i = 0; i < comedies.size(); i++) {
      if (comedies.at(i) > *film) break;
      iterator++;
      std::cerr << "i: " << i << std::endl;
   }

   comedies.insert(iterator, *film);
   return true;
}

// (+) --------------------------------|
// #addDrama(Drama*)
//-------------------------------------|
// Desc:    Adds a new film onject to the list
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
bool InvDB::addDrama(Drama* film) {

   int index = 0;
   auto iterator = dramas.begin();
   for (int i = 0; i < dramas.size(); i++) {
      if (dramas.at(i) > *film) break;
      iterator++;
      std::cerr << "i: " << i << std::endl;
   }
   dramas.insert(iterator, *film);
   return true;
}

// (+) --------------------------------|
// #addFilm(Film*)
//-------------------------------------|
// Desc:    Adds a new film object to the list
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
bool InvDB::addFilm(Film* film) {
   // TODO: Implement
   return true;
} // Closing addFilm()

// (+) --------------------------------|
// #adjustStock(Trans&)
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
void InvDB::adjustStock(Trans& trans) { // TODO: Add const to Trans& argument?

   std::cerr << "Trans Data: " << trans.getTitle() << " : " << trans.getRelease() << std::endl;

   if (trans.getGenre() == 'F') {
      Comedy film;
      film.setTitle(trans.getTitle());
      film.setReleaseDate(std::stoi(trans.getRelease()));

      if (trans.getType() == 'B') {
         retrieve(&film)->setStock(retrieve(&film)->getStock() + 1);
      }
      else {
         retrieve(&film)->setStock(retrieve(&film)->getStock() - 1);
      }
   }

   else if (trans.getGenre() == 'D') {
      
   }

   else if (trans.getGenre() == 'C') {
      Classic filmAA("C, 0, , , ");
      
   }

}

// (+) --------------------------------|
// #contains(Film*)
//-------------------------------------|
// Desc:    Outputs a string representation of the InvDB
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
bool InvDB::contains(Film* film) {

   // search the table for the film being added to see if it's already present
   bool alreadyContainsFilm = false;
   int index = 0; 

   // if this film is a comedy
   if (film->getGenre() == 'F') {
      while (index < comedies.size()) {
         if (comedies.at(index) == *film) {
            alreadyContainsFilm = true;
            break;
         }
         else {
            index++;
         }
      }

      return alreadyContainsFilm;
   }
   // if this film is a drama
   else if (film->getGenre() == 'D') {
      while (index < dramas.size()) {
         if (dramas.at(index) == *film) {
            alreadyContainsFilm = true;
            break;
         }
         else {
            index++;
         }
      }

      return alreadyContainsFilm;
   }
   // if this film is a classic
   else if (film->getGenre() == 'C') {
      while (index < classics.size()) {
         if (classics.at(index) == *film) {
            alreadyContainsFilm = true;
            break;
         }
         else {
            index++;
         }
      }

      return alreadyContainsFilm;
   }
   else {
      return false;
   }
}

// (+) --------------------------------|
// #display()
//-------------------------------------|
// Desc:    Displays to cout the status of the InvDB
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
void InvDB::display() {
   std::cout << toString();
}

// (+) --------------------------------|
// #isLegal()
//-------------------------------------|
// Desc:    Tests the legality of a received command string
//          Outputs an error to cout for illegal conditions
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
bool InvDB::isLegal(std::string command) {
   // TODO: Implement
   return true;
}

// (+) --------------------------------|
// #isValid()
//-------------------------------------|
// Desc:    Tests the legality of a received command string
//          Outputs an error to cout for illegal conditions
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
bool InvDB::isValid(std::string someCommand) {
   // TODO: Implement? Driver currently calls 'isValid', but that can be changed
   return(true);
}

// (+) --------------------------------|
// #retrieve(Film*)
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
Film* InvDB::retrieve(Film* film) {

   // search the table for the film being added to see if it's already present
   int index = 0; 

   // if this film is a comedy
   if (film->getGenre() == 'F') {
      while (index < comedies.size()) {
         if (comedies.at(index) == *film) {
            break;
         }
         else {
            index++;
         }
      }

      return &comedies.at(index);
   }

   else if (film->getGenre() == 'D') {
      while (index < dramas.size()) {
         if (dramas.at(index) == *film) {
            break;
         }
         else {
            index++;
         }
      }

      return &dramas.at(index);
   }

   else if (film->getGenre() == 'C') {
      while (index < classics.size()) {
         if (classics.at(index) == *film) {
            break;
         }
         else {
            index++;
         }
      }

      return &classics.at(index);
   }
   else {
      return NULL;
   }
}

// (+) --------------------------------|
// #toString()
//-------------------------------------|
// Desc:    Outputs a string representation of the InvDB
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
std::string const InvDB::toString() { // TODO: @MG - Verify inclusion of const?
   std::string retString = "";

   retString += "Comedy Films: \n";

   for (int i = 0; i < comedies.size(); i++) {
      retString += std::to_string(comedies.at(i).getStock()) + ", ";
      retString += comedies.at(i).getTitle() + ", ";
      retString += comedies.at(i).getDirector() + ", ";
      retString += std::to_string(comedies.at(i).getReleaseDate()) + "\n";
   }


   retString += "Drama Films: \n";

   for (int i = 0; i < dramas.size(); i++) {
      retString += std::to_string(dramas.at(i).getStock()) + ", ";
      retString += dramas.at(i).getTitle() + ", ";
      retString += dramas.at(i).getDirector() + ", ";
      retString += std::to_string(dramas.at(i).getReleaseDate()) + "\n";
   }


   retString += "Classic Films: \n";

   for (int i = 0; i < classics.size(); i++) {
      retString += std::to_string(classics.at(i).getStock()) + ", ";
      retString += classics.at(i).getTitle() + ", ";
      retString += classics.at(i).getDirector() + ", ";
      retString += classics.at(i).getReleaseDate() + "\n";
   }

   return (retString);
} // Closing toString()



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CONSTRUCTORS/DSTRUCTOR
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// (+) --------------------------------|
// #InvDB()
//-------------------------------------|
// Desc:    Default InvDB constructor
// Params:  NULL
// PreCons: NULL
// PosCons: An empty InvDB object has been created
// RetVal:  None
// MetCall: NULL
InvDB::InvDB() {
   // TODO: Initialize all fields (to keep g++ happy)
} // Closing InvDB()

// (+) --------------------------------|
// #InvDB(ifstream&)
//-------------------------------------|
// Desc:    InvDB constructor by bulk command set
// Params:  ifstream& arg1 - The bulk set of inventory commands
// PreCons: NULL
// PosCons: NULL
// RetVal:  None
// MetCall: NULL
InvDB::InvDB(std::ifstream& data) {

   while (!data.eof()) {
      // Read the next relevant line of command
      std::string filmData;
      std::getline(data, filmData);

      if (filmData.length() > 10) {
         // create Comedy object and add to database
         if (filmData.at(0) == 'F') {
            addComedy(new Comedy(filmData));
         }

         // create Drama object and add to database
         else if (filmData.at(0) == 'D') {
            addDrama(new Drama(filmData));
         }

         // check Classic object and add to database
         else if (filmData.at(0) == 'C') {
            addClassic(new Classic(filmData));
         }

         // otherwise, this is an invalid film type
         else {
            std::cerr << "Invalid film type: " << filmData.at(0) << std::endl;
         }
      }
   }
}

// (+) --------------------------------|
// #~InvDB()
//-------------------------------------|
// Desc:    InvDB deconstructor
// Params:  None
// PreCons: NULL
// PosCons: NULL
// RetVal:  None
// MetCall: NULL
InvDB::~InvDB() {
   // std::cerr << "destruct invDB" << std::endl;

   // std::cerr << "end destruct invDB" << std::endl;
}

//-------------------------------------|
// End Student Code
//-------------------------------------|

// End of file - InvDB.cpp
