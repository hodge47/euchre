#include "cardmanager.hpp"

CardManager::CardManager()
{
	// Create a new deck
	this->create_deck();
	// Get the first trump suit
	this->set_trump_suit();
}

CardManager::~CardManager()
{
	// Delete the deck
	delete this->m_deck;
}

void CardManager::create_deck() {
	// Create deck object
	m_deck = new std::vector<std::shared_ptr<Card>>();

	// Card ranks - 9,10,Jack(11),Queen(12),King(13),Ace(14)
	// Card suits - Clubs, Diamonds, Hearts, Spades
	// Card colors - Black, Red

	// Clubs
	this->create_cards("Clubs", "Black");
	// Diamonds
	this->create_cards("Diamonds", "Red");
	// Hearts
	this->create_cards("Hearts", "Red");
	// Spades
	this->create_cards("Spades", "Black");
	
}

// A simple function to create necessary cards for each suit and color
void CardManager::create_cards(std::string suit, std::string color)
{
	// Since only 9 through ace is played
	const int rankCount = 6;
	// Create cards
	for (int i = 0; i < rankCount; i++)
	{
		std::shared_ptr<Card> _card = std::make_shared<Card>(i + 9, suit, color);
		this->m_deck->push_back(_card);
	}
}

void CardManager::list_cards_in_deck() 
{
	const int count = this->m_deck->size();
	for (int i = 0; i < count; i++)
	{
		std::shared_ptr<Card> _c = this->m_deck->at(i);
		std::cout << _c->get_rank() << ":" << _c->get_suit() << ":" << _c->get_color() << std::endl;
	}
}

void CardManager::print_deck_count()
{
	std::cout << "Deck count: " << this->m_deck->size() << std::endl;
}

int CardManager::get_deck_count()
{
	return this->m_deck->size();
}

std::vector<std::shared_ptr<Card>> CardManager::deal_hand()
{
	// Random hand vector
	std::shared_ptr<std::vector<std::shared_ptr<Card>>> _hand = std::make_shared<std::vector<std::shared_ptr<Card>>>();
	// Time seed
	srand(time(0));
	int _randomIndex = 0;
	// Deal hand
	const int _numOfCardsInHand = 5;
	for (int i = 0; i < _numOfCardsInHand; i++)
	{
		_randomIndex = rand() % (this->get_deck_count());
		//std::cout << "Random index: " << _randomIndex << std::endl;
		std::shared_ptr<Card> _cardToDeal = this->m_deck->at(_randomIndex);
		_hand->push_back(_cardToDeal);
		// Remove card from deck
		this->m_deck->erase(m_deck->begin() + _randomIndex);
	}
	// Return the new hand
	return *_hand;
}

void CardManager::set_trump_suit()
{
	// Time seed
	srand(time(0));
	int _randomNumber = rand() % 4;
	std::string _trumpSuit = "Null String";
	switch (_randomNumber)
	{
	case 0:
		_trumpSuit = "Clubs";
		break;
	case 1:
		_trumpSuit = "Diamonds";
		break;
	case 2:
		_trumpSuit = "Hearts";
		break;
	case 3:
		_trumpSuit = "Spades";
		break;
	}
	this->m_trump_suit = _trumpSuit;
}

std::string CardManager::get_trump_suit()
{
	return this->m_trump_suit;
}