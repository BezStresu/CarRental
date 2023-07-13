#include "CustomerBase.h"

using namespace std;

CustomerBase::CustomerBase(){};

void CustomerBase::add_customer(shared_ptr<Customer>& customer){
    cusBase.push_back(customer);
    fstream file;
    file.open("CustomerBase.txt", ios::app);
    if(file.is_open()){
        file << endl;
        file << customer->get_id() << endl;
        file << customer->get_password() << endl;
        file << customer->get_fname() << endl;
        file << customer->get_lname() << endl;
        file << customer->get_age() << endl;
        file << customer->get_mail() << endl;
        file << customer->get_phone_number();
    }
    file.close();
};

void CustomerBase::upload_cus_base(){
    cusBase.clear();

    fstream file;
    string line;
    file.open("CustomerBase.txt", ios::in);
    if(file.is_open()){
        while(!file.eof()){
            shared_ptr<Customer> customer = make_shared<Customer>();
            getline(file,line);
            customer->set_id(line);
            getline(file,line);
            customer->set_password(line);
            getline(file,line);
            customer->set_fname(line);
            getline(file,line);
            customer->set_lname(line);
            getline(file,line);
            customer->set_age(line);
            getline(file,line);
            customer->set_mail(line);
            getline(file,line);
            customer->set_phone_number(line);

            cusBase.push_back(customer);


        }
    }
    file.close();
};


void CustomerBase::show_cus_base(){
    size_t roz = cusBase.size();
    for(int i = 0; i < roz; ++i){
        gotoxy(30,35 + i);
        cout << i + 1 << ". " << cusBase[i]->get_id() << " " << cusBase[i]->get_password() << " " << cusBase[i]->get_fname()  << " " << cusBase[i]->get_lname() << " " << cusBase[i]->get_age() << " " << cusBase[i]->get_mail() << " " << cusBase[i]->get_phone_number() << endl;    
    }
};
