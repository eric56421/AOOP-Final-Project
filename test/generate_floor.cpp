#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    for (int i=1; i<=20; i++) {
        string tmp = "floor["+to_string(i)+"] = new Floor(new P"+to_string(i)+");";
        cout<<tmp<<endl;
    }

    return 0;
}