/*
* Towers of Hanoi
*/

#include <iostream>

using namespace std;

//采用递归来求解汉诺塔问题
void towersOfHanoi(int n, int x, int y, int z);

int main()
{
    cout << "Towers of Hanoi!" << endl;

    int n=6;
    towersOfHanoi(n,1,2,3);

    return 0;
}

/*
* 设塔 x 有 n 个碟子
*
*     -|-         |           |
*    --|--        |           |
*   ---|---       |           |
*  ----|----      |           |
* -----|-----     |           |
*     x           y           z
*
*
* Idea: 为了把最大的碟子移到塔 y 的底部, 必须把其余 n-1 个碟子移到塔 z
*       然后把最大的碟子移到塔 y. 接下来把塔 z 上的 n-1 个碟子移到塔 y.
*/
void towersOfHanoi(int n, int x, int y, int z)
{
    //把塔x顶部的 n 个碟子移到塔y
    //用塔z作为中转地

    if(n>0)
    {
        towersOfHanoi(n-1,x,z,y);
        cout << "Move top disk from tower " << x
             << " to top of tower " << y << endl;
        towersOfHanoi(n-1,z,y,x);
    }
}
