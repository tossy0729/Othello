#include <iostream>
using namespace std;

class OthelloBoard
{
    static const int WD = 8;//width
    static const int HT = 8;//height
    enum{
        SPACE = 0,
        BLACK,
        WHITE,
    };
    private:
        char m_boad[WD][HT]; //盤面の状態
    public:
        OthelloBoard();
        void init(){
            for(int y=0;y<HT;++y){
                for(int x=0;x<WD;++x){
                    m_boad[x][y] = SPACE;
                }
            }
            m_boad[3][4] = m_boad[4][3] = BLACK;
            m_boad[3][3] = m_boad[4][4] = WHITE;
        }
        void print() const;
        void turn( int x, int y, int a);
};