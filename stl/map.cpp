#include <map>
#include <string>
#include <iostream>

using namespace std;

typedef struct
{
    string name;
} User;

int main(int argc, char* argv[])
{
    map<int, User> user_map;

    User user;

    user.name = "hch";
    user_map[0] = user;

    user.name = "desk";
    user_map[1] = user;

    map<int, User>::iterator iter = user_map.find(0);

    // first is the key in map while second is the value
    cout<<iter->first<<": "<<iter->second.name<<endl;
    return 0;
}
