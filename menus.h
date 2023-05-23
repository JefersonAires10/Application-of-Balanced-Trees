#ifndef MENUS_H
#define MENUS_H

#include <iostream>

void menuInicial() {
    std::cout << " »»━━━━━━━━━━━━━━━◦◦◦◦◦◦◦◦◦◦━━━━━━━━━━━━━━━━«« " << std::endl;
    std::cout << " ┃                                           ┃ " << std::endl;
    std::cout << " ┃               MENU INICIAL                ┃ " << std::endl;
    std::cout << " ┃                                           ┃ " << std::endl;
    std::cout << " »»━━━━━━━━━━━━━━━◦◦◦◦◦◦◦◦◦◦━━━━━━━━━━━━━━━━«« " << std::endl;
    std::cout << " ┃                                           ┃ " << std::endl;
    std::cout << " ┃             1. Realizar Buscas            ┃ " << std::endl;
    std::cout << " ┃                                           ┃ " << std::endl;
    std::cout << " ┃             2. Opções Adicionais          ┃ " << std::endl;
    std::cout << " ┃                                           ┃ " << std::endl;
    std::cout << " ┃             3. Sair                       ┃ " << std::endl;
    std::cout << " ┃                                           ┃ " << std::endl;
    std::cout << " »»━━━━━━━━━━━━━━━◦◦◦◦◦◦◦◦◦◦━━━━━━━━━━━━━━━━«« " << std::endl;

}

void menuPrincipal() {
    std::cout << " »»━━━━━━━━━━━━━━━◦◦◦◦◦◦◦◦◦◦━━━━━━━━━━━━━━━━«« " << std::endl;
    std::cout << " ┃                                           ┃ " << std::endl;
    std::cout << " ┃               MENU PRINCIPAL              ┃ " << std::endl;
    std::cout << " ┃                                           ┃ " << std::endl;
    std::cout << " »»━━━━━━━━━━━━━━━◦◦◦◦◦◦◦◦◦◦━━━━━━━━━━━━━━━━«« " << std::endl;
    std::cout << " ┃                                           ┃ " << std::endl;
    std::cout << " ┃           1. Buscar por CPF               ┃ " << std::endl;
    std::cout << " ┃                                           ┃ " << std::endl;    
    std::cout << " ┃           2. Buscar por Nome              ┃ " << std::endl;
    std::cout << " ┃                                           ┃ " << std::endl;    
    std::cout << " ┃           3. Buscar por Data              ┃ " << std::endl;
    std::cout << " ┃                                           ┃ " << std::endl;
    std::cout << " ┃           4. Voltar ao Menu Inicial       ┃ " << std::endl;
    std::cout << " ┃                                           ┃ " << std::endl;
    std::cout << " »»━━━━━━━━━━━━━━━◦◦◦◦◦◦◦◦◦◦━━━━━━━━━━━━━━━━«« " << std::endl;
}

void menuOpAdicionais() {
    std::cout << " »»━━━━━━━━━━━━━━━◦◦◦◦◦◦◦◦◦◦━━━━━━━━━━━━━━━━«« " << std::endl;
    std::cout << " ┃                                           ┃ " << std::endl;
    std::cout << " ┃              OPÇÕES ADICIONAIS            ┃ " << std::endl;
    std::cout << " ┃                                           ┃ " << std::endl;
    std::cout << " »»━━━━━━━━━━━━━━━◦◦◦◦◦◦◦◦◦◦━━━━━━━━━━━━━━━━«« " << std::endl;
    std::cout << " ┃                                           ┃ " << std::endl;
    std::cout << " ┃          1. Exibir Árvores                ┃ " << std::endl;
    std::cout << " ┃                                           ┃ " << std::endl;
    std::cout << " ┃          2. Exibir Cidade                 ┃ " << std::endl;
    std::cout << " ┃                                           ┃ " << std::endl;
    std::cout << " ┃          3. Voltar ao menu Inicial        ┃ " << std::endl;
    std::cout << " ┃                                           ┃ " << std::endl;
    std::cout << " »»━━━━━━━━━━━━━━━◦◦◦◦◦◦◦◦◦◦━━━━━━━━━━━━━━━━«« " << std::endl;
}

void menuExibirArvores() {
    std::cout << " »»━━━━━━━━━━━━━━━◦◦◦◦◦◦◦◦◦◦━━━━━━━━━━━━━━━━«« " << std::endl;
    std::cout << " ┃                                           ┃ " << std::endl;
    std::cout << " ┃               MENU DE ÁRVORES             ┃ " << std::endl;
    std::cout << " ┃                                           ┃ " << std::endl;
    std::cout << " »»━━━━━━━━━━━━━━━◦◦◦◦◦◦◦◦◦◦━━━━━━━━━━━━━━━━«« " << std::endl;
    std::cout << " ┃                                           ┃ " << std::endl;
    std::cout << " ┃         1. Exibir Árvore de CPF's         ┃ " << std::endl;
    std::cout << " ┃                                           ┃ " << std::endl;
    std::cout << " ┃         2. Exibir Árvore de Nomes         ┃ " << std::endl;
    std::cout << " ┃                                           ┃ " << std::endl;
    std::cout << " ┃         3. Exibir Árvore de Datas         ┃ " << std::endl;
    std::cout << " ┃                                           ┃ " << std::endl;
    std::cout << " ┃         4. Voltar                         ┃ " << std::endl;
    std::cout << " ┃                                           ┃ " << std::endl;
    std::cout << " »»━━━━━━━━━━━━━━━◦◦◦◦◦◦◦◦◦◦━━━━━━━━━━━━━━━━«« " << std::endl;
}

void menuEncerramento() {
    std::cout << " »»━━━━━━━━━━━━━━━◦◦◦◦◦◦◦◦◦◦━━━━━━━━━━━━━━━━«« " << std::endl;
    std::cout << " ┃                                           ┃ " << std::endl;
    std::cout << " ┃             DESENVOLVIDO POR:             ┃ " << std::endl;
    std::cout << " ┃              Jeferson Aires               ┃ " << std::endl;
    std::cout << " ┃                                           ┃ " << std::endl;
    std::cout << " »»━━━━━━━━━━━━━━━◦◦◦◦◦◦◦◦◦◦━━━━━━━━━━━━━━━━«« " << std::endl;
    std::cout << " ┃                                           ┃ " << std::endl;
    std::cout << " ┃           PROFESSOR ORIENTADOR:           ┃ " << std::endl;
    std::cout << " ┃               Atílio Luís                 ┃ " << std::endl;
    std::cout << " ┃                                           ┃ " << std::endl;
    std::cout << " »»━━━━━━━━━━━━━━━◦◦◦◦◦◦◦◦◦◦━━━━━━━━━━━━━━━━«« " << std::endl;
    std::cout << " ┃                                           ┃ " << std::endl;
    std::cout << " ┃                   CURSO:                  ┃ " << std::endl;
    std::cout << " ┃            Ciência da Computação          ┃ " << std::endl;
    std::cout << " ┃                                           ┃ " << std::endl;
    std::cout << " »»━━━━━━━━━━━━━━━◦◦◦◦◦◦◦◦◦◦━━━━━━━━━━━━━━━━«« " << std::endl;
}

#endif // MENUS_H