#include "GameControllCommandsConverter.hpp"

//initialization
GameControllCommandsConverter::GameControllCommandsConverter(){
    this->createDictionary();
};

//converte string key to sf::Keyboard::Key
sf::Keyboard::Key GameControllCommandsConverter::convert(std::string key){
    auto search = this->dict_commands.find(key);
    if (search != this->dict_commands.end()){
        return search->second;
    }
};

//filling dict_commands
void GameControllCommandsConverter::createDictionary(){
    //first line
    this->dict_commands.emplace("Q", sf::Keyboard::Q);
    this->dict_commands.emplace("W", sf::Keyboard::W);
    this->dict_commands.emplace("E", sf::Keyboard::E);
    this->dict_commands.emplace("R", sf::Keyboard::R);
    this->dict_commands.emplace("T", sf::Keyboard::T);
    this->dict_commands.emplace("Y", sf::Keyboard::Y);
    this->dict_commands.emplace("U", sf::Keyboard::U);
    this->dict_commands.emplace("I", sf::Keyboard::I);
    this->dict_commands.emplace("O", sf::Keyboard::O);
    this->dict_commands.emplace("P", sf::Keyboard::P);
    //second line
    this->dict_commands.emplace("A", sf::Keyboard::A);
    this->dict_commands.emplace("S", sf::Keyboard::S);
    this->dict_commands.emplace("D", sf::Keyboard::D);
    this->dict_commands.emplace("F", sf::Keyboard::F);
    this->dict_commands.emplace("G", sf::Keyboard::G);
    this->dict_commands.emplace("H", sf::Keyboard::H);
    this->dict_commands.emplace("J", sf::Keyboard::J);
    this->dict_commands.emplace("K", sf::Keyboard::K);
    this->dict_commands.emplace("L", sf::Keyboard::L);
    //third line
    this->dict_commands.emplace("Z", sf::Keyboard::Z);
    this->dict_commands.emplace("X", sf::Keyboard::X);
    this->dict_commands.emplace("C", sf::Keyboard::C);
    this->dict_commands.emplace("V", sf::Keyboard::V);
    this->dict_commands.emplace("B", sf::Keyboard::B);
    this->dict_commands.emplace("N", sf::Keyboard::N);
    this->dict_commands.emplace("M", sf::Keyboard::M);
    //numbers
    this->dict_commands.emplace("0", sf::Keyboard::Num0);
    this->dict_commands.emplace("1", sf::Keyboard::Num1);
    this->dict_commands.emplace("2", sf::Keyboard::Num2);
    this->dict_commands.emplace("3", sf::Keyboard::Num3);
    this->dict_commands.emplace("4", sf::Keyboard::Num4);
    this->dict_commands.emplace("5", sf::Keyboard::Num5);
    this->dict_commands.emplace("6", sf::Keyboard::Num6);
    this->dict_commands.emplace("7", sf::Keyboard::Num7);
    this->dict_commands.emplace("8", sf::Keyboard::Num8);
    this->dict_commands.emplace("9", sf::Keyboard::Num9);
    //f numbers
    this->dict_commands.emplace("f1", sf::Keyboard::F1);
    this->dict_commands.emplace("f2", sf::Keyboard::F2);
    this->dict_commands.emplace("f3", sf::Keyboard::F3);
    this->dict_commands.emplace("f4", sf::Keyboard::F4);
    this->dict_commands.emplace("f5", sf::Keyboard::F5);
    this->dict_commands.emplace("f6", sf::Keyboard::F6);
    this->dict_commands.emplace("f7", sf::Keyboard::F7);
    this->dict_commands.emplace("f8", sf::Keyboard::F8);
    this->dict_commands.emplace("f9", sf::Keyboard::F9);
    this->dict_commands.emplace("f10", sf::Keyboard::F10);
    this->dict_commands.emplace("f11", sf::Keyboard::F11);
    this->dict_commands.emplace("f12", sf::Keyboard::F12);
    //special symbols
    this->dict_commands.emplace("Space", sf::Keyboard::Space);
    this->dict_commands.emplace("Tab", sf::Keyboard::Tab);
    this->dict_commands.emplace("Enter", sf::Keyboard::Enter);
    this->dict_commands.emplace("Esc", sf::Keyboard::Escape);

    this->dict_commands.emplace("Up", sf::Keyboard::Up);
    this->dict_commands.emplace("Down", sf::Keyboard::Down);
    this->dict_commands.emplace("Left", sf::Keyboard::Left);
    this->dict_commands.emplace("Right", sf::Keyboard::Right);
};
