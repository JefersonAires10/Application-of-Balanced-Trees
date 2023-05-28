#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <regex>
#include "pessoa.h"
#include "avl.h"
#include "node.h"
#include "data.h"
#include "menus.h"

using namespace std;

void readFile(vector<Pessoa> &pessoas, string filename) {

    ifstream file(filename);
    string line;

    while (getline(file, line)) {

        stringstream ss(line);
        string cpf, nome, sobrenome, data, cidade;
        getline(ss, cpf, ',');
        getline(ss, nome, ',');
        getline(ss, sobrenome, ',');
        getline(ss, data, ',');
        getline(ss, cidade, ',');

        stringstream ss2(data);
        int dia, mes, ano;
        ss2 >> mes;
        ss2.ignore(1);
        ss2 >> dia;
        ss2.ignore(1);
        ss2 >> ano;
        Date dataDeNascimento(mes, dia, ano);

        Pessoa pessoa(cpf, nome + " " + sobrenome, dataDeNascimento, cidade);
        pessoas.push_back(pessoa);

    }
}
/**
 * @brief Função que preenche as árvores com os dados do arquivo csv
 * @param referencia para a árvore de CPF, Nome, Data de Nascimento e Cidade e o vector de pessoas
 * 
*/
void preencherArvores(avl_tree<string> &Cpf, avl_tree<string> &Nome, avl_tree<Date> &data_nascimento, avl_tree<string> &Cidade, vector<Pessoa> &pessoas) {
    for (int i = 0; i < pessoas.size(); i++) {
        Cpf.add(pessoas[i].getCpf(), &pessoas[i]);
        Nome.add(pessoas[i].getNome(), &pessoas[i]);
        data_nascimento.add(pessoas[i].getDataNascimento(), &pessoas[i]);
        Cidade.add(pessoas[i].getCidade(), &pessoas[i]);
    }
}


