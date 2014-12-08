/*
 * Lab3.cpp
 * CSE 4252
 * Fall 2014
 *
 * Author: Damonique Thomas
 */

#include <iostream>
#include "lab2.h"

void printCalender(int prevDays, int month, char startDay);
int firstOfMonth(int prevDays, char startDay);

using namespace std;

int main(int argc, char**argv) {
    Month month;
    Year year;
    int feb, prevDays, monthIn, yr, *d, contin;
    char start, cont;
    
    contin = 0;
    while(contin != 1){
        cout << "Enter the year: ";
        cin >> yr;
        if (yr < 1 || yr > 9999) {
            cout << "ERROR: Invalid Year";
            return 0;
        }

        cout << "Enter the month: ";
        cin >> monthIn;
        if (monthIn < 1 || monthIn > 12) {
            cout << "ERROR: Invalid Month";
            return 0;
        }

        cout << "Enter the First Day of the Year: ";
        cin >> start;
        if(month.validStartDay(start) == 1){
            cout << "ERROR: Invalid First of the Year";
            return 0;
        }

        d = month.days;
        feb = year.leapYear(yr);
        month.numOfDays(d, feb);
        prevDays = month.prevDays(d, monthIn);
        printCalender(prevDays, *(d+monthIn -1), start);

        cout<<endl;
        cout<<endl;
        cout<<"Another calender? Enter y to continue or any key to quit:";
        cin>>cont;
        cout<<endl;
        if(cont != 'y'){
            contin = 1;
        }
    }
    return 0;
}

/*
 *Returns the number corespsonding to the weekday of the
 * first of the input month
 */
int firstOfMonth(int prevDays, char startDay) {
    Day *day = new Day;
    int firstDay, weekDay;
    
    firstDay = day->weekDay(startDay);
    weekDay = (prevDays - (7-firstDay)) %7;
    
    return weekDay;
}


/*
 *Outputs the calender for the input month
 */
void printCalender(int prevDays, int monthDays, char startDay) {
    int weekDay, i, j, count;
    
    weekDay = firstOfMonth(prevDays, startDay);
    cout<<endl;
    cout << "Su\tMo\tTu\tWe\tTh\tFr\tSa" << endl;
    cout <<"-----------------------------------------------------"<<endl;
    j = 1;
    //output first week
    if((weekDay !=0) && (weekDay < 7)){
        for(i = 0; i < 7; i++){
            if(i > weekDay-1){
                cout << j << "\t";
                j++;
            }
            else {
                cout << "\t";
            }
        }
        cout<<endl;
    }
    
    //ouput rest of calender
    count = 0;
    while (j < monthDays +1){
        if (count > 6){
            cout<<endl;
            count = 0;
        }
        cout << j << "\t";
        j++;
        count++;
    }
}
