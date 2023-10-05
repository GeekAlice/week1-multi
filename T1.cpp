#include <iostream>
#include <string>
using namespace std;

//3<4<5<6<7<8<9<10<J<Q<K<A<2<小王<大王

//X or D
//bomb !=0
bool shouldCallLandlord(const string& hand) {
    char alpha[10]={'J','Q','K','A','T'};
    int countJokers = 0;
    int countBomb = 0;
    
    for (char card : hand) {
        if (card == 'X' || card == 'D') {
            countJokers++;
        }
    }
    
    for (char c = '2'; c <= '9'; c++) {
        int count = 0;
        for (char card : hand) {
            if (card == c) {
                count++;
            }
        }
        if (count >= 4) {
            countBomb++;
        }
    }
    for(int i=0;i<=4;i++){
        int count = 0;
        for(char card : hand){
            if(card == alpha[i]){
                count++;
            }
        }
        if(count>=4){
            countBomb++;
        }
    }
    return countJokers == 2 || countBomb > 0;
}

int main() {
    int T;
    cin >> T;
    
    for (int i = 0; i < T; i++) { //T组数据
        string hand; //手牌
        cin >> hand;
        
        if (shouldCallLandlord(hand)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    
    return 0;
}
