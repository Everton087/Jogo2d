
#ifndef PERSONAGEM_HPP
#define PERSONAGEM_HPP



#include <SFML/Graphics.hpp>

class Personagem{
    protected:
    sf::Texture texCima;
    sf::Texture texBaixo;
    sf::Texture texEsquerda;
    sf::Texture texDireita;
    sf::Sprite sprite;
    float velocidade = 3.f;

    public:
    Personagem(float velincial);
    virtual ~Personagem();
    virtual void mover() = 0;
    virtual void habilidade() = 0;
    void limite();
    
    void desenhar(sf::RenderWindow& window);


};
#endif