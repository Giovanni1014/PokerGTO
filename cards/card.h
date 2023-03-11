#include<string>

enum Suit { C = 1, D, H, S };
enum Rank { TWO = 1, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };


class Card {
public:
    Card(Rank r, Suit s);
    Card operator<(const Card& other);
    Rank getRank() const;
    Suit getSuit() const;
    std::string toString() const;
private:
    Rank rank;
    Suit suit;
};


