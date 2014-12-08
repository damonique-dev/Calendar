/*
 * Lab2.cpp
 * CSE 4252
 * Fall 2014
 *
 * Author: Damonique Thomas
 */

#include <iostream>
#include "lab2.h"

Day::Day(){}
Month::Month(){}
Year::Year(){}


int Day::weekDay(char startday) {
    switch (startday) {
        case 'U':
        case 'u':
            return 0;
            break;
        case 'M':
        case 'm':
            return 1;
            break;
        case 'T':
        case 't':
            return 2;
            break;
        case 'W':
        case 'w':
            return 3;
            break; 
        case 'R':
        case 'r':
            return 4;
            break;
        case 'F':
        case 'f':
            return 5;
            break;
        case 'S':
        case 's':
            return 6;
            break;
        default:
            return 7;
            break;
    }
    return 0;
}

int Month::validStartDay(char startday){
    switch (startday) {
        case 'U':
        case 'u':
        case 'M':
        case 'm':
        case 'T':
        case 't':
        case 'W':
        case 'w':
        case 'R':
        case 'r':
        case 'F':
        case 'f':
        case 'S':
        case 's':
            return 0;
            break;
        default:
            return 1;
            break;
    }
}

int Month::prevDays(int *days, int month) {
    int prevDays, i;
    prevDays = 0;
    for (i = 0; i < month-1; i++) {
        prevDays += *(days+i);
    }
    return prevDays;
}

void Month::numOfDays(int *days, int feb) {
    for (int i = 0; i < 12; i++) {
        switch (i) {
            case 0:
            case 2:
            case 4:
            case 6:
            case 7:
            case 9:
            case 11:
                *(days + i) = 31;
                break;
            case 1:
                *(days + i) = feb;
                break;
            default:
                *(days + i) = 30;
                break;

        }
    }
}

int Year::leapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return 29;
            }
        }
    }
    return 28;
}


