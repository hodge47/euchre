#include "handcompare.hpp"

HandCompare::HandCompare()
{

}

HandCompare::~HandCompare()
{

}

float HandCompare::compare_hands(Hand* hand1, Hand* hand2, std::string trump_suit)
{
    // TODO: Create algorithm to determine a hand's chance at winning
	float _handStrength = 0;
	// Get the hands 
	std::vector<std::shared_ptr<Card>> _handOne = hand1->get_hand();
	std::vector<std::shared_ptr<Card>> _handTwo = hand2->get_hand();
	// Sort hands by largest card rank
	std::sort(_handOne.begin(), _handOne.end(), [](std::shared_ptr<Card> card1, std::shared_ptr<Card> card2) {
		return card1->get_rank() > card2->get_rank();
		});
	std::sort(_handTwo.begin(), _handTwo.end(), [](std::shared_ptr<Card> card1, std::shared_ptr<Card> card2) {
		return card1->get_rank() > card2->get_rank();
		});
	hand1->set_hand(_handOne);
	hand2->set_hand(_handTwo);

	// Get the trump suit
	std::string _trumpSuit = trump_suit;

	// Check for bowers
	bool _handOneBower = this->check_for_bower(hand1->get_hand(), _trumpSuit);
	bool _handTwoBower = this->check_for_bower(hand2->get_hand(), _trumpSuit);
	// Logic to see if bowers present
	if (_handOneBower && !_handTwoBower|| _handTwoBower && !_handOneBower)
	{
		_handStrength = (_handOneBower == 1) ? 1 : 0;
	}
	else
	{
		// Test same suit
		int _sameSuitWinner = this->check_for_same_suit(hand1->get_hand(), hand2->get_hand(), _trumpSuit);

		if (_sameSuitWinner != 0)
		{
			_handStrength = (_sameSuitWinner == 1) ? 1 : 0;
		}
		else
		{
			// Test highest rank card
			_handStrength = (hand1->get_hand().begin() > hand2->get_hand().begin()) ? 1 : 0;
		}
	}

	return _handStrength;
}

bool HandCompare::check_for_bower(std::vector<std::shared_ptr<Card>> _hand, std::string _trumpSuit)
{
	bool _bower = false;
	for (auto c : _hand)
	{
		std::string _suit = c->get_suit();
		if (c->get_rank() == 11)
		{
			// TODO: get rid of this ugly logic
			if (_suit == _trumpSuit)
			{
				_bower = true;
			}
			else if ((_trumpSuit == "Clubs" && _suit == "Spades") || (_trumpSuit == "Spades" && _suit == "Clubs"))
			{
				_bower = true;
			}
			else if ((_trumpSuit == "Diamonds" && _suit == "Hearts") || (_trumpSuit == "Hearts" && _suit == "Diamonds"))
			{
				_bower = true;
			}
			else
			{
				_bower = false;
			}
		}
	}
	return _bower;
}

int HandCompare::check_for_same_suit(std::vector<std::shared_ptr<Card>> _handOne, std::vector<std::shared_ptr<Card>> _handTwo, std::string _trumpSuit)
{
	int _winningHand = 0;
	int _handOneHighestOfSuit = 0;
	int _handTwoHighestOfSuit = 0;
	// Check hand one 
	for (auto c : _handOne)
	{
		if (c->get_suit() == _trumpSuit)
		{
			if(c->get_rank() > _handOneHighestOfSuit)
			{
				_handOneHighestOfSuit = c->get_rank();
			}
		}
	}
	// Check hand 2
	for (auto c : _handTwo)
	{
		if (c->get_suit() == _trumpSuit)
		{
			if (c->get_rank() > _handTwoHighestOfSuit)
			{
				_handTwoHighestOfSuit = c->get_rank();
			}
		}
	}

	// Compare the two highest
	if (_handOneHighestOfSuit > _handTwoHighestOfSuit)
	{
		_winningHand = 1;
	} 
	else if(_handTwoHighestOfSuit > _handOneHighestOfSuit)
	{
		_winningHand = 2;
	}
	else
	{
		_winningHand = 0;
	}

	return _winningHand;
}