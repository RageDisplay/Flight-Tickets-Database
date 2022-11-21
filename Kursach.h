#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <string>
#include <cctype>
#include <algorithm>
 
using namespace std;

class Database
{
public:
    Database(){count = 0;}
    void addRecord(string name, string lastname, string flightnum, string date, string time);
    string getNameById(int id);
    string getLastNameById(int id);
    string getFlightNumById(int id);
    string getDateById(int id);
    string getTimeById(int id);
    int getCount();
    void save();
    void load();
    void editRecord(int id, string name, string lastname, string flightnum, string date, string time);
    void printDatabase();
    void search();

protected:
    int count;
    string name[100];
    string lastname[100];
    string flightnum[100];
    string date[100];
    string time[100];
};

void AddRecord(Database& server);
void EditRecord(Database& server);
void DeleteRecord(Database& server);

