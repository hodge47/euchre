#include "hand.hpp"

Hand::Hand()
{
	// Create a new hand
	this->m_hand = new std::vector<std::shared_ptr<Card>>();
}

Hand::~Hand()
{
	// Delete the pointer to the hand vector
	delete this->m_hand;
}

void Hand::set_hand_name(std::string _handName)
{
	this->m_hand_name = _handName;
}

std::string Hand::get_hand_name()
{
	return this->m_hand_name;
}

void Hand::print_hand()
{
	const int _handSize = this->m_hand->size();
	if (_handSize > 0)
	{
		std::cout << this->m_hand_name << ":" << std::endl;
		for (int i = 0; i < _handSize; i++)
		{
			std::shared_ptr<Card> c = this->m_hand->at(i);
			std::cout << "    " << c->get_rank() << ":" << c->get_suit() << ":" << c->get_color() << std::endl;
		}
	}
	else
	{
		std::cout << "This hand is empty!" << std::endl;
	}
}

void Hand::deal_hand(std::vector<std::shared_ptr<Card>> _newHand)
{
	// Clear the current hand if there is already a hand
	const int _currentHandSize = this->m_hand->size();
	if (_currentHandSize > 0)
	{
		this->m_hand->clear();
	}

	// Set the hand to the hand passed in
	const int _newHandSize = _newHand.size();
	for (int i = 0; i < _newHandSize; i++)
	{
		this->m_hand->push_back(_newHand[i]);
	}
}

void Hand::set_hand(std::vector<std::shared_ptr<Card>> hand)
{
	*m_hand = hand;
}

std::vector<std::shared_ptr<Card>> Hand::get_hand()
{
	return *m_hand;
}