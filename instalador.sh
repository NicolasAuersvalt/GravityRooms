#!/bin/bash

set -e  # Para o script se algum comando falhar

# Atualiza pacotes e instala dependências
sudo apt update && sudo apt install -y libsfml-dev build-essential cmake

# Clona o repositório
if [ ! -d "GravityRooms" ]; then
    git clone https://github.com/NicolasAuersvalt/GravityRooms.git
fi

cd GravityRooms

# Cria diretório de build se não existir
mkdir -p build && cd build

# Compila o projeto
cmake ..
make

echo "Instalação concluída! Para rodar o jogo, use ./build.sh"
