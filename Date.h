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
    bool validatedError = false;

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

    int validatedDay() {
      if (this->month == 2 && this->year %400 == 0 || this->year %4 == 0){
        if (this->day < 1) {
          cout << "\nEl dia que ingreso (" << this->day << ") no es valido.\n";
          this->day = 1;
          this->validatedError = true;
        } else if (this->day > 29) {
          cout << "\nEl dia que ingreso (" << this->day << ") no es valido.\n";
          this->day = 1;
          ++this->month;
          this->validatedError = true;
        }
      } else if (this->month == 2) {
        if (this->day < 1) {
          cout << "\nEl dia que ingreso (" << this->day << ") no es valido.\n";
          this->day = 1;
          this->validatedError = true;
        } else if (this->day > 28) {
          cout << "\nEl dia que ingreso (" << this->day << ") no es valido.\n";
          this->day = 1;
          ++this->month;
          this->validatedError = true;
        }
      } else if (this->month == 1 || this->month == 3 || this->month == 5 || this->month == 7 || this->month == 8 || this->month == 10 || this->month == 12){
        if (this->day < 1) {
          cout << "\nEl dia que ingreso (" << this->day << ") no es valido.\n";
          this->day = 1;
          this->validatedError = true;
        } else if (this->day > 31) {
          cout << "\nEl dia que ingreso (" << this->day << ") no es valido.\n";
          this->day = 1;
          ++this->month;
          this->validatedError = true;
        }
      } else if (this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11){
        if (this->day < 1) {
          cout << "\nEl dia que ingreso (" << this->day << ") no es valido.\n";
          this->day = 1;
          this->validatedError = true;
        } else if (this->day > 30) {
          cout << "\nEl dia que ingreso (" << this->day << ") no es valido.\n";
          this->day = 1;
          ++this->month;
          this->validatedError = true;
        }
      }

      return 0;
    }

    int validatedYear() {
      if (this->year < 1) {
        cout << "\nEl ano que ingreso (" << this->year << ") no es valido.\n";
        this->year = 1;
        this->validatedError = true;
      } else if (this->year > 3000) {
        cout << "\nEl ano que ingreso (" << this->year << ") no es valido.\n";
        this->validatedError = true;
      }

      return 0;
    }

    int validateMonth() {
      if (this->month < 1) {
        cout << "\nEl mes que ingreso (" << this->month << ") no es valido.\n";
        this->month = 1;
        this->validatedError = true;
      } else if (this->month > 12) {
        cout << "\nEl mes que ingreso (" << this->month << ") no es valido.\n";
        this->day = 1;
        this->month = 1;
        ++this->year;
        this->validatedError = true;
      }

      return 0;
    }

    int leapYear() {
      if (this->year %400 == 0 && this->validatedError == false){
        cout << "\nAno bisiesto.\n";
      } else {
        if(this->year %4 == 0 && this->validatedError == false){
          cout << "\nAno bisiesto.\n";
        } else if(this->validatedError == false) {
          cout << "\nAno no bisiesto.\n";
        }
      }

      return 0;
    }

    Date& operator++() {
      day++;
      return *this;
    }
    
    void toString() {
      validateMonth();
      validatedDay();
      validatedYear();
      leapYear();
      cout << "\n" << this->year << "/" << this->month << "/" << this->day;
    }
};