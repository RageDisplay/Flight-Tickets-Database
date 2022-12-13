#include "Kursach.h"

void  Database::editRecord(int id, string name, string lastname, string flightnum, string date, string time, string location)
{
    this->name[id] = name;
    this->lastname[id] = lastname;
    this->flightnum[id] = flightnum;
    this->date[id]=date;
    this->time[id]=time;
    this->location[id]=location;
}

int Database::getCount()
{
    return count;
}
 
void Database::addRecord(string name, string lastname, string flightnum, string date, string time, string location)
{
    this->name[count] = name;
    this->lastname[count] = lastname;
    this->flightnum[count] = flightnum;
    this->date[count] = date;
    this->time[count]=time;
    this->location[count]=location;
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
string Database::getLocationById(int id)
{
    return location[id];
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
        if(getNameById(i) != delete_flag && getLastNameById(i) != delete_flag && getFlightNumById(i) != delete_flag && getDateById(i) != delete_flag && getTimeById(i) != delete_flag && getLocationById(i) != delete_flag)
        {
            output << getNameById(i) << " " << getLastNameById(i) << " " << getFlightNumById(i) << " " << getDateById(i) << " " << getTimeById(i) << " " << getLocationById(i) << endl;
        }
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
        string location;
        input >> location;

        if(name != "")
        {
            addRecord(name,lastname,flightnum,date,time,location);
        }
    }
 
    input.close();
}
 
void Database::printDatabase()
{
    for(int i=0; i < count; ++i)
    {
        cout << i << "." << getNameById(i) << " " << getLastNameById(i) << " "<< getFlightNumById(i) << " " << getDateById(i) << " " << getTimeById(i) << " " << getLocationById(i) << endl;
    }
}

void Database::search()
{
    string data;
    cout <<"Enter the some data from the ticket: ";
    cin >> data;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for(int i=0; i < count; ++i)
    {
        if ((data == getNameById(i)) || (data == getLastNameById(i)) || (data == getFlightNumById(i)) || (data == getDateById(i)) || (data == getTimeById(i)) || (data == getLocationById(i)))
        {
            cout << i << "." << getNameById(i) << " " << getLastNameById(i) << " "<< getFlightNumById(i) << " " << getDateById(i) << " " << getTimeById(i) << " " << getLocationById(i) << endl;
        }
    }   
}

void AddRecord(Database& server)
{
    bool con = true;
    while(con)
    {
        nm:
        cout << "Enter the passenger's first name: ";
        string name;
        cin >> name;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if(find_if(name.begin(), name.end(),(int(*)(int))isdigit) == name.end())
        {
            lm:
            cout << "Enter the passengers's last name: ";
            string lastname;
            cin >> lastname;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if(find_if(lastname.begin(), lastname.end(),(int(*)(int))isdigit) == lastname.end())
            {
                jum1:
                cout << "Enter the flight number (XXX-XXX-XXX) : ";
                string flightnum;
                cin >> flightnum;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if(flightnum.length() == 11 && flightnum[3] == '-' && flightnum[7] == '-')
                {
                    jum2:
                    cout << "Enter the date of the flight (DD-MM-YYYY): ";
                    string date;
                    cin >> date;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    if(date.length() == 10 && date[2] == '-' && date[5] == '-' && date[0] >= '0' && date[0] <= '9'&& date[1] >= '0' && date[1] <= '9'&& date[3] >= '0' && date[3] <= '9'&& date[4] >= '0' && date[4] <= '9'&& date[6] >= '0' && date[6] <= '9'&& date[7] >= '0' && date[7] <= '9'&& date[8] >= '0' && date[8] <= '9'&& date[9] >= '0' && date[9] <= '9')
                    {
                        jum3:
                        cout << "Enter the time of the flight (XX:XX): ";
                        string time;
                        cin >> time;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        if(time.length() == 5 && time[0] >= '0' && time[0] <= '9'&& time[1] >= '0' && time[1] <= '9' && time[2] == ':' && time[3] >= '0' && time[3] <= '9'&& time[4] >= '0' && time[4] <= '9')
                        {
                            loc:
                            cout << "Enter the location: ";
                            string location;
                            cin >> location;
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            if(find_if(location.begin(), location.end(),(int(*)(int))isdigit) == location.end())
                            {
                                server.addRecord(name,lastname,flightnum,date,time,location);
                                server.save();
                                con=false;
                            }

                            else
                            {
                                cout<<"Enter the location without numbers !"<<endl;;
                                goto loc;
                            }
                        }

                        else
                        {
                            cout<<"Wrong data format"<<endl;
                            goto jum3;
                        }
                    }

                    else
                    {
                        cout<<"Wrong data format"<<endl;
                        goto jum2;
                    }
                }

                else
                {
                    cout<<"Wrong data format"<<endl;
                    goto jum1;
                }
            }
    
            else
            {
                cout<<"Enter the last name without numbers !"<<endl;
                goto lm;
            }
        }

        else
        {
            cout<<"Enter the first name without numbers !"<<endl;
            goto nm;
        }
    }
}

