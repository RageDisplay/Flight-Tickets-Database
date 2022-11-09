#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <string>
#include <cctype>
#include <algorithm>
//#include <locale.h>
//#include <clocale>
//#include <Windows.h>
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
 
void  Database::editRecord(int id, string name, string lastname, string flightnum, string date, string time)
{
    this->name[id] = name;
    this->lastname[id] = lastname;
    this->flightnum[id] = flightnum;
    this->date[id]=date;
    this->time[id]=time;
}

int Database::getCount()
{
    return count;
}
 
void Database::addRecord(string name, string lastname, string flightnum, string date, string time)
{
    this->name[count] = name;
    this->lastname[count] = lastname;
    this->flightnum[count] = flightnum;
    this->date[count] = date;
    this->time[count]=time;
    ++count;
}
 
string Database::getNameById(int id)
{
    return name[id];
}

string Database::getLastNameById(int id)
{
    return lastname[id];
}

string Database::getFlightNumById(int id)
{
    return flightnum[id];
}
string Database::getDateById(int id)
{
    return date[id];
}
string Database::getTimeById(int id)
{
    return time[id];
}

void  Database::save()
{
    ofstream output;
    output.open("database.txt");
 
    if(!output.is_open())
    {
        cerr << "Error open database.txt" << endl;
        exit(1);
    }
 
    output.clear();
 
    string delete_flag = "%delete";
 
    for(int i=0; i < count; ++i)
    {
        if(getNameById(i) != delete_flag && getLastNameById(i) != delete_flag && getFlightNumById(i) != delete_flag && getDateById(i) != delete_flag && getTimeById(i) != delete_flag)
            output << getNameById(i) << " " << getLastNameById(i) << " " << getFlightNumById(i) << " " << getDateById(i) << " " << getTimeById(i) << endl;
    }
 
    output.close();
 
}
 
void  Database::load()
{
    ifstream input;
    input.open("database.txt");
 
    if(!input.is_open())
    {
        cerr << "Error open database.txt" << endl;
        exit(1);
    }
 
    while(!input.eof())
    {
        string name;
        input >> name;
        string lastname;
        input >> lastname;
        string flightnum;
        input >> flightnum;
        string date;
        input >> date;
        string time;
        input >> time;
        
        if(name != "")
        {
            addRecord(name,lastname,flightnum,date,time);
        }
    }
 
    input.close();
 
}
 
void Database::printDatabase()
{
    for(int i=0; i < count; ++i)
    {
        cout << i << "." << getNameById(i) << " " << getLastNameById(i) << " "<< getFlightNumById(i) << " " << getDateById(i) << " " << getTimeById(i) << endl;
    }
}

void Database::search()
{
    string data;
    cout <<"Enter the some data from the ticket: ";
    cin >> data;
    for(int i=0; i < count; ++i)
    {
        if ((data == getNameById(i)) || (data == getLastNameById(i)) || (data == getFlightNumById(i)) || (data == getDateById(i)) || (data == getTimeById(i)))
        {
            cout << i << "." << getNameById(i) << " " << getLastNameById(i) << " "<< getFlightNumById(i) << " " << getDateById(i) << " " << getTimeById(i) << endl;
        }
    }   
}

