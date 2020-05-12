#ifndef CARD_HPP
#define CARD_HPP
#include <iostream>
#include <string>

class Card
{
public:
	Card(int _rank, std::string _suit, std::string _color);
	~Card();
	int get_rank();
	std::string get_suit();
	std::string get_color();
	void print_all();

private:
	int m_rank;
	std::string m_suit;
	std::string m_color;
};

#endif
