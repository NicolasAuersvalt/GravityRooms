#!/bin/bash

# Verifica se o clang-format está instalado
if ! command -v clang-format &> /dev/null; then
    echo "Erro: clang-format não encontrado. Instale-o primeiro."
    exit 1
fi

# Formatar todos os arquivos .cpp e .h no diretório atual e subdiretórios
find . -name "*.cpp" -o -name "*.h" | xargs -P4 -I{} clang-format -i {}

echo "Formatacao concluida!"
