// Film.cpp
#include <string>
#include <iostream>
#include "Film.h"

Film::Film() {

}

Film::Film(std::string data) {
	// std::cerr << "creating film";
   std::cerr << data << std::endl;

   // split the data string by commas and parse into object data
   std::string delim = ", ";
   std::string items[5];

   for (int i = 0; i < 5; i++) {
      items[i] = data.substr(0, data.find(delim));
      data.erase(0, data.find(delim) + delim.length());
   }

   genre = items[0][0]; // char
   stock = std::stoi(items[1]); // int
   director = items[2];
   title = items[3];
   releaseDate = std::stoi(items[4]); // int

   // std::cerr << " : genre: " << genre;
   // std::cerr << " : stock: " << stock;
   // std::cerr << " : director: " << director;
   // std::cerr << " : title: " << title;
   // std::cerr << " : release: " << releaseDate;
}

Film::~Film() {

}

/**
 * == operator
 * Desc: compares two films based on title & release date
 * Pre: assumes title and release data are populated
**/
bool Film::operator==(Film& rhs) {

   if (title == rhs.title && releaseDate == rhs.releaseDate) {
      return true;
   }
   else {
      return false;
   }
}