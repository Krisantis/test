#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "VISUAL NOVEL");
    
	// on fait tourner le programme jusqu'à ce que la fenêtre soit fermée
	while (window.isOpen())
	{
	// on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
	sf::Event event;
	
	//Fond 
	sf::Texture texture;
	if (!texture.loadFromFile("grunge-texture-18536.jpg"))
	{
 	   // erreur...
	}
	sf::Sprite sprite;
	sprite.setTexture(texture);
	
	//Rectangle pour texte
	sf::RectangleShape rectangleText;
	rectangleText.setSize(sf::Vector2f(750, 160));
	rectangleText.setFillColor(sf::Color::Blue);
	rectangleText.setOutlineColor(sf::Color::Black);
	rectangleText.setOutlineThickness(4);
	rectangleText.setPosition(0, 440);
	
	//Rectangle pour menu
	sf::RectangleShape rectangleMenu;
	rectangleMenu.setSize(sf::Vector2f(50, 600));
	rectangleMenu.setFillColor(sf::Color::Blue);
	rectangleMenu.setOutlineColor(sf::Color::Black);
	rectangleMenu.setOutlineThickness(4);
	rectangleMenu.setPosition(750, 0);
	
	//Font
//Trouver un police avec des accents 
	sf::Font font;
	if (!font.loadFromFile("goodfish.ttf"))
	{
  	  // erreur...
	}
	
	//Text
	sf::Text text;
	// choix de la police à utiliser
	text.setFont(font); // font est un sf::Font
	// choix de la chaîne de caractères à afficher
	text.setString(L"C'est un texte è.é'");

	// choix de la taille des caractères
	text.setCharacterSize(24); // exprimée en pixels, pas en points !

	// choix de la couleur du texte
	text.setColor(sf::Color::White);
	
	text.setPosition(450,50);
	// choix du style du texte
	//text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	
	
	while (window.pollEvent(event))
		{
		// évènement "fermeture demandée" : on ferme la fenêtre
		if (event.type == sf::Event::Closed)
			window.close();
		}
		// effacement de la fenêtre en noir
        	window.clear(sf::Color::Black);

        	// c'est ici qu'on dessine tout
        	// window.draw(...);
        	
        	
        	window.draw(sprite);
        	window.draw(rectangleText);
        	window.draw(rectangleMenu);
        	window.draw(text);
        	

        	// fin de la frame courante, affichage de tout ce qu'on a dessiné
        	window.display();
	}

	return 0;
}
