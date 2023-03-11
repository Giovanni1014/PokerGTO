#include "card.cc"
#include "vector"

using namespace std;

class Deck {
public:
    Deck();
    void shuffle();
    Card deal();
    void reset();
private:
    vector<Card> cards;
    void shuffleOnce();

};
