//#include "jogo.h"
#include "Gravity_rooms.h"
#include <iostream>
#include <unistd.h>

int main(){

    char buf[1024];
    getcwd(buf, sizeof(buf));
    std::cout << "Diretorio atual: " << buf << std::endl;

    // ===/===/===/===/ Obrigatório ===/===/===/===/

    //Jogo GravityRooms;

    // ===/===/===/===/ Outros ===/===/===/===/
    Gravity_Rooms gravityrooms;

    // Gerenciador_Grafico graficos;

    return 0;
}