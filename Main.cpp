#include "OthelloBoard.cpp"
using namespace std;

int main(){
    OthelloBoard O;
    O.print();
    bool fin = false;
    int b = 0;
    while(!fin){
        fin = O.check();//盤面のチェック
        if(!fin){
            b++;//手番を管理する
            cout << b << "手目" << endl;
            if(b % 2 == 1) cout << "黒の手番です" << endl;
            else cout << "白の手番です" << endl;

            cout << "２つの数字(x,y)を入力してください" << endl;
            cout << "終了する場合は10 10,パスの場合は22 22と入力してください" << endl;
            int x,y; cin >> x >> y;
            if(x == 10 && y == 10) fin = true;//finをtrueにする
            else if(x == 22 && y == 22) continue;
            else if(x>8 || y>8) {
                b--;
                cout << "正しい値を入力してください" << endl;
                continue;
            }
            else {
                O.turn(x-1,y-1,&b);
                O.print();
            }
        }
    }
    return 0;
}