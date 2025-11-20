#include<iostream>
#include<string>
#include "BookList.h"
#include "peoplelist.h"
#include "ReaderList.h"
using namespace std;
int main(){
    cout<<"**********************************************************************************"<<endl;
    cout<<"**********************************************************************************"<<endl;
    cout<<"**********************************************************************************"<<endl;
    cout<<"***********************************图书管理系统***********************************"<<endl;
    cout<<"**********************************************************************************"<<endl;
    cout<<"**********************************************************************************"<<endl;
    cout<<"**********************************************************************************"<<endl;
    peoplelist pl;
    ReaderList rl;
    BookList bl;
    pl.load();
    rl.load_readerfile();
    bl.load_file();
    while(true){
        cout<<"请选择模块：1.员工管理模块，2.图书管理模块，3.读者管理模块，4.退出系统，5.使用说明"<<endl;
        int num;
        cin>>num;
        if(num==1){
            while(true){
                cout<<"请选择以下功能：1.添加信息，2.删除信息，3.清空信息，4.修改信息，5.显示信息，6.查找信息，7.返回上一级。"<<endl;
                int n;
                cin>>n;
                if(n==1){
                    people p;
                    p.set();
                    pl.add(p);
                }
                else if(n==2){
                    pl.remove();
                }
                else if(n==3){
                    pl.deleteAll();
                }
                else if(n==4){
                    pl.modify();
                }
                else if(n==5){
                    pl.display();
                }
                else if(n==6){
                    pl.find();
                }
                else if(n==7){
                    break;
                }
            }
        }
        else if(num==2){
            while(true){
                cout<<"请选择以下功能：1.新书入库，2.查找书籍，3.删除书籍，4.修改书籍，5.显示全部在架书籍，6.清空全部书籍，7.返回上一级。"<<endl;
                int n;
                cin>>n;
                if(n==1){
                    Book b;
                    b.set();
                    bl.AddNewBook(b);
                }
                else if(n==2){
                    bl.search();
                }
                else if(n==3){
                    bl.delete_onebook();
                }
                else if(n==4){
                    bl.change_content();
                }
                else if(n==5){
                    bl.show_all();
                }
                else if(n==6){
                    bl.deleteAll();
                }
                else if(n==7){
                    break;
                }
            }
        }
        else if(num==3){
            while(true){
                cout<<"1.读者注册，2.登录查看，3.修改密码，4.注销读者，5.清除全部读者信息，6.查看帮助，7借书，8.还书，9.返回上一级"<<endl;
                int n;
                cin>>n;
                if(n==1){
                    Reader r;
                    r.set();
                    rl.reader_register(r);
                }
                else if(n==2){
                    rl.reader_land();
                }
                else if(n==3){
                    rl.change_password();
                }
                else if(n==4){
                    rl.delete_reader();
                }
                else if(n==5){
                    rl.deleteAll();
                }
                else if(n==6){
			        cout<<"*****************读者注册可用以注册借书。***************************"<<endl;
			        cout<<"*****************登录查看可用以查看借书情况。***********************"<<endl;
			        cout<<"*****************修改密码可用以改写自己的密码。**********************"<<endl;
			        cout<<"*****************注销读者可以删除某个读者的信息。********************"<<endl;
			        cout<<"*****************清楚全部可以删除全部读者的信息。********************"<<endl;
                }
                else if(n==7){
                    cout<<"请输入你要借的书的名字:"<<endl;
		            string bookname;
		            cin>>bookname;
                    int a;
                    a=bl.borrow_book(bookname);
                    if(a==0){
                        int b;
                        b=rl.borrow(bookname);
                        if(b==1){
                            bl.i_oBorrow(bookname);
                        }
                    }
                }
                else if(n==8){
                    cout<<"请输入你要还的书的名字："<<endl;
                    string bookname;
                    cin>>bookname;
                    int a;
                    a=bl.return_book(bookname);
                    if(a==1){
                        int b=rl.Return(bookname);
                        if(b==1){
                            bl.i_oReturn(bookname);
                        }
                    }
                }
                else if(n==9){
                    break;
                }
            }
        }
        else if(num==4){
            bl.save_file();
            pl.save();
            rl.save_readerfile();
            break;
        }
        else if(num==5){
            cout<<"本系统主要用于图书管理，员工信息管理和读者信息管理，选择与选项对应的数字即可使用此功能。"<<endl;
        }
    }
    system("pause");
    return 0;
}