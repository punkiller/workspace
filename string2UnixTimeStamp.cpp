//============================================================================
// Name        : string2UnixTimeStamp.cpp
// Author      : pankaj
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string>
#include<cstdlib>
using namespace std;
class unixts{
public:
	int ss,min,hh;
	int yy,mm,dd;
	void showtime(){
		cout<<mm<<":"<<dd<<":"<<yy<<":"<<hh<<":"<<min<<":"<<ss<<"\n";
	}
};

//input = "mm/dd/yy hh:mm:ss"
unsigned long long str2unixts(const char * str){
	unixts temp;
	std::string tempStr(str);

	tempStr[2] = '\0';
	temp.mm = atoi(&tempStr[0]);
	tempStr[5] = '\0';
	temp.dd = atoi(&tempStr[3]);
	tempStr[8] = '\0';
	temp.yy = atoi(&tempStr[6]);
	if( temp.yy < 70)
		temp.yy += 2000;
	else
		temp.yy += 1900;
	tempStr[11] = '\0';
	temp.hh = atoi(&tempStr[9]);
	tempStr[14] = '\0';
	temp.min = atoi(&tempStr[12]);
	tempStr[15] = '\0';
	temp.ss = atoi(&tempStr[13]);
	temp.showtime();
	unsigned long long noDays = 365 * (temp.yy - 1970);
	// add leap days
	for( int i = 1970; i < temp.yy ; i++){
		if( i%4 == 0 && i%200 != 0){
			noDays++;
		}
	}
	int MonthArr[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	if((temp.yy%4 == 0) && (temp.yy%200 != 0))
		MonthArr[1] = 29;
	for ( int i = 0; i < temp.mm - 1 ; ++i)
		noDays += MonthArr[i];

	noDays += temp.dd - 1;
	unsigned long long noSecs
	= ((noDays*24 + temp.hh)*60 + temp.min)*60 + temp.ss;

	return noSecs;
}
int main() {
	const char * str = "01/01/71 01:01:01";
	cout<<"\n"<<str2unixts(str);
	return 0;
}
