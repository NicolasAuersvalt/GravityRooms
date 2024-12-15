all:
	# Compilando todos os arquivos .cpp necessários
	g++ -I"include" src/*.cpp main.cpp -o GravityRooms -lsfml-graphics -lsfml-window -lsfml-system
	# Copiando as DLLs necessárias (se houver)
	cp libs/*.dll .

# Limpeza (opcional)
clean:
	rm -f GravityRooms