void EditRecord(Database& server)
{
    idi:
    cout << "Enter the passenger's ID: ";
    int id;
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if(!cin)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"Only numbers are available"<<endl;
        goto idi;
    }
    int numline = 0;
    string line;
    ifstream myfile("database.txt");
    if(!myfile.is_open())
    {
        cerr << "Error open database.txt" << endl;
        goto idi;
    }
    while (getline(myfile, line)){++numline;}
    if(id > -1 && id < numline)
    {
        bool con = true;
        while(con)
        {
            nm:
            cout << "Enter the passenger's first name: ";
            string name;
            cin >> name;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if(find_if(name.begin(), name.end(),(int(*)(int))isdigit) == name.end())
            {
                lm:
                cout << "Enter the passengers's last name: ";
                string lastname;
                cin >> lastname;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if(find_if(lastname.begin(), lastname.end(),(int(*)(int))isdigit) == lastname.end())
                {
                    jum1:
                    cout << "Enter the flight number (XXX-XXX-XXX) : ";
                    string flightnum;
                    cin >> flightnum;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    if(flightnum.length() == 11 && flightnum[3] == '-' && flightnum[7] == '-')
                    {
                        jum2:
                        cout << "Enter the date of the flight (DD-MM-YYYY): ";
                        string date;
                        cin >> date;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        if(date.length() == 10 && date[2] == '-' && date[5] == '-' && date[0] >= '0' && date[0] <= '9'&& date[1] >= '0' && date[1] <= '9'&& date[3] >= '0' && date[3] <= '9'&& date[4] >= '0' && date[4] <= '9'&& date[6] >= '0' && date[6] <= '9'&& date[7] >= '0' && date[7] <= '9'&& date[8] >= '0' && date[8] <= '9'&& date[9] >= '0' && date[9] <= '9')
                        {
                            jum3:
                            cout << "Enter the time of the flight (XX:XX): ";
                            string time;
                            cin >> time;
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');

                            if(time.length() == 5 && time[0] >= '0' && time[0] <= '9'&& time[1] >= '0' && time[1] <= '9' && time[2] == ':' && time[3] >= '0' && time[3] <= '9'&& time[4] >= '0' && time[4] <= '9')
                            {
                                loc:
                                cout << "Enter the location: ";
                                string location;
                                cin >> location;
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                if(find_if(location.begin(), location.end(),(int(*)(int))isdigit) == location.end())
                                {
                                    server.editRecord(id,name,lastname,flightnum,date,time,location);
                                    server.save();
                                    con=false;
                                }

                                else
                                {
                                    cout<<"Enter the location without numbers !"<<endl;
                                    goto loc;
                                }
                            }
                            else
                            {
                                cout<<"Wrong data format"<<endl;
                                goto jum3;
                            }
                        }

                        else
                        {
                            cout<<"Wrong data format"<<endl;
                            goto jum2;
                        }
                    }

                    else
                    {
                        cout<<"Wrong data format"<<endl;
                        goto jum1;
                    }
                }
    
                else
                {
                    cout<<"Enter the last name without numbers !"<<endl;
                    goto lm;
                }
            }

            else
            {
                cout<<"Enter the first name without numbers !"<<endl;
                goto nm;
            }
        }
    }
    else
    {
        cout<<"Incorrect ID"<<endl;
        goto idi;
    }
}
 
