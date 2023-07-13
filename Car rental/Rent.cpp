#include "Rent.h"

using namespace std;

Rent::Rent(){
    vector<shared_ptr<Car>> new_vec;
    rent_cars = new_vec;
    shared_ptr<Customer> xd;
    rent_cus = xd;
    
};

shared_ptr<Customer>& Rent::get_rent_cus(){return rent_cus;}
vector<shared_ptr<Car>>& Rent::get_rent_cars(){return rent_cars;}

void Rent::set_rent_cars(vector<shared_ptr<Car>>& cars){rent_cars = cars;}
void Rent::set_rent_cus(shared_ptr<Customer>& cus){rent_cus = cus;}

void Rent::remove_car(int num){
    rent_cars.erase(rent_cars.begin() + num);

};

void Rent::show_rent() {   
    gotoxy(30,35); 
    cout << rent_cus->get_id() << "\t" << rent_cus->get_fname() << "\t" << rent_cus->get_lname() << endl;
    for (size_t i = 0; i < rent_cars.size();++i) {
        gotoxy(30,36+i);
        cout << 1 + i << ". " << rent_cars[i]->get_plate() << "\t" << rent_cars[i]->get_class() << "\t" << rent_cars[i]->get_type() << "\t" << rent_cars[i]->get_brand() << "\t" << rent_cars[i]->get_model() << endl;
    }
}