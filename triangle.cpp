void Game::generateRandomCards() {
    static vector<Card> savedCards;  // Сохраненные карты, которые были показаны ранее
    static size_t currentIndex = 0;  // Текущий индекс для отображения сохраненных карт

    // Если колода пуста и сохраненные карты существуют
    if (deck.stockEmpty()) {
        if (savedCards.empty()) {
            cout << "Колода пуста! Невозможно показать карты." << endl;
            return;
        }

        // Если достигнут конец сохраненных карт, начать с начала
        if (currentIndex >= savedCards.size()) {
            currentIndex = 0;
        }

        // Показать следующие три карты из сохраненных
        randomCards.clear();
        for (int i = 0; i < 3 && currentIndex < savedCards.size(); ++i, ++currentIndex) {
            randomCards.push_back(savedCards[currentIndex]);
        }
        return;
    }

    // Вытягиваем новые карты из колоды и сохраняем их в savedCards
    randomCards.clear();
    for (int i = 0; i < 3; ++i) {
        if (!deck.stockEmpty()) {
            deck.drawCard();
            Card card = deck.getWasteTop();
            deck.popWasteTop();

            // Принудительно открыть карту, если она закрыта
            if (card.isFaceUp()) {  // Проверяем, если карта уже перевернута
                card.flip();       // Переворачиваем снова, чтобы сделать её открытой
            }

            randomCards.push_back(card);
            savedCards.push_back(card);  // Сохраняем карту для повторного показа
        }
    }

    // Устанавливаем текущий индекс для следующего показа
    currentIndex = savedCards.size();
}
