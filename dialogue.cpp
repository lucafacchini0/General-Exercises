#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>

using std::string;

const std::string RESET = "\033[0m";  
const std::string RED = "\033[31m"; 
const std::string YELLOW = "\033[33m"; // Yellow text

int dialogue_index = 0;









enum Character {
    RAZZAQ,
    LUCA,
};



std::string getCharacterName(Character character) {
    switch (character) {
        case RAZZAQ: return "Zaq";
        case LUCA: return "Luca";

        default: return "Unknown";
    }
}

enum DialogueType {
    CONVERSATION,
};

class Dialogue {
private:
    Character character;
    string text;
    DialogueType type;

public:
    Dialogue(Character character, std::string text, DialogueType type) : character(character), text(text), type(type) { print(); }

    void print() {
        std::cout << YELLOW << getCharacterName(character) << ": " << RESET;

        for(int i = 0; i < text.length(); i++) {
            std::cout << text[i];
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }

    } 
};

int main() {
    std::vector<Dialogue> dialogues;

    dialogues[dialogue_index++] = Dialogue(LUCA, "Ciao", CONVERSATION);
    dialogues[dialogue_index++] = Dialogue(RAZZAQ, "Ciao Luca, come stai? Ti carryo su Rust", CONVERSATION);

    return 0;
}
