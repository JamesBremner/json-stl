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

    json_obj.Clear();

    test_object[ "test2"] = 1.23456789;
    json_obj[ "test" ] = test_object;

    // convert JSON to string
    s = json::Serialize( json_obj );
    cout << s << endl;

    if( s != "{\"test\":{\"test2\":1.234568}}" )
    {
        cout << "failed 2" << endl;
        return 1;
    }

    ///////////////////////////////////////
    // test reducing double output format to a single digit after decimal point

    json::theConfig.setDoubleFormat( "%.1f" );

    json_obj.Clear();
    test_object[ "test2"] = 1.23456789;
    json_obj[ "test" ] = test_object;
    s = json::Serialize( json_obj );
    cout << s << endl;

    if( s != "{\"test\":{\"test2\":1.2}}" )
    {
        cout << "failed 3" << endl;
        return 1;
    }

    // reset to default
    json::theConfig.setDoubleFormat();
    s = json::Serialize( json_obj );
    cout << s << endl;

    if( s != "{\"test\":{\"test2\":1.234568}}" )
    {
        cout << "failed 2" << endl;
        return 1;
    }


    cout << "success";

    return 0;
}
