#include "inimigos.hpp"
#include <iostream>
#include <cmath>
#include <cstdlib>

#define RASTREADOR 200.f
#define RAIO_LINGUADA 50.f


Iainimigo::Iainimigo(Player* jogadorAlvo) : jogador(jogadorAlvo) , Personagem(5.0f) {


         if (!texDireita.loadFromFile("assets/sapo_direita.png") ||
        !texEsquerda.loadFromFile("assets/sapo_esquerda.png") ||
        !texCima.loadFromFile("assets/sapo_cima.png") ||
        !texBaixo.loadFromFile("assets/sapo_baixo.png")) {
        std::cout << "Erro ao carregar as texturas das direcoes do sapo!" << std::endl;
    }
     texDireita.setSmooth(false);
    texEsquerda.setSmooth(false);
    texCima.setSmooth(false);
    texBaixo.setSmooth(false);

    sprite.setTexture(texEsquerda);

    sprite.setScale(2.5f, 2.5f);
    sprite.setPosition(600.f,100.f);

    


};

Iainimigo::~Iainimigo(){

};

void Iainimigo::mover(){
    sf::Vector2f posJogador = jogador->getSprite().getPosition();
    sf::Vector2f posinimigo = sprite.getPosition();
    float distX = posJogador.x - posinimigo.x;
    float distY = posJogador.y - posinimigo.y;
    float mtperto = std::sqrt(std::pow(distX, 2) + std::pow(distY, 2));
    bool pertoJogador = false;

    if(mtperto <= RAIO_LINGUADA){
        this -> habilidade();
        return;
    }
    if(mtperto <= RASTREADOR){
        sf::Vector2f movimento (0.0f, 0.0f);
        pertoJogador = true;

        float margem = 3.0f; 

     if (std::abs(distX) > margem) {
    if(distX > 0.0f){
        movimento.x += velocidade;
        sprite.setTexture(texDireita);
    }
    else{movimento.x -= velocidade;
        sprite.setTexture(texEsquerda);}
    }

     if (std::abs(distY) > margem) {
    if(distY > 0.0f){
        movimento.y += velocidade;
        sprite.setTexture(texBaixo);
    }
    else{ movimento.y -= velocidade;;
        sprite.setTexture(texCima);
    }
    }
    sprite.move(movimento);
}
if(pertoJogador == false){

     if (relogioPasseio.getElapsedTime().asSeconds() >= 2.0f) {
     movealeatorio = rand()%4;
    relogioPasseio.restart();
     }
    sf::Vector2f passo(0.f, 0.f);
    float velPasseio = 1.5f;
    if(movealeatorio == 0){
      (passo.x += velPasseio);
      sprite.setTexture(texDireita);
    }

    else if(movealeatorio == 1){
      (passo.x -= velPasseio);
      sprite.setTexture(texEsquerda);
    }
    else if(movealeatorio == 2){
      (passo.y += velPasseio);
      sprite.setTexture(texBaixo);
    }
    else if(movealeatorio == 3){
      (passo.y -= velPasseio);
      sprite.setTexture(texCima);
    }
      sprite.move(passo);
      

}
limite();
};


void Iainimigo::habilidade(){

    sf::Vector2f posSapo = sprite.getPosition();
    sf::Vector2f posJogador = posSapo;
    posJogador.x += 40.f;

    jogador->setPosition(posJogador);



}