#include <iostream>
#include <string>
#include "cardmanager.hpp"
#include "hand.hpp"
#include "handcompare.hpp"

int main()
{
	// Create a card manager
	CardManager* cardManager = new CardManager();
	std::string trumpSuit = cardManager->get_trump_suit();
	// Output welcome message
	std::cout << "\nWelcome to the Euchre hand comparer." << std::endl;
	std::cout << "The trump suit is: " << trumpSuit << std::endl;
	std::cout << "\n";
	// Create and deal hands
	Hand* hand1 = new Hand();
	hand1->set_hand_name("Hand 1 (Yours)");
	hand1->deal_hand(cardManager->deal_hand());
	hand1->print_hand();
	Hand* hand2 = new Hand();
	hand2->set_hand_name("Hand 2");
	hand2->deal_hand(cardManager->deal_hand());
	hand2->print_hand();
	// Compare hands to see who wins
	HandCompare* handCompare = new HandCompare();
	float winningHandPercent = handCompare->compare_hands(hand1, hand2, trumpSuit);
	// Output winning hand
	if (winningHandPercent == 1)
	{
		std::cout << "Your hand won!" << std::endl;
	}
	else
	{
		std::cout << "Your hand lost..." << std::endl;
	}


	// Delete pointers
	delete cardManager;
	delete hand1;
	delete hand2;
	delete handCompare;

	return 0;
}