#ifndef HANDCOMPARE_HPP
#define HANDCOMPARE_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include "hand.hpp"

class HandCompare
{
public:
	HandCompare();
	~HandCompare();
	float compare_hands(Hand* hand1, Hand* hand2, std::string trump_suit);
private:
	bool check_for_bower(std::vector<std::shared_ptr<Card>> _hand, std::string _suit);
	int check_for_same_suit(std::vector<std::shared_ptr<Card>> _handOne, std::vector<std::shared_ptr<Card>> _handTwo, std::string _trumpSuit);
};

#endif
