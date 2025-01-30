#!/bin/bash

# Habilita "modo estrito" para mostrar erros e interromper se algo falhar
set -e

# Criar a pasta 'build' se não existir
mkdir -p build
cd build

# Configuração do CMake para modo Debug
echo "🛠️  Configurando CMake..."
cmake -DCMAKE_BUILD_TYPE=Debug ..

# Compilação
echo "⚙️  Compilando..."
make -j$(nproc)  # Usa múltiplos núcleos para acelerar a compilação

gdb GravityRooms

# Verificar se o executável foi gerado
EXECUTAVEL="./GravityRooms"
if [ -f "$EXECUTAVEL" ]; then
    echo "🚀 Executando o programa..."
    $EXECUTAVEL
else
    echo "❌ Erro: O executável '$EXECUTAVEL' não foi encontrado!"
    exit 1
fi

