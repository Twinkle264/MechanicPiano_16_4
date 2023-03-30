#include <iostream>
#include <string>

bool isCorrect(const std::string &a) {
    if (a.size() < 2) {
        std::cerr << "Invalid input! The chord cannot be less than 2 notes" << std::endl;
        return false;
    }

    for (char i: a) {
        if (i < '1' || i > '7') {
            std::cerr << "Invalid input! Can use 1-7" << std::endl;
            return false;
        }
    }
    return true;
}

enum note {
    DO = 1,
    RE = 2,
    MI = 4,
    FA = 8,
    SOL = 16,
    LA = 32,
    SI = 64
};

int main() {
    int melody[12] = {0};
    std::cout << "Enter the melody (12 combinations of notes):" << std::endl;
    for (int i = 0; i < 12; ++i) {
        std::string notes;

        do {
            std::cin >> notes;
        } while (!isCorrect(notes));

        for (int j = 0; j < notes.size(); ++j) {
            int tmp = 1 << (notes[j] - '0' - 1);
            melody[i] = tmp | melody[i];
        }

    }

    std::cout << "Playing the melody..." << std::endl;
    for (int i = 0; i < 12; ++i) {
        int notes = melody[i];
        std::string chord;
        if (notes & DO) {
            chord += "DO ";
        }
        if (notes & RE) {
            chord += "RE ";
        }
        if (notes & MI) {
            chord += "MI ";
        }
        if (notes & FA) {
            chord += "FA ";
        }
        if (notes & SOL) {
            chord += "SOL ";
        }
        if (notes & LA) {
            chord += "LA ";
        }
        if (notes & SI) {
            chord += "SI ";
        }
        std::cout << "Chord " << i + 1 << ": " << chord << std::endl;
    }

    return 0;
}