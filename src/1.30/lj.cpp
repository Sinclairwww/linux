#include <cstring>
#include <iostream>
#include <stdlib.h>

using namespace std;
class String {
private:
    char* Mystr;

public:
    String ();
    String ( const char* str );
    String ( const String& s );
    // String &operator=(const String &s);
    friend ostream& operator<< ( ostream& out, String s );
    ~String ();
};
String::String () {}
String::String ( const char* str = "" ) {
    cout << "String类的带参构造函数被调用" << endl;
    if ( str == NULL )
        this->Mystr = "";
    else {
        int len = strlen ( str );
        this->Mystr = new char[ len + 1 ];
        strcpy ( this->Mystr, str );
    }
}
String::String ( const String& s ) {
    cout << "String类的拷贝构造函数被调用" << endl;
    int len = strlen ( s.Mystr );
    this->Mystr = new char[ len + 1 ];
    strcpy ( this->Mystr, s.Mystr );
}
/*
String &String::operator=(const String &s)
{
    cout << "String类的operator = 运算符重载函数被调用" << endl;
    if (this != &s)
    {
        int len = strlen(s.Mystr);
        char *tmp = new char[len + 1];
        strcpy(tmp, s.Mystr);
        delete this->Mystr;
        this->Mystr = tmp;
    }
    return *this;
}
*/
ostream& operator<< ( ostream& out, String s ) {
    out << s.Mystr;
    return out;
}
String::~String () {
    cout << "String类的析构函数被调用" << endl;
    delete this->Mystr;
}
String getString ( const char* str ) {
    String tmp ( str );
    return tmp;
}
int main () {
    String s1 = getString ( "hello" );
    cout << s1 << endl;
    return 0;
}
