#ifndef _BOOKLIST_H_
#define _BOOKLIST_H_
#include <iostream>
#include <string>
#include <fstream>
#include "Book.h"
using namespace std;
Book b;
class BookList   
{
	private:
	Book *head;
	Book *node;  //定义两个Book指针，head为头指针，node为活动指针
	public:
	BookList(){
		head=&b;
		head->next=nullptr;                                 //构造函数，使指针初始化
	}
	void save_file(){
    	string filePath = "D:\\system of book management\\src\\book.txt";
    	ofstream fout;
    	fout.open(filePath);
		if(!fout.is_open()){
			cout<<"文件打开失败。"<<endl;
		}
    	Book *p;
		p=head->next;
		while(p!=nullptr){
			Book data;
			data=*p;
			fout<<data.BookName<<" "<<data.ISBN<<" "<<data.Writer<<" "<<data.Publisher<<" "<<data.PublishDate.year<<" "<<data.PublishDate.month<<" "<<data.PublishDate.day<<" "<<data.BriefIntroduction<<" "<<data.i_o<<endl;
			p=p->next;
		}
    	fout.close();
	};                       //存储文件
	void load_file(){
		string filepath="D:\\system of book management\\src\\book.txt";
    	ifstream fin;
    	fin.open(filepath);
		if(!fin.is_open()){
			cout<<"文件打开失败。"<<endl;
		}
		Book *p;
		p=head;
		Book data;
		while(fin>>data){
			node=new Book;
			*node=data;
			p->next=node;
			p=node;
		}
		p->next=nullptr;
    	fin.close();
	};                       //上传文件
	void AddNewBook(Book obj){
		Book *p;
		p=head;
		while(p->next!=nullptr){
			p=p->next;
		}
		node=new Book;
		*node=obj;
		p->next=node;
		node->next=nullptr;
	}                            //添加新书
	int borrow_book(string bookname){
		Book *p;
		p=head->next;
		while(p!=nullptr){
			if(bookname==p->BookName){
				if(p->i_o==0){
					int a=p->i_o;
					return a;
					break;
				}
				else if(p->i_o==1){
					cout<<"该书已借出。"<<endl;
					return 2;
					break;
				}
			}
			p=p->next;
		}
		if(p==nullptr){
			cout<<"该书不在书架中。"<<endl;
		}
		return 2;
	};                  //借书手续
	void i_oBorrow(string bookname){
		Book *p;
		p=head->next;
		while(p!=nullptr){
			if(bookname==p->BookName){
				p->i_o=1;
				break;
			}
			p=p->next;
		}
		if(p==nullptr){
			cout<<"该书不在书架中。"<<endl;
		}
	}
	void i_oReturn(string bookname){
		Book *p;
		p=head->next;
		while(p!=nullptr){
			if(bookname==p->BookName){
				p->i_o=0;
				break;
			}
			p=p->next;
		}
		if(p==nullptr){
			cout<<"该书不在书架中。"<<endl;
		}
	}
	int return_book(string bookname){
		Book *p;
		p=head->next;
		while(p!=nullptr){
			if(bookname==p->BookName){
				if(p->i_o==1){
					int a=p->i_o;
					return a;
					break;
				}
				else if(p->i_o==0){
					cout<<"该书在架。"<<endl;
					return 2;
					break;
				}
			}
			p=p->next;
		}
		if(p==nullptr){
			cout<<"该书不在书架中。"<<endl;
		}
		return 2;
	};                   //还书手续
	int search_ISBN(string ISBN){
		Book *p;
		p=head->next;
		while(p!=nullptr){
			if(ISBN==p->ISBN){
				cout<<*p;
				return p->i_o;
			}
			p=p->next;
		}
		int a=2;
		return a;
	};               //按ISBN号查找图书
	int search_BookName(string BookName){
		Book *p;
		p=head->next;
		while(p!=nullptr){
			if(BookName==p->BookName){
				cout<<*p;
				return p->i_o;
			}
			p=p->next;
		}
		int a=2;
		return a;
	};           //按书名查找图书
	int search_Writer(string Writer){
		Book *p;
		p=head->next;
		while(p!=nullptr){
			if(Writer==p->Writer){
				cout<<*p;
				return p->i_o;
			}
			p=p->next;
		}
		int a=2;
		return a;
	};               //按作者名查找图书
	int search_Publisher(string Publisher){
		Book *p;
		p=head->next;
		while(p!=nullptr){
			if(Publisher==p->Publisher){
				cout<<*p;
				return p->i_o;
			}
			p=p->next;
		}
		int a=2;
		return a;
	};            //按出版商查找图书
	int search_PublishDate(Date PublishDate){
		Book *p;
		p=head->next;
		while(p!=nullptr){
			if(PublishDate==p->PublishDate){
				cout<<*p;
				return p->i_o;
			}
			p=p->next;
		}
		int a=2;
		return a;

	};          //按出版日期查找图书
	void search(){
		cout<<"*******************输入数字以对应以下的选项以进行查询************************"<<endl;
		cout<<"*******************1.按ISBN号进行查询**************************************"<<endl;
		cout<<"*******************2.按书名进行查询*****************************************"<<endl;
		cout<<"*******************3.按作者名进行查询***************************************"<<endl;
		cout<<"*******************4.按出版商进行查询***************************************"<<endl;
		cout<<"*******************5.按出版日期进行查询*************************************"<<endl;
		int num;
		int n;
		cin>>num;
		if(num==1){
			string ISBN;
			cout<<"请输入你要查询的书籍的ISBN号"<<endl;
			cin>>ISBN;
			n=this->search_ISBN(ISBN);
			if(n==0){
				cout<<"该书在架。"<<endl;
			}
			else if(n==1){
				cout<<"该书已借出。"<<endl;
			}
			else if(n==2){
				cout<<"该书不在书架中。"<<endl;
			}
		}
		else if(num==2){
			string BookName;
			cout<<"请输入你要查询的书籍的书名"<<endl;
			cin>>BookName;
			n=this->search_BookName(BookName);
			if(n==0){
				cout<<"该书在架。"<<endl;
			}
			else if(n==1){
				cout<<"该书已借出。"<<endl;
			}
			else if(n==2){
				cout<<"该书不在书架中。"<<endl;
			}
		}
		else if(num==3){
			string Writer;
			cout<<"请输入你要查询的书籍的作者名"<<endl;
			cin>>Writer;
			n=this->search_Writer(Writer);
			if(n==0){
				cout<<"该书在架。"<<endl;
			}
			else if(n==1){
				cout<<"该书已借出。"<<endl;
			}
			else if(n==2){
				cout<<"该书不在书架中。"<<endl;
			}
		}
		else if(num==5){
			Date PublishDate;
			cout<<"请输入你要查询的书籍的出版日期"<<endl;
			cin>>PublishDate;
			n=this->search_PublishDate(PublishDate);
			if(n==0){
				cout<<"该书在架。"<<endl;
			}
			else if(n==1){
				cout<<"该书已借出。"<<endl;
			}
			else if(n==2){
				cout<<"该书不在书架中。"<<endl;
			}
		}
		else if(num==4){
			string Publisher;
			cout<<"请输入你要查询的书籍的出版商"<<endl;
			cin>>Publisher;
			n=this->search_Publisher(Publisher);
			if(n==0){
				cout<<"该书在架。"<<endl;
			}
			else if(n==1){
				cout<<"该书已借出。"<<endl;
			}
			else if(n==2){
				cout<<"该书不在书架中。"<<endl;
			}
		}
	};                         //进入查找菜单
	void show_content(int i){
		Book *p;
		int n;
		n=1;
		p=head->next;
		while(p!=nullptr){
			if(n==i){
				cout<<*p;
			}
			n++;
			p=p->next;
		}
	};               //显示某本书的内容
		void deleteAll(){
		Book *p1,*p2;
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
	void show_all(){
		Book *p;
		p=head->next;
		while(p!=nullptr){
			if(p->i_o==0){
				cout<<*p;
			}
			p=p->next;
		}
	};                       //显示所有库存的未被借出的图书
	void delete_onebook(){
		cout<<"*****************************输入数字以对应以下的选项以进行删除************************"<<endl;
		cout<<"*****************************1.按ISBN号进行删除**************************************"<<endl;
		cout<<"*****************************2.按书名进行删除*****************************************"<<endl;
		cout<<"*****************************3.按作者名进行删除***************************************"<<endl;
		cout<<"*****************************4.按出版商进行删除***************************************"<<endl;
		cout<<"*****************************5.按出版日期进行删除*************************************"<<endl;
		int num;
		Book *p1,*p2;
		cin>>num;
		if(num==1){
			string ISBN;
			cout<<"请输入你要删除的书籍的ISBN号"<<endl;
			cin>>ISBN;
			p1=head;
			p2=p1->next;
			while(p2!=nullptr){
				if(p2->ISBN==ISBN){
					p1->next=p2->next;
					delete p2;
					p2=p1->next;
				}
				if(p2==nullptr){
					break;
				}
				p1=p1->next;
				p2=p1->next;
			}
		}
		else if(num==2){
			string BookName;
			cout<<"请输入你要查询的书籍的书名"<<endl;
			cin>>BookName;
			p1=head;
			p2=p1->next;
			while(p2!=nullptr){
				if(p2->BookName==BookName){
					p1->next=p2->next;
					delete p2;
					p2=p1->next;
				}
				if(p2==nullptr){
					break;
				}
				p1=p1->next;
				p2=p1->next;
			}
		}
		else if(num==3){
			string Writer;
			cout<<"请输入你要查询的书籍的作者名"<<endl;
			cin>>Writer;
			p1=head;
			p2=p1->next;
			while(p2!=nullptr){
				if(p2->Writer==Writer){
					p1->next=p2->next;
					delete p2;
					p2=p1->next;
				}
				if(p2==nullptr){
					break;
				}
				p1=p1->next;
				p2=p1->next;
			}
		}
		else if(num==4){
			Date PublishDate;
			cout<<"请输入你要查询的书籍的出版日期"<<endl;
			cin>>PublishDate;
			p1=head;
			p2=p1->next;
			while(p2!=nullptr){
				if(p2->PublishDate==PublishDate){
					p1->next=p2->next;
					delete p2;
					p2=p1->next;
				}
				if(p2==nullptr){
					break;
				}
				p1=p1->next;
				p2=p1->next;
			}
		}
		else if(num==5){
			string Publisher;
			cout<<"请输入你要查询的书籍的出版商"<<endl;
			cin>>Publisher;
			p1=head;
			p2=p1->next;
			while(p2!=nullptr){
				if(p2->Publisher==Publisher){
					p1->next=p2->next;
					delete p2;
					p2=p1->next;
				}
				if(p2==nullptr){
					break;
				}
				p1=p1->next;
				p2=p1->next;
			}
		}
	};                 //删除某本书
	void change_content(){
		cout<<"*******************输入数字以对应以下的选项以进行修改************************"<<endl;
		cout<<"*******************1.按ISBN号进行修改**************************************"<<endl;
		cout<<"*******************2.按书名进行修改*****************************************"<<endl;
		cout<<"*******************3.按作者名进行修改***************************************"<<endl;
		cout<<"*******************4.按出版商进行修改***************************************"<<endl;
		cout<<"*******************5.按出版日期进行修改*************************************"<<endl;
		int num;
		int n;
		cin>>num;
		if(num==1){
			string ISBN;
			cout<<"请输入你要查询的书籍的ISBN号"<<endl;
			cin>>ISBN;
			Book *p;
			p=head;
			while(p!=nullptr){
				if(ISBN==p->ISBN){
					Book b;
					cout<<"请输入修改书籍的信息"<<endl;
					b.set();
					*p=b;
					break;
				}
				p=p->next;
			}
			if(p==nullptr){
				cout<<"该书不在书架中。"<<endl;
			}
		}
		else if(num==2){
			string BookName;
			cout<<"请输入你要查询的书籍的书名"<<endl;
			cin>>BookName;
			Book *p;
			p=head;
			while(p!=nullptr){
				if(BookName==p->BookName){
					Book b;
					cout<<"请输入修改书籍的信息"<<endl;
					b.set();
					*p=b;
					break;
				}
				p=p->next;
			}
			if(p==nullptr){
				cout<<"该书不在书架中。"<<endl;
			}
		}
		else if(num==3){
			string Writer;
			cout<<"请输入你要查询的书籍的作者名"<<endl;
			cin>>Writer;
			Book *p;
			p=head;
			while(p!=nullptr){
				if(Writer==p->Writer){
					Book b;
					cout<<"请输入修改书籍的信息"<<endl;
					b.set();
					*p=b;
					break;
				}
				p=p->next;
			}
			if(p==nullptr){
				cout<<"该书不在书架中。"<<endl;
			}
		}
		else if(num==4){
			Date PublishDate;
			cout<<"请输入你要查询的书籍的出版日期"<<endl;
			cin>>PublishDate;
			Book *p;
			p=head;
			while(p!=nullptr){
				if(PublishDate==p->PublishDate){
					Book b;
					cout<<"请输入修改书籍的信息"<<endl;
					b.set();
					*p=b;
					break;
				}
				p=p->next;
			}
			if(p==nullptr){
				cout<<"该书不在书架中。"<<endl;
			}
		}
		else if(num==5){
			string Publisher;
			cout<<"请输入你要查询的书籍的出版商"<<endl;
			cin>>Publisher;
			Book *p;
			p=head;
			while(p!=nullptr){
				if(Publisher==p->Publisher){
					Book b;
					cout<<"请输入修改书籍的信息"<<endl;
					b.set();
					*p=b;
					break;  
				}
				p=p->next;
			}
			if(p==nullptr){
				cout<<"该书不在书架中。"<<endl;
			}
		}
	};                 //更改某本书的信息
	void GoInto_BookInfo();                //进入书库信息菜单
};
#endif