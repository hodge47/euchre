#include <iostream>
#include "cardmanager.hpp"
#include "hand.hpp"

int main()
{
	CardManager* cardManager = new CardManager();
	//cardManager->list_cards_in_deck();
	//cardManager->print_deck_count();
	Hand* playerHand = new Hand();
	playerHand->set_hand_name("Hand 1");
	playerHand->deal_hand(cardManager->deal_hand());
	playerHand->print_hand();

	// Delete pointers
	delete cardManager;
	delete playerHand;
	return 0;
}