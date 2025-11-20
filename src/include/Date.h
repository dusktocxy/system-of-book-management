#ifndef _DATE_H_
#define _DATE_H_
#include <iostream>
using namespace std;
class Date{
public:
	int year;  
	int month; 
	int day; 
public:
	Date(int year,int month,int day){
        this->year=year;
        this->month=month;
        this->day=day;
    }    //Date类的构造函数
    Date(){

    }
	void set(){
        cout<<"请输入年"<<endl;
        int year;
        cin>>year;
        this->year=year;
        cout<<"请输入月"<<endl;
        int month;
        cin>>month;
        this->month=month;
        cout<<"请输入日"<<endl;
        int day;
        cin>>day;
        this->day=day;
    }  //Date类的设置函数
	friend istream & operator >>(istream &in,Date &d){
        in>>d.year>>d.month>>d.day;
        return in;
    }   //重载“》”
	friend ostream & operator <<(ostream &out,Date &d){
        out<<d.year<<"-"<<d.month<<"-"<<d.day;
        return out;
    }   //重载“《”
	void operator =(const Date &d){
        this->year=d.year;
        this->month=d.month;
        this->day=d.day;
    }
    bool operator==(const Date &d){
        if(this->year==d.year&&this->month==d.month&&this->day==d.day){
            return true;
        }
        else{
            return false;
        }
    } 
};
#endif