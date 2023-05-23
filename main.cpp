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

        /*for (int i = 0; i < cpf.size(); i++) {
            if (cpf[i] == '.' || cpf[i] == '-') {
                cpf.erase(i--, 1);
            }
        }*/

        stringstream ss2(data);
        int dia, mes, ano;
        ss2 >> mes;
        ss2.ignore(1);
        ss2 >> dia;
        ss2.ignore(1);
        ss2 >> ano;
        Date dataDeNascimento(mes, dia, ano);

        Pessoa pessoa(cpf, nome + " " + sobrenome, dataDeNascimento);
        pessoas.push_back(pessoa);

    }
}

void preencherArvores(avl_tree<string> &Cpf, avl_tree<string> &Nome, avl_tree<Date> &data_nascimento, vector<Pessoa> &pessoas) {
    for (int i = 0; i < pessoas.size(); i++) {
        Cpf.add(pessoas[i].getCpf(), &pessoas[i]);
        Nome.add(pessoas[i].getNome(), &pessoas[i]);
        data_nascimento.add(pessoas[i].getDataNascimento(), &pessoas[i]);
    }
}


int main() {

    system("chcp 65001 > nul");

    vector<Pessoa> pessoas;
    readFile(pessoas, "data.csv");

    avl_tree<string> Cpf;
    avl_tree<string> Nome;
    avl_tree<Date> data_nascimento;

    preencherArvores(Cpf, Nome, data_nascimento, pessoas);

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
                        cout << endl;
                        system("cls || clear");
                        cout << "O Cpf informado é inválido, digite uma string no formato: 000.000.000-00" << endl;
                        cout << endl;                        
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
                /*else if (opcao == 3) {
                    cout << "Digite a data de nascimento da pessoa que você procura: ";
                    string data;
                    cin >> data;
                    regex dataRegex(R"(\d{2}\/\d{2}\/\d{4})");
                    if (regex_match(data, dataRegex)) {
                        stringstream ss(data);
                        int dia, mes, ano;
                        ss >> dia;
                        ss.ignore(1);
                        ss >> mes;
                        ss.ignore(1);
                        ss >> ano;
                        Date dataDeNascimento(mes, dia, ano);
                        system("cls || clear");
                        data_nascimento.searchDate(data_nascimento, dataDeNascimento);
                    }
                    else {
                        cout << endl;
                        system("cls || clear");
                        cout << "A data informada é inválida, digite uma string no formato: dd/mm/aaaa" << endl;
                        cout << endl;
                    }
                }*/
                else if (opcao == 4) {
                    system("cls || clear");
                    break;
                }
                else {
                    cout << endl;
                    system("cls || clear");
                    cout << "Opção inválida, digite uma opção válida." << endl;
                    cout << endl;
                }
            }
        }

        else if (op == 2) {
            system("cls || clear");
            menuOpAdicionais();

        }

        else if (op == 3) {
            system("cls || clear");
            menuEncerramento();
            break;
        }        
    }
}