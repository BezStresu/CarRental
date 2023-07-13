#include "Car.h"

using namespace std;

Car::Car(){
    c_plate = "";
    c_class = "";
    c_type = "";
    c_brand = "";
    c_model = "";
    c_color = "";
    c_fuel = "";
    c_transmission = "";
    c_year = "";
    c_engine = "";
    c_hp = "";
    c_seats = "";
    c_price = "";
    c_borrowed = false;

};

string Car::get_plate() const {return c_plate;}
string Car::get_class() const {return c_class;}
string Car::get_type() const {return c_type;}
string Car::get_brand() const {return c_brand;}
string Car::get_model() const {return c_model;}
string Car::get_color() const {return c_color;}
string Car::get_fuel() const {return c_fuel;}
string Car::get_transmission() const {return c_transmission;}
string Car::get_year() const {return c_year;}
string Car::get_engine() const {return c_engine;}
string Car::get_hp() const {return c_hp;}
string Car::get_seats() const {return c_seats;}
string Car::get_price() const {return c_price;}
bool Car::get_borrowed() const {return c_borrowed;}

void Car::set_plate (string i_plate) {c_plate = i_plate; }
void Car::set_class (string i_class) {c_class = i_class; }
void Car::set_type (string i_type) {c_type = i_type; }
void Car::set_brand (string i_brand ) {c_brand = i_brand; }
void Car::set_model (string i_model) {c_model = i_model; }
void Car::set_color (string i_color) {c_color = i_color; }
void Car::set_fuel (string i_fuel) {c_fuel = i_fuel; }
void Car::set_transmission (string i_transmission) {c_transmission = i_transmission; }
void Car::set_year (string i_year) {c_year = i_year; }
void Car::set_engine (string i_engine) {c_engine = i_engine; }
void Car::set_hp (string i_hp) {c_hp = i_hp;}
void Car::set_seats (string i_seats) {c_seats = i_seats; }
void Car::set_price (string i_price) {c_price = i_price; }
void Car::set_borrowed (bool i_borrowed) {c_borrowed = i_borrowed; }

void Car::borrow_car(){
    c_borrowed = true;
}
void Car::return_car(){
    c_borrowed = false;
}




