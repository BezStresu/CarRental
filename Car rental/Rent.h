#ifndef _Rent_h_
#define _Rent_h_
#include <string>
#include <memory>
#include <vector>
#include "Customer.h"
#include "CustomerBase.h"
#include "Car.h"
#include "CarBase.h"

using namespace std;

class Rent{
private:
    vector<shared_ptr<Car>> rent_cars;
    shared_ptr<Customer> rent_cus;
public:
    Rent();
    shared_ptr<Car>& get_one_rent_car(int i){return rent_cars.at(i);}
    vector<shared_ptr<Car>>& get_rent_cars();
    shared_ptr<Customer>& get_rent_cus();
    void set_rent_cars(vector<shared_ptr<Car>>& cars);
    void set_rent_cus(shared_ptr<Customer>& cus);
    void remove_car(int num);
    void show_rent();
    
};













#endif

