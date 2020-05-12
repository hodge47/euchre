#ifndef HANDCOMPARE_HPP
#define HANDCOMPARE_HPP

#include <iostream>
#include <string>
#include "hand.hpp"

class HandCompare
{
public:
	HandCompare();
	~HandCompare();
	float compare_hands(Hand* hand1, Hand* hand2, std::string trump_suit);
private:
};

#endif
