#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <ctime>
#include <math.h>

using namespace std;

int main()
{
    while(true){
        int total=0;
        time_t now = time(0);
        char* dt = ctime(&now);
        ifstream dep("deposit.txt");
        string line;
        if(dep.is_open())
        {
            cout << "Deposits:>>>\n" << endl;
            while ( getline (dep,line) )
                {
                  cout << line << '\n';
                  getline(dep,line);
                  cout << line << " LE" <<endl;
                    total+=atoi(line.c_str());
                }
            dep.close();
        }
        ifstream wthdrw("withdraw.txt");
        if(wthdrw.is_open())
        {
            cout << "----------------"<<endl;
            cout << "\nWithdrawals:>>>\n" << endl;
            while ( getline (wthdrw,line) )
                {
                  cout << line << '\n';
                  getline(wthdrw,line);
                  cout << line << " LE" <<endl;
                  total-=atoi(line.c_str());
                }
            wthdrw.close();
        }
        cout << "\n----------------\nAllowable: " << total <<" LE <<<\n";
        cout << "\nThe local date and time is: " << dt;
        cout << "----------------\nEnter Amount:\n" ;
        int price=0;
        string reason="";
        cin >> price;
        while(cin.fail())
        {
            cout << "Enter a Number!!"<<endl;
            cin.clear();
            cin.ignore(256,'\n');
            cin >> price;
        }
        cin.sync();
        if(price>=0)
        {
            cout << "Enter Deposit Reason:\n";
            getline(cin,reason);
            ofstream deposit("deposit.txt", std::ios_base::app | std::ios_base::out);
            if(deposit.is_open())
                {
                    deposit << reason << "\n" << price << "\n" ;
                    deposit.close();
                }
        }
        else
        {
            cout << "Enter Withdrawal Reason:" << endl;
            getline(cin,reason);
            ofstream withdraw("withdraw.txt", std::ios_base::app | std::ios_base::out);
            if(withdraw.is_open())
                {

                    withdraw << reason << "\n" << abs(price) << "\n" ;
                    withdraw.close();
                }
        }
        cout <<"----------------\n"<<endl;
    }
    return 0;
}
