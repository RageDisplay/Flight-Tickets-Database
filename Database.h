#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>
#include <sstream>
#include <locale>
#include <iterator>
#include <numeric>
 
using namespace std;

class Database
{
public:
    Database(){count = 0;}
    void addRecord(string name, string lastname, string flightnum, string date, string time, string location);
    string getNameById(int id);
    string getLastNameById(int id);
    string getFlightNumById(int id);
    string getDateById(int id);
    string getTimeById(int id);
    string getLocationById(int id);
    int getCount();
    void save();
    void load();
    void editRecord(int id, string name, string lastname, string flightnum, string date, string time, string location);
    void printDatabase();
    void sortedByDate();
    void sortedByLocation();
    void search();

protected:
    int count;
    string name[100];
    string lastname[100];
    string flightnum[100];
    string date[100];
    string time[100];
    string location[100];

struct list
{
    wstring skip1;
    wstring skip2;
    wstring skip3;
    wstring skip4;
    wstring skip5;
    wstring needata;
};

};

void AddRecord(Database& server);
void EditRecord(Database& server);
void DeleteRecord(Database& server);

