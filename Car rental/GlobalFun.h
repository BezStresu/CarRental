#ifndef _GlobalFun_h_
#define _GlobalFun_h_

#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <vector>
#include "Screen.h"

using namespace std;


extern bool is_file_empty(fstream& file);
extern bool str_to_bool(string& line);
extern bool isNumber(const string& str);
extern bool check_option(string choice, vector<string> options);
#endif