#include "GlobalFun.h"

using namespace std;

extern bool is_file_empty(fstream& file){  
    return file.peek() == fstream::traits_type::eof();
};

extern bool str_to_bool(string& line) {
    if (line == "1") {
        return true;
    }
    else
    {
        return false;
    }
};


extern bool isNumber(const string& str){
    for (char const& c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
};


extern bool check_option(string a, vector<string> ans){
	bool value = false;

	for (size_t i = 0; i < ans.size(); ++i)
	{
		if (a == ans[i])
		{
			value = true;
		}
	}

	if (value == false)
	{
		system("CLS");
		gotoxy(30,35);
		cout << "\t\t\t\t\tPlease select the correct option from the menu";
		cout << endl << endl << endl << endl << endl;
		Sleep(1000);	}

	return value;
}
