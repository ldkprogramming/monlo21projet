//
// Created by Leo on 21/11/2023.
//

#include "game.h"
#include <string>
#include "nlohmann/json.hpp"
#include "coinboard.h"
#include <fstream>

using json = nlohmann::json;

const CardPyramid &Game::getPyramid() const {
    return pyramid;
}

const Coinbag & Game::getCoinBag() const {
    return coinBag;
}

const Coinboard &Game::getCoinBoard() const {
    return coinBoard;
}

int Game::getPrivileges() const {
    return privileges;
}

const Card& Game::get_Card_from_ID(int cID) const
{
    for (auto card : getPyramid().getLevel1Cards()) {
        if (card.getId() == cID) {
            return card;
        }
    }
    for (auto card : getPyramid().getLevel2Cards()) {
        if (card.getId() == cID) {
            return card;
        }
    }
    for (auto card : getPyramid().getLevel3Cards()) {
        if (card.getId() == cID) {
            return card;
        }

    }
    for (auto card : getPyramid().getRoyalCards()) {
        if (card.getId() == cID) {
            return card;
        }
    }
}


const std::pair<CardLevel, int> Game::cardinfosfromCard(const Card& card) const
{
    int iterator_tracker;
        for (auto c : getPyramid().getLevel1Cards()) {

            if (c.getId() == card.getId()) {
                return std::pair<CardLevel,int >( CardLevel::One, iterator_tracker);
            }
            iterator_tracker++;
        }
    
    for (auto d : getPyramid().getLevel2Cards()) {
            if (d.getId() == card.getId()) {
                return std::pair< CardLevel,int>( CardLevel::Two,iterator_tracker);
            }
            iterator_tracker++;
        }
    
    
        iterator_tracker = 0;
        for (auto e : getPyramid().getLevel3Cards())
            if (e.getId() == card.getId()) {
                return std::pair<CardLevel, int>(CardLevel::Three,iterator_tracker);
            }
        iterator_tracker++;
}


const Pile &Game::getPile1() const {
    return pile1;
}

const Pile &Game::getPile2() const {
    return pile2;
}

const Pile &Game::getPile3() const {
    return pile3;
}

const Player &Game::getPlayer1() const{
    return player1;
}

const Player &Game::getPlayer2() const {
    return player2;
}

const Pile &Game::getRoyalPile() const {
    return royalPile;
}



std::string toString(PlayerEnum p){
    switch(p){
        case PlayerEnum::Player1:
            return "Player1";
            break;
        case PlayerEnum::Player2:
            return "Player2";
            break;
        default:
            return "Empty";
            break;
    }
}

PlayerEnum toPlayerEnum(std::string s){
    // faudra ajouter le traitement des erreurs
    if (s == "Player1"){
        return PlayerEnum::Player1;
    }
    if (s == "Player2"){
        return PlayerEnum::Player2;
    }
    return PlayerEnum::Empty;
}

bool Game::playerUsePrivilege(std::pair<int, int> coordinates) {
    // returns true if action has been done, false otherwise



    // faut verifier si les coordonnees sont correctes, valides
    // faudra ajouter un attribut largeur au coinboard, mais pour l'instant ca marche
    if ((coordinates.first > 4) || (coordinates.first < 0) || (coordinates.second > 4) || (coordinates.second < 0)) {return false;}

    // faut verifier si ce n'est pas un jeton or
    if ((coinBoard.getCoin(coordinates.first, coordinates.second).getColor() == CoinColor::Gold) || (coinBoard.getCoin(coordinates.first, coordinates.second).getColor() == CoinColor::Empty)) {
        return false;
    }
    // faut verifier que le joueur a qui c le tour possede au moins un privilege
    if (getPlayer(turn).getPrivileges() < 1) {
        return false;
    }

    getActivePlayer().addCoin(coinBoard.getCoin(coordinates.first, coordinates.second));

    // on vide le jeton du plateau
    coinBoard.setCoin(coordinates.first, coordinates.second, CoinColor::Empty);

    getActivePlayer().decrementPrivileges();
    return true;



}

