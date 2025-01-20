cmake_minimum_required(VERSION 3.10)

# Nome do projeto
project(GravityRooms VERSION 1.0)

# Definir o padrão do C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Diretórios de include
include_directories(include)

# Adicionar todos os arquivos .cpp do diretório src e suas subpastas
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Definir a pasta de assets
set(ASSETS_DIR ${PROJECT_SOURCE_DIR}/assets)

# Copiar arquivos da pasta assets para a pasta de build
file(COPY ${ASSETS_DIR} DESTINATION ${CMAKE_BINARY_DIR})

# Procurar o SFML (componentes: system, window, graphics)
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

# Criar o executável
add_executable(GravityRooms ${SOURCES})

# Linkar as bibliotecas do SFML
target_link_libraries(GravityRooms sfml-system sfml-window sfml-graphics)
