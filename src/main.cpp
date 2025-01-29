//#include "jogo.h"
#include "gravity_rooms.h"
#include <iostream>
#include <unistd.h>

int main(){

	char buf[1024];
	getcwd(buf, sizeof(buf));
	std::cout << "Diretório atual: " << buf << std::endl;

	// ===/===/===/===/ Obrigatório ===/===/===/===/

	//Jogo GravityRooms;

	// ===/===/===/===/ Outros ===/===/===/===/
	Gravity_Rooms gravityrooms;

	// Gerenciador_Grafico graficos;

	return 0;
}
