cmake_minimum_required(VERSION 3.10)

# Nome do projeto
project(GravityRooms)

# Definir versão do C++
set(CMAKE_CXX_STANDARD 11)

# Incluir o diretório atual (onde os arquivos .cpp estão localizados)
include_directories(.)

# Procurar todos os arquivos .cpp diretamente no diretório atual
file(GLOB SOURCES "*.cpp")

# Criar o executável
add_executable(GravityRooms ${SOURCES})

# Procurar SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Vincular SFML ao executável
target_link_libraries(GravityRooms sfml-graphics sfml-window sfml-system)

# Comando para copiar as DLLs necessárias após o build
add_custom_command(TARGET GravityRooms POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/libs $<TARGET_FILE_DIR:GravityRooms>/libs)