PlayerEnum getOpponent(PlayerEnum p){
    switch (p){
        case (PlayerEnum::Player1) : {
            return PlayerEnum::Player2;
        }
        case (PlayerEnum::Player2) : {
            return PlayerEnum::Player1;
        }
        default : {
            return PlayerEnum::Empty;
        }
    }
}

bool Game::playerUsePrivileges(int numberOfPrivileges, const std::vector<std::pair<int, int>> &coordinates) {
    // Returns true if action has been done correctly
    // false otherwise

    // faut verifier si le nombre de privileges et de coordonnees correspond
    if (numberOfPrivileges != coordinates.size()){
        return false;
    }
    // faut verifier si le joueeur a assez de privileges
    if (getActivePlayer().getPrivileges() < numberOfPrivileges){
        return false;
    }
    // faut verifier si les coordonnees sont valides
    for (auto c : coordinates){
        if ((c.first > 4 ) || (c.first < 0) || (c.second > 4 ) || (c.second < 0)){
            return false;
        }
        // faut verifier si ce n'est pas un jeton or
        if ((coinBoard.getCoin(c.first, c.second).getColor() == CoinColor::Gold) || (coinBoard.getCoin(c.first, c.second).getColor() == CoinColor::Empty)){
            return false;
        }
    }
    for (auto c : coordinates){
        // faudra verifier si aucune coordonnee n'est pareil que l'autre
        if (playerUsePrivilege(c) == false) { return false; }
    }
    return true;
}

bool Game::playerFillBoard() {
    if (coinBag.isEmpty()){
        return false;
    }
    // Si le jeu contient des privileges, l'adversaire le prend
    // sinon , si le jeu n'en contient pas mais le joueur actif en a, l'adversaire le vole
    // sinon, il en prend pas (ca vetu dire qu'il a deja les 3 privileges).
    if (privileges > 0){
        decrementPrivileges();
        getOpponentPlayer().incrementPrivileges();
    } else if (getActivePlayer().getPrivileges() > 0){
        getActivePlayer().decrementPrivileges();
        getOpponentPlayer().incrementPrivileges();
    }
    coinBoard.fill(coinBag);
    return true;
}

bool Game::playerTakeCoin(std::pair<int, int> coordinates) {
    // on doit verifier si les coordonnees sont valides
    if ((coordinates.first > 4 ) || (coordinates.first < 0)|| (coordinates.second > 4 ) ||(coordinates.second < 0)){
        return false;
    }
    // on doit verifier si c'est un jeton vide ou or
    if ((coinBoard.getCoin(coordinates.first, coordinates.second).getColor() == CoinColor::Empty)){
        return false;
    }

    getActivePlayer().addCoin(coinBoard.getCoin(coordinates.first, coordinates.second));
    // on vide le jeton du plateau

    coinBoard.setCoin(coordinates.first, coordinates.second, CoinColor::Empty);
    return true;
}

