#ifndef INIMIGOS_HPP
#define INIMIGOS_HPP
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "personagem.hpp"

class Player;

class Iainimigo : public Personagem {
    private:

    Player* jogador = nullptr;

   

    public:
    Iainimigo(Player* jogador);
    ~Iainimigo();
    virtual void mover();
    virtual void habilidade();
    sf::Clock relogioPasseio;
     int movealeatorio = 0;



};
#endif