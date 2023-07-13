#include "CarBase.h"
#include "Screen.h"

using namespace std;

CarBase::CarBase(){}

void CarBase::add_car(shared_ptr<Car>& car){
    base.push_back(car);
    update_base();
//    fstream file;
//    file.open("CarBase.txt", ios::app);
//    if(file.is_open()){
//        file << endl;
//        file << car->get_plate() << endl;
//        file << car->get_class() << endl;
//        file << car->get_type() << endl;
//        file << car->get_brand() << endl;
//        file << car->get_model() << endl;
//        file << car->get_color() << endl;
//        file << car->get_fuel() << endl;
//        file << car->get_transmission() << endl;
//       file << car->get_year() << endl;
//        file << car->get_engine() << endl;
//        file << car->get_hp() << endl;
//        file << car->get_seats() << endl;
//        file << car->get_price() << endl;
//        file << car->get_borrowed();
//    }

//    file.close();
}

void CarBase::delate_car(string num_plate){
    size_t size = base.size();

    for(size_t i = 0; i < size; ++i){
        if(base[i]->get_plate() == num_plate){
            base.erase(base.begin() + i);
            base.resize(size - 1);
            break;
        }
    }

    ofstream delate;
    delate.open("CarBase.txt", std::ofstream::out | std::ofstream::trunc);
    delate.close();



    fstream file;
    file.open("CarBase.txt", ios::out);
    
    if(file.is_open()){
        int end = 1;
        for(auto i : base){
            file << i->get_plate() << endl;
            file << i->get_class() << endl;
            file << i->get_type() << endl;
            file << i->get_brand() << endl;
            file << i->get_model() << endl;
            file << i->get_color() << endl;
            file << i->get_fuel() << endl;
            file << i->get_transmission() << endl;
            file << i->get_year() << endl;
            file << i->get_engine() << endl;
            file << i->get_hp() << endl;
            file << i->get_seats() << endl;
            file << i->get_price() << endl;
            if(end < base.size()){
                file << i->get_borrowed() << endl;
                ++end;
            }
            else{
                file << i->get_borrowed();
            }
           
        }
    }

    file.close();

}

void CarBase::upload_base(){
   
    base.clear();     

    fstream file;
    string line; 
    file.open("CarBase.txt", ios::in);
    if(file.is_open()){
        while(!file.eof()){
            shared_ptr<Car> car = make_shared<Car>();
            getline(file,line);
            car->set_plate(line);
            getline(file,line);
            car->set_class(line);
            getline(file,line);
            car->set_type(line);
            getline(file,line);
            car->set_brand(line);
            getline(file,line);
            car->set_model(line);
            getline(file,line);
            car->set_color(line);
            getline(file,line);
            car->set_fuel(line);
            getline(file,line);
            car->set_transmission(line);
            getline(file,line);
            car->set_year(line);
            getline(file,line);
            car->set_engine(line);
            getline(file,line);
            car->set_hp(line);
            getline(file,line);
            car->set_seats(line);
            getline(file,line);
            car->set_price(line);
            getline(file,line);
            car->set_borrowed(str_to_bool(line));

            base.push_back(car);
        }
    }
    file.close();
}

void CarBase::update_base() {

    ofstream delate;
    delate.open("CarBase.txt", std::ofstream::out | std::ofstream::trunc);
    delate.close();
    size_t end = 1;

    fstream file;
    file.open("CarBase.txt", ios::app);
    if(file.is_open()){
        for(auto i : base){
            file << i->get_plate() << endl;
            file << i->get_class() << endl;
            file << i->get_type() << endl;
            file << i->get_brand() << endl;
            file << i->get_model() << endl;
            file << i->get_color() << endl;
            file << i->get_fuel() << endl;
            file << i->get_transmission() << endl;
            file << i->get_year() << endl;
            file << i->get_engine() << endl;
            file << i->get_hp() << endl;
            file << i->get_seats() << endl;
            file << i->get_price() << endl;
            if (end < base.size()) {
                file << i->get_borrowed() << endl;
                ++end;
            }
            else {
                file << i->get_borrowed();
            }
        }
    }
    file.close();
}

void CarBase::show_base() {
    size_t size = base.size();
    for (size_t i = 0; i < size; ++i) {
        gotoxy(30,35+i);
        cout << i + 1 << ". " << base[i]->get_plate() << " " << base[i]->get_class() << " " << base[i]->get_type() << " " << base[i]->get_brand() << " " << base[i]->get_model() << " " << base[i]->get_color() << " " << base[i]->get_fuel() << " " << base[i]->get_transmission() << " " << base[i]->get_year() << " " << base[i]->get_engine() << " " << base[i]->get_hp() << " " << base[i]->get_seats() << " " << base[i]->get_price() << " ";
        if (base[i]->get_borrowed() == true) {
            cout << "borrowed" << endl;
        }
        else
        {
            cout << "not borrowed" << endl;
        }
    }
}
