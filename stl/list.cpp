#include <list>
#include <iostream>

int main(int argc, char* argv[])
{
    std::list<int> int_list;

    int_list.push_front(0);
    int_list.push_front(1);
    int_list.push_front(2);

    int_list.push_back(3);
    int_list.push_back(4);
    int_list.push_back(5);

    std::list<int>::iterator iter = int_list.begin();
    for(; iter != int_list.end(); iter++)
    {
        std::cout<<*iter<<" ";
    }

    std::cout<<std::endl;

    return 0;
}
