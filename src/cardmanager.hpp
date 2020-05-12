#ifndef CARDMANAGER_HPP
#define CARDMANAGER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "card.hpp"

class CardManager
{
public:
	CardManager();
	~CardManager();
	void list_cards_in_deck();
	void print_deck_count();
	int get_deck_count();
	void set_trump_suit();
	std::string get_trump_suit();
	std::vector<std::shared_ptr<Card>> deal_hand();
private:
	std::vector<std::shared_ptr<Card>>* m_deck;
	std::string m_trump_suit = "Nothing to see here";
	void create_deck();
	void create_cards(std::string suit, std::string color);
};

#endif
