#ifndef UNTITLED_EVENT_H
#define UNTITLED_EVENT_H

#include <iostream>
#include <queue>
#include <string>
#include <ctime>
#include <algorithm>
#include <vector>

using namespace std;


class event {
public:
    string name;
    string place;
    int numofdelete;
    bool isDone;
    int start_year, start_month, start_day, end_year, end_month, end_day;
    int startHour;
    int endHour;
    int reminder;
    int remainder;
    bool isIntersects;

    event(string, string, int, int, int, int, int, int, int, int, int, vector<event>);

    event();

public:
    void deleteEvent(vector<event>);

    void createEvent(vector<event>);

    void showSorted(vector<event>);

    void show(vector<event> v);

    void getTodayTime();

    void checkIfDone();

    int calculateRemainder();

    bool checkIfIntersected(vector<event> v);

    void set_start_date();

    void set_name();

    void set_place();

    void set_end_date();
};


#endif //UNTITLED_EVENT_H