int main() {

    system("chcp 65001 > nul");

    vector<Pessoa> pessoas;
    readFile(pessoas, "data.csv");

    // Instancias das árvores
    avl_tree<string> Cpf;
    avl_tree<string> Nome;
    avl_tree<Date> data_nascimento;
    avl_tree<string> Cidade;

    preencherArvores(Cpf, Nome, data_nascimento, Cidade, pessoas);

    while (true) {
        int op;
        menuInicial();
        cout << "Digite a opção desejada: ";
        cin >> op;

    
        if (op == 1) {
            system("cls || clear");
            while (true) {
                menuPrincipal();
                int opcao;
                cout << "Digite a opção desejada: ";
                cin >> opcao;
                if (opcao == 1) {
                    cout << "Digite o CPF da pessoa para exibir os seus dados: ";
                    string cpf;
                    cin >> cpf;

                    regex cpfRegex(R"(\d{3}\.\d{3}\.\d{3}-\d{2})");
                    if (regex_match(cpf, cpfRegex)) {
                        system("cls || clear");
                        cout << "Busca realizada, segue o retorno da operação: " << endl;
                        cout << endl;
                        Cpf.searchCpf(Cpf, cpf);
                        cout << endl;
                    }
                    else {
                        try {
                            system("cls");
                            cout << "╭――――――――――――――――――――――――――――——————————————————————————————————————————————————————―╮" << endl;
                            cout << "│                                                                                   │"<< endl;
                            cout << "│    O Cpf informado é inválido, digite uma string no formato: 000.000.000-00       │" << endl;
                            cout << "│                                                                                   │"<< endl;
                            cout << "╰――――――――――――――――――――――――――――——————————————————————————————————————————————————————―╯" << endl; 
                            cout << endl;
                        }
                        catch (const char *msg) {
                            cerr << msg << endl;
                        }
                    }
                }

                else if (opcao == 2) {
                    cout << "Se você procura alguém específico, digite o nome completo desta pessoa: " << endl;
                    system("pause");
                    cout << "Caso contrário, digite apenas uma string qualquer: ";
                    string nome;
                    cin.ignore();
                    getline(cin, nome);
                    system("cls || clear");
                    Nome.searchName(Nome, nome); 

                }
                else if (opcao == 3) {
                    Date dataInicio;
                    Date dataFim;
                    cout << "Digite a data de início da busca no formato mm dd aaaa: ";
                    cin >> dataInicio.mes >> dataInicio.dia >> dataInicio.ano;
                    
                    cout << "Digite a data de fim da busca no formato mm dd aaaa: ";
                    cin >> dataFim.mes >> dataFim.dia >> dataFim.ano;
                    cout << endl;
                    
                    system("cls || clear");
                    data_nascimento.searchDate(data_nascimento, dataInicio, dataFim);
                }

                else if (opcao == 4) {
                    system("cls || clear");
                    break;
                }
                else {
                    try {
                        system("cls");
                        cout << "╭――――――――――――――――――――――――――――——————————————————————————―╮" << endl;
                        cout << "│                                                       │"<< endl;
                        cout << "│    Opção inválida, digite uma opção entre 1 e 4       │" << endl;
                        cout << "│                                                       │"<< endl;
                        cout << "╰――――――――――――――――――――――――――――——————————————————————————―╯" << endl; 
                        cout << endl;
                    }
                    catch (const char *msg) {
                        cerr << msg << endl;
                    }
                }
            }
        }

        else if (op == 2) {
            system("cls || clear");
            while (true) {
                menuOpAdicionais();
                int opcao;
                cout << "Digite a opção desejada: ";
                cin >> opcao;
                if (opcao == 1) {
                    system("cls || clear");
                    menuExibirArvores();
                    int opcao2;
                    cout << "Qual árvore deseja exibir?: ";
                    cin >> opcao2;
                    if (opcao2 == 1) {
                        system("cls || clear");
                        Cpf.bshow();
                    }
                    else if (opcao2 == 2) {
                        system("cls || clear");
                        Nome.bshow();
                    }
                    else if (opcao2 == 3) {
                        system("cls || clear");
                        data_nascimento.bshow();
                    }
                    else if (opcao2 == 4) {
                        system("cls || clear");
                        Cidade.bshow();
                    }
                    else if (opcao2 == 5) {
                        system("cls || clear");
                        break;
                    }
                    else {
                        try {
                        system("cls");
                        cout << "╭――――――――――――――――――――――――――――——————————————————————————―╮" << endl;
                        cout << "│                                                       │"<< endl;
                        cout << "│    Opção inválida, digite uma opção entre 1 e 5       │" << endl;
                        cout << "│                                                       │"<< endl;
                        cout << "╰――――――――――――――――――――――――――――——————————————————————————―╯" << endl; 
                        cout << endl;
                    }
                    catch (const char *msg) {
                        cerr << msg << endl;
                    }
                    }
                }
                else if (opcao == 2) {
                    cout << "Digite o Nome da pessoa que deseja saber sua cidade: ";
                    string nome;
                    cin.ignore();
                    getline(cin, nome);
                    if (nome == "") {
                        system("cls || clear");
                        cout << "Busca realizada, segue o retorno da operação: " << endl;
                        cout << endl;
                        Nome.exibirCidade(Nome, nome);
                        cout << endl;
                    }
                    else {
                        try {
                        system("cls");
                        cout << "╭――――――――――――――――――――――――――――——————―――――——————―――――——————―――――——————―――――———————————————————————―╮" << endl;
                        cout << "│                                                                                                │"<< endl;
                        cout << "│    Essa consulta não é por prefixo, portanto, digite o nome completo da pessoa que busca       │" << endl;
                        cout << "│                                                                                                │"<< endl;
                        cout << "╰―――――――――――――――――――――――――――——————―――――——————―――――——————―――――———――――――——————————————————————————―╯" << endl; 
                        cout << endl;
                        }
                        catch (const char *msg) {
                            cerr << msg << endl;
                        }
                    }
                }
                else if (opcao == 3) {
                    system("cls || clear");
                    break;
                }
                else {
                    try {
                        system("cls");
                        cout << "╭――――――――――――――――――――――――――――——————————————————————————―╮" << endl;
                        cout << "│                                                       │"<< endl;
                        cout << "│    Opção inválida, digite uma opção entre 1 e 3       │" << endl;
                        cout << "│                                                       │"<< endl;
                        cout << "╰――――――――――――――――――――――――――――——————————————————————————―╯" << endl; 
                        cout << endl;
                    }
                    catch (const char *msg) {
                        cerr << msg << endl;
                    }
                }
            }

        }

        else if (op == 3) {
            system("cls || clear");
            menuEncerramento();
            break;
        }
    
        else {
            try {
                system("cls");
                cout << "╭――――――――――――――――――――――――――――——————————————————————————————―╮" << endl;
                cout << "│                                                           │"<< endl;
                cout << "│    Opção inválida, escolha entre as opções do menu.       │" << endl;
                cout << "│                                                           │"<< endl;
                cout << "╰―――――—————————————————————————————————————————————————————―╯" << endl; 
                cout << endl;
            }
            catch (const char *msg) {
                cerr << msg << endl;
            }
        }
    }
}