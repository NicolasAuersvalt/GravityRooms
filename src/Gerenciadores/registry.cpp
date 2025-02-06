// #include "Gerenciadores/registry.h"

// // Implementação do método para obter a instância singleton
// Registry& Registry::getInstance() {
//   static Registry instance;
//   return instance;
// }

// // Implementação do método para registrar uma classe
// void Registry::registrarClasse(const std::string& tipo, FactoryFunc factory)
// {
//   factories[tipo] = factory;
// }

// // Implementação do método para criar uma entidade a partir de dados JSON
// std::unique_ptr<Ente> Registry::criar(json& data) {
//   std::string tipo = data["tipo"];
//   auto it = factories.find(tipo);
//   if (it != factories.end()) {
//     return it->second(data);
//   } else {
//     std::cerr << "Tipo de entidade não registrado: " << tipo << std::endl;
//     return nullptr;
//   }
// }