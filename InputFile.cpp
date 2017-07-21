/*
 * InputFile.cpp
 *
 *  Created on: Dec 6, 2013
 *      Author: marydubard
 */

#include "InputFile.h"
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;


int main(){
	string originalDate;
	cout << "Please enter a date in the form of mm/dd/yyyy: ";
	cin >> originalDate;
	if(cin.fail()) cout << "Bad input. Please try again.";
	while(originalDate.length() > 10){
		cout << "Inputted date is too long. Please try again in the form of mm/dd/yyyy: ";
		cin >> originalDate;
	}
	while(originalDate.length() < 10){
			cout << "Inputted date is too short. Please try again in the form of mm/dd/yyyy: ";
			cin >> originalDate;
		}
	string monthString = originalDate.substr(0,2);
//	cout << monthString;
	string dayString = originalDate.substr(3,2);
//	cout << dayString;
	string yearString = originalDate.substr(6, 4);
//	cout << yearString;

	stringstream sstream(monthString);
	int month;
	sstream >> month;
	if (!sstream){
		cout << "Month is not a number. Please reenter the month in the form of mm: ";
		cin >> month;
	}
	stringstream xstream(dayString);
	int day;
	xstream >> day;
	if (!xstream){
			cout << "Day is not a number. Please reenter the day in the form of dd: ";
			cin >> day;
		}
	stringstream astream(yearString);
		int year;
		astream >> year;
		if (!astream){
				cout << "Year is not a number. Please reenter the year in the form of yyyy: ";
				cin >> year;
			}

	while (year < 1200 || year >= 2200){
		cout << "Year is out of range. Please enter a year between 1200 and 2199: ";
		cin >> year;
	}

	bool leapYear = false;
	if(year%400 == 00 || (year%100 != 0 && year%4 == 0))
		leapYear = true;

	switch(month){
	case 1 : while(day > 31){
				cout << "There are only 31 days in January. Please enter a valid day: ";
				cin >> day;
			 }
		break;
	case 2 :
			if(leapYear){
				while(day > 29){
					cout << "There are only 29 days in February. Please enter a valid day: ";
					cin >> day;
				}
			}
			else{
				while(day > 28){
					cout << "There are only 28 days in February. Please enter a valid day: ";
					cin >> day;
				}
			}
		break;
	case 3 :
		while(day > 31){
						cout << "There are only 31 days in March. Please enter a valid day: ";
						cin >> day;
					 }
		break;
	case 4 :
		while(day > 30){
						cout << "There are only 30 days in April. Please enter a valid day: ";
						cin >> day;
					 }
		break;
	case 5 :
		while(day > 31){
						cout << "There are only 31 days in May. Please enter a valid day: ";
						cin >> day;
					 }
		break;
	case 6 :
		while(day > 30){
						cout << "There are only 30 days in June. Please enter a valid day: ";
						cin >> day;
					 }
		break;
	case 7 :
		while(day > 31){
						cout << "There are only 31 days in July. Please enter a valid day: ";
						cin >> day;
					 }
		break;
	case 8 :
		while(day > 31){
						cout << "There are only 31 days in August. Please enter a valid day: ";
						cin >> day;
					 }
		break;
	case 9 :
		while(day > 30){
						cout << "There are only 30 days in September. Please enter a valid day: ";
						cin >> day;
					 }
		break;
	case 10 :
		while(day > 31){
						cout << "There are only 31 days in October. Please enter a valid day: ";
						cin >> day;
					 }
		break;
	case 11 :
		while(day > 30){
						cout << "There are only 30 days in November. Please enter a valid day: ";
						cin >> day;
					 }
		break;
	case 12 :
		while(day > 31){
						cout << "There are only 31 days in December. Please enter a valid day: ";
						cin >> day;
					 }
		break;
	}

	//DoomsDay Algorithm
	int century = year/100;
	int anchor = -1;

	switch(century){
	case 12: anchor = 2; //anchor day is Tuesday
	break;
	case 13: anchor = 0; //anchor day is Sunday
	break;
	case 14: anchor = 5; //anchor day is Friday
	break;
	case 15: anchor = 3; //anchor day is Wednesday
	break;
	case 16: anchor = 2; //anchor day is Tuesday
	break;
	case 17: anchor = 0; //anchor day is Sunday
	break;
	case 18: anchor = 5; //anchor day is Friday
	break;
	case 19: anchor = 3; //anchor day is Wednesday
	break;
	case 20: anchor = 2; //anchor day is Tuesday
	break;
	case 21: anchor = 0; //anchor day is Sunday
	break;
	default:
		cout << "Year is not correct. Please quit and restart.";
	}

	int yearOfCentury = year%100;
	int calculation1 = yearOfCentury/12; //how many times 12 fits into the last two years of the date, because every 12 years the DoomsDay advances by one
	int calculation2 = yearOfCentury%12; //remainder from 12 going into last two years of the date
	int calculation3 = calculation2/4; //how many times 4 goes into remainder
	int sum = anchor + calculation1 + calculation2 + calculation3; //adds up the 3 calculations and the anchor
	int doomsDay = sum; //sets doomsDay equal to sum
	while(doomsDay > 6){
		doomsDay = doomsDay - 7; //brings doomsDay to an integer that represents a week day
	}

	int monthArray[11] = {1, 2, 4, 5, 6, 7, 8, 9, 10, 11, 12}; //creates an array of the months containing a DoomsDay
	int min = 13;
	int closestMonth = 15;
	for(int x = 0; x < 11; x++){
		if(abs(monthArray[x]-month) < min){
			closestMonth = monthArray[x]; //finds the closest month to the inputted date
			min = abs(monthArray[x]-month);
		}
	}

	int closestDay = 40;


	//Finds closest DoomsDay to inputted date
	switch(closestMonth){
	case 1:
		if(leapYear)
			closestDay = 4;
		else
			closestDay = 3;
		break;
	case 2:
		if(leapYear)
			closestDay = 29;
		else
			closestDay = 28;
		break;
	case 4:
		closestDay = 4;
		break;
	case 5:
		closestDay = 9;
		break;
	case 6:
		closestDay = 6;
		break;
	case 7:
		if(abs(day-4) <= abs(day-11))
			closestDay = 4;
		else
			closestDay = 11;
		break;
	case 8:
		closestDay = 8;
		break;
	case 9:
		closestDay = 5;
		break;
	case 10:
		if(abs(day-10) <= abs(day-31))
			closestDay = 10;
		else
			closestDay = 31;
		break;
	case 11:
		closestDay = 7;
		break;
	case 12:
		closestDay = 12;
		break;
	default:
		closestDay = 50;
	}

	int dayOfWeek = 8;
	int difference = closestDay - day;
	if(difference >= 0){ //if the day is before the closest DoomsDay
		if(difference%7 == 0 || difference == 0){ //if the day is one the same day of the week as the closest DoomsDay
			dayOfWeek = doomsDay; //sets dayOfWeek equal to doomsDay
		}
		else
		{
			dayOfWeek = doomsDay; //automatically sets dayOfWeek equal to doomsDay
			int m = difference; //sets m as difference
			while(m > 6){
				m = m-7; //gets the difference down to an integer between 0 and 6, representing weekdays
			}
			for(int x = 0; x < m; x++){ //counts the days between DoomsDay and the weekday of the chosen day
				dayOfWeek--; //subtracts a day from the day of the week
				if(dayOfWeek < 0) //if it switches from Sunday to Saturday
					dayOfWeek = 6; //sets dayOfWeek to correct value for Saturday
			}
		}
	}
	else //if the day is after the closest DoomsDay
	{
		dayOfWeek = doomsDay; //automatically sets it to the same day as doomsDay
		int m = -1 * difference; //makes the difference positive
		while( m > 6){
			m = m-7; //gets the difference down to an integer between 0 and 6, representing weekdays
		}
		for(int x = 0; x < m; x++){ //counts the days from DoomsDay to the weekday of the chosen day
			dayOfWeek++; //adds a day to the day of the week
			if(dayOfWeek > 6) //if it switches from Saturday to Sunday
				dayOfWeek = 0; //sets dayOfWeek to correct value for Sunday
		}
	}

	if(month < 3){ //adjusts for later switch
		month = month + 12;
	}


//	cout << month << " " << day << " " << year;
//	Zeller's Algorithm
//
//	int century = year/100;
//	int yearOfCentury = year%100;
//	int dayOfWeek = (century/4) + 5*century;
//	dayOfWeek = dayOfWeek + yearOfCentury + yearOfCentury/4;
//	dayOfWeek = dayOfWeek + ((month+1)*26)/10;
//	dayOfWeek = dayOfWeek + day;
//	dayOfWeek = dayOfWeek%7;
//	dayOfWeek = ((dayOfWeek+5)%7) +1;

	string weekDay = "Does Not Exist";
	string type = "don't exist!";
	string monthString2 = "nonexistent";

	switch(dayOfWeek){
	case 1 : 	weekDay = "Monday";
				type = "are fair of face!";
	break;
	case 2 : 	weekDay = "Tuesday";
				type = "are full of grace!";
	break;
	case 3 : 	weekDay = "Wednesday";
				type = "are full of woe.";
	break;
	case 4 : 	weekDay = "Thursday";
				type = "have far to go.";
	break;
	case 5 : 	weekDay = "Friday";
				type = "are loving and giving!";
	break;
	case 6 : 	weekDay = "Saturday";
				type = "work hard for a living.";
	break;
	case 0 : 	weekDay = "Sunday";
				type = "are fair and wise and good and gay!";
	break;
	default : 	weekDay = "something";
				type = "are a big loser.";
	}

	switch(month){
	case 3 : 	monthString = "March";
		break;
	case 4 : 	monthString = "April";
		break;
	case 5 : 	monthString = "May";
		break;
	case 6 : 	monthString = "June";
		break;
	case 7 : 	monthString = "July";
		break;
	case 8 : 	monthString = "August";
		break;
	case 9 : 	monthString = "September";
		break;
	case 10 : 	monthString = "October";
		break;
	case 11 : 	monthString = "November";
		break;
	case 12 : 	monthString = "December";
		break;
	case 13 : 	monthString = "January";
		break;
	case 14 : 	monthString = "February";
		break;
	}

	string doomsDayString = "nothing";

	switch(doomsDay){
	case 0:		doomsDayString = "Sunday";
		break;
	case 1:		doomsDayString = "Monday";
		break;
	case 2:		doomsDayString = "Tuesday";
		break;
	case 3:		doomsDayString = "Wednesday";
		break;
	case 4:		doomsDayString = "Thursday";
		break;
	case 5:		doomsDayString = "Friday";
		break;
	case 6:		doomsDayString = "Saturday";
		break;
	}


	cout << "Doomsday of " << year << ": " << doomsDayString;
	cout << "\nDay of the Week of Date: " << weekDay;
//	cout << "\nIf you were born on " << monthString << " " << day << ", " << year << ", then you "<< type;

	return 0;
};






