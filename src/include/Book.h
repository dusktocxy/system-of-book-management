#ifndef _BOOK_H_
#define _BOOK_H_
#include <iostream>
#include <string>
#include "Date.h"
using namespace std;
class Book                       //存储图书信息的类
{   public:
	string BookName;           //书名，用于查找
	string ISBN;                //ISBN号，用于查找
	string Writer;               //作者名，用于查找
	string Publisher;	            //出版商，用于查找
	Date PublishDate;          //出版日期，用于查找
	string BriefIntroduction;     //该书内容简介
	int i_o=0;                      //判断书是否借出，0为在架，1为借出
	Book *next;                  //指向下一个节点的指针
	public:
	void operator =(const Book &obj){
		this->BookName=obj.BookName;
		this->BriefIntroduction=obj.BriefIntroduction;
		this->i_o=obj.i_o;
		this->ISBN=obj.ISBN;
		this->Writer=obj.Writer;
		this->Publisher=obj.Publisher;
		this->PublishDate=obj.PublishDate;
	}         //运算符重载
	friend ostream &operator<<(ostream &out,Book &b){
		out<<"书名为："<<b.BookName<<"；ISBN号为："<<b.ISBN<<"；作者为："<<b.Writer<<"；出版商为："<<b.Publisher<<"；出版日期为："<<b.PublishDate<<"；内容简介："<<b.BriefIntroduction<<endl;
		return out;
	}
	friend istream &operator>>(istream &in,Book &b){
		in>>b.BookName>>b.ISBN>>b.Writer>>b.Publisher>>b.PublishDate>>b.BriefIntroduction>>b.i_o;
		return in;
	}
	Book(){

	}
	void set(){
		cout<<"请输入书名："<<endl;
		string BookName;
		cin>>BookName;
		this->BookName=BookName;
		cout<<"请输入ISBN号:"<<endl;
		string ISBN;
		cin>>ISBN;
		this->ISBN=ISBN;
		cout<<"请输入作者名:"<<endl;
		string Writer;
		cin>>Writer;
		this->Writer=Writer;
		cout<<"请输入出版商："<<endl;
		string Publisher;
		cin>>Publisher;
		this->Publisher=Publisher;
		cout<<"请输入出版日期："<<endl;
		Date PublishDate;
		cin>>PublishDate;
		this->PublishDate=PublishDate;
		cout<<"请输入内容简介"<<endl;
		string BriefIntroduction;
		cin>>BriefIntroduction;
		this->BriefIntroduction=BriefIntroduction;
	}
};
#endif