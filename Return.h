#pragma once
#include <string>
#include "Trans.h"

class Return : public Trans {
public:
   Return();
   Return(std::string);
   ~Return();
private: 
};
