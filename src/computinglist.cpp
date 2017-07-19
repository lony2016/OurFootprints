#include<iostream>
#include<fstream>
using namespace std;
void grading(int, int, int);

struct node
{
    int data;
    struct node *nextPtr;
};

void computingList(node *head)
{
    int positive=0,negtive=0,zero=0;
    struct node *p = head;
//    p = head;
    while(p != NULL)
    {
        if(p->data > 0)
        {
            positive++;
        }
        else if(p->data < 0)
        {
            negtive++;
        }
        else
        {
            zero++;
        }
        p = p->nextPtr;
    }
    grading(positive, zero, negtive);
}

struct node *createList(void)
{
    node *head=NULL, *p1, *p2;
    int   i;
    int a[10] = {-1,3,4,0,9,4,11,-6,2,-10};
    head=p2=p1= new node;
    p1->data = a[0];
    for (i=1; i<10; i++)
    {
        p1= new node;
        p1->data = a[i];
        p2->nextPtr=p1;
        p2=p1;
    }
    p2->nextPtr=NULL;
    return (head);
}


//int main()
//{
//    struct node *head;
//    head = createList();
//    computingList(head);
//    return 0;
//}

//以下忽略阅读
void grading(int a,int b,int c)
{
    fstream myfile;
    myfile.open("out.txt",ios::out);
    myfile<<a<<" "<<b<<" "<<c<<endl;
    myfile.close();
}
