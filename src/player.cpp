#include "player.hpp"
#include <iostream>

Player::Player() : Personagem(3.0f){

     if (!texDireita.loadFromFile("assets/joaninha_direita.png") ||
        !texEsquerda.loadFromFile("assets/joaninha_esquerda.png") ||
        !texCima.loadFromFile("assets/joaninha_cima.png") ||
        !texBaixo.loadFromFile("assets/joaninha_baixo.png")) {
        std::cout << "Erro ao carregar as texturas das direcoes da joaninha!" << std::endl;
    }
    texDireita.setSmooth(false);
    texEsquerda.setSmooth(false);
    texCima.setSmooth(false);
    texBaixo.setSmooth(false);

    sprite.setTexture(texCima);

    sprite.setScale(2.5f, 2.5f);
     sprite.setPosition(400.f, 300.f); 
   

}
Player::~Player(){

}
void Player::mover(){

    sf::Event event;

    sf::Keyboard::Key ultimaTecla = sf::Keyboard::Unknown;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        sprite.move(0.0f, -velocidade);
        ultimaDirecao = 'W';
        sprite.setTexture(texCima);
        
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        sprite.move(0.0f, velocidade);
        ultimaDirecao = 'S';
        sprite.setTexture(texBaixo);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        sprite.move(-velocidade, 0.0f);
        ultimaDirecao = 'A';
        sprite.setTexture(texEsquerda);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        sprite.move(velocidade, 0.0f);
        ultimaDirecao = 'D';
        sprite.setTexture(texDireita);
    }
    Personagem::limite();
    
  
   
    }
void Player::habilidade(){
    int tamDash = 150.f;

       if(ultimaDirecao == 'W'){
        sprite.move(0.f , -tamDash);
    }
    if(ultimaDirecao == 'S')
        sprite.move(0.f , tamDash);
       
    if(ultimaDirecao == 'A'){
        sprite.move(-tamDash , 0.f);
    }
    if(ultimaDirecao == 'D')
        sprite.move(tamDash , 0.f);
        Personagem::limite();

    }
    const sf::Sprite& Player::getSprite() const {
    return sprite; 
}
void Player::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}

void Player::setPosition(const sf::Vector2f& novaPos) {
    sprite.setPosition(novaPos);
}


