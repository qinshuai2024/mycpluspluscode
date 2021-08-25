#include<iostream>
#include<cstring>
#include<iomanip>
#include<cstdio>
using namespace std;


int soldier_HP[5];
char soldier_name[5][20] = { "iceman", "lion", "wolf", "ninja", "dragon" };
class player
{
private:
    int time, soldier_total, cur;//cur point to current specific soldier
    int HP;//health point
    char name[20];
    bool produce_end;//false represents no HP
    int soldier[5];//in the order of iceman、lion、wolf、ninja、dragon
public:
    int arr[5] = { 0, 1, 2, 3, 4 };//red sequence
    int arr2[5] = { 1, 4, 3, 0, 2 };//blue sequence
    player(const char* p, int n) :HP(n), time(-1), produce_end(true), soldier_total(0), cur(-1)
    {
        strcpy(name, p);
        if (strcmp(name, "blue") == 0)
        {
            for (int i = 0; i < 5; ++i)
                arr[i] = arr2[i];
        }
        memset(soldier, 0, sizeof(soldier));
    };
    int gettime()
    {
        return time;
    }
    bool run()
    {
        if (produce_end == false)
            return false;
        ++time;
        cur = (cur + 1) % 5;
        int t = arr[cur];
        if (HP >= soldier_HP[t])
        {
            HP -= soldier_HP[t];
            soldier[t]++;
            soldier_total++;
            cout << setfill('0') << setw(3) << time << ' ' << name << ' ' << soldier_name[t] <<
                ' ' << soldier_total << " born with strength " << soldier_HP[t] << ',' 
                << soldier[t] << ' ' <<soldier_name[t] << " in " << name << " headquarter" << endl;
            return true;
        }
        else
        {
            int i, t;
            for (i = 1; i < 5; ++i)
            {
                cur++;
                t = arr[cur % 5];
                if (HP >= soldier_HP[t])
                {
                    HP -= soldier_HP[t];
                    soldier[t]++;
                    soldier_total++;
                    cout << setfill('0') << setw(3) << time << ' ' << name << ' ' << soldier_name[t] <<
                        ' ' << soldier_total << " born with strength " << soldier_HP[t] << ',' << 
                        soldier[t] << ' ' <<soldier_name[t] << " in " << name << " headquarter" << endl;
                    return true;
                }


            }
            if (i == 5)
            {
                cout << setfill('0') << setw(3) << time << ' ' << name;
                cout << " headquarter stops making warriors" << endl;
                produce_end = false;
                return false;
            }
        }
    }
};
int main()
{
    int n, hp, cnt = 0;
    cin >> n;
    while (n--)
    {
        cin >> hp;
        player R("red", hp), B("blue", hp);
        cin >> soldier_HP[4] >> soldier_HP[3] >> soldier_HP[0] >> soldier_HP[1] >> soldier_HP[2];
        bool f[2];
        //f[0] = true;
        cout << "Case:" << ++cnt << endl;
        f[0] = R.run();
        f[1] = B.run();
        while (f[0] || f[1])
        {
            f[0] = R.run();
            f[1] = B.run();
        }
    }
    return 0;
}