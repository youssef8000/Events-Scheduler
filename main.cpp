#include <iostream>
#include<windows.h>
#include<fstream>
#include <string>
#include <vector>
#include "event.h"
#include "event.cpp"

using namespace std;

vector<event> v;
vector<event> v2;

void update();

void removeDone();

int main() {
    ifstream file;
    file.open("D:\\kolaya\\2nd year\\2nd semester\\Data structure\\project\\event\\f1.txt");
    if (file.is_open()) {
        while (!file.eof()) {
            string name, place;
            int start_year, start_month, start_day, start_hour, reminder, end_year, end_month, end_day, end_hour;
            string ssy, ssm, ssd, ssh, sr, sey, sem, sed, seh;
            getline(file, ssy);
            getline(file, ssm);
            getline(file, ssd);
            getline(file, ssh);
            getline(file, sr);
            getline(file, sey);
            getline(file, sem);
            getline(file, sed);
            getline(file, seh);
            getline(file, name);
            getline(file, place);
            start_year = stoi(ssy);
            start_month = stoi(ssm);
            start_day = stoi(ssd);
            start_hour = stoi(ssh);
            reminder = stoi(sr);
            end_year = stoi(sey);
            end_month = stoi(sem);
            end_day = stoi(sed);
            end_hour = stoi(seh);

            event e({ name, place, start_year, start_month, start_day, start_hour, reminder, end_year, end_month,
                     end_day, end_hour, v });

            if (e.isIntersects == 0) {
                v.push_back(e);
            }
        }
    }
    else {
        cout << "error" << endl;
        file.close();
    }
    file.close();
    ifstream file_Done;
    file_Done.open("D:\\kolaya\\2nd year\\2nd semester\\Data structure\\project\\event\\f2.txt");
    if (file_Done.is_open()) {
        while (!file_Done.eof()) {
            string name, place;
            int start_year, start_month, start_day, start_hour, reminder, end_year, end_month, end_day, end_hour;
            string ssy, ssm, ssd, ssh, sr, sey, sem, sed, seh;
            getline(file_Done, ssy);
            getline(file_Done, ssm);
            getline(file_Done, ssd);
            getline(file_Done, ssh);
            getline(file_Done, sr);
            getline(file_Done, sey);
            getline(file_Done, sem);
            getline(file_Done, sed);
            getline(file_Done, seh);
            getline(file_Done, name);
            getline(file_Done, place);
            start_year = stoi(ssy);
            start_month = stoi(ssm);
            start_day = stoi(ssd);
            start_hour = stoi(ssh);
            reminder = stoi(sr);
            end_year = stoi(sey);
            end_month = stoi(sem);
            end_day = stoi(sed);
            end_hour = stoi(seh);

            event e({ name, place, start_year, start_month, start_day, start_hour, reminder, end_year, end_month,
                     end_day, end_hour, v2 });


            v2.push_back(e);

        }
    }
    else {
        cout << "error" << endl;
        file_Done.close();
    }
    file_Done.close();
    event mainEvent;
    cout << "                                      HELLO                                      \n";
    mainEvent.showSorted(v);
    while (true) {

        cout << "Choose the Number of the Operation You Want\n";
        cout << "1-Add an Event\n2-Delete an Event\n3-Edit an Event\n4-Show The Events Sorted\n5-Show Done Events\n6-End Task\n";
        removeDone();
        event e;
        int options;
        cin >> options;
        system("cls");
        cout << "LOADING...";
        Sleep(500);
        cout << ".....";
        Sleep(500);
        cout << ".....\n";
        switch (options) {
        case 1:
            e.createEvent(v);
             if(e.checkIfIntersected(v)){
               cout << "Your Event Intersects with another Event" << endl ;
            }
            else{
              v.push_back(e);
             }
            cout << "LOADING...";
            Sleep(500);
            cout << ".....";
            Sleep(500);
            cout << ".....\n";
            system("cls");

            break;
        case 2:
            e.show(v);
            e.deleteEvent(v);
            v.erase((v.begin() + e.numofdelete - 1));
            cout << "LOADING...";
            Sleep(500);
            cout << ".....";
            Sleep(500);
            cout << ".....\n";
            system("cls");
            break;
        case 3:
            e.show(v);
            update();
            cout << "LOADING...";
            Sleep(500);
            cout << ".....";
            Sleep(500);
            cout << ".....\n";
            system("cls");
            break;
        case 4:
            mainEvent.showSorted(v);
            break;
        case 5:
            mainEvent.show(v2);
            break;
        case 6: {
            ofstream event_final;
            event_final.open("D:\\kolaya\\2nd year\\2nd semester\\Data structure\\project\\event\\f1.txt");
            for (int t = 0; t < v.size(); t++) {
                event_final << v.at(t).start_year << endl;
                event_final << v.at(t).start_month << endl;
                event_final << v.at(t).start_day << endl;
                event_final << v.at(t).startHour << endl;
                event_final << v.at(t).reminder << endl;
                event_final << v.at(t).end_year << endl;
                event_final << v.at(t).end_month << endl;
                event_final << v.at(t).end_day << endl;
                event_final << v.at(t).endHour << endl;
                event_final << v.at(t).name << endl;
                if (t == (v.size() - 1)) {
                    event_final << v.at(t).place;
                }
                else {
                    event_final << v.at(t).place << endl;
                }
            }
            event_final.close();
            ofstream event_Done_final;
            event_Done_final.open("D:\\kolaya\\2nd year\\2nd semester\\Data structure\\project\\event\\f2.txt");
            for (int t = 0; t < v2.size(); t++) {
                event_Done_final << v2.at(t).start_year << endl;
                event_Done_final << v2.at(t).start_month << endl;
                event_Done_final << v2.at(t).start_day << endl;
                event_Done_final << v2.at(t).startHour << endl;
                event_Done_final << v2.at(t).reminder << endl;
                event_Done_final << v2.at(t).end_year << endl;
                event_Done_final << v2.at(t).end_month << endl;
                event_Done_final << v2.at(t).end_day << endl;
                event_Done_final << v2.at(t).endHour << endl;
                event_Done_final << v2.at(t).name << endl;
                if (t == (v2.size() - 1)) {
                    event_Done_final << v2.at(t).place;
                }
                else {
                    event_Done_final << v2.at(t).place << endl;
                }
            }
            event_Done_final.close();

            cout << "                                    ********* Good Bye *********                                       \n";
            cout << "                            ********* Developed and Maintained By : ********                                      \n";
            cout << "                              ************* Youssef Shaaban *************                                       \n";
            cout << "                                *********** Youssef Said **************                                     \n";
            cout << "                                  ********* Omar Mahmoud ************                                     \n";
            cout << "                                    ******* Youssef Amr ***********                                     \n";
            cout << "                                      ***** Youssef Walid *******                                     \n";
            cout << "                                        *** Youssef Wael ******                                     \n";
            cout << "                                          * Eslam Khaled ****                                     \n";
            exit(0);
        }
        default:
            cout << "Invalid Input \n";
            break;
        }
    }
}

