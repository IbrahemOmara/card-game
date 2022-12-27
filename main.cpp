#include <bits/stdc++.h>
using namespace std;

class Cards
{
    public: 
        string name="";
        int power, defense, stars;
        virtual void setHealth(int attack) = 0;
        virtual void get() = 0;
};

class Bomba: public Cards
{
    public: 
        Bomba()
        {
            name="Bomba";
            cout << setw(10) << "★★★ Bomba has been summoned ★★★\n\n";
            power = 500;
            defense = 50;
            stars = 3;
        }

        void setHealth(int attack)
        {
            cout << "Bomba's health has been dropped from " << defense;
            defense -= attack;
            defense = defense < 0 ? defense = 0: defense;
            cout << " to " << defense << "\n";
        }
        void get()
        {
            cout << "His name is BOMBA!!\n";
            cout << "Current Health: " << defense << "\n";
            cout << "Attack Power: " << power << "\n";
            cout << "Stars: " << stars << "\n";
        }

        ~Bomba()
        {
            if(defense <= 0) cout << "Bomba has been destroyed\n\n";
            else cout << "Bomba has been sacrificed\n";
        }
};



int main()
{
    cout << "You summoned a monster: \n";
    Bomba * us = new Bomba;
    cout << "Enemy has summoned a monster: \n";
    Bomba * monster2 = new Bomba;
    cout << "Enemy has decided to attack!\n";
    cout << us->name << " has been attacked by opposing " << monster2->name << "\n";
    us->setHealth(monster2->power);
    if(us->defense <= 0) delete us;
}   
