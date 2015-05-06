#include <iostream>

#include "../json.h"

using namespace std;

int main()
{
    json::Object json_obj;
    json::Object test_object;

    test_object[ "test2"] = 0;
    json_obj[ "test" ] = test_object;

    // convert JSON to string
    string s = json::Serialize( json_obj );
    cout << s << endl;

    if( s != "{\"test\":{\"test2\":0}}" )
    {
        cout << "failed 1" << endl;
        return 1;
    }

    cout << "success";

    return 0;
}
