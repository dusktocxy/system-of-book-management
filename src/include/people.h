#ifndef _PEOPLE_H_
#define _PEOPLE_H_
#include <iostream>
#include <string>
#include "Date.h"
using namespace std;
class people
{
public:
	people(){
	}  //people类的构造函数
	friend ostream & operator <<(ostream &out,people &p){
		out<<"姓名："<<p.name<<",性别："<<p.sex<<",身份证号："<<p.id<<",电话号码："<<p.telephone<<",出生日期："<<p.birthday<<",工作证号："<<p.number<<",家庭地址："<<p.address<<",薪水："<<p.salary<<",职务："<<p.post<<",工作部门："<<p.department<<endl;
		return out;
	}   //重载“〈〈”
	friend istream & operator >>(istream &in,people &p){
		in>>p.name>>p.sex>>p.id>>p.telephone>>p.birthday>>p.number>>p.address>>p.salary>>p.post>>p.department;
		return in;
	}   //重载“〈〈”
	void operator =(const people &p){
		this->name=p.name;
		this->sex=p.sex;
		this->id=p.id;
		this->telephone=p.telephone;
		this->birthday=p.birthday;
		this->number=p.number;
		this->address=p.address;
		this->salary=p.salary;
		this->post=p.post;
		this->department=p.department;
	}   //重载“=”
	void set(){
		cout<<"请输入你的姓名："<<endl;
		string name;
		cin>>name;
		this->name=name;
		cout<<"请输入你的性别："<<endl;
		string sex;
		cin>>sex;
		this->sex=sex;
		cout<<"请输入你的身份证号："<<endl;
		string id;
		cin>>id;
		this->id=id;
		cout<<"请输入你的电话号码："<<endl;
		string telephone;
		cin>>telephone;
		this->telephone=telephone;
		cout<<"请输入你的出生日期："<<endl;
		Date birthday;
		cin>>birthday;
		this->birthday=birthday;
		cout<<"请输入你的工作证号："<<endl;
		string number;
		cin>>number;
		this->number=number;
		cout<<"请输入你的家庭住址："<<endl;
		string address;
		cin>>address;
		this->address=address;
		cout<<"请输入你的薪水："<<endl;
		string salary;
		cin>>salary;
		this->salary=salary;
		cout<<"请输入你的职务："<<endl;
		string post;
		cin>>post;
		this->post=post;
		cout<<"请输入你的工作部门："<<endl;
		string department;
		cin>>department;
		this->department=department;
	}   //people类的设置函数
	string getname(){
		return this->name;
	}   //获得姓名
	string getsex(){
		return this->sex;
	}   //获得性别
	string getid(){
		return this->id;
	}   //获得id
	string gettelephone(){
		return this->telephone;
	}   //获得电话号码
	Date getbirthday(){
		return this->birthday;
	}   //获得生日
	string getnumber(){
		return this->number;
	}   //获得工作证号
	string getaddress(){
		return this->address;
	}
	string getsalary(){
		return this->salary;
	}
	string getpost(){
		return this->post;
	}
	string getdepartment(){
		return this->department;
	}
	void setname(string name){
		this->name=name;
	}   //设置姓名
	void setsex(string sex){
		this->sex=sex;
	}   //设置性别
	void setid(string id){
		this->id=id;
	}   //设置id 
	void setnumber(string number){
		this->number=number;
	}   //设置工作证号
	void setaddress(string address){
		this->address=address;
	}   //设置家庭地址
	void settelephone(string telephone){
		this->telephone=telephone;
	}   //设置电话号码
	void setbirthday(Date birthday){
		this->birthday=birthday;
	}   //设置出生日期
	void setsalary(string salary){
		this->salary=salary;
	}   //设置薪水
	void setpost(string post){
		this->post=post;
	}   //设置职务
	void setdepartment(string department){
		this->department=department;
	}   //设置工作部门
protected:
	string name;      //姓名
	string sex;         //性别
	string id;         //身份证号
	string telephone;   //电话号码
	Date birthday;         //出生日期
	string number;      //工作证号
	string address;      //家庭地址
	string salary;        //薪水
	string post;         //职务
	string department;   //工作部门
public:
	people *next;       //下一个节点
};
#endif // _PEOPLE_H_