#pragma once
#include <Graphics.hpp>
class TextBox :
    public sf::RectangleShape
{

public:
    using sf::RectangleShape::getGlobalBounds;
    using sf::RectangleShape::setPosition;
    TextBox(float width, float height, std::string newText);
    TextBox(){}
    ~TextBox(){}

    void setText(const std::string& newText);

    void setPositionForTextBox(sf::Vector2i position);

    void displayText(sf::RenderWindow& window);

    void setLight(bool value);

    std::string getNotation();

private:
    sf::Font font;
    sf::Text text;
    bool light;
};

