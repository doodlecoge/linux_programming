#include <list>
#include <iostream>

typedef struct
{
    int value;
} TheType;

typedef std::list<TheType>::iterator LI_t;

void foo(LI_t& li)
{
    std::cout<<li->value<<std::endl;
}


int main(int argc, char* argv[])
{
    std::list<TheType> int_list;

    TheType a;

    a.value = 0;
    int_list.push_front(a);

    a.value = 1;
    int_list.push_front(a);

    a.value = 2;
    int_list.push_front(a);

    std::list<TheType>::iterator iter = int_list.begin();
    for(; iter != int_list.end(); iter++)
    {
        foo(iter);
    }

    std::cout<<std::endl;

    return 0;
}
