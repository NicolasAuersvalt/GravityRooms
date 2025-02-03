// #include "Gerenciadores/gerenciador_json.h"

// namespace Gerenciadores {

// // Construtor
// Gerenciador_Json::Gerenciador_Json() {}

// // Destruidor
// Gerenciador_Json::~Gerenciador_Json() {}

// // Método para converter os dados para o formato JSON
// json Gerenciador_Json::toJson(Dados& dados) {
//   json j;
//   j["nome"] = dados.getNome();
//   j["x"] = dados.getPos().first;
//   j["y"] = dados.getPos().second;
//   cout << dados.getNome() << endl;
//   cout << dados.getPos().first << endl;
//   cout << dados.getPos().second << endl;
//   return j;
// }

// // Método para carregar os dados do arquivo JSON
// void Gerenciador_Json::carregarJson(
//     Dados& dados) {  // Passando dados por referência para modificar
//     diretamente
//   cout << dados.getNome() << endl;  // Supondo que você tenha o método
//   getNome()

//   // Abre o arquivo
//   std::ifstream arquivo(dados.getLocal());  // Certifique-se de que
//   'getLocal'
//                                             // exista na classe Dados

//   // Verifica se o arquivo foi aberto com sucesso
//   if (!arquivo.is_open()) {
//     cerr << "Erro ao abrir o arquivo: " << dados.getLocal() << std::endl;
//     return;
//   }

//   // Lê o conteúdo do arquivo para uma string
//   string conteudo((std::istreambuf_iterator<char>(arquivo)),
//                   std::istreambuf_iterator<char>());

//   try {
//     // Faz o parsing do conteúdo lido
//     json dadosCarregados = json::parse(conteudo);

//     // Carrega os dados
//     dados.setNome(dadosCarregados["nome"]);
//     dados.setPos(make_pair(dadosCarregados["x"],
//                            dadosCarregados["y"]));  // Configura a posição

//     // Exibe os dados carregados
//     std::cout << "Dados carregados: nome = " << dados.getNome()
//               << ", x = " << dados.getPos().first
//               << ", y = " << dados.getPos().second << std::endl;

//   } catch (const json::parse_error& e) {
//     std::cerr << "Erro ao parsear o arquivo JSON: " << e.what() << std::endl;
//   }

//   arquivo.close();  // Fecha o arquivo após a leitura
// }

// // Método para gerar um objeto JSON
// json Gerenciador_Json::getJson(Dados& dados) {
//   json j = toJson(dados);
//   return j;
// }

// }  // namespace Gerenciadores