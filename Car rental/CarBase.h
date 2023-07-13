#ifndef _CarBase_h_
#define _CarBase_h_
#include <vector>
#include "Car.h"
#include "GlobalFun.h"
#include <memory>
#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

class CarBase{
private:
    vector<shared_ptr<Car>> base;
public:
    CarBase();
    void add_car(shared_ptr<Car>& car);
    void delate_car(string num_plate);
    void upload_base();
    void update_base();
    void show_base();
    shared_ptr<Car>& get_car(int i){return base.at(i);}
    size_t get_base_size(){return base.size();}
};


#endif