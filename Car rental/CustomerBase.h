#ifndef _CustomerBase_h_
#define _CustomerBase_h_
#include <vector>
#include "Customer.h"
#include "GlobalFun.h"
#include <memory>
#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

class CustomerBase{
private:
    vector<shared_ptr<Customer>> cusBase;
public:
    CustomerBase();
    void add_customer(shared_ptr<Customer>& customer);
    void show_cus_base();
    void upload_cus_base();
    shared_ptr<Customer> & get_customer(int i){return cusBase.at(i);}

};



#endif