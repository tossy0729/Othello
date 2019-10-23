#include "OthelloBoard.h"

OthelloBoard::OthelloBoard()
{
    for(int y = 0;y<HT;++y){
        for(int x=0;x<WD;++x) m_boad[x][y] = SPACE;
        
    }
    m_boad[3][4] = m_boad[4][3] = BLACK;
    m_boad[3][3] = m_boad[4][4] = WHITE;
}

void OthelloBoard::print() const
{
    for(int i=0;i<WD;++i) cout << i+1 <<" ";
    cout << "\n";
    for(int y=0;y<HT;++y){
        for(int x=0;x<WD;++x){
            switch(m_boad[x][y]){
                case SPACE:
                    cout << "# ";//本来は"・"だったが、描写的に"#"にした
                    break;
                case BLACK:
                    cout << "○ ";
                    break;
                case WHITE:
                    cout << "● ";
                    break;
            }
        }
        cout << y+1 << "\n";
    }
    cout << "\n";
}

void OthelloBoard::turn(int x,int y, int b)
{
    char color;//現在の手番の色
    char revcolor;//相手番の色
    if(b == 0) {
        color = BLACK;
        revcolor = WHITE;
    }
    else {
        color = WHITE;
        revcolor = BLACK;
    }
    if(m_boad[x][y] == SPACE){//指定された座標が空白なら以下の処理をする
        m_boad[x][y] = color;//指定された座標を手番の色にする
        int a = -1;//フラグ
        if(x<8){//xが右端でなければ
            for(int i=x+1;i<WD;++i){//右側について調べる
                if(m_boad[i][y] == revcolor && a == -1) continue;//もし、revcolorが続いていたらループを続ける
                else if(m_boad[i][y] == color && a == -1){//もし、revが続いてきて、colorが現れたら、その座標を覚える
                    a = i;
                    break;
                } 
                else break;//それ以外ならループを終了する
            }
            if(a != -1){//ひっくり返す部分が存在する(aが-1でないなら)ひっくり返す操作を行う
                for(int i=x+1;i<=a;++i){
                    m_boad[i][y] = color;
                }
            }
            a = -1;
        }
        if(x>=1){//xが左橋でなければ
            for(int i=x-1;i>=0;--i){//左側について調べる
                if(m_boad[i][y] == revcolor && a == -1) continue;//もし、revcolorが続いていたらループを続ける
                else if(m_boad[i][y] == color && a == -1){//もし、revが続いてきて、colorが現れたら、その座標を覚える
                    a = i;
                    break;
                } 
                else break;//それ以外ならループを終了する
            }
            if(a != -1){//ひっくり返す部分が存在する(aが-1でないなら)ひっくり返す操作を行う
                for(int i=x-1;i>=a;--i){
                    m_boad[i][y] = color;
                }
            }
            a = -1;
        }
        if(y<8){//yが一番下でなければ
            for(int i=y+1;i<HT;++i){//下側について調べる
                if(m_boad[x][i] == revcolor && a == -1) continue;//もし、revcolorが続いていたらループを続ける
                else if(m_boad[x][i] == color && a == -1){//もし、revが続いてきて、colorが現れたら、その座標を覚える
                    a = i;
                    break;
                } 
                else break;//それ以外ならループを終了する
            }
            if(a != -1){//ひっくり返す部分が存在する(aが-1でないなら)ひっくり返す操作を行う
                for(int i=y+1;i<=a;++i){
                    m_boad[x][i] = color;
                }
            }
            a = -1;
        }
        if(y>=1){//xが左橋でなければ
            for(int i=y-1;i>=0;--i){//左側について調べる
                if(m_boad[x][i] == revcolor && a == -1) continue;//もし、revcolorが続いていたらループを続ける
                else if(m_boad[x][i] == color && a == -1){//もし、revが続いてきて、colorが現れたら、その座標を覚える
                    a = i;
                    break;
                } 
                else break;//それ以外ならループを終了する
            }
            if(a != -1){//ひっくり返す部分が存在する(aが-1でないなら)ひっくり返す操作を行う
                for(int i=y-1;i>=a;--i){
                    m_boad[x][i] = color;
                }
            }
            a = -1;
        }
    }
}

int main(){
    OthelloBoard O;
    O.print();
    bool fin = false;
    int a = -1;
    while(!fin){
        a++;//ターン数をカウント
        int b = a%2;//手番を管理するフラグ
        if(b == 0) cout << "黒の手番です" << endl;
        else cout << "白の手番です" << endl;

        cout << "２つの数字(x,y)を入力してください" << endl;
        cout << "終了する場合は10 10と入力してください" << endl;
        int x,y; cin >> x >> y;
        if(x == 10 && y == 10) fin = true;//finをtrueにする
        else if(x>8 || y>8) {
            a--;
            cout << "正しい値を入力してください" << endl;
            continue;
        }
        else {
            O.turn(x-1,y-1,b);
            O.print();
        }
    }
    return 0;
}
