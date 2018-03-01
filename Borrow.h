#pragma once
#include "Trans.h"
#include <string>
class Borrow : public Trans {
public:
   Borrow();
   Borrow(std::string);
   ~Borrow();
private:
};