void AddRecord(Database& server)
{
    nm:
    cout << "Enter the passenger's first name: ";
 
    string name;
    cin >> name;
    if(find_if(name.begin(), name.end(),(int(*)(int))isdigit) !=name.end())
    {
        cout<<"Without numbers plz"<<endl;
        goto nm;
    }
    else
    {
        goto ln;        
    }
    ln:
    cout << "Enter the passenger's second name: ";
    
    string lastname;
    cin >> lastname;
    if(find_if(lastname.begin(), lastname.end(),(int(*)(int))isdigit) !=lastname.end())
    {
        cout<<"Without numbers plz"<<endl;
        goto ln;
    }
    else
    {
        goto other;        
    }
    other:
    bool con = true;

    while(con)
    {
        jum1:
        cout << "Enter the flight number (XXX-XXX-XXX) : ";
        string flightnum;
        cin >> flightnum;

        if(flightnum.length() == 11 && flightnum[3] == '-' && flightnum[7] == '-')
        {
            jum2:
            cout << "Enter the date of the flight (DD-MM-YYYY): ";
            string date;
            cin >> date;

            if(date.length() == 10 && date[2] == '-' && date[5] == '-')
            {
                jum3:
                cout << "Enter the time of the flight (XX:XX): ";
                string time;
                cin >> time;

            if(time.length() == 5 && time[2] == ':')
            {
                server.addRecord(name,lastname,flightnum,date,time);
                con=false;
            }

            else
            {
                cout<<"Wrong Data"<<endl;
                goto jum3;
            }
            }

            else
            {
                cout<<"Wrong Data"<<endl;
                goto jum2;
            }
        }

        else
        {
            cout<<"Wrong Data"<<endl;
            goto jum1;
        }
    }
}
void EditRecord(Database& server)
{
 
    cout << "Enter the passenger's ID: ";
 
    int id;
    cin >> id;
 
    cout << "Enter the passenger's first name: ";
 
    string name;
    cin >> name;
 
    cout << "Enter the passenger's second name: ";
 
    string lastname;
    cin >> lastname;
    bool con = true;

    while(con)
    {
        jum1:
        cout << "Enter the flight number (XXX-XXX-XXX) : ";
        string flightnum;
        cin >> flightnum;

        if(flightnum.length() == 11 && flightnum[3] == '-' && flightnum[7] == '-')
        {
            jum2:
            cout << "Enter the date of the flight (DD-MM-YYYY): ";
            string date;
            cin >> date;

            if(date.length() == 10 && date[2] == '-' && date[5] == '-')
            {
                jum3:
                cout << "Enter the time of the flight (XX:XX): ";
                string time;
                cin >> time;

            if(time.length() == 5 && time[2] == ':')
            {
                server.editRecord(id,name,lastname,flightnum,date,time);
                con=false;
            }

            else
            {
                cout<<"Wrong Data"<<endl;
                goto jum3;
            }
            }

            else
            {
                cout<<"Wrong Data"<<endl;
                goto jum2;
            }
        }

        else
        {
            cout<<"Wrong Data"<<endl;
            goto jum1;
        }
    }
}
 
void DeleteRecord(Database& server)
{
    cout << "Enter the ID of the ticket: ";
 
    int id;
    cin >> id;
 
    string delete_flag = "%delete";
 
    server.editRecord(id,delete_flag, delete_flag, delete_flag, delete_flag, delete_flag);
}
 
void menu(Database& server)
{
    bool end = false;
 
    while(!end)
    {
        mn:
        cout << "----------BD's Menu---------" << endl << endl;
 
        cout << "1. Load the BD file                       *Load, if you already have the BD*" << endl;
 
        cout << "2. Record the new data" << endl;
 
        cout << "3. Delete the data" << endl;
 
        cout << "4. Show all tickets" << endl;
 
        cout << "5. Save the BD                            *If you don't have the DB file - File will be created after the save of the DB" << endl;
        
        cout << "6. Change the ticket's data" << endl;
 
        cout << "7. Search for matches in the DB" << endl;

        cout << "8. Exit" << endl;
 
        cout << "\n\nSelect the function: ";

        int answer;
        if(cin>>answer)
        {
        switch(answer)
        {
            case 1:
                server.load();
                system("cls");
                break;
            case 2:
                AddRecord(server);
                system("pause");
                system("cls");
                break;
            case 3:
                DeleteRecord(server);
                system("pause");
                system("cls");
                break;
            case 4:
                server.printDatabase();
                system("pause");
                system("cls");
                break;
            case 5:
                server.save();
                system("pause");
                system("cls");
                break;
            case 6:
                EditRecord(server);
                system("cls");
                break;
            case 7:
                server.search();
                system("pause");
                system("cls");
                break;
            case 8:
                end = true;
                break;
            default:
                cout << "Wrong num " << endl;
                system("pause");
                system("cls");
                break;
        }
        }
        else
        {
            server.save();
            cout<<"Bad DATA"<<endl;
            break;
        }
    }
}
 
int main()
{
    Database server;
    menu(server);
    return 0;
}