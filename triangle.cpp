#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <random>
#include <ctime>
#include <sstream>
#include <string>

using namespace std;

class Suit {
public:
    static const int CLUBS = 0;
    static const int DIAMONDS = 1;
    static const int HEARTS = 2;
    static const int SPADES = 3;
};

class Card {
private:
    int rank;
    int suit;
    bool faceUp;
public:
    Card(int r, int s, bool faceUp = false) : rank(r), suit(s), faceUp(faceUp) {}
    int getRank() const { return rank; }
    int getSuit() const { return suit; }
    bool isFaceUp() const { return faceUp; }
    void flip() { faceUp = !faceUp; }
    string toString() const {
        if (faceUp) return "===";  
        string rankStr;
        switch (rank) {
        case 1: rankStr = "A"; break;
        case 11: rankStr = "J"; break;
        case 12: rankStr = "Q"; break;
        case 13: rankStr = "K"; break;
        default: rankStr = to_string(rank);
        }
        char suitChar = "CDHS"[suit];
        return rankStr + suitChar;
    }
};

class Deck {
private:
    queue<Card> stock;
    stack<Card> waste;
public:
    Deck() {}
    void initialize();
    void drawCard();
    bool stockEmpty() const { return stock.empty(); }
    Card getWasteTop() const { return waste.top(); }
    void popWasteTop() { waste.pop(); }
};

void Deck::initialize() {
    vector<Card> allCards;
    for (int r = 1; r <= 13; ++r) {
        allCards.emplace_back(r, Suit::CLUBS);
        allCards.emplace_back(r, Suit::DIAMONDS);
        allCards.emplace_back(r, Suit::HEARTS);
        allCards.emplace_back(r, Suit::SPADES);
    }
    shuffle(allCards.begin(), allCards.end(), mt19937(static_cast<unsigned int>(time(0))));
    for (auto& card : allCards) {
        stock.push(card);
    }
}

void Deck::drawCard() {
    if (stock.empty()) return;
    Card card = stock.front();
    stock.pop();
    card.flip();
    waste.push(card);
}

class Game {
private:
    Deck deck;
    vector<vector<Card>> tableau;
    stack<Card> foundations[4];
    vector<Card> randomCards;

public:
    Game() : tableau(7) {}
    void initGame();
    void display() const;
    void generateRandomCards();
    void run();

    //funkcii dla ruchu 
    bool moveCardToFoundation(int column);      
    bool moveCardBetweenColumns(int from, int to); 
    bool isValidMove(const Card& fromCard, const Card& toCard) const; 
};

void Game::initGame() {
    deck.initialize();
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j <= i; ++j) {
            deck.drawCard();
            Card card = deck.getWasteTop();
            deck.popWasteTop();

            if (j == i) {
                card.flip(); 
            }
            else {
       
            }

            tableau[i].push_back(card);
        }
    }
    generateRandomCards();
}
string padCard(const string& card) {
    if (card.length() == 2) return "  " + card + "  ";
    if (card.length() == 3) return " " + card + "  ";
    return card;
}

void Game::generateRandomCards() {
    static vector<Card> savedCards;  
    static size_t currentIndex = 0; 

    if (deck.stockEmpty()) {
        if (savedCards.empty()) {
            cout << "Колода пуста! Невозможно показать карты." << endl;
            return;
        }

        if (currentIndex >= savedCards.size()) {
            currentIndex = 0;
        }

        randomCards.clear();
        for (int i = 0; i < 3 && currentIndex < savedCards.size(); ++i, ++currentIndex) {
            randomCards.push_back(savedCards[currentIndex]);
        }
        return;
    }

    randomCards.clear();
    for (int i = 0; i < 3; ++i) {
        if (!deck.stockEmpty()) {
            deck.drawCard();
            Card card = deck.getWasteTop();
            deck.popWasteTop();

            if (card.isFaceUp()) {  
                card.flip();       
            }

            randomCards.push_back(card);
            savedCards.push_back(card);  
        }
    }

    currentIndex = savedCards.size();
}


//ruch z kolumny do 8 9 10 11 
bool Game::moveCardToFoundation(int column) {
    
    return false;
}

//ruch miedzu kolumnami
bool Game::moveCardBetweenColumns(int from, int to) {
    
    return false;
}

//sprawdzeneie ruchu
bool Game::isValidMove(const Card& fromCard, const Card& toCard) const {

    return false;
}

void Game::display() const {
    cout << "        0                         8    9    10   11 " << endl;
    cout << "--------------------------------------------------" << endl;

    // Отображение случайных карт под 0
    for (const auto& card : randomCards) {
        cout << padCard(card.toString());
    }
    cout << "             ";
    for (int i = 0; i < 4; ++i) {
        if (foundations[i].empty()) {
            cout << "  0  ";
        }
        else {
            cout << padCard(foundations[i].top().toString());
        }
    }
    cout << endl;
    cout << "--------------------------------------------------" << endl;

    int maxRows = 0;
    for (const auto& pile : tableau) {
        if (static_cast<int>(pile.size()) > maxRows) maxRows = static_cast<int>(pile.size());
    }

    for (int row = 0; row < maxRows; ++row) {
        for (int col = 0; col < 7; ++col) {
            cout << "|";
            if (row < static_cast<int>(tableau[col].size())) {
                cout << padCard(tableau[col][row].toString());
            }
            else {
                cout << "      ";
            }
        }
        cout << "|" << endl;
    }

    cout << "--------------------------------------------------" << endl;
}


void Game::run() {
    initGame();
    display();

    string command;
    while (true) {
        cout << ">> ";
        getline(cin, command);

        if (command == "q") break;

        if (command == "d") {
            generateRandomCards();
            display();
        }
    }
}

int main() {
    Game game;
    game.run();
    return 0;
}
