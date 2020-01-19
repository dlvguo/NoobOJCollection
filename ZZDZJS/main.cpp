#include <iostream>
#include <time.h>

using namespace std;
//#define SIZE 5

class Map //类开头大写
{
private:
    int tao[60][120]; //可以大点
    int length;       //定义y轴行数
    int width;        //定义x轴列数
public:
    Map()
    {
        this->length = 12;
        this->width = 6;
    }

    Map(int w, int l)
    {
        this->length = l;
        this->width = w;
    }

    void SizeDefine() //尺寸设定，这里请取 width=6；length=12，我老师规定了这个尺寸，所以这段代码作为练习//
    {
        cout << "Please enter the width of the map: " << endl;
        cin >> width;
        cout << "Please enter the length of the map: " << endl;
        cin >> length;
    }

    //这边用DrawMap好一点 不止放G
    void G_placement() //大脑（G）的放置
    {
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < length; j++)
            {
                cout << "----"; //首先先定义每个横纵坐标循环后，输出---作为横格 //
            }
            cout << endl;

            for (int j = 0; j < length; j++)
            {
                if (j == 0)
                { //定义，当j==0时，就是第一列时，放置大脑G //
                    cout << "| G | ";
                }
                else
                {
                    cout << "  | "; //其余j != 0,即其他列，输出｜ //
                }
            }
            cout << endl;
        }
        //在最后面输出下这个不就可以了
        for (int j = 0; j < length; j++)
        {
            cout << "----"; //首先先定义每个横纵坐标循环后，输出---作为横格 //
        }
    }
};

int main() //Recall every function block//
{
    Map map; //名字好看一点
    map.SizeDefine();
    map.G_placement();
    return 0;
}

//总结，我会继续看一下动态刷新的用法，明天开搞僵尸和土豆的随机放置， 国哥牛b

//横杆在最左边就可以了