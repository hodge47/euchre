#include "cardmanager.hpp"

CardManager::CardManager()
{
	// Create a new deck
	this->create_deck();
}

CardManager::~CardManager()
{
	// Delete the deck
	delete this->m_deck;
}

void CardManager::create_deck() {
	// Create deck object
	m_deck = new std::vector<std::shared_ptr<Card>>();

	// Card ranks - 2,3,4,5,6,7,8,9,10,Jack(11),Queen(12),King(13),Ace(14)
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
	const int rankCount = 13;
	// Create cards
	for (int i = 0; i < rankCount; i++)
	{
		std::shared_ptr<Card> _card = std::make_shared<Card>(i + 2, "Clubs", "Black");
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