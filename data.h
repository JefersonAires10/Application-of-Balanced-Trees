#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <sstream>

struct Date {
    int dia;
    int mes;
    int ano;

    Date() {}

    Date(int dia, int mes, int ano) {
        this->dia = dia;
        this->mes = mes;
        this->ano = ano;
    }
    /**
     * @brief getDia da classe Date
     * @return dia
    */
    int getDia() { return this->dia; }
    /**
     * @brief setDia da classe Date
     * @param dia
    */
    void setDia(int dia) { this->dia = dia; }
    /**
     * @brief getMes da classe Date
     * @return mes
    */
    int getMes() { return this->mes; }
    /**
     * @brief setMes da classe Date
     * @param mes
    */
    void setMes(int mes) { this->mes = mes; }
    /**
     * @brief getAno da classe Date
     * @return ano
    */
    int getAno() { return this->ano; }
    /**
     * @brief setAno da classe Date
     * @param ano
    */
    void setAno(int ano) { this->ano = ano; }
    /**
     * @brief operator< da classe Date
     * @param data 
     * @return true se a data for menor que a data passada por parâmetro
    */
    bool operator<(Date data) {
        if (this->getAno() < data.getAno()) { 
            return true; 
        }

        else if (this->getAno() == data.getAno()) {
            if (this->getMes() < data.getMes()) { 
                return true; 
            }

            else if (this->getMes() == data.getMes()) {
                if (this->getDia() < data.getDia()) { 
                    return true; 
                }
                else { 
                    return false; 
                }
            }
            else { 
                return false; 
            }
        
        }
        else { 
            return false; 
        }
    }
    /**
     * @brief operator> da classe Date
     * @param data
     * @return true se a data for maior que a data passada por parâmetro
    */
    bool operator>(Date data) {
        if (this->getAno() > data.getAno()) {
            return true;
        }

        else if (this->getAno() == data.getAno()) {
            if (this->getMes() > data.getMes()) {
                return true;
            }

            else if (this->getMes() == data.getMes()) {
                if (this->getDia() > data.getDia()) {
                    return true;
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
            
        }
        else {
            return false;
        }
       
    }
    /**
     * @brief operator== da classe Date
     * @param data
     * @return true se a data for igual a data passada por parâmetro
    */
    bool operator==(Date data) { 
        if (this->getAno() == data.getAno() && this->getMes() == data.getMes() && this->getDia() == data.getDia()) {
            return true;
        }
        else {
            return false;
        }
    }
    /**
     * @brief operator!= da classe Date
     * @param data
     * @return true se a data for diferente da data passada por parâmetro
    */
    bool operator!=(Date data) {
        if (this->getAno() != data.getAno() || this->getMes() != data.getMes() || this->getDia() != data.getDia()) {
            return true;
        }
        else {
            return false;
        }
    }
    /**
     * @brief operator>= da classe Date
     * @param data
     * @return true se a data for maior ou igual a data passada por parâmetro
    */
    bool operator>=(Date data) {
        return (*this > data || *this == data);
    }
    /**
     * @brief operator<= da classe Date
     * @param data
     * @return true se a data for menor ou igual a data passada por parâmetro
    */
    bool operator<=(Date data) {
        return (*this < data || *this == data);
    }  
    /**
     * @brief operator<< da classe Date
     * @param os, data
     * @return os
    */
    friend std::ostream& operator<<(std::ostream& os, Date& data)
    {
        os << data.mes << "/" << data.dia << "/" << data.ano;
        return os;
    }
    
};
#endif // DATE_H