void DeleteRecord(Database& server)
{
    idd:
    cout << "Enter the ID of the ticket: ";
    int id;
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if(!cin)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"Only numbers are available"<<endl;
        goto idd;
    }
    int numline = 0;
    string line;
    ifstream myfile("database.txt");
    if(!myfile.is_open())
    {
        cerr << "Error open database.txt" << endl;
        goto idd;
    }
    while (getline(myfile, line)){++numline;}
    if(id > -1 && id < numline)
    {
        string delete_flag = "%delete";
        server.editRecord(id,delete_flag, delete_flag, delete_flag, delete_flag, delete_flag, delete_flag);
        server.save();
    }
    
    else
    {
        cout<<"Incorrect ID"<<endl;
        goto idd;
    }

}

void Database::sortedByDate()
{
    vector<list> flightlist;
    wfstream myfile("database.txt",ios::in);
    if(!myfile.is_open())
    {
        cerr << "Error open database.txt" << endl;
        exit(1);
    }

    while (!myfile.eof())
    {
        list flist;
        myfile>>flist.skip1>>flist.skip2>>flist.skip3;
        getline(myfile,flist.needata);
        flightlist.push_back(flist);
    }
    sort(flightlist.begin(), flightlist.end(),[](const list& lhs, const list& rhs)->bool{return lhs.needata < rhs.needata;});
    for_each(flightlist.begin(), flightlist.end(), [](const list& f){wcout<<f.skip1 << " " << f.skip2 << " " << f.skip3<< f.needata<<"\n";});
    myfile.close();
} 

void Database::sortedByLocation()
{
    vector<list> loclist;
    wfstream myfile("database.txt",ios::in);
    if(!myfile.is_open())
    {
        cerr << "Error open database.txt" << endl;
        exit(1);
    }

    while (!myfile.eof())
    {
        list llist;
        myfile>>llist.skip1>>llist.skip2>>llist.skip3>>llist.skip4>>llist.skip5;
        getline(myfile,llist.needata);
        loclist.push_back(llist);
    }
    sort(loclist.begin(), loclist.end(),[](const list& lhs, const list& rhs)->bool{return lhs.needata < rhs.needata;});
    for_each(loclist.begin(), loclist.end(), [](const list& f){wcout<<f.skip1 << " " << f.skip2 << " " << f.skip3 << f.skip4 << " " << f.skip5 << " " << f.needata<<"\n";});
    myfile.close();
}

void menu(Database& server)
{
    server.load();
    mn:
    bool end = false;
 
    while(!end)
    {
        cout << "----------BD's Menu---------" << endl << endl;
 
        cout << "1. Record the new data" << endl;
 
        cout << "2. Delete the data" << endl;

        cout << "3. Edit the ticket's data" << endl;
 
        cout << "4. Show all tickets" << endl;

        cout << "5. Show sorted base by date" << endl;

        cout << "6. Show sorted base by location" << endl;

        cout << "7. Search for matches in the DB" << endl;

        cout << "8. Exit" << endl;

 
        cout << "\n\nSelect the function: ";

        int answer;
        cin>>answer;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if(!cin)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Wrong data type"<<endl;
            system("pause");
            system("cls");
            goto mn;
        }

        switch(answer)
        {
            case 1:
                AddRecord(server);
                system("pause");
                system("cls");
                break;
            case 2:
                DeleteRecord(server);
                system("pause");
                system("cls");
                break;
            case 3:
                EditRecord(server);
                system("cls");
                break;
            case 4:
                server.printDatabase();
                system("pause");
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
            case 5:
                server.sortedByDate();
                system("pause");
                system("cls");
                break;
            case 6:
                server.sortedByLocation();
                system("pause");
                system("cls");
                break;
            default:
                cout << "Wrong num " << endl;
                system("pause");
                system("cls");
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