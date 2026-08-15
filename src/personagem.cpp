#include "personagem.hpp"


Personagem::Personagem(float velinicial) : velocidade(velinicial) {}


Personagem::~Personagem(){}


void Personagem::limite(){
     sf::FloatRect bounds = sprite.getGlobalBounds();
    sf::Vector2f pos = sprite.getPosition();
    if(pos.y + bounds.height >= 600.f){

        sprite.setPosition(pos.x,600.f - bounds.height);
        
      
    }
    if(pos.y <= 0){
        
        
        sprite.setPosition(pos.x, 0.f);
    }

    pos = sprite.getPosition();
        if(pos.x + bounds.width >= 800.f){
        
     
        sprite.setPosition(800.f - bounds.width, pos.y);
    }

    if(pos.x <= 0.f){

        sprite.setPosition(0.f , pos.y);
    }
}
void Personagem::desenhar(sf::RenderWindow& window){

    window.draw(sprite);
}