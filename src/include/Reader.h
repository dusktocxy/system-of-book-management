#ifndef _READER_H_
#define _READER_H_
#include <iostream>
#include <string>
using namespace std;
class Reader{ //存储读者信息类
    public:
    Reader(){
    }                       //构造函数
    void set(){
        cout<<"请输入您的姓名："<<endl;
        string ReaderName;
        cin>>ReaderName;
        this->ReaderName=ReaderName;
        cout<<"请输入您的密码："<<endl;
        string password;
        cin>>password;
        this->Password=password;
    }
    void operator =(const Reader &obj){
        this->ReaderName=obj.ReaderName;
        this->Password=obj.Password;
        this->book1=obj.book1;
        this->book2=obj.book2;
        this->y_n=obj.y_n;
    }
	friend ostream &operator<<(ostream &out,Reader &b){
		out<<"姓名为"<<b.getReaderName()<<"；密码为"<<b.getPassword()<<"，";
        return out;
	}
    friend istream &operator>>(istream &in,Reader &b){
        in>>b.ReaderName>>b.Password>>b.y_n>>b.book1>>b.book2;
        return in;
    }
    string getReaderName(){
        return this->ReaderName;
    }
    string getPassword(){
        return this->Password;
    }
    string getBook1(){
        return this->book1;
    }
    string getBook2(){
        return this->book2;
    }
    int getY_N(){
        return this->y_n;
    }
    void book1set(string book1){
        this->book1=book1;
    }
    void book2set(string book2){
        this->book2=book2;
    }
    void show(){
        if(this->y_n==0){
            cout<<"读者的姓名为："<<this->ReaderName<<"，读者的密码为："<<this->Password<<"，读者借的书有：无"<<endl;
        }
        else if(this->y_n==1){
            cout<<"读者的姓名为："<<this->ReaderName<<"，读者的密码为："<<this->Password<<"，读者借的书有："<<"《"<<this->book1<<"》"<<endl;
        }
        else{
            cout<<"读者的姓名为："<<this->ReaderName<<"，读者的密码为："<<this->Password<<"，读者借的书有："<<"《"<<this->book1<<"》，《"<<this->book2<<"》"<<endl;
        }
    }
    void Change_Password(){
        cout<<"请输入您修改的密码："<<endl;
        string password;
        cin>>password;
        this->Password=password;
    }
    protected:
	string ReaderName;         //读者姓名
	string Password;            //密码
	string book1="a";
    string book2="a";		//每人最多借两本书，可以根据需要增减限额
    public: 
    Reader *next;                 //指向下一节点的指针
    int y_n=0;                      //记录借的书的数目，0为没有借书，1为借了一本
};
#endif