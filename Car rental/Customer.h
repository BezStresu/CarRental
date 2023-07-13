#ifndef _Customer_h_
#define _Customer_h_
#include <iostream>
#include <string>

using namespace std; 

class Customer{
private:
    string u_fname{};
    string u_lname{};
    string u_age{};
    string u_mail{};
    string u_phone_number{};
    string u_id{};
    string u_password{};
public:
    Customer();

    string get_fname() const;
    string get_lname() const;
    string get_age() const;
    string get_mail() const;
    string get_phone_number() const;
    string get_id() const;
    string get_password() const;

    void set_fname(string i_fname);
    void set_lname(string i_lname);
    void set_age(string i_age);
    void set_mail(string i_mail);
    void set_phone_number(string i_phone);
    void set_id(string i_id);
    void set_password(string i_password);

    bool is_Admin(string id, string pass);
    int cous_Count();
    void create_uniqe_id();
    bool of_age(string age);
};

#endif