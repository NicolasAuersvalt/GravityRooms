#ifndef REGISTRY_H
#define REGISTRY_H

#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>

#include "json.hpp"

using json = nlohmann::json;

class Ente;

class Registry {
 public:
  using FactoryFunc = std::function<std::unique_ptr<Ente>(json &)>;

  // Singleton: retorna a instância única do Registry
  static Registry &getInstance() {
    static Registry instance;
    return instance;
  }

  // Registra uma classe no Registry com uma função de fábrica
  void registrarClasse(const std::string &tipo, FactoryFunc factory) {
    factories[tipo] = factory;
  }

  // Cria uma entidade com base nos dados JSON
  std::unique_ptr<Ente> criar(json &data) {
    std::string tipo = data["tipo"];
    auto it = factories.find(tipo);
    if (it != factories.end()) {
      return it->second(data);  // Chama a função de fábrica correspondente
    } else {
      std::cerr << "Tipo de entidade não registrado: " << tipo << std::endl;
      return nullptr;
    }
  }

 private:
  Registry() = default;  // Construtor privado para garantir Singleton
  std::unordered_map<std::string, FactoryFunc> factories;  // Mapa de fábricas
};

// Macro para registrar classes automaticamente no Registry
#define REGISTRAR_CLASSE(CLASS, TIPO)                                     \
  static struct Registrar##CLASS {                                        \
    Registrar##CLASS() {                                                  \
      Registry::getInstance().registrarClasse(                            \
          TIPO, [](json &data) -> std::unique_ptr<Ente> {                 \
            return std::make_unique<CLASS>(                               \
                sf::Vector2f(data["posicao"]["x"], data["posicao"]["y"]), \
                sf::Vector2f(10, 10), static_cast<IDs::IDs>(data["id"])); \
          });                                                             \
    }                                                                     \
  } registrar##CLASS;  // Instância estática para registro automático

#endif  // REGISTRY_H