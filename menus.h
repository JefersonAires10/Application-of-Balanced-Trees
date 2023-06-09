#ifndef MENUS_H
#define MENUS_H

#include <iostream>

/**
 * @brief Menu inicial do programa
*/
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
/**
 * @brief Menu de consultas do programa
*/
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
/**
 * @brief Menu de opções adicionais do programa
*/
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
/**
 * @brief Menu de exibição de árvores do programa
*/
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
    std::cout << " ┃         4. Exibir Árvores de Cidades      ┃ " << std::endl;    
    std::cout << " ┃                                           ┃ " << std::endl;
    std::cout << " ┃         5. Voltar                         ┃ " << std::endl;
    std::cout << " ┃                                           ┃ " << std::endl;
    std::cout << " »»━━━━━━━━━━━━━━━◦◦◦◦◦◦◦◦◦◦━━━━━━━━━━━━━━━━«« " << std::endl;
}
/**
 * @brief Menu de enecerramento do programa
*/
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