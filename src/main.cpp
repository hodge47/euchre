#include <iostream>
#include "cardmanager.hpp"

int main()
{
	CardManager* cardManager = new CardManager();
	cardManager->list_cards_in_deck();
	cardManager->print_deck_count();
	delete cardManager;
	return 0;
}