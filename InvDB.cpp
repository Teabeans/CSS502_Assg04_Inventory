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



// Necessary for film objects
#include "Film.h"
#include "FilmClassic.h"
#include "FilmDrama.h"
#include "FilmComedy.h"

// Necessary for transaction objects
#include "Trans.h"
#include "TransBorrow.h"
#include "TransReturn.h"

#include "InvDB.h"

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
   // @TB: Let'd discard it. The hash function won't provide anything for storing
   //      the films, and it'll mess up the sorting. So long as we have the hash in
   //      the custDB we'll be fine.
   return(0);
}



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PUBLIC FIELDS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PUBLIC METHODS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// (+) --------------------------------|
// #runCmd(string)
//-------------------------------------|
// Desc:    Accepts a command string and executes it
// Note:    For establishing inventory only, not for transactions afterwards
// Params:  string arg1 - The line of command (sourced from data4movies.txt)
// PreCons: All error checks have been performed prior to command receival
//          arg1 is verified to be a syntactically and logically valid command
// PosCons: The inventory database holds the film and data provided by the command
// RetVal:  None
// MetCall: NULL
void InvDB::runCmd(std::string command) {
   // Example inputs:
   // C, 10, Victor Fleming, The Wizard of Oz, Judy Garland 7 1939
   // D, 10, Steven Spielberg, Schindler's List, 1993
   // F, 10, Rob Reiner, When Harry Met Sally, 1989
}

// (+) --------------------------------|
// #addFilm(Film*)
//-------------------------------------|
// Desc:    Adds a new generic film object to the list
// Note:    Sorted by title
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
bool InvDB::addFilm(Film* film) {
   int index = 0;

   if (film->getGenre() == 'F') {

      // find the appropriate position in the comedies vector
      auto iterator = comedies.begin();
      for (int i = 0; i < comedies.size(); i++) {
         if (comedies.at(i) > *film) break;
         iterator++;
      }
      comedies.insert(iterator, *film);
   }

   else if (film->getGenre() == 'D') {

      // find the appropriate position in the dramas vector
      auto iterator = dramas.begin();
      for (int i = 0; i < dramas.size(); i++) {
         if (dramas.at(i) > *film) break;
         iterator++;
      }
      dramas.insert(iterator, *film);
   }

   else if (film->getGenre() == 'C') {

      // find the appropriate position in the classics vector
      auto iterator = classics.begin();
      for (int i = 0; i < classics.size(); i++) {
         if (classics.at(i) > *film) break;
         iterator++;
      }
      classics.insert(iterator, *film);
   }

   else {

      // find the appropriate position in the otherFilms vector
      auto iterator = otherFilms.begin();
      for (int i = 0; i < otherFilms.size(); i++) {
         if (otherFilms.at(i) > *film) break;
         iterator++;
      }
      otherFilms.insert(iterator, *film);
   }

   return true;
} // Closing addFilm()

// (+) --------------------------------|
// #adjustStock(Trans&)
//-------------------------------------|
// Desc:    Updates the stock value of a film based on the arg transaction
// Params:  transaction object
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
void InvDB::adjustStock(Trans& trans) { // TODO: Add const to Trans& argument?

   // std::cerr << "Trans Data: " << trans.getTitle() << " : " << trans.getReleaseYear() << std::endl;

   // if (trans.getGenre() == 'F') {
   //    Comedy film;
   //    film.setTitle(trans.getTitle());

   //    film.setReleaseYear(std::stoi(trans.getRelease()));

   //    film.setReleaseDate(trans.getReleaseYear());


   //    if (trans.getType() == 'B') {
   //       retrieve(&film)->setStock(retrieve(&film)->getStock() + 1);
   //    }
   //    else {
   //       retrieve(&film)->setStock(retrieve(&film)->getStock() - 1);
   //    }
   // }

   // else if (trans.getGenre() == 'D') {
      
   // }

   // else if (trans.getGenre() == 'C') {
   //    Classic filmAA("C, 0, , , ");
      
   // }

}

// (+) --------------------------------|
// #contains(Film*)
//-------------------------------------|
// Desc:    Checks the DB for a particular film
// Params:  Ptr to film object
// PreCons: NULL
// PosCons: NULL
// RetVal:  True if the film is present, False otherwise
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
   }
   return alreadyContainsFilm;

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
// #retrieve(Film*)
//-------------------------------------|
// Desc:    Searches for a film object and returns it instead of a bool
// Params:  Film object to be found
// PreCons: NULL
// PosCons: NULL
// RetVal:  Pointer to the film object
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
// #toString()
//-------------------------------------|
// Desc:    Outputs a string representation of the InvDB
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  string
// MetCall: NULL
std::string const InvDB::toString() { // TODO: @MG - Verify inclusion of const?
   std::string retString = "";

   retString += "Comedy films: \n";

   for (int i = 0; i < comedies.size(); i++) {
      retString += std::to_string(comedies.at(i).getStock()) + ", ";
      retString += comedies.at(i).getTitle() + ", ";
      retString += comedies.at(i).getDirector() + ", ";
      retString += std::to_string(comedies.at(i).getReleaseYear()) + "\n";
   }


   retString += "Drama films: \n";

   for (int i = 0; i < dramas.size(); i++) {
      retString += std::to_string(dramas.at(i).getStock()) + ", ";
      retString += dramas.at(i).getTitle() + ", ";
      retString += dramas.at(i).getDirector() + ", ";
      retString += std::to_string(dramas.at(i).getReleaseYear()) + "\n";
   }


   retString += "Classic films: \n";

   for (int i = 0; i < classics.size(); i++) {
      retString += std::to_string(classics.at(i).getStock()) + ", ";
      retString += classics.at(i).getTitle() + ", ";
      retString += classics.at(i).getDirector() + ", ";
      retString += classics.at(i).getActor() + ", ";
      retString += std::to_string(classics.at(i).getReleaseMonth()) + " ";
      retString += std::to_string(classics.at(i).getReleaseYear()) + "\n";
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
            addFilm(new Comedy(filmData));
         }

         // create Drama object and add to database
         else if (filmData.at(0) == 'D') {
            addFilm(new Drama(filmData));
         }

         // check Classic object and add to database
         else if (filmData.at(0) == 'C') {
            addFilm(new Classic(filmData));
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
