#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

vector<string> split(string str, char pattern) {
    
    int posInit = 0;
    int posFound = 0;
    string splitted;
    vector<string> results;
    
    while(posFound >= 0){
        posFound = str.find(pattern, posInit);
        splitted = str.substr(posInit, posFound - posInit);
        posInit = posFound + 1;
        results.push_back(splitted);
    }
    
    return results;
}

int main()
{
    string str;
    char pattern;
    vector<string> results;
    
    cin >> str;
    
    results = split(str, '-');
    
    for(int i = 0; i < results.size(); i++){
        cout << results[i] << endl;
    }
    string nuevo = results[0] +'-'+results[9];   
    cout<<nuevo<<endl;
    return (0);
}
