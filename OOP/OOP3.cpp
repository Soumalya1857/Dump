#include<bits/stdc++.h>
using namespace std;


class Base{
    public:
        Base(){
            cout<< "Base Constructor\n";
        }

        virtual ~Base(){
            cout<< "Base Destructor\n";
        }
};

class Derived : public Base{
    public:
        Derived(){
            cout<< "Derived Constructor\n";
        }

        ~Derived(){
            cout<< "Derived Destructor\n";
        }
};

int main()
{
    Base *bptr = new Derived();
    delete bptr;
    return 0;
}