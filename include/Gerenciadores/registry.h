// registry.h
#ifndef REGISTRY_H
#define REGISTRY_H

#include <functional>
#include <memory>
#include <string>
#include <unordered_map>

#include "json.hpp"

using json = nlohmann::json;

class Ente;

class Registry {
 public:
  using FactoryFunc = std::function<std::unique_ptr<Ente>(const json&)>;

  static Registry& getInstance() {
    static Registry instance;
    return instance;
  }

  void registrarClasse(const std::string& tipo, FactoryFunc factory) {
    factories[tipo] = factory;
  }

  std::unique_ptr<Ente> criar(const json& data) {
    std::string tipo = data["tipo"];
    auto it = factories.find(tipo);
    return (it != factories.end()) ? it->second(data) : nullptr;
  }

 private:
  Registry() = default;
  std::unordered_map<std::string, FactoryFunc> factories;
};

#define REGISTRAR_CLASSE(CLASS, TIPO)                                      \
  static struct Registrar##CLASS {                                         \
    Registrar##CLASS() {                                                   \
      Registry::getInstance().registrarClasse(TIPO, [](const json& data) { \
        auto obj = std::make_unique<CLASS>();                              \
        obj->carregar(data);                                               \
        return obj;                                                        \
      });                                                                  \
    }                                                                      \
  } registrar##CLASS;

#endif