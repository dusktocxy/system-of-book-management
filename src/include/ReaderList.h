#ifndef _READERLIST_H_
#define _READERLIST_H_
#include <iostream>
#include <string>
#include <fstream>
#include "Reader.h"
using namespace std;
Reader r;
class ReaderList
{
	public:
	ReaderList(){   //构造函数，使指针初始化
	head=&r;
    head->next=nullptr;
	}
	void save_readerfile(){
    	string filePath = "D:\\system of book management\\src\\reader.txt";
    	ofstream fout;
    	fout.open(filePath);
		if(!fout.is_open()){
			cout<<"文件打开失败。"<<endl;
		}
    	Reader *p;
		p=head->next;
		while(p!=nullptr){
			Reader data;
			data=*p;
			fout<<data.getReaderName()<<" "<<data.getReaderName()<<" "<<data.getY_N()<<" "<<data.getBook1()<<" "<<data.getBook2()<<endl;
			p=p->next;
		}
    	fout.close();
    };             //存储文件
	void load_readerfile(){
		string filepath="D:\\system of book management\\src\\reader.txt";
    	ifstream fin;
    	fin.open(filepath);
		if(!fin.is_open()){
			cout<<"文件打开失败。"<<endl;
			exit(0);
		}
		Reader *p;
		p=head;
		Reader data;
		while(fin>>data){
			node=new Reader;
			*node=data;
			p->next=node;
			p=node;
		}
		p->next=nullptr;
    	fin.close();
	};             //上传文件
	void reader_register(Reader obj){
		Reader *p;
		p=head;
		while(p->next!=nullptr){
			p=p->next;
		}
		node=new Reader;
		*node=obj;
		p->next=node;
		node->next=nullptr;
    };             //读者注册
	void reader_land(){
		cout<<"请输入你的姓名:"<<endl;
		string name;
		cin>>name;
		cout<<"请输入你的密码:"<<endl;
		string password;
		cin>>password;
		Reader *p;
		p=head->next;
		while(p!=nullptr){
			if(name==p->getReaderName()&&password==p->getPassword()){
				cout<<"登录成功"<<endl;
				if(p->getY_N()==0){
					cout<<"您目前并未借书"<<endl;
					break;
				}
				else if(p->getY_N()==1){
					cout<<"您借的书有："<<"《"<<p->getBook1()<<"》"<<endl;
					break;
				}
				else{
					cout<<"您借的书有："<<"《"<<p->getBook1()<<"》，《"<<p->getBook2()<<"》"<<endl;
					break;
				}
			}
			p=p->next;
		}
		if(p==nullptr){
			cout<<"姓名或密码错误。"<<endl;
		}
	};               //读者登录
	int search_ReaderName(string ReaderName){
        Reader *p;
        p=head->next;
        while(p!=nullptr){
            if(ReaderName==p->getReaderName()){
                return 1;
            }
        }
		return 0;
    };   //按姓名查找	
	void show_OneReader(int n){
        Reader *p;
		p=head->next;
		int i=1;
		while(p!=nullptr){
			if(n==i){
				p->show();
				break;
			}
			i++;
			p=p->next;
		}
		if(p==nullptr){
			cout<<"没有此读者。"<<endl;
		}
    };  //显示某读者信息
	void display(){
		Reader *p;
		p=head->next;
		while(p!=nullptr){
			p->show();
			p=p->next;
		}
	}
	void change_password(){
        string ReaderName;
		cout<<"请输入你的姓名"<<endl;
		cin>>ReaderName;
		string password;
		cout<<"请输入你的密码"<<endl;
		cin>>password;
        Reader *p;
        p=head->next;
        while(p!=nullptr){
            if(ReaderName==p->getReaderName()&&password==p->getPassword()){
                p->Change_Password();
				break;
            }
			p=p->next;
        }
		if(p==nullptr){
			cout<<"姓名或密码错误。"<<endl;
		}
    };          //修改密码
	void delete_reader(){
		Reader *p1,*p2;
		p1=head;
		p2=p1->next;
		cout<<"请输入你的姓名："<<endl;
		string name;
		cin>>name;
		cout<<"请输入你的密码:"<<endl;
		string password;
		cin>>password;
		while(p2!=nullptr){
			if(name==p2->getReaderName()&&password==p2->getPassword()){
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
	};             //读者注销
	int borrow(string book){
		Reader *p;
		cout<<"请输入你的名字:"<<endl;
		string name;
		cin>>name;
		cout<<"请输入你的密码:"<<endl;
		string password;
		cin>>password;
		p=head->next;
		while(p!=nullptr){
			if(name==p->getReaderName()&&password==p->getPassword()){
				if(p->y_n==0){
					p->book1set(book);
					p->y_n=1;
					return 1;
				}
				else if(p->y_n==1){
					p->book2set(book);
					p->y_n=2;
					return 1;
				}
				else{
					cout<<"你借书的数量已达上限"<<endl;
					return 0;
				}
			}
			p=p->next;
		}
		if(p==nullptr){
			cout<<"姓名或密码错误"<<endl;
		}
		return 0;
	}
	int Return(string book){
		Reader *p;
		cout<<"请输入你的名字:"<<endl;
		string name;
		cin>>name;
		cout<<"请输入你的密码:"<<endl;
		string password;
		cin>>password;
		p=head->next;
		string a="a";
		while(p!=nullptr){
			if(name==p->getReaderName()&&password==p->getPassword()){
				if(p->y_n==2){
					if(book==p->getBook2()){
						p->book2set(a);
					}
					else if(book==p->getBook1()){
						string b;
						b=p->getBook2();
						p->book1set(b);
						p->book2set(a);
					}
					p->y_n=1;
					return 1;
				}
				else if(p->y_n==1){
					p->book1set(a);
					p->y_n=0;
					return 1;
				}
				else{
					cout<<"你没有借书。"<<endl;
					return 0;
				}
			}
			p=p->next;
		}
		if(p==nullptr){
			cout<<"姓名或密码错误"<<endl;
		}
		return 0;
	}
	void GoInto_ReaderInfo(){
		cout<<"1.读者注册，2.登录查看，3.修改密码，4.注销读者，5.清除全部，6.查看帮助"<<endl;
		int num;
		cin>>num;
		if(num==1){
			Reader a;
			a.set();
			Reader *p;
			p=head;
			while(p->next!=nullptr){
				p=p->next;
			}
			node=new Reader;
			*node=a;
			p->next=node;
			node->next=nullptr;
		}
		else if(num==2){
			cout<<"请输入你的姓名:"<<endl;
			string name;
			cin>>name;
			cout<<"请输入你的密码:"<<endl;
			string password;
			cin>>password;
			Reader *p;
			p=head->next;
			while(p!=nullptr){
				if(name==p->getReaderName()&&password==p->getPassword()){
					cout<<"登录成功"<<endl;
					if(p->getY_N()==0){
						cout<<"您目前并未借书"<<endl;
						break;
					}
					else if(p->getY_N()==1){
						cout<<"您借的书有："<<"《"<<p->getBook1()<<"》"<<endl;
						break;
					}
					else{
						cout<<"您借的书有："<<"《"<<p->getBook2()<<"》，《"<<p->getBook2()<<"》"<<endl;
						break;
					}
				}
				p=p->next;
			}
			if(p==nullptr){
				cout<<"姓名或密码错误。"<<endl;
			}
		}
		else if(num==3){
			cout<<"请输入你的姓名:"<<endl;
			string name;
			cin>>name;
			cout<<"请输入你的密码:"<<endl;
			string password;
			cin>>password;
			Reader *p;
			p=head->next;
			while(p!=nullptr){
				if(name==p->getReaderName()&&password==p->getPassword()){
					p->Change_Password();
					break;
				}
				p=p->next;
			}
			if(p==nullptr){
				cout<<"姓名或密码错误。"<<endl;
			}
		}
		else if(num==4){
			this->delete_reader();
		}
		else if(num==5){
			head->next=nullptr;
		}
		else if(num==6){
			cout<<"*****************读者注册可用以注册借书。***************************"<<endl;
			cout<<"*****************登录查看可用以查看借书情况。***********************"<<endl;
			cout<<"*****************修改密码可用以改写自己的密码。**********************"<<endl;
			cout<<"*****************注销读者可以删除某个读者的信息。********************"<<endl;
			cout<<"*****************清楚全部可以删除全部读者的信息。********************"<<endl;
		}
	};        //读者信息菜单
	void deleteAll(){
		Reader *p1,*p2;
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
	}
	private:
	Reader *head;
	Reader *node;	  //定义两个Reader指针，head为头指针，node为活动指针
};
#endif