bool Game::playerTakeCoins(std::vector<std::pair<int, int>> coordinates) {
    // faudra verifier la validite des coordonnees
    int numberOfPearlCoins = 0;
    bool allSameColor = true;

    if (coordinates.size() > 3){
        return false;
    }

    for (auto c : coordinates){
        //faudra ajouter les verifications
        continue;
    }
    const Coin& firstCoin = coinBoard.getCoin(coordinates[0].first, coordinates[0].second);
    for (auto c : coordinates){
        if (coordinates.size() == 1) {
            allSameColor = false;
        }


        if (firstCoin.getColor() != coinBoard.getCoin(c.first, c.second).getColor()){
            allSameColor = false;
        }
        if (coinBoard.getCoin(c.first, c.second).getColor() == CoinColor::Pearl){
            numberOfPearlCoins += 1;
        }
        playerTakeCoin(c);
    }

    if (allSameColor&& coordinates.size()==3 || (numberOfPearlCoins == 2)){
        if (privileges > 0){
            decrementPrivileges();
            getOpponentPlayer().incrementPrivileges();
        } else if (getActivePlayer().getPrivileges() > 0){
            getActivePlayer().decrementPrivileges();
            getOpponentPlayer().incrementPrivileges();
        }
    }
    // On passe au tour suivant !

}
Game::Game(const std::string& path) : player1(json::parse(std::ifstream(path))["player1"]["name"], toPlayerType(json::parse(std::ifstream(path))["player1"]["type"])), player2(json::parse(std::ifstream(path))["player2"]["name"],toPlayerType(json::parse(std::ifstream(path))["player2"]["type"])) {
    std::ifstream f(path);
    json data = json::parse(f);

    // On initialise le sac a jetons
    std::vector<Coin> coinsInCoinBag;
    for (auto c : data["coinBag"]){
        coinsInCoinBag.push_back(Coin(toCoinColor(c)));
    }
    coinBag = Coinbag(coinsInCoinBag);

    // On initialise le plateau de jetons
    for (int i =0 ; i<5;i++){
        for (int j=0; j<5; j++){
            coinBoard.setCoin(i, j, toCoinColor(data["coinBoard"][i][j]));
        }
    }

    // On initialise les pioches
    std::vector<Card> pile1Cards;
    for (auto c : data["pile1"]){
        pile1Cards.push_back(Card(c));
    }
    pile1 = Pile(PileType::One, pile1Cards);
    std::vector<Card> pile2Cards;
    for (auto c : data["pile2"]){
        pile2Cards.push_back(Card(c));
    }
    pile2 = Pile(PileType::Two, pile2Cards);
    std::vector<Card> pile3Cards;
    for (auto c : data["pile3"]){
        pile3Cards.push_back(Card(c));
    }
    pile3 = Pile(PileType::Three, pile3Cards);
    std::vector<Card> royalPileCards;
    for (auto c : data["royalPile"]){
        royalPileCards.push_back(Card(c));
    }
    royalPile = Pile(PileType::Royal, royalPileCards);

    // On initialise les joueurs

    // On initialise les privileges
    privileges = data["privileges"];

    //On initialise la pyramide
    std::vector<Card> level1Cards;
    for (auto c: data["pyramid"]["level1Cards"]){
        level1Cards.push_back(Card(c));
    }
    std::vector<Card> level2Cards;
    for (auto c: data["pyramid"]["level2Cards"]){
        level2Cards.push_back(Card(c));
    }
    std::vector<Card> level3Cards;
    for (auto c: data["pyramid"]["level3Cards"]){
        level3Cards.push_back(Card(c));
    }
    std::vector<Card> royalCards;
    for (auto c: data["pyramid"]["royalCards"]){
        royalCards.push_back(Card(c));
    }

    pyramid = CardPyramid(level1Cards, level2Cards, level3Cards, royalCards);
    winConditions = WinConditions(data["winConditions"]["totalPoints"],data["winConditions"]["totalCrowns"], data["winConditions"]["pointsInOneColor"]);
    turn = toPlayerEnum(data["turn"]);
    winner = PlayerEnum::Empty;
    loser = PlayerEnum::Empty;
}

bool Game::playerReserveCard(CardLevel level, int cardNumber) {
    // ajouter les verifications
    // par exemple, on peut pas reserver de carte royale
    if (level == CardLevel::Royal){
        return false;
    }
    // ou bien, on peut pas reserver une carte inexistante
    if ((cardNumber < 0) || (cardNumber > pyramid.getNumberOfCards(level))){
        return false;
    }

    getActivePlayer().reserveCard(pyramid.distributeCard(level, cardNumber));
    switch (level){
        case CardLevel::One : {
            pyramid.refill(level, pile1);
        }
        case CardLevel::Two : {
            pyramid.refill(level, pile2);
        }
        case CardLevel::Three : {
            pyramid.refill(level, pile3);
        }
        default : {
            throw std::runtime_error("Bad card level !");
        }

    }
  
 
    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            if (coinBoard.getCoin(x, y).getColor() == CoinColor::Gold) {
                playerTakeCoin(std::pair<int, int>(x, y));
            }
        }
    }

    return true;
}

