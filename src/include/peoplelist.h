#ifndef _POEPLELIST_H_
#define _POEPLELIST_H_
#include <iostream>
#include <string>
#include <fstream>
#include "Date.h"
#include "people.h"
using namespace std;
class peoplelist
{
public:
	peoplelist(){
		head=new people;
		head->next=nullptr;
	}      //peoplelist类的构造函数
	void set(){

	}        //peoplelist类的设置函数
	void add(people obj){
		people *p;
		p=head;
		while(p->next!=nullptr){
			p=p->next;
		}
		node=new people;
		*node=obj;
		p->next=node;
		node->next=nullptr;
	}       //添加函数
	void display(){
		node=head->next;
		while(node!=nullptr){
			cout<<*node;
			node=node->next;
		}
	}    //显示函数
	void find(){
		people *p;
		p=head->next;
		cout<<"请输入你要查找人员的姓名："<<endl;
		string name;
		cin>>name;
		while(p!=nullptr){
			string s=p->getname();
			if(name.compare(s)==0){
				cout<<"已查找到。"<<endl;
				cout<<*p;
				break;
			}
			p=p->next;
		}
		if(p==nullptr){
			cout<<"未查找到。"<<endl;
		}
	}       //查找函数
	void deleteAll(){
		people *p1,*p2;
		p1=head;
		p2=p1->next;
		while(p2!=nullptr){
			p1->next=p2->next;
			delete p2;
			p2=p1->next;
			if(p2==nullptr){
				break;
			}
		}
	}   //清空函数
	void save(){
    	string filePath = "D:\\system of book management\\src\\people.txt";
    	ofstream fout;
    	fout.open(filePath);
		if(!fout.is_open()){
			cout<<"文件打开失败。"<<endl;
			exit(0);
		}
    	people *p;
		p=head->next;
		while(p!=nullptr){
			people data;
			data=*p;
			Date a=data.getbirthday();
			fout<<data.getname()<<" "<<data.getsex()<<" "<<data.getid()<<" "<<data.gettelephone()<<" "<<a.year<<" "<<a.month<<" "<<a.day<<" "<<data.getnumber()<<" "<<data.getaddress()<<" "<<data.getsalary()<<" "<<data.getpost()<<" "<<data.getdepartment()<<endl;
			p=p->next;
		}
    	fout.close();
	}       //写入文件
	void load(){
		string filepath="D:\\system of book management\\src\\people.txt";
    	ifstream fin;
    	fin.open(filepath);
		if(!fin.is_open()){
			cout<<"文件打开失败。"<<endl;
			exit(0);
		}
		people *p;
		p=head;
		people data;
		while(fin>>data){
			node=new people;
			*node=data;
			p->next=node;
			p=node;
		}
		p->next=nullptr;
    	fin.close();
	};       //读进内存
	void modify(){
		people *p=head->next;
		cout<<"请输入你要修改的员工的姓名："<<endl;
		string name;
		cin>>name;
		while(p!=nullptr){
			string s=p->getname();
			if(name.compare(s)==0){
				cout<<"请输入你要修改的信息："<<endl;
				people person;
				person.set();
				*p=person;
				break;
			}
			p=p->next;
		}
		if(p==nullptr){
			cout<<"没有此员工。"<<endl;
		}
	};     //修改函数
	void remove(){
		people *p1,*p2;
		p1=head;
		p2=p1->next;
		cout<<"请输入你要删除的员工的姓名："<<endl;
		string name;
		cin>>name;
		while(p2!=nullptr){
			string s=p2->getname();
			if(name.compare(s)==0){
				p1->next=p2->next;
				delete p2;
				p2=p1->next;
				break;
			}
			if(p2==nullptr){
				break;
			}
			p1=p1->next;
			p2=p1->next;
		}
	};     //删除函数
	public:
	people *head;     //链表头
	people *node;     //链表节点
};
#endif