#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
#include<time.h>
#include <string>
using namespace std;
//fix rand(), not actually random?
//making sure no category appears more than half of the time
class Pass{
public:
    Pass(){
        total++;
        for(int j = 0; j < 10; j++){nums.push_back('0'+j);}
        for(int i = 0; i < 26; i++){
            alphas.first.push_back('a'+i);
            alphas.second.push_back('A'+i);
        }
        algorithm();
        }
    ~Pass(){};
    void renew(){total++; algorithm(); size = ps.size();};
    void algorithm(){
        srand(time(0)+total);
        size = 18+( rand()*rand()%8);
        ps = "";
        int num = 0; int al = 0; int sym = 0;
        int r = 0;
        for(int i = 0; i < size; i++){
            r = ( rand()*rand()%4);
            if(r == 0 || r == 1){
                if(al < (size+1)/2){
                    int t =  rand()*rand()%2;
                    int f =  rand()*rand()%26;
                    if(t==0){ps+=alphas.first[f];}else{ps+=alphas.second[f];}
                    al++;
                }else{
                    int ok =  rand()*rand()%2;
                    if(ok == 0){
                        int t =  rand()*rand()%10;
                        ps+=nums[t];
                        num++;
                    }else{
                        int t =  rand()*rand()%symbols.size();
                        ps+=symbols[t];
                        sym++;
                    }
                }
            }else if(r == 2){
                if(num < (size+1)/2){
                    int t =  rand()*rand()%10;
                    ps+=nums[t];
                    num++;
                }else{
                    int ok =  rand()*rand()%3;
                    if(ok < 2){
                        int t =  rand()*rand()%2;
                        int f =  rand()*rand()%26;
                        if(t==0){ps+=alphas.first[f];}else{ps+=alphas.second[f];}
                        al++;
                    }else{
                        int t =  rand()*rand()%symbols.size();
                        ps+=symbols[t];
                        sym++;
                    }
                }
            }else{
                if(sym < (size+1)/2){
                    int t =  rand()*rand()%symbols.size();
                    ps+=symbols[t];
                }else{
                    int ok =  rand()*rand()%3;
                    if(ok < 2){
                        int t =  rand()*rand()%2;
                        int f =  rand()*rand()%26;
                        if(t==0){ps+=alphas.first[f];}else{ps+=alphas.second[f];}
                        al++;
                    }else{
                        int t =  rand()*rand()%10;
                        ps+=nums[t];
                        num++;
                    }
                }
            }
        }

    }
    char &operator[](int i) throw(out_of_range){ //starting from 1
        if(i> size || i <= 0){throw out_of_range("invalid_index");}
        return ps[i-1];
    }
    Pass &operator=(const Pass &p){
        size = p.size;
        ps = p.ps;
        return *this;
    }
    friend ostream &operator<<(ostream &out, const Pass &p){
        out << p.ps;
        return out;

    }
    int siz(){
        return size;
    }
private:
   string ps;
   int size;
   int numbers;
   int alphabes;
   int symbolss;
   vector<char> nums; //0-9
   pair<vector<char>, vector<char>> alphas; //lower and upper
   vector<char> symbols = {'!', '?', '@', '%', '&', '*', '(', ')'}; //symbols; //symbols
   static int total;
};

int Pass::total = 0;
int main() {
    cout << "Enter number of passwords: " << "\n";
    int t;
    cin >> t;
    while(t--) {
        Pass s;
        cout << "Size: " << s.siz() << "\n";
        cout << "Pass: " << s << "\n";

    }

    return 0;
}
