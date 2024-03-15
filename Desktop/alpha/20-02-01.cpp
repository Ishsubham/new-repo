#include<iostream>
#include<vector>
#include<utility>
using namespace std;

void convertMooreToMealy(vector<pair<vector<int>,char> > &moore, vector<vector<pair<int,char> > > &mealy){
    int n = moore.size();
    for(int i=0;i<n;++i){
        mealy[i][0] = make_pair(moore[i].first[0], moore[moore[i].first[0]].second);
        mealy[i][1] = make_pair(moore[i].first[1], moore[moore[i].first[1]].second);
    }
}

int main() {
    int states;
    cout << "Enter the number of states in the Moore machine: ";
    cin >> states;
    vector<pair<vector<int>,char> > moore(states, pair<vector<int>,char>(vector<int>(2),'0'));
    for (int i = 0; i < states; ++i) {
        cout << "Enter transition of state " << i << " for input 0 : "; cin>>moore[i].first[0];
        cout << "Enter transition of state " << i << " for input 1 : "; cin>>moore[i].first[1];
        cout<< "Enter output for state "<<i<<" : "; cin>>moore[i].second;
    }
    vector<vector<pair<int,char> > > mealy(states,vector<pair<int,char> >(3));

    convertMooreToMealy(moore, mealy);
    cout<<"Mealy machine is:\n";
    cout<<"State\t0\t1\n";
    for(int i=0;i<states;++i){
        cout<<i<<"\t("<<mealy[i][0].first<<","<<mealy[i][0].second<<")\t"<<'('<<mealy[i][1].first<<","<<mealy[i][1].second<<")\n";
    }
    return 0;
}