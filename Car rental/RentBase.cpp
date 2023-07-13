#include "RentBase.h"

using namespace std;


void RentBase::set_rent_base(vector<shared_ptr<Rent>> base){rent_base = base;}

RentBase::RentBase(){};

void RentBase::add_rent(shared_ptr<Rent>& rent){
    rent_base.push_back(rent);
    update_rent_base();

};

void RentBase::upload_rent_base() {
    rent_base.clear();

    fstream file;
    string line;
    size_t noc;
    file.open("RentBase.txt", ios::in);
    if (file.is_open()) {
        while (!file.eof()) {
            shared_ptr<Rent> rent = make_shared<Rent>();
            shared_ptr<Customer> cus = make_shared<Customer>();
            vector<shared_ptr<Car>> vec;
            getline(file, line);
            cus->set_id(line);
            getline(file, line);
            cus->set_password(line);
            getline(file, line);
            cus->set_fname(line);
            getline(file, line);
            cus->set_lname(line);
            getline(file, line);
            cus->set_age(line);
            getline(file, line);
            cus->set_mail(line);
            getline(file, line);
            cus->set_phone_number(line);

            rent->set_rent_cus(cus);

            getline(file, line);
            noc = atoi(line.c_str());

            for (int i = 0; i < noc; ++i) {
                shared_ptr<Car> car = make_shared<Car>();
                getline(file, line);
                car->set_plate(line);
                getline(file, line);
                car->set_class(line);
                getline(file, line);
                car->set_type(line);
                getline(file, line);
                car->set_brand(line);
                getline(file, line);
                car->set_model(line);
                getline(file, line);
                car->set_color(line);
                getline(file, line);
                car->set_fuel(line);
                getline(file, line);
                car->set_transmission(line);
                getline(file, line);
                car->set_year(line);
                getline(file, line);
                car->set_engine(line);
                getline(file, line);
                car->set_hp(line);
                getline(file, line);
                car->set_seats(line);
                getline(file, line);
                car->set_price(line);
                getline(file, line);
                car->set_borrowed(str_to_bool(line));

                vec.push_back(car);
            }
            rent->set_rent_cars(vec);
            rent_base.push_back(rent);
        }
    }
    file.close();

};



void RentBase::update_rent_base() {
    ofstream delate;
    delate.open("RentBase.txt", std::ofstream::out | std::ofstream::trunc);
    delate.close();
    size_t end = 0;     

    fstream file;
    file.open("RentBase.txt", ios::app);
    if (file.is_open()) {
        for (auto i : rent_base) {
            file << i->get_rent_cus()->get_id() << endl;
            file << i->get_rent_cus()->get_password() << endl;
            file << i->get_rent_cus()->get_fname() << endl;
            file << i->get_rent_cus()->get_lname() << endl;
            file << i->get_rent_cus()->get_age() << endl;
            file << i->get_rent_cus()->get_mail() << endl;
            file << i->get_rent_cus()->get_phone_number() << endl;            
            file << i->get_rent_cars().size() << endl;
            for (auto u : i->get_rent_cars()) {
                file << u->get_plate() << endl;
                file << u->get_class() << endl;
                file << u->get_type() << endl;
                file << u->get_brand() << endl;
                file << u->get_model() << endl;
                file << u->get_color() << endl;
                file << u->get_fuel() << endl;
                file << u->get_transmission() << endl;
                file << u->get_year() << endl;
                file << u->get_engine() << endl;
                file << u->get_hp() << endl;
                file << u->get_seats() << endl;
                file << u->get_price() << endl;
                    file << u->get_borrowed() << endl;
            }

        }
    }
};



void RentBase::show_whole_base() {
    size_t size = rent_base.size();
    for (size_t i = 0; i < size; ++i) {
        gotoxy(30,35+(5*i));
        cout << rent_base[i]->get_rent_cus()->get_id() << "\t" << rent_base[i]->get_rent_cus()->get_fname() << "\t" << rent_base[i]->get_rent_cus()->get_lname() << endl;
        for (size_t u = 0; u < rent_base[i]->get_rent_cars().size(); ++u) {
            gotoxy(30,(36 +(5*i)) + u);
            cout << u + 1 << ". " << rent_base[i]->get_rent_cars()[u]->get_plate() << "\t" << rent_base[i]->get_rent_cars()[u]->get_class() << "\t" << rent_base[i]->get_rent_cars()[u]->get_type() << "\t" << rent_base[i]->get_rent_cars()[u]->get_brand() << "\t" << rent_base[i]->get_rent_cars()[u]->get_model() << "\t" << rent_base[i]->get_rent_cars()[u]->get_price() << "/per day" << endl;
        }
    }
};

