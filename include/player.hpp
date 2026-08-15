#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "personagem.hpp"

class Player : public Personagem {
    private:
   
    char ultimaDirecao = 'D';

    public:
    Player();
    virtual ~Player();
    const sf::Sprite& getSprite() const; 
    void setPosition(float x, float y); 
    void setPosition(const sf::Vector2f& novaPos);
    void mover() override;
    void habilidade();
    
   
};
#endif