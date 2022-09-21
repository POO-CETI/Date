#include <iostream>
#include <string>
#include <cstring>

class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date(std::string date) {
        char dayMonthYear[50];
        char* ptr;

        strcpy(dayMonthYear, date.c_str());

        ptr = strtok(dayMonthYear, "/");
        // this->year = std::stoi(ptr);
        this->year = sscanf(ptr, "%d", &ptr);

        ptr = strtok(NULL, "/");
        // this->month = std::stoi(ptr);
        this->month = sscanf(ptr, "%d", &ptr);

        ptr = strtok(NULL, " ");
        // this->day = std::stoi(ptr);
        this->day = sscanf(ptr, "%d", &ptr);
    }

    void setDay(/*int day*/) {
        this->day = day;
    }

    void setMonth(/*int month*/) {
        if (this->month < 1 || this->month > 12) {
            std::cout << "El mes no es valido.";
        }
        // this->month = month;
    }

    void setYear(/*int year*/) {
        if (this->year < 1 || this->year > 3000) {
            std::cout << "El ano que ingreso no es valido."; // No sean mal pensados
        }
        // this->year = year;
    }

    int getDay() {
        return this->day;
    }

    int getMonth() {
        return this->month;
    }

    int getYear() {
        return this->year;
    }

    void toString() {
        if (this->year %400 == 0){
            std::cout << "Ano bisiesto";
        } else {
            if(this->year %4 == 0){
                std::cout << "Ano bisiesto";
            } else {
                std::cout << "Ano no bisiesto";
            }
        }
    }
};