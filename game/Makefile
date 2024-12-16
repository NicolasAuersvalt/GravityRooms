# Defina os diretórios dos módulos
SRC_DIR = src
INC_DIR = include
LIBS_DIR = libs

# Defina os arquivos de cada módulo
SRC_GERENCIADOR_GRAFICO = $(SRC_DIR)/gerenciador_grafico/gerenciador_grafico.cpp
SRC_ENTE = $(SRC_DIR)/ente/ente.cpp
SRC_MIMICO = $(SRC_DIR)/mimico/mimico.cpp
SRC_JOGO = $(SRC_DIR)/jogo/jogo.cpp

# Todos os arquivos .cpp a serem compilados
SRC_FILES = $(SRC_GERENCIADOR_GRAFICO) $(SRC_ENTE) $(SRC_MIMICO) $(SRC_JOGO) main.cpp

# O nome do executável
TARGET = GravityRooms

# Defina as flags de compilação
CXXFLAGS = -I$(INC_DIR)

# Regras
all: $(TARGET)

$(TARGET): $(SRC_FILES)
	# Compilando os arquivos .cpp e gerando o executável
	g++ $(CXXFLAGS) $(SRC_FILES) -o $(TARGET) -lsfml-graphics -lsfml-window -lsfml-system
	# Copiando as DLLs necessárias (se houver)
	cp $(LIBS_DIR)/*.dll .

# Limpeza (opcional)
clean:
	rm -f $(TARGET)