bool Game::playerBuyCard(CardLevel level, int cardNumber, CoinColor bonusColor = CoinColor::Empty,
                         CoinColor stolenColor = CoinColor::Empty, std::pair<int, int> coordinates = {0, 0}) {
    // l'argument optionnel bonusColor sert en cas de capacite bonus
    // l'argument optionnel stolenColor sert en cas de capacite robCoin
    // On peut pas acheter une carte royale
    if (level == CardLevel::Royal){
        std::cout << "Pas de royal";
        return false;
    }
    // ou bien, on peut pas acheter une carte inexistante
    if ((cardNumber < 0) || (cardNumber > pyramid.getNumberOfCards(level))){
        std::cout << "Number";
        return false;
    }
    // on verifie evidemment si le joueur peut acheter la carte
    if (!getActivePlayer().canBuy(pyramid.checkCard(level, cardNumber))){
        std::cout << "Canbuy";
        return false;
    }
    
    std::cout << "Youhou" << std::endl;


    // On traite la question des jetons
    for (auto c : pyramid.checkCard(level, cardNumber).getCosts()){
        if (c.second > 0){
            int cost = c.second - getActivePlayer().getBonus(c.first);
            while (cost > 0){
                getActivePlayer().loseCoin(c.first);
                std::cout << "LOSECOIN" << std::endl;
            }
        }
    }


    pyramid.checkCard(level, cardNumber);

    // on applique les capacites
   applyCardSkill(pyramid.checkCard(level, cardNumber), pyramid.checkCard(level, cardNumber).getSkill1(), bonusColor, stolenColor, coordinates);
    applyCardSkill(pyramid.checkCard(level, cardNumber), pyramid.checkCard(level, cardNumber).getSkill2(), bonusColor, stolenColor, coordinates);

    // On ajoute la carte a la main du joueur
    getActivePlayer().addCardToHand(pyramid.checkCard(level, cardNumber));


    // On traite la capacite PlayAgain
    // Si la carte ne possede pas la capacite, on change de tour
    if (((pyramid.checkCard(level, cardNumber).getSkill1() == Skill::PlayAgain) || (pyramid.checkCard(level, cardNumber).getSkill2() == Skill::PlayAgain))){
        turn = getOpponent(turn);
    }
    pyramid.distributeCard(level, cardNumber);
    // on doit remplir la pyramide
    switch (level){
        case CardLevel::One :{
            pyramid.refill(level, pile1);
        }
        case CardLevel::Two :{
            pyramid.refill(level, pile2);
        }
        case CardLevel::Three :{
            pyramid.refill(level, pile3);
        }
    }

    return true;
}

bool Game::applyCardSkill(Card &card, Skill skill, CoinColor bonusColor, CoinColor stolenColor,
                          std::pair<int, int> coordinates) {
    // la capacite playAgain sera traitee au niveau de la methode playerBuyCard
    switch (skill){
        case (Skill::Bonus): {
            card.incrementBonus(bonusColor, 1);
            break;
        }
        case (Skill::RobCoin) : {
            // faudra faire la verification des jetons possedes par l'adversaire
            getOpponentPlayer().loseCoin(stolenColor);
            getActivePlayer().addCoin(stolenColor);
        }
        case (Skill::TakeCoin) : {
            // faudra laisser prendre seulement les jetons valides...
            if (coinBoard.containsAtLeastOne(card.getCardColor())){
                // Faudra surement creer une methode distributeCoin pour ne pas devoir a
                // ecrire tout le temps ces deux lignes cote a cote
                getActivePlayer().addCoin(coinBoard.getCoin(coordinates.first, coordinates.second));
                coinBoard.setCoin(coordinates.first, coordinates.second, CoinColor::Empty);

            }
        }
        case (Skill::TakePrivilege) : {
            if (privileges > 0){
                decrementPrivileges();
                getActivePlayer().incrementPrivileges();
            } else if (getOpponentPlayer().getPrivileges() > 0){
                getOpponentPlayer().decrementPrivileges();
                getActivePlayer().incrementPrivileges();
            }
        }

    }
    return true;
}
PlayerType Game::toPlayerType(std::string json)
{
    if (json == "AI") { return PlayerType::AI; }
    else return  PlayerType::Human;
}
