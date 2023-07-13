#include <fstream>
#include <vector>
#include <string>
#include "Customer.h"

using namespace std;

Customer::Customer(){
    u_fname = "";
    u_lname = "";
    u_age = "";
    u_mail = "";
    u_phone_number = "";
    u_id = "";
    u_password = "";
};
string Customer::get_fname()const{return u_fname;}
string Customer::get_lname()const{return u_lname;}
string Customer::get_age()const{return u_age;}
string Customer::get_mail()const{return u_mail;}
string Customer::get_phone_number()const{return u_phone_number;}
string Customer::get_id()const{return u_id;}
string Customer::get_password()const{return u_password;}

void Customer::set_fname(string i_fname){u_fname = i_fname; }
void Customer::set_lname(string i_lname){u_lname = i_lname; }
void Customer::set_age(string i_age){u_age = i_age; }
void Customer::set_mail(string i_mail){u_mail = i_mail; }
void Customer::set_phone_number(string i_phone){u_phone_number = i_phone; }
void Customer::set_id(string i_id){u_id = i_id; }
void Customer::set_password(string i_password){u_password = i_password; }

bool Customer::is_Admin(string id, string pass){
    if(id == "admin" && pass == "1234"){
        return true;
    }
    else{
        return false;
    }
}

int Customer::cous_Count(){
    int numOfCust = 0;
    int numOflines = 0;
	ifstream ifs("CustomerBase.txt"); 

	string word;
	while (getline(ifs, word))
	{
    	if (!word.empty())
        	numOflines++;
	   
        if(numOflines % 7 == 0){
        numOfCust++;
        }
    }
	ifs.close();

	return numOfCust;
}

void Customer::create_uniqe_id(){
    int id = 1001 + cous_Count();
    u_id = to_string(id);
}

bool Customer::of_age(string age){
    int i = stoi(age);
    if(i >= 18){
        return true;
    }
    else{
        return false;
    }
}


