#include <iostream>
#include <string>
#include "cardmanager.hpp"
#include "hand.hpp"
#include "handcompare.hpp"

int main()
{
	CardManager* cardManager = new CardManager();
	std::string trumpSuit = cardManager->get_trump_suit();
	//cardManager->list_cards_in_deck();
	//cardManager->print_deck_count();
	std::cout << "Welcome to the Euchre hand comparer.\n\n";
	std::cout << "The trump suit is: " << trumpSuit << std::endl;
	std::cout << "\n\n";
	Hand* hand1 = new Hand();
	hand1->set_hand_name("Hand 1 (Yours)");
	hand1->deal_hand(cardManager->deal_hand());
	hand1->print_hand();
	Hand* hand2 = new Hand();
	hand2->set_hand_name("Hand 2");
	hand2->deal_hand(cardManager->deal_hand());
	hand2->print_hand();
	//std::cout << cardManager->get_deck_count() << std::endl;

	HandCompare* handCompare = new HandCompare();
	float winningHandPercent = handCompare->compare_hands(hand1, hand2, trumpSuit);

	std::cout << "You hand has this chance of winning: " << winningHandPercent << std::endl;

	// Delete pointers
	delete cardManager;
	delete hand1;
	delete hand2;
	delete handCompare;
	return 0;
}