#include "Screen.h"
using namespace std;

extern void fullscreen(){
    keybd_event(VK_MENU,0x38,0,0);
	keybd_event(VK_RETURN,0x1c,0,0);
	keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
	keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
};

extern const string currentDataTime(){
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%d/%m/%Y TIME: %X", &tstruct);

    return buf;
};

extern void gotoxy(int x, int y){

 COORD coord;

 coord.X = x;

 coord.Y = y;

 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

};

extern void GotoXY(int x, int y){
    HANDLE a;
    COORD b;
    fflush(stdout);
    b.X = x;
    b.Y = y;
    a = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(a,b);
};


extern void Boarder(){
int i;
   system("cls");
   for(i=10;i<140;i++)
   {
       GotoXY(i,10);
           cout<<"=";
       GotoXY(i,58);
           cout<<"=";
   }
   for(i=10;i<58;i++)
   {
       GotoXY(10,i);
           cout<<"|";
       GotoXY(140,i);
       		cout<<"|";
   }
};

extern void art(){

	Boarder();
	gotoxy(0, 20);
	
	ifstream ifs ("Art.txt");    
	string Lines = "";
    if (ifs)
    {
		while (ifs.good())
		{
	    	string TempLine;
	    	getline(ifs , TempLine);
	    	TempLine += "\n";
	    
	    	Lines += TempLine;
		}
		
	cout << Lines;
	cout << "\n\t  |\t\t\t\t\t\tDATE: " << currentDataTime() << endl;
	}
    
    ifs.close ();
};

extern void main_menu_load(){
	Boarder();
	
	int timer =5 + rand()%10;
    int row,col,r,c,q;
    gotoxy(65,34);
    cout<<"BOOTING UP...";
    gotoxy(60,36);
    for(r=1;r<=timer;r++)
	{
    for(q=0;q<=100000000;q++);
    printf("%c",177);
	}
    Sleep(100);
    system("cls");
};

extern void pre_login()
{
	Boarder();
	int timer = rand()%15+1;
    int row,col,r,c,q;
    gotoxy(65,34);
    printf("LOG IN...");
    gotoxy(60,36);
    for(r=1;r<=timer;r++)
	{
    for(q=0;q<=100000000;q++);
    printf("%c",177);
	}
    Sleep(100);
    system("cls");
}


extern void updating_data_base(){
	Boarder();
	
    int row,col,r,c,q;
    int timer = rand()%25+1; 
    gotoxy(65,34);
    printf("UPDATING DATABASE...");
    gotoxy(60,36);
    for(r=1;r<=timer;r++)
	{
    for(q=0;q<=100000000;q++);
    printf("%c",177);
	}
    Sleep(100);
    system("cls");
};

extern void pre_logout(){
	Boarder();
	
    int row,col,r,c,q;
    int timer = rand()%15+1;
    gotoxy(65,34);
    printf("LOGGING OFF...");
    gotoxy(60,36);
    for(r=1;r<=timer;r++)
	{
    for(q=0;q<=100000000;q++);
    printf("%c",177);
	}
    Sleep(100);
    system("cls");
};

extern void welcome(){

	Boarder();
	gotoxy(0, 30);
	ifstream ifs("Welcome.txt");
	string Lines = "";

	if (ifs)
	{
		while (ifs.good())
		{
			string TempLine;
			getline(ifs, TempLine);
			TempLine += "\n";

			Lines += TempLine;
		}

		cout << Lines;


	}
	cout << "\n\t  |\t\t\t\t\t\t\t";
	ifs.close();
	Sleep(2000); 
	
};

extern void exit_imag(){
	Boarder();
	gotoxy(0, 30);
	ifstream ifs ("ExitArt.txt");    
	string Lines = " ";
    
    if (ifs)
    {
		while (ifs.good ())
		{
	    	string TempLine;
	    	getline (ifs , TempLine);
	    	TempLine += "\n";
	    
	    	Lines += TempLine;
		}
		
	cout << Lines;
	
	}
    cout<<"\n\t  |\t\t\t\t\t\t\t";
    ifs.close ();
    Sleep(3000);
    exit(0);
};
