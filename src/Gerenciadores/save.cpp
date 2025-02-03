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
//   gravarDados();  // Save main player

//   // Add level information
//   dados.setLevel(dynamic_cast<Laboratorio*>(fase) ? "laboratorio" : "nave");

//   // Add second player if exists
//   if (hasPlayer2 && pJog2) {
//     dados.setPlayer2Pos(pJog2->getPosicao());
//     dados.setPlayer2Health(pJog2->getVida());
//   }

//   json j = getJson(dados);
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