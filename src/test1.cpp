#include "test1.h";
#include <iostream>;

using namespace std;

void Father::test()
{
    cout << "Father's Test" << endl;
}



void Son::test()
{
    cout << "son's Test" << endl;
}
//int main()
//{
//    Father *p1 = new Father();
//    p1->test();
//    Father *p2 = new Son();
//    p2->test();
//    return 0;
//}
