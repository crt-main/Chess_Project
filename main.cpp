#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include <map>
#include <array>

enum class Player_ {
    PLAYER_1_MOVE,
    PLAYER_2_MOVE,
};

enum class Color_ {
    BLACK,
    WHITE
};

enum class PieceType_ {
    PAWN,
    BISHOP,
    ROOK,
    QUEEN,
    KING,
};

class Piece {
private:
    Color_ colorCode_;
    PieceType_ pieceType_;
    sf::Color color_;
    sf::Vector2i position_;

public:
    Piece(const PieceType_ pieceType, const sf::Color color, const sf::Vector2i position, const Color_ colorCode) {
        this->pieceType_ = pieceType;
        this->color_ = color;
        this->position_ = position;
        this->colorCode_ = colorCode;
    }
};

class Player {
private:
    std::array<Piece, 16> pieces_;
    Color_ colorCode_;
    sf::Mouse::Button playerMouse;

public:
    Player(const Color_ colorCode_) : playerMouse(sf::Mouse::Button::Left) {
        this->colorCode_ = colorCode_;
    }

    [[nodiscard]] Color_ getColor() const {return colorCode_;}
};

class Square {
private:
    bool placeHeld_;
    Color_ colorCode_;
    sf::Color color_;
    sf::Vector2i position_;
    sf::RectangleShape square_;

public:
    Square(const bool placeHeld, const Color_ colorCode, const sf::Color color, const sf::Vector2i position) :
    square_({20,20})
    {
        this->placeHeld_ = placeHeld;
        this->colorCode_ = colorCode;
        this->color_ = color;
        this->position_ = position;
    }

};

class Board {
private:
    std::array<std::array<Square, 8>, 8> squares_;

public:
    Board() {
        for (int y = 0; y < 8; y++) {
            for (int x = 0; x < 8; x++) {
                const bool isWhite = (x + y) % 2 == 0;
                squares_[y][x] = Square(
                    false,
                    isWhite ? Color_::WHITE : Color_::BLACK,
                    isWhite ? sf::Color::White : sf::Color::Black,
                    sf::Vector2i(x, y)
                );
            }
        }
    }
};

int main() {
    Board board;
    Player playerWhite(Color_::WHITE);
    Player playerBlack(Color_::BLACK);

}