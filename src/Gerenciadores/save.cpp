// #include "Gerenciadores/save.h"

// Save::Save() : dados() { dados.setLocal("saves/save.json"); }

// Save::~Save() {}

// void Save::setJogador(Entidades::Personagens::Tripulante* jogador) {
//   if (jogador) {
//     pJog1 = jogador;
//   }
// }

// Entidades::Personagens::Tripulante* Save ::getJogador() { return pJog1; }

// void Save::gravarDados() {
//   dados.setNome("Jogador1");
//   dados.setPos(make_pair(pJog1->getPosicao().x, pJog1->getPosicao().y));
//   dados.setLocal("saves/save.json");
// }

// void Save::salvar() {
//   // Salva os dados do Jogador
//   gravarDados();

//   // Cria um arquivo de texto Json
//   json j = getJson(dados);

//   // Envia para o salvamento
//   salvarArquivo(dados, j);
// }

// void Save::carregar() {
//   cout << "Save::carregar()" << endl;
//   bool carregado = arquivoExiste(dados);
//   if (carregado) {
//     carregarJson(dados);
//   }
//   pJog1->setPosicao(dados.getPos().first, dados.getPos().first);
// }