// ComplexNumber.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*
** Name: test.cxx
** Author: Leo Liberti
** Purpose: testing the complex numbers class
** Source: GNU C++
** History: 061019 work started
*/
#include <iostream>
#include <string>
#include "complex.h"

/**
*  第一个参数，整型，通常命名为argc，代表参数个数。argc是一个正整数，因为程序所在的路径即第一个参数。
*  第二个参数，通常命名为argv，是一个指向字符串的指针数组。这是一个个参数的集合，依次以指针形式依次存放在数组中。
*/
int main(int argc, char** argv)
{
    /**
    *  "using namespace std;" 是 C++ 程序中常用的一个语句，它告诉编译器在当前程序中使用 "std" 命名空间中的符号。
    *  "std" 是 C++ 标准库的缩写，里面包含了许多常用的函数和类型，如 cout、endl、string 等。
    *  使用 "using namespace std;" 可以省去在使用这些符号时前缀 "std::" 的麻烦
    */
    using namespace std; 
    if (argc < 4) {
        /**
        *  cout：写到标准输出的ostream对象；
        *  cerr：输出到标准错误的ostream对象，常用于程序错误信息；
        *  clog：也是输出标准错误流（这点儿和cerr是一样的），貌似平时很少用到这个啊；
        */
        cerr << "need an operation on command line" << endl;
        cerr << " e.g. ./test 4.3+3i - 2+3.1i" << endl;
        cerr << " (no spaces within each complex number, use spaces to\n";
        cerr << " separate the operands and the operator - use arithmetic\n";
        cerr << " operators only)" << endl;
        return 1;
    }
    string complexString1 = argv[1];
    string complexString2 = argv[3];
    Complex complex1;
    complex1.fromString(complexString1);
    Complex complex2;
    complex2.fromString(complexString2);
    Complex complex3;
    //这部分有问题
    if (argv[2][0] == '+') {
        complex3 = complex1 + complex2;
    }
    else if (argv[2][0] == '-') {
        complex3 = complex1 - complex2;
    }
    else if (argv[2][0] == '*' || argv[2][0] == '.') {
        argv[2][0] = '*';
        complex3 = complex1 * complex2;
    }
    else if (argv[2][0] == '/') {
        complex3 = complex1 / complex2;
    }
    cout << complex1 << " " << argv[2][0] << " (" << complex2 << ") = "
        << complex3 << endl;
    return 0;
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
