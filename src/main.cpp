#include <iostream>
#include "card.hpp"

int main()
{
	Card* card = new Card(10, "Diamond", "Black");
	int r = card->get_rank();
	std::string s = card->get_suit();
	std::string c = card->get_color();
	std::cout << r << ":" << s << ":" << c << std::endl;
	delete card;
	return 0;
}