// Comedy.cpp
#include <string>
#include <iostream>
#include "Comedy.h"

Comedy::Comedy() {

}

Comedy::Comedy(std::string data) : Film(data) {
   // std::cerr << "creating Comedy: ";
}

Comedy::~Comedy() {
   // std::cerr << "destruct Comedy" << std::endl;

}
