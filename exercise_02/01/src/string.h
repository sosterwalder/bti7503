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
        String();
        String(const String&);
        String(string strInput);
        ~String() {}

        String& operator = (const string& strInput);
        String& operator = (const String& strInput);

        void* operator new (size_t size);
        void operator delete (void* ptr);

        char& operator[] (const int nIndex);

    private:
        string m_strString;
};

#endif
