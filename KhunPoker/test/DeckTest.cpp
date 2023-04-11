#include "gtest/gtest.h"
#include "Deck.h"
#include "Card.h"
#include <unordered_set>

using std::vector, std::unordered_set;

namespace DeckTest {
  class DeckTestFixture : public ::testing::Test {
    protected:
      Deck standard, khun;
      DeckTestFixture() : standard(STANDARD), khun(KHUN) { }

      ~DeckTestFixture() override { }

      void SetUp() override { 
        standard = Deck(STANDARD);
        khun = Deck(KHUN);
      }

      void TearDown() override { }
  };

  TEST_F(DeckTestFixture, InitStandardDeck) {
    unordered_set<int> all;
    for (const Card& card : standard.getCards()) {
      all.insert(card.getRank() * 4 + card.getSuit());
    }
    ASSERT_EQ(all.size(), 52);
  }

  TEST_F(DeckTestFixture, InitKhunDeck) {
    unordered_set<int> all;
    for (const Card& card : khun.getCards()) {
      all.insert(card.getRank() * 4 + card.getSuit());
    }
    ASSERT_EQ(all.size(), 3);
  }


  TEST_F(DeckTestFixture, ShuffleStandardDeck) {
    const vector<Card> cards = standard.getCards();
    standard.shuffle();

    int maxIterations = 10;
    // Probabilistic method to check if shuffle is properly working. 
    for (int it = 0; it < maxIterations; it++) {
      for (int i = 0; i < cards.size(); i++) {
        standard.shuffle();
      }
      const vector<Card> modCards = standard.getCards();

      ASSERT_EQ(cards.size(), modCards.size());

      bool changed = false;
      for (int i = 0; i < cards.size(); i++) {
        if (cards[i] != modCards[i]) {
          changed = true;
        }
      }

      if (changed) {
        ASSERT_TRUE(changed);
        return;
      }
    }
    ASSERT_TRUE(false);
  }

  TEST_F(DeckTestFixture, ShuffleKhunDeck) {
    const vector<Card> cards = khun.getCards();
    khun.shuffle();

    int maxIterations = 10;
    // Probabilistic method to check if shuffle is properly working. 
    for (int it = 0; it < maxIterations; it++) {
      for (int i = 0; i < cards.size(); i++) {
        khun.shuffle();
      }
      const vector<Card> modCards = khun.getCards();

      ASSERT_EQ(cards.size(), modCards.size());

      bool changed = false;
      for (int i = 0; i < cards.size(); i++) {
        if (cards[i] != modCards[i]) {
          changed = true;
        }
      }

      if (changed) {
        ASSERT_TRUE(changed);
        return;
      }
    }
    ASSERT_TRUE(false);
  }
} // DeckTest