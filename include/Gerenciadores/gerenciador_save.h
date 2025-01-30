#ifndef GERENCIADOR_SAVE_H
#define GERENCIADOR_SAVE_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <fstream>
#include <mutex>

using namespace std;
using namespace sf;

mutex mtx;

namespace Gerenciadores{

    class SaveManager {
    public:
        static void save(const Vector2f& position) {
            lock_guard<mutex> lock(mtx);
            ofstream file("player_save.txt");
            if (file.is_open()) {
                file << position.x << " " << position.y;
                file.close();
            }
        }

        static Vector2f load() {
            lock_guard<mutex> lock(mtx);
            ifstream file("player_save.txt");
            Vector2f position(100, 100);
            if (file.is_open()) {
                file >> position.x >> position.y;
                file.close();
            }
            return position;
        }
    };
}