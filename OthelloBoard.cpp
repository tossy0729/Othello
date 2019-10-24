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

void OthelloBoard::turn(int x,int y, int* b)
{
    char color;//現在の手番の色
    char revcolor;//相手番の色
    if( b == nullptr){
        cout << "不正な値です" << endl;
    }
    else{
        if(*b % 2 == 1) {
            color = BLACK;
            revcolor = WHITE;
        }
        else {
            color = WHITE;
            revcolor = BLACK;
        }
        if(m_boad[x][y] == SPACE){//指定された座標が空白なら以下の処理をする
            
            int a = -1;//フラグ
            int c = 0;//0ならどこもひっくり返らないので、置けない
            if(x<7){//xが右端でなければ
                for(int i=x+1;i<WD;++i){//右側について調べる
                    if(m_boad[i][y] == revcolor && a == -1) continue;//もし、revcolorが続いていたらループを続ける
                    else if(m_boad[i][y] == color && a == -1 && i!=x+1){//もし、revが続いてきて、colorが現れたら、その座標を覚える
                        a = i;
                        break;
                    } 
                    else break;//それ以外ならループを終了する
                }
                if(a != -1){//ひっくり返す部分が存在する(aが-1でないなら)ひっくり返す操作を行う
                    for(int i=x+1;i<=a;++i) m_boad[i][y] = color;
                    c = 1;
                }
                a = -1;
            }
            if(x>=1){//xが左橋でなければ
                for(int i=x-1;i>=0;--i){//左側について調べる
                    if(m_boad[i][y] == revcolor && a == -1) continue;//もし、revcolorが続いていたらループを続ける
                    else if(m_boad[i][y] == color && a == -1 && i!=x-1){//もし、revが続いてきて、colorが現れたら、その座標を覚える
                        a = i;
                        break;
                    } 
                    else break;//それ以外ならループを終了する
                }
                if(a != -1){//ひっくり返す部分が存在する(aが-1でないなら)ひっくり返す操作を行う
                    for(int i=x-1;i>=a;--i) m_boad[i][y] = color;
                    c = 1;
                }
                a = -1;
            }
            if(y<7){//yが一番下でなければ
                for(int i=y+1;i<HT;++i){//下側について調べる
                    if(m_boad[x][i] == revcolor && a == -1) continue;//もし、revcolorが続いていたらループを続ける
                    else if(m_boad[x][i] == color && a == -1 && i!=y+1){//もし、revが続いてきて、colorが現れたら、その座標を覚える
                        a = i;
                        break;
                    } 
                    else break;//それ以外ならループを終了する
                }
                if(a != -1){//ひっくり返す部分が存在する(aが-1でないなら)ひっくり返す操作を行う
                    for(int i=y+1;i<=a;++i) m_boad[x][i] = color;
                    c = 1;
                }
                a = -1;
            }
            if(y>=1){//xが左端でなければ
                for(int i=y-1;i>=0;--i){//左側について調べる
                    if(m_boad[x][i] == revcolor && a == -1) continue;//もし、revcolorが続いていたらループを続ける
                    else if(m_boad[x][i] == color && a == -1 && i!=y-1){//もし、revが続いてきて、colorが現れたら、その座標を覚える
                        a = i;
                        break;
                    } 
                    else break;//それ以外ならループを終了する
                }
                if(a != -1){//ひっくり返す部分が存在する(aが-1でないなら)ひっくり返す操作を行う
                    for(int i=y-1;i>=a;--i) m_boad[x][i] = color;
                    
                    c = 1;
                }
                a = -1;
            }
            if(x>=1 && y>=1){//左端の列、一番上の行でなければ
                int MIN = min(x,y);//ループの終了条件のためにminを求める
                for(int i=1;i<=MIN;++i){//左上へと上がっていく
                    if(m_boad[x-i][y-i] == revcolor && a == -1) continue;
                    else if(m_boad[x-i][y-i] == color && a == -1 && i!=1){
                        a = i;
                        break;
                    }
                    else break;
                }
                if(a != -1){
                    for(int i=1;i<=a;++i) m_boad[x-i][y-i] = color;
                    c = 1;
                }
                a = -1;
            }
            if(x<7 && y>=1){//右端の列、一番上の行でなければ
                int MIN = min(WD-1-x,y);//ループの終了条件のためにminを求める
                for(int i=1;i<=MIN;++i){//右上へと上がっていく
                    if(m_boad[x+i][y-i] == revcolor && a == -1) continue;
                    else if(m_boad[x+i][y-i] == color && a == -1 && i!=1){
                        a = i;
                        break;
                    }
                    else break;
                }
                if(a != -1){
                    for(int i=1;i<=a;++i) m_boad[x+i][y-i] = color;
                    c = 1;
                }
                a = -1;
            }
            if(x>=1 && y<7){//左端の列、一番下の行でなければ
                int MIN = min(x,HT-1-y);//ループの終了条件のためにminを求める
                for(int i=1;i<=MIN;++i){//左下へと下がっていく
                    if(m_boad[x-i][y+i] == revcolor && a == -1) continue;
                    else if(m_boad[x-i][y+i] == color && a == -1 && i!=1){
                        a = i;
                        break;
                    }
                    else break;
                }
                if(a != -1){
                    for(int i=1;i<=a;++i) m_boad[x-i][y+i] = color;
                    c = 1;
                }
                a = -1;
            }
            if(x<7 && y<7){//右端の列、一番下の行でなければ
                int MIN = min(WD-1-x,HT-1-y);//ループの終了条件のためにminを求める
                for(int i=1;i<=MIN;++i){//右下へと下がっていく
                    if(m_boad[x+i][y+i] == revcolor && a == -1) continue;
                    else if(m_boad[x+i][y+i] == color && a == -1 && i!=1){
                        a = i;
                        break;
                    }
                    else break;
                }
                if(a != -1){
                    for(int i=1;i<=a;++i) m_boad[x+i][y+i] = color;
                    c = 1;
                }
                a = -1;
            }
            if(c == 1) m_boad[x][y] = color;//指定された座標を手番の色にする
            else{
                *b = *b-1;
                cout << "そこには置けません" << endl;
            }
        }
        else{
            *b = *b-1;
            cout << "そこには置けません" << endl;
        }
    }
}

bool OthelloBoard::check() const //盤面の状態をチェックする
{
    bool fin = true;//盤面が終了状態かどうかを判定するbool
    int black = 0;//黒の数
    int white = 0;//白の数
    int space = 0;//空白の数
    for(int x=0;x<WD;++x){//盤面をチェックする
        for(int y=0;y<HT;++y){
            if(m_boad[x][y] == BLACK) black++;
            else if(m_boad[x][y] == WHITE)  white++;
            else space++;
        }
    }
    if(white != 0 && black != 0 && space != 0) fin=false;//白か黒がゼロでない、または、空白が残っている場合false
    if(fin){
        if(white == 0) cout << "黒の勝ちです" << endl;
        else if(black == 0) cout << "白の勝ちです" << endl;
        else{
            if(white > black) cout << "白の勝ちです" << endl;
            else if(black > white) cout << "黒の勝ちです" << endl;
            else cout << "引き分けです" << endl;
        }
    }
    return fin;
}

int main(){
    OthelloBoard O;
    O.print();
    bool fin = false;
    int b = 0;
    while(!fin){
        fin = O.check();//盤面のチェック
        if(!fin){
            b++;//手番を管理するフラグ
            cout << b << "手目" << endl;
            if(b % 2 == 1) cout << "黒の手番です" << endl;
            else cout << "白の手番です" << endl;

            cout << "２つの数字(x,y)を入力してください" << endl;
            cout << "終了する場合は10 10と入力してください" << endl;
            int x,y; cin >> x >> y;
            if(x == 10 && y == 10) fin = true;//finをtrueにする
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
