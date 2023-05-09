#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "node.h"
#include "avl.h"
#include "data.h"

using namespace std;

Date::Date(int dia, int mes, int ano) {
    this->dia = dia;
    this->mes = mes;
    this->ano = ano;
}

// GETS
int Date::getDia() {
    return this->dia;
}
int Date::getMes() {
    return this->mes;
}
int Date::getAno() {
    return this->ano;
}
// SETS
void Date::setDia(int dia) {
    this->dia = dia;
}
void Date::setMes(int mes) {
    this->mes = mes;
}
void Date::setAno(int ano) {
    this->ano = ano;
}   

void Date::print() {
    cout << getDia() << "/" << getMes() << "/" << getAno() << endl;
}

string Date::strPrint() {
    std::stringstream ss;
    ss << getDia() << "/" << getMes() << "/" << getAno();
    return ss.str();
}

// IMPLEMENTAÇÃO DOS OPERADORES
bool Date::operator==(Date data) {
    if (this->getAno() == data.getAno() && this->getMes() == data.getMes() && this->getDia() == data.getDia()) {
        return true;
    } else {
        return false;
    }
}
bool Date::operator!=(Date data) {
    if (this->getAno() != data.getAno() || this->getMes() != data.getMes() || this->getDia() != data.getDia()) {
        return true;
    } else {
        return false;
    }
}
bool Date::operator>(Date data) {
    if (this->getAno() > data.getAno()) {
        return true;
    } else if (this->getAno() == data.getAno() && this->getMes() > data.getMes()) {
        return true;
    } else if (this->getAno() == data.getAno() && this->getMes() == data.getMes() && this->getDia() > data.getDia()) {
        return true;
    } else {
        return false;
    }
}
bool Date::operator<(Date data) {
    if (this->getAno() < data.getAno()) {
        return true;
    } else if (this->getAno() == data.getAno() && this->getMes() < data.getMes()) {
        return true;
    } else if (this->getAno() == data.getAno() && this->getMes() == data.getMes() && this->getDia() < data.getDia()) {
        return true;
    } else {
        return false;
    }
}
bool Date::operator>=(Date data) {
    if (this->getAno() > data.getAno()) {
        return true;
    } else if (this->getAno() == data.getAno() && this->getMes() > data.getMes()) {
        return true;
    } else if (this->getAno() == data.getAno() && this->getMes() == data.getMes() && this->getDia() > data.getDia()) {
        return true;
    } else if (this->getAno() == data.getAno() && this->getMes() == data.getMes() && this->getDia() == data.getDia()) {
        return true;
    } else {
        return false;
    }
}
bool Date::operator<=(Date data) {
    if (this->getAno() < data.getAno()) {
        return true;
    } else if (this->getAno() == data.getAno() && this->getMes() < data.getMes()) {
        return true;
    } else if (this->getAno() == data.getAno() && this->getMes() == data.getMes() && this->getDia() < data.getDia()) {
        return true;
    } else if (this->getAno() == data.getAno() && this->getMes() == data.getMes() && this->getDia() == data.getDia()) {
        return true;
    } else {
        return false;
    }
}

std::ostream& operator<<(std::ostream& os, Date& date) {
    os << date.strPrint();
    return os;
}