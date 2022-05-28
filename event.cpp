    #include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>
#include <string>
#include "event.h"

using namespace std;
time_t now = time(0);
tm* ltm = localtime(&now);

int currentYear = 1900 + ltm->tm_year;
int currentMonth = 1 + ltm->tm_mon;
int currentDay = ltm->tm_mday;

void event::deleteEvent(vector<event> v) {

    cout << "Enter The No. of Event You Want to Delete: (from 1 to " << v.size() << ") ";
    cin >> numofdelete;

}

void event::createEvent(vector<event> v) {

    getTodayTime();

    set_name();
    set_place();
    set_start_date();
    set_end_date();

    isDone = false;
    calculateRemainder();
    checkIfDone();

    cout << "Event has been added" << endl;
}

void event::showSorted(vector<event> v) {
    sort(v.begin(), v.end(), [](event a, event b) {
        return a.remainder < b.remainder;
        });
    cout << "The Upcoming Events Are:" << endl;
    for (int i = 0; i < v.size(); i++) {
        if (v.at(i).isDone == 0) {
            cout << "Event No.:" << i + 1 << endl;
            cout << "Event Name:" << v.at(i).name << endl;
            cout << "Event place:" << v.at(i).place << endl;
            cout << "Event Start Date: " << v.at(i).start_day << "-" << v.at(i).start_month << "-"
                << v.at(i).start_year;
            cout << " at " << v.at(i).startHour << " o'clock" << endl;
            cout << "Event End Date: " << v.at(i).end_day << "-" << v.at(i).end_month << "-" << v.at(i).end_year;
            cout << " at " << v.at(i).endHour << " o'clock" << endl;
            if (v.at(i).remainder == 1) {
                cout << "Event " << v.at(i).name << " will be tomorrow at ";
                cout << v.at(i).startHour << " o'clock" << endl << endl;
            }

            cout << "========================================================" << endl;
        }
    }
}

void event::getTodayTime() {

    cout << "Date:" << currentDay << "-" << currentMonth << "-" << currentYear << endl;
}

int event::calculateRemainder() {

    if (start_year == currentYear && start_month == currentMonth && start_day == currentDay) {
        remainder = 0;
    }
    else if (start_year - currentYear == 0 && start_month - currentMonth == 0) {
        remainder = start_day - currentDay;

    }
    else if (start_year - currentYear == 0 && start_month - currentMonth > 0) {
        if (start_month - currentMonth == 1) {
            remainder = (30 - currentDay) + start_day;
        }
        else if (start_month - currentMonth > 1) {
            remainder = ((30 * (start_month - currentMonth)) - currentDay) + start_day;
        }
    }
    else if (start_year - currentYear > 0) {
        int remMonth = start_month - currentMonth;
        int remDays = start_day - currentDay;
        int remYears = start_year - currentYear;
        remainder = (remYears * 365) + (remMonth * 30) + remDays;
    }
    return remainder;
}

void event::checkIfDone() {


    if (end_year < currentYear) {
        isDone = true;
    }
    else if (end_year - currentYear == 0 && end_month - currentMonth < 0) {
        isDone = true;
    }
    else if (end_year - currentYear == 0 && end_month - currentMonth == 0 && end_day - currentDay < 0) {
        isDone = true;
    }
    else {
        isDone = false;
    }
}

bool event::checkIfIntersected(vector<event> v) {
    int start = (365 * start_year) + (30 * start_month) + start_day;
    int end = (365 * end_year) + (30 * end_month) + end_day;
    for (int i = 0; i < v.size(); i++) {
        int vector_event_start = (365 * v.at(i).start_year) + (30 * v.at(i).start_month) + v.at(i).start_day;
        int vector_event_end = (365 * v.at(i).end_year) + (30 * v.at(i).end_month) + v.at(i).end_day;
        if (name != v.at(i).name) {
            if ((start >= vector_event_start && start <= vector_event_end) ||
                (end >= vector_event_start && end <= vector_event_end) ||
                (start <= vector_event_start && start >= vector_event_end) || (end <= vector_event_start && end >= vector_event_end)) {
                return true;
            }
        }
        else {
            return false;
        }
    }
    return false;
}

event::event(string Name, string Place, int Start_Year, int Start_Month, int Start_Day, int Start_Hour, int Reminder,
    int End_Year, int End_Month, int End_Day, int End_Hour, vector<event> v) {
    name = Name;
    place = Place;
    start_year = Start_Year;
    start_month = Start_Month;
    start_day = Start_Day;
    startHour = Start_Hour;
    reminder = Reminder;
    end_year = End_Year;
    end_month = End_Month;
    end_day = End_Day;
    endHour = End_Hour;
    isIntersects = checkIfIntersected(v);
    calculateRemainder();
    checkIfDone();

}

