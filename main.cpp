#include "Application.h"
#include <cstdlib>

int main()
{
	Application app;
	app.run();
	return EXIT_SUCCESS;
}

//#include <SFML/Graphics.hpp>

//int main() {
//    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Text Example");
//
//    // Tạo một đối tượng font
//    sf::Font font;
//    if (!font.loadFromFile("data\\TextFont\\goodtime.otf")) {
//        // Xử lý lỗi khi không thể tải font
//        return EXIT_FAILURE;
//    }
//
//    // Tạo đối tượng văn bản và thiết lập các thuộc tính
//    sf::Text text("Hello, SFML!", font, 30);
//    text.setPosition(100.0f, 100.0f);
//    text.setFillColor(sf::Color::White);
//
//    while (window.isOpen()) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        window.clear();
//
//        // Vẽ đối tượng văn bản ra cửa sổ
//        window.draw(text);
//
//        window.display();
//    }
//
//    return 0;
//}