#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "personagem.hpp"
#include "inimigos.hpp"

int main(){


    sf::RenderWindow window(sf::VideoMode(800.f, 600.f) ,"jogo");
    window.setFramerateLimit(60);

   
    Player jogador;
    Iainimigo sapo(&jogador);

    while (window.isOpen()){
        

     
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed){
                window.close();}
                   if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Space) {
            jogador.habilidade();
        }
    }
        }
      
   
      jogador.mover();
      sapo.mover();
      window.clear();
      window.clear(sf::Color::Green);
        jogador.desenhar(window);
        sapo.desenhar(window);
        
        window.display();
    
     }
    
    
    return 0;
}