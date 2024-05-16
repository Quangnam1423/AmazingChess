This is small **chess game** built with **sfml library** 

# SETUP 

You need install sfml library first. [Here](https://www.sfml-dev.org/download.php).    
Link header files and .lib files follow this tutorial.[Here] (https://www.sfml-dev.org/tutorials/2.6/start-vc.php)    
The sfml library is made of five module  
> - ""sfml-system""  
> - ""sfml-graphics""  
> - ""sfml-window""  
> - ""sfml-network""  
> - ""sfml-audio""


    #include <SFML/Graphics.hpp>
    int main()
    {
        sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
        sf::CircleShape shape(100.f);
        shape.setFillColor(sf::Color::Green);
    
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
    
            window.clear();
            window.draw(shape);
            window.display();
        }
    
        return 0;
    }
> Run this code to verify if the setup is successful!!!  
  
  
  
## RUN  
  
clone this repository:  
> `cd .\AmazingChess`  
> `.\AmazingChess.sln`  
......................  
This game still lacks many features and therefore needs further development!!!  
