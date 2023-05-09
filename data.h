#ifndef DATE_H
#define DATE_H
#include <string>
#include <iostream>

class Date {
private:
    int dia, mes, ano;
public:
    Date() = default;
    Date(int dia, int mes, int ano);

    int getDia();
    void setDia(int dia);
    
    int getMes();
    void setMes(int mes);

    int getAno();
    void setAno(int ano);

    void print();

    std::string strPrint();

    // SOBRECARGA DE OPERADORES
    bool operator==(Date data);
    bool operator!=(Date data);
    bool operator>(Date data);
    bool operator<(Date data);
    bool operator>=(Date data);
    bool operator<=(Date data);

    friend std::ostream& operator<<(std::ostream& os, Date& date);

};
#endif // DATE_H
