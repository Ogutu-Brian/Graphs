#if !defined KEY_OBJECT
#define KEY_OBJECT
#include "CSC1310\include\String_.h"
//any objects stored in the graph must have a getKey method
using CSC1310::String;
class KeyObject
{
private:
    String* ko_name;
public:
    KeyObject(String* k_name)
    {
        ko_name = k_name;
    }
    virtual ~KeyObject()
    {
        delete ko_name;
    }

    String* getKey()
    {
        return ko_name;
    }
};

#endif
