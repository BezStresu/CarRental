#ifndef _Car_h_
#define _Car_h_
#include <iostream>
#include <string>
using namespace std;

class Car{

private:
    string c_plate{};
    string c_class{};
    string c_type{};
    string c_brand{};
    string c_model{};
    string c_color{};
    string c_fuel{};
    string c_transmission{};
    string c_year{};
    string c_engine{};
    string c_hp{};
    string c_seats{};
    string c_price{};
    bool c_borrowed;
    
public:

    Car();

    string get_plate()const;
    string get_class()const;
    string get_type()const;
    string get_brand()const;
    string get_model()const;
    string get_color()const;
    string get_fuel()const;
    string get_transmission()const;
    string get_year()const;
    string get_engine()const;
    string get_hp()const;
    string get_seats()const;
    string get_price()const;
    bool get_borrowed()const;
    


    void set_plate (string i_plate);
    void set_class (string i_class);
    void set_type (string i_type);
    void set_brand (string i_brand);
    void set_model (string i_model);
    void set_color (string i_color);
    void set_fuel (string i_fuel);
    void set_transmission (string i_transmission);
    void set_year (string i_year);
    void set_engine (string i_engine);
    void set_hp (string i_hp);
    void set_seats (string i_seats);
    void set_price (string i_price);
    void set_borrowed(bool i_borrowed);

    void borrow_car();
    void return_car();
};

#endif