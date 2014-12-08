/* 
 * File:   lab2.h
 * Author: nikkbandy
 *
 * Created on October 4, 2014, 11:58 PM
 */

#ifndef LAB2_H
#define	LAB2_H

class Day {
public:
    Day();
    
    int weekDay(char startday);
    
private:
    int date;
};

class Month {
public:
    Month();
    
    int days[12];
    void numOfDays(int *days, int feb);
    int validStartDay(char startday);
    int prevDays(int *days, int month);
    
private:
    int num;
    char startDay;
};

class Year {
public:
    Year();
    
    int leapYear(int num);
    
private:
    int num;
};

#endif	/* LAB2_H */