void removeDone() {
    for (int i = 0; i < v.size(); i++) {
        if (v.at(i).isDone == 1) {
            v2.push_back(v.at(i));
            v.erase((v.begin() + i));
        }
    }
}

void update() {
    int numofchange;
    int choice;
    while (numofchange > v.size() || numofchange <= 0) {
        cout << "Enter The No. of Event You Want to Edit: (from 1 to " << v.size() << ") ";
        cin >> numofchange;
    }
    bool x = true;
    while (x) {
        cout << "Choose the Number of the Operation You Want\n";
        cout
            << "1-Change Event's Name\n2-Change Event's Place\n3-Change Event's Start date\n4-Change Event's End date\n5-End Editting process\n";
        cin >> choice;
        switch (choice) {
        case 1:
            v.at(numofchange - 1).set_name();
            break;
        case 2:
            v.at(numofchange - 1).set_place();
            break;
        case 3:
            v.at(numofchange - 1).set_start_date();
            while (v.at(numofchange - 1).checkIfIntersected(v)) {
                cout << "This New Start Date Intersects With Another Event" << endl;
                cout << "Try Again" << endl;
                v.at(numofchange - 1).set_start_date();
            }
            break;
        case 4:
            v.at(numofchange - 1).set_end_date();
            while (v.at(numofchange - 1).checkIfIntersected(v)) {
                cout << "This New End Date Intersects With Another Event" << endl;
                cout << "Try Again" << endl;
                v.at(numofchange - 1).set_end_date();
            }
            break;
        case 5:
            v.at(numofchange - 1).calculateRemainder();
            v.at(numofchange - 1).checkIfDone();
            removeDone();
            x = false;
            break;
        default:
            cout << "Invalid Input";
            break;
        }
    }
}
