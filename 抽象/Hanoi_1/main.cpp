/*
* Towers of Hanoi
*/

#include <iostream>

using namespace std;

//���õݹ�����⺺ŵ������
void towersOfHanoi(int n, int x, int y, int z);

int main()
{
    cout << "Towers of Hanoi!" << endl;

    int n=6;
    towersOfHanoi(n,1,2,3);

    return 0;
}

/*
* ���� x �� n ������
*
*     -|-         |           |
*    --|--        |           |
*   ---|---       |           |
*  ----|----      |           |
* -----|-----     |           |
*     x           y           z
*
*
* Idea: Ϊ�˰����ĵ����Ƶ��� y �ĵײ�, ��������� n-1 �������Ƶ��� z
*       Ȼ������ĵ����Ƶ��� y. ���������� z �ϵ� n-1 �������Ƶ��� y.
*/
void towersOfHanoi(int n, int x, int y, int z)
{
    //����x������ n �������Ƶ���y
    //����z��Ϊ��ת��

    if(n>0)
    {
        towersOfHanoi(n-1,x,z,y);
        cout << "Move top disk from tower " << x
             << " to top of tower " << y << endl;
        towersOfHanoi(n-1,z,y,x);
    }
}
