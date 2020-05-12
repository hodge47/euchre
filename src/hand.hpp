#ifndef HAND_HPP
#define HAND_HPP

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "card.hpp"

class Hand
{
public:
	Hand();
	~Hand();
	void set_hand_name(std::string _handName);
	std::string get_hand_name();
	void deal_hand(std::vector<std::shared_ptr<Card>>);
	void set_hand(std::vector<std::shared_ptr<Card>> hand);
	void print_hand();
	std::vector<std::shared_ptr<Card>> get_hand();
private:
	std::string m_hand_name = "Unowned Hand";
	std::vector<std::shared_ptr<Card>> *m_hand;
};

#endif
