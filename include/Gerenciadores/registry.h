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
  using FactoryFunc = std::function<std::unique_ptr<Ente>(json&)>;

  static Registry& getInstance() {
    static Registry instance;
    return instance;
  }

  void registrarClasse(const std::string& tipo, FactoryFunc factory) {
    factories[tipo] = factory;
  }

  std::unique_ptr<Ente> criar(json& data) {
    std::string tipo = data["tipo"];
    auto it = factories.find(tipo);
    if (it != factories.end()) {
      return it->second(data);
    } else {
      std::cerr << "Tipo de entidade não registrado: " << tipo << std::endl;
      return nullptr;
    }
  }

 private:
  Registry() = default;
  std::unordered_map<std::string, FactoryFunc> factories;
};

#define REGISTRAR_CLASSE(CLASS, TIPO)                                          \
  static struct Registrar##CLASS {                                             \
    Registrar##CLASS() {                                                       \
      Registry::getInstance().registrarClasse(                                 \
          TIPO,                                                                \
          [](json& data)                                                       \
              -> std::unique_ptr<                                              \
                  Ente> { /* Retorno explícito necessário */                   \
                          if constexpr (std::is_constructible_v<               \
                                            CLASS, sf::Vector2f, sf::Vector2f, \
                                            IDs::IDs>) {                       \
                            return std::make_unique<CLASS>(                    \
                                sf::Vector2f(data["posicao"]["x"],             \
                                             data["posicao"]["y"]),            \
                                sf::Vector2f(10, 10),                          \
                                static_cast<IDs::IDs>(data["id"]));            \
                          } else if constexpr (std::is_constructible_v<        \
                                                   CLASS, sf::Vector2f,        \
                                                   std::nullptr_t,             \
                                                   IDs::IDs>) {                \
                            return std::make_unique<CLASS>(                    \
                                sf::Vector2f(data["posicao"]["x"],             \
                                             data["posicao"]["y"]),            \
                                nullptr, static_cast<IDs::IDs>(data["id"]));   \
                          } else {                                             \
                            std::cerr << "Erro: Nenhum construtor adequado "   \
                                         "encontrado para "                    \
                                      << TIPO << std::endl;                    \
                            return nullptr; /* Necessário para evitar erro de \
                                               conversão */                   \
                          }                                                    \
          });                                                                  \
    }                                                                          \
  } registrar##CLASS;

#endif