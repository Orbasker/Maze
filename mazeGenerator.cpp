#include <SFML/Graphics.hpp>
#include "maze.hpp"
#include "mazeGame.hpp"
#include <iostream>

void drawMaze(sf::RenderWindow& window, const Maze* maze, int playerX, int playerY) {
    // Get the maze width and height
    int mazeWidth = maze->getMazeWidth();
    int mazeHeight = maze->getMazeHeight();

    // Calculate the size of each cell in the maze
    int cellSize = 40; // You can adjust this value as needed

    // Create a rectangle shape for the rooms
    sf::RectangleShape roomShape(sf::Vector2f(cellSize, cellSize));
    roomShape.setFillColor(sf::Color::Yellow);

    // Create a rectangle shape for the walls
    sf::RectangleShape wallShape(sf::Vector2f(cellSize, cellSize));
    wallShape.setFillColor(sf::Color::Red);

    // Create a circle shape for the player
    sf::CircleShape playerShape(cellSize / 4);
    playerShape.setFillColor(sf::Color::Green);

    // Clear the window
    window.clear();

    // Draw the maze
    for (int y = 0; y < mazeHeight; y++) {
        for (int x = 0; x < mazeWidth; x++) {
            roomShape.setPosition(x * cellSize, y * cellSize);
            window.draw(roomShape);
        }
    }

    // Draw the player at their current position
    int playerPosX = playerX * cellSize;
    int playerPosY = playerY * cellSize;
    playerShape.setPosition(playerPosX, playerPosY);
    window.draw(playerShape);

    // Display the window contents
    window.display();
}



int main() {
    std::cout << "Welcome to the Maze Game!" << std::endl;
    std::cout << "Use the arrow keys to move the player." << std::endl;
    std::cout << "Press 'Q' to quit the game." << std::endl;
    
    // Load the font
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cout << "Error loading font." << std::endl;
        return 1;
    }
    MazeGame mazeGame(20);
    Maze* maze = mazeGame.getMaze();
    int playerX = 10; // Player's starting position X-coordinate
    int playerY = 10; // Player's starting position Y-coordinate

    // Create SFML window
    sf::RenderWindow window(sf::VideoMode(400, 400), "Maze Game");

    // Text instructions
    sf::Text instructionsText("Welcome to the Maze Game!", font, 24);
    instructionsText.setPosition(10, 10);
    //color of text
    instructionsText.setFillColor(sf::Color::Blue);
    // Rectangle background for text
    sf::RectangleShape textBackground(sf::Vector2f(780, 40));
    textBackground.setPosition(10, 10);
    textBackground.setFillColor(sf::Color::White);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            //handle mouse events
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    std::cout << "Left mouse button pressed" << std::endl;
                }
                else if (event.mouseButton.button == sf::Mouse::Right) {
                    std::cout << "Right mouse button pressed" << std::endl;
                }

            }

            // Handle keyboard events
            if (event.type == sf::Event::KeyPressed) {
                // Move the player
                if (event.key.code == sf::Keyboard::Up) {
                    if (maze->getRoom(playerY, playerX)->getSide(North) == nullptr) {
                        playerY--;
                    }
                }
                else if (event.key.code == sf::Keyboard::Down) {
                    if (maze->getRoom(playerY, playerX)->getSide(South) == nullptr) {
                        playerY++;
                    }
                }
                else if (event.key.code == sf::Keyboard::Left) {
                    if (maze->getRoom(playerY, playerX)->getSide(West) == nullptr) {
                        playerX--;
                    }
                }
                else if (event.key.code == sf::Keyboard::Right) {
                    if (maze->getRoom(playerY, playerX)->getSide(East) == nullptr) {
                        playerX++;
                    }
                }                
            }
        }

        // Clear the window
        window.clear();

        // Draw the text background and text
        window.draw(textBackground);
        window.draw(instructionsText);

        // Draw the maze and player
        drawMaze(window, maze, playerX, playerY);

        // Display the window
        window.display();
    }

    return 0;
}

