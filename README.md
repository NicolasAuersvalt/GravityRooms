# GravityRooms

![GravityRooms](assets/Logo.jpg)

Federal University of Technology - Paraná (2024-2025)

---


Developed by:

Nícolas Auersvalt Marques

Isabela Bella Bortoleto

---


Antes de instalar o jogo, certifique-se de ter as seguintes ferramentas instaladas no seu sistema:

CMake: Ferramenta de automação de compilação (3.22.1).

Make: Sistema de compilação (GNU Make 4.3).

Compilador C++: Recomendado o g++ ou clang++ (g++ (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0).

SFML 2.5.1 (Audio, Graphics, Network, System, Window)

# Instação

No Ubuntu ou outras distribuições baseadas no Debian, você pode instalar esses pacotes com:

    sudo apt update 
    sudo apt install build-essential cmake

Se ainda não tiver o repositório, clone-o usando:

    git clone https://github.com/NicolasAuersvalt/GravityRooms.git
    cd GravityRooms 

Crie e entre no diretório de build, onde a compilação do projeto será feita:

    mkdir build && cd build

Use o CMake para gerar os arquivos necessários para a construção do projeto, em seguida, compile com o Make:

    cmake ..
    make

Depois de compilado, execute o jogo com o comando:

    ./GravityRooms


## Contexto e Planejamento

(V) Escolher o jogo de plataforma a ser desenvolvido.

(V) Validar a escolha do jogo com o professor.

(V) Planejar as fases, obstáculos, inimigos e funcionalidades.

## Requisitos Funcionais do Jogo

( ) Criar menu gráfico com:

( ) Opções de seleção de fases. (Observer: Menu)

( ) Exibição do ranking de jogadores.

( ) Outras funcionalidades pertinentes.

( ) Implementar suporte para:

( ) Um jogador.

( ) Dois jogadores (opcional ou parcialmente realizado).

( ) Desenvolver ao menos duas fases jogáveis:

( ) Fases com diferentes dificuldades.

( ) Fases com obstáculos e inimigos variados.

( ) Incluir pelo menos três tipos de inimigos:

( ) Um inimigo capaz de lançar projéteis.

( ) Um chefão.

( ) Adicionar no mínimo três tipos de obstáculos:

( ) Obstáculos que causem dano ao jogador.

( ) Implementar física básica:

( ) Efeito de gravidade.

( ) Detecção de colisões entre jogadores, inimigos e obstáculos. (Mediator: Gerenciador de Colisões)

( ) Incluir persistência de dados:

( ) Salvar nome do jogador e pontuação.

( ) Salvar e recuperar estado do jogo.

( ) Gerar ranking.

## Modelagem e Projeto

(V) Elaborar diagrama de classes em UML:

(V) Baseado no modelo fornecido.

(V) Melhorar e expandir conforme necessário.

( ) Validar o diagrama com o professor.

## Implementação

(V) Desenvolver o jogo em C++.

(V) Utilizar uma biblioteca gráfica (preferencialmente SFML).

( ) Aplicar conceitos de orientação a objetos:

(V) Classes e objetos.

( ) Herança e polimorfismo. (Template Method: Hierarquia de Ente, Entidade, Personagem)

( ) Encapsulamento e coesão.

( ) Desacoplamento. (Bridge: Relação entre Ente e Interface Gráfica)

( ) Implementar funcionalidades gráficas e interativas.

## Documentação

( ) Seguir o modelo de formatação fornecido.

( ) Escrever as seguintes seções no documento:

( ) Introdução:

( ) Contexto e objetivo do trabalho.

( ) Objeto de estudo.

( ) Método utilizado.

( ) Estrutura do documento.

( ) Explicação do Jogo:

( ) Tela e funcionalidades principais.

( ) Figuras e telas do jogo.

( ) Desenvolvimento:

( ) Requisitos funcionais atendidos.

( ) Descrição do diagrama de classes.

( ) Principais classes e sua interação.

( ) Reflexão comparativa (se aplicável):

( ) Comparação com desenvolvimento procedimental.

( ) Discussão e Conclusões:

( ) Reflexão sobre dificuldades e resultados.

( ) Considerações pessoais (opcional).

( ) Divisão de tarefas:

( ) Tabela com atividades e responsáveis.

( ) Revisar o documento para evitar erros de português e formatação.

## Reuniões e Interações

(V) Realizar pelo menos duas reuniões com o professor.

( ) Realizar quatro reuniões com o monitor.

( ) Registrar e enviar resumos das reuniões por e-mail.

## Apresentação

( ) Preparar os slides (.ppt ou .pdf).

( ) Ensaiar a apresentação do trabalho.

## Entrega

( ) Enviar:

( ) Documento escrito (.docx e .pdf).

( ) Diagrama(s) de classes (digital e impresso).

( ) Código-fonte do jogo.

( ) Slides da apresentação.

( ) Utilizar plataformas seguras para envio (preferencialmente Google Drive institucional).

## Padrões de Software Aplicados

( ) (Adapter: Coordenadas)

( ) (Observer: Notificações, Gerenciador de Eventos, Menu)

( ) (Mediator: Gerenciador de Colisões)

( ) (Template Method: Hierarquia de Ente, Entidade, Personagem)

( ) (Builder: Construção de entidades na fase)

## Conceitos

(V) - Classes, objetos. & - Atributos (privados), variáveis e constantes - Métodos (com e sem retorno).

( ) Métodos (com retorno const e parâmetro const) & Construtores (sem/com parâmetros) e destrutores

( ) Classe Principal.

(V) Divisão em .h e .cpp.

( ) Associação direcional. & - Associação bidirecional.

( ) Agregação via associação. & - Agregação propriamente dita.

(V) Herança elementar. & - Herança em vários níveis.

( ) Herança múltipla.

( ) Operador this para fins de relacionamento bidirecional.

( ) Alocação de memória (new & delete).

(V) Gabaritos/Templates criada/adaptados pelos autores para Listas.

( ) Uso de Tratamento de Exceções (try catch).

(V) Construtoras e Métodos.

( ) Operadores (2 tipos de operadores pelo menos)

( ) Persistência de Objetos. 

( ) Persistência de Relacionamento de Objetos.

(V) Métodos Virtuais Usuais.

(V) Polimorfismo.

(V) Métodos Virtuais Puros / Classes Abstratas.

( ) Coesão/Desacoplamento efetiva e intensa com o apoio de padrões de projeto (mais de 5 padrões). 

(V) Espaço de Nomes (Namespace) criada pelos autores.

( ) Classes aninhadas (Nested) criada pelos autores.

( ) Atributos estáticos e métodos estáticos.

( ) Uso extensivo de constante (const) parâmetro, retorno, método...

( ) A classe Pré-definida  String ou equivalente. & - Vector e/ou List da STL (p/ objetos ou ponteiros de objetos de classes definidos pelos autores)

( ) Pilha, Fila, Bifila, Fila de Prioridade, Conjunto, Multi-Conjunto, Mapa OU Multi-Mapa.

( ) Threads (Linhas de Execução) no âmbito da Orientação a Objetos, utilizando Posix, C-Run-Time OU Win32API ou afins.

( ) Threads (Linhas de Execução) no âmbito da Orientação a Objetos com uso de Mutex, Semáforos, OU Troca de mensagens.

( ) Funcionalidades Elementares. & Funcionalidades Avançadas como: tratamento de colisões e duplo buffer

( ) Programação orientada e evento efetiva (com gerenciador apropriado de eventos inclusive, via padrão de projeto Observer) em algum ambiente gráfico. OU - RAD – Rapid Application Development (Objetos gráficos como formulários, botões etc).

( ) Ensino Médio Efetivamente.

( ) Ensino Superior Efetivamente.

( ) Compreensão, melhoria e rastreabilidade de cumprimento de requisitos.

( ) Diagrama de Classes em UML.

( ) Uso efetivo e intensivo de padrões de projeto GOF, i.e., + de 5 padrões.

(V) Testes à luz da Tabela de Requisitos e do Diagrama de Classes.

(V) Controle de versão de modelos e códigos automatizado (via github) e uso de alguma forma de cópia de segurança (i.e., backup).

(V) Reuniões com o professor para acompanhamento do andamento do projeto. [ITEM OBRIGATÓRIO A ENTREGA DO TRABALHO]

(V) Reuniões com monitor da disciplina para acompanhamento do andamento do projeto. [ITEM OBRIGATÓRIO PARA A ENTREGA]

( )Escrita do trabalho e feitura da apresentação & Revisão do trabalho escrito de outra equipe e vice-versa.
