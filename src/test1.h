#ifndef TEST1_H
#define TEST1_H
class Father
{
public:
    virtual void test();
};

class Son:public Father
{
public:
    void test();
};

#endif // TEST1_H
