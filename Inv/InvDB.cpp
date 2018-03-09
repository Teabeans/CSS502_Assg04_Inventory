#include "InvDB.h"

// film types
#include "Film.h"
#include "Classic.h"
#include "Drama.h"
#include "Comedy.h"

// transactions
#include "../Trans/Trans.h"
#include "../Trans/Borrow.h"
#include "../Trans/Return.h"

// Necessary for file stream object handling
#include <fstream>
#include <string>



std::string InvDB::toString() {
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
}

void InvDB::display() {

   std::cout << toString();
}

void InvDB::adjustStock(Trans& trans) {

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




/**
 * addComedy
 * Desc: adds a new film onject to the list
**/
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

/**
 * addDrama
 * Desc: adds a new film onject to the list
**/
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

/**
 * addClassic
 * Desc: adds a new film onject to the list
**/
bool InvDB::addClassic(Classic* film) {
   // sorted by release date, then actor -- 

   // TODO: Update film objects to support actor as just a string
   // update classic constructor with actor as a string
   // update display method to just display a list of all classic films sorted by the new actor field
   // update adjustStock to handle sharing invetory between classic films with the same title and release date


   classics.push_back(*film);
   return(true);
}

/**
 * isLegal
 * Desc: checks that an item exists, 
**/
bool InvDB::isLegal(std::string command) {

   return true;
}







//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CONSTRUCTORS/DSTRUCTOR
//
//-------|---------|---------|---------|---------|---------|---------|---------|

/**
 * Int Constructor
 * Desc: uses a default size to dynamically allocate a new array
**/
InvDB::InvDB() {

}

/**
 * Int Constructor
 * Desc: takes in a size array and dynamically allocates an array to hold
 * the film titles
 * Pre: expects size to be generated by IntenvoryController
**/
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

InvDB::~InvDB() {
   // std::cerr << "destruct invDB" << std::endl;

   // std::cerr << "end destruct invDB" << std::endl;
}