event::event() {
    name = "empty";
    place = "empty";
    start_year = 0;
    start_month = 0;
    start_day = 0;
    startHour = 0;
    reminder = 0;
    end_year = 0;
    end_month = 0;
    end_day = 0;
    endHour = 0;
    remainder = 0;
    isDone = false;
    isIntersects = false;
}

void event::show(vector<event> v) {
    for (int i = 0; i < v.size(); i++) {

        cout << "Event No.:" << i + 1 << endl;
        cout << "Event Name:" << v.at(i).name << endl;
        cout << "Event place:" << v.at(i).place << endl;
        cout << "Event Start Date: " << v.at(i).start_day << "-" << v.at(i).start_month << "-"
            << v.at(i).start_year;
        cout << " at " << v.at(i).startHour << " o'clock" << endl;
        cout << "Event End Date: " << v.at(i).end_day << "-" << v.at(i).end_month << "-" << v.at(i).end_year;
        cout << " at " << v.at(i).endHour << " o'clock" << endl;
        if (v.at(i).remainder == 1) {
            cout << "Event " << v.at(i).name << " will be tomorrow at ";
            cout << v.at(i).startHour << " o'clock" << endl << endl;
        }

        cout << "========================================================" << endl;
    }
}

void event::set_name() {
    cout << "Enter Event's Name:";
    cin.ignore();
    getline(cin, name);

}

void event::set_start_date() {
    cout << "Start Year:";
    cin >> start_year;
    while (start_year < currentYear) {
        cout << "INVALID YEAR" << endl;
        cout << "Try Again" << endl;
        cout << "Start Year:";
        cin >> start_year;
    }
    cout << "Start Month:";
    cin >> start_month;
    while ((start_year == currentYear && start_month < currentMonth) || (start_month > 12 || start_month <= 0)) {
        cout << "INVALID MONTH" << endl;
        cout << "Try Again" << endl;
        cout << "Start Month:";
        cin >> start_month;
    }
    cout << "Start Day:";
    cin >> start_day;
    while ((start_year == currentYear && start_month == currentMonth && start_day < currentDay) || (start_day > 31 || start_day <= 0)) {
        cout << "INVALID DAY" << endl;
        cout << "Try Again" << endl;
        cout << "Start Day:";
        cin >> start_day;
    }
    cout << "Start Hour:";
    cin >> startHour;
    while (startHour > 24 || startHour < 0) {
        cout << "INVALID HOUR" << endl;
        cout << "Try Again" << endl;
        cout << "Start Hour:";
        cin >> startHour;
    }
    cout << "Enter hour you want to be reminded at:";
    cin >> reminder;
    while (reminder > 24 || reminder < 0) {
        cout << "INVALID HOUR" << endl;
        cout << "Try Again" << endl;
        cout << "Enter hour you want to be reminded at:";
        cin >> reminder;
    }

}

void event::set_place() {
    cout << "Enter Event's place:";
    cin.ignore();
    getline(cin, place);
}

void event::set_end_date() {
    cout << "End Year Event:";
    cin >> end_year;
    while (end_year < start_year) {
        cout << "INVALID YEAR" << endl;
        cout << "Try Again" << endl;
        cout << "End Year Event:";
        cin >> end_year;
    }
    cout << "End Month:";
    cin >> end_month;
    while ((start_year == end_year && end_month < start_month) || end_month > 12 || end_month <= 0) {
        cout << "INVALID MONTH" << endl;
        cout << "Try Again" << endl;
        cout << "End Month:";
        cin >> end_month;
    }
    cout << "End Day:";
    cin >> end_day;
    while ((start_year == end_year && end_month == start_month && end_day < start_day) || end_day > 31 || end_day <= 0) {
        cout << "INVALID DAY" << endl;
        cout << "Try Again" << endl;
        cout << "End Day:";
        cin >> end_day;
    }
    cout << "End Hour:";
    cin >> endHour;
    while ((start_year == end_year && end_month == start_month && end_day == start_day && endHour < startHour) ||
        endHour > 24 || endHour <= 0) {
        cout << "INVALID HOUR" << endl;
        cout << "Try Again" << endl;
        cout << "End Hour:";
        cin >> endHour;
    }

}
