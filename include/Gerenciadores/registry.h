#ifndef REGISTRY_H
#define REGISTRY_H

#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>

#include "json.hpp"

using json = nlohmann::json;

using namespace std;
using namespace sf;

class Ente;

// =====/=====/=====/=====/=====/=====/
// Requisitos Funcionais  10

// Requisitos Conceituais 4.3
// Requisitos Conceituais 6.3
// =====/=====/=====/=====/=====/=====/

class Registry {
public:
  using FactoryFunc = function<unique_ptr<Ente>(json &)>;

  // Singleton: retorna a instância única do Registry
  static Registry &getInstance() {
    static Registry instance;
    return instance;
  }

  // Registra uma classe no Registry com uma função de fábrica
  void registrarClasse(const string &tipo, FactoryFunc factory) {
    factories[tipo] = factory;
  }

  // Cria uma entidade com base nos dados JSON
  unique_ptr<Ente> criar(json &data) {
    string tipo = data["tipo"];
    auto it = factories.find(tipo);
    if (it != factories.end()) {
      return it->second(data); // Chama a função de fábrica correspondente
    } else {
      cerr << "Tipo de entidade não registrado: " << tipo << endl;
      return nullptr;
    }
  }

private:
  Registry() = default; // Construtor privado para garantir Singleton
  unordered_map<string, FactoryFunc> factories; // Mapa de fábricas
};

// Macro para registrar classes automaticamente no Registry
#define REGISTRAR_CLASSE(CLASS, TIPO)                                          \
  static struct Registrar##CLASS {                                             \
    Registrar##CLASS() {                                                       \
      Registry::getInstance().registrarClasse(                                 \
          TIPO, [](json &data) -> unique_ptr<Ente> {                           \
            return make_unique<CLASS>(                                         \
                Vector2f(data["posicao"]["x"], data["posicao"]["y"]),          \
                Vector2f(10, 10), static_cast<IDs::IDs>(data["id"]));          \
          });                                                                  \
    }                                                                          \
  } registrar##CLASS; // Instância estática para registro automático

#endif // REGISTRY_H