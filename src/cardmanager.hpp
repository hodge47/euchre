#ifndef CARDMANAGER_HPP
#define CARDMANAGER_HPP

#include <iostream>
#include <vector>
#include <memory>
#include "card.hpp"

class CardManager
{
public:
	CardManager();
	~CardManager();
	void list_cards_in_deck();
	void print_deck_count();
private:
	std::vector<std::shared_ptr<Card>>* m_deck;

	void create_deck();
	void create_cards(std::string suit, std::string color);
};

#endif
