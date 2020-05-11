#include "card.hpp"

Card::Card(int _rank, std::string _suit, std::string _color)
{
	m_rank = _rank;
	m_suit = _suit;
	m_color = _color;
}

Card::~Card()
{

}

int Card::get_rank()
{
	return m_rank;
}

std::string Card::get_suit()
{
	return m_suit;
}

std::string Card::get_color()
{
	return m_color;
}