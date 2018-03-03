// Drama.cpp
#include <string>
#include <iostream>
#include "Drama.h"

Drama::Drama() {

}

Drama::Drama(std::string data) : Film(data) {
	std::cerr << "creating Drama: ";
}

Drama::~Drama() {
   std::cerr << "destruct Drama" << std::endl;

}