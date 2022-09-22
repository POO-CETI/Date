#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date(string date) {
      char dayMonthYear[50];
      char* ptr;

      strcpy(dayMonthYear, date.c_str());
      ptr = strtok(dayMonthYear, "/");
      this->year = stoi(ptr);

      ptr = strtok(NULL, "/");
      this->month = stoi(ptr);

      ptr = strtok(NULL, " ");
      this->day = std::stoi(ptr);
    }

    void setDay(int day) {
      this->day = day;
    }

    void setMonth(int month) {
      this->month = month;
    }

    void setYear(int year) {
      this->year = year;
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
      cout << this->year << "/" << this->month << "/" << this->day;

      if (this->month == 2 && this->year %400 == 0 || this->year %4 == 0){
        if (this->day < 1 || this->day > 29){
          cout << "\nEl dia que ingreso (" << this->day << ") no es valido.\n";
        }
      } else if (this->month == 2){
        if (this->day < 1 || this->day > 28){
          cout << "\nEl dia que ingreso (" << this->day << ") no es valido.\n";
        }
      } else if (this->month == 1 || this->month == 3 || this->month == 5 || this->month == 7 || this->month == 8 || this->month == 10 || this->month == 12){
        if (this->day < 1 || this->day > 31){
          cout << "\nEl dia que ingreso (" << this->day << ") no es valido.\n";
        }
      } else if (this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11){
        if (this->day < 1 || this->day > 30){
          cout << "\nEl dia que ingreso (" << this->day << ") no es valido.\n";
        }
      }

      if (this->year < 1 || this->year > 3000) {
        cout << "\nEl ano que ingreso (" << this->year << ") no es valido.\n";
      }
      
      if (this->month < 1 || this->month > 12) {
        cout << "\nEl mes que ingreso (" << this->month << ") no es valido.\n";
      }
      
      if (this->year %400 == 0){
        cout << "\nAno bisiesto.\n";
      } else {
        if(this->year %4 == 0){
          cout << "\nAno bisiesto.\n";
        } else {
          cout << "\nAno no bisiesto.\n";
        }
      }
    }
};