#ifndef __STRING_H_
#define __STRING_H_

#include <string>
#include <iostream>

using namespace std;

class String
{
    friend ostream& operator<<(ostream& s, const String strString);
    friend ostream& operator<<(ostream& s, const String* strString);

    public:
        String() { cout << "Default constructor" << endl; }
        String(string strInput);
        ~String() {}

        String& operator = (const string& strInput);
        String& operator = (const String& strInput);

    private:
        string m_strString;
};

#endif
