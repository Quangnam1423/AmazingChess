#include "TextBox.h"
#include <Graphics.hpp>

#include <iostream>




TextBox::TextBox(float width, float height, std::string newText) {
    light = false;
    setFillColor(sf::Color(50, 50, 50));
    setSize(sf::Vector2f(width, height));

    font.loadFromFile("data\\TextFont\\goodtime.otf");

    text.setFont(font);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);
    text.setString(newText);
}

void TextBox::setText(const std::string& newText) {
    text.setString(newText);
}

void TextBox::setLight(bool value)
{
    light = value;
}

std::string TextBox::getNotation()
{
    return text.getString();
}

void TextBox::setPositionForTextBox(sf::Vector2i position)
{
    setPosition(static_cast<sf::Vector2f> (position));
    text.setPosition(static_cast<sf::Vector2f> (position));
}

void TextBox::displayText(sf::RenderWindow& window) 
{
    window.draw(*this);
    window.draw(text);
}

