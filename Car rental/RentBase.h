#ifndef _RentBase_h_
#define _RentBase_h_
#include "Rent.h"
#include "GlobalFun.h"
#include <fstream>

using namespace std;

class RentBase{
private:
    vector<shared_ptr<Rent>> rent_base;
public:
    RentBase();
    void set_rent_base(vector<shared_ptr<Rent>> base);
    void add_rent(shared_ptr<Rent>& rent);
    void upload_rent_base();
    void update_rent_base();
    void show_whole_base();
    shared_ptr<Rent>& get_one_rent(int i) { return rent_base.at(i); }
    size_t get_base_size() { return rent_base.size(); }


};

#endif