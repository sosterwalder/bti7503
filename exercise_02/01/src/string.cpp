#include "string.h"

String::String(string strInput) {
    std::cout << "Calling overladed String(str)" << std::endl;
    std::cout << "m_strString is now: " << strInput << std::endl;

    this->m_strString = strInput;
}

String& String::operator=(const string& strInput) {
    std::cout << "Calling operator=(string) " << std::endl;

    m_strString = strInput;

    return *this;
}

String& String::operator=(const String& strInput)
{
    std::cout << "Calling operator=(String) " << std::endl;
}

std::ostream& operator<<(std::ostream& s, const String strString) {
    return s << strString.m_strString;
}

std::ostream& operator<<(std::ostream& s, const String* strString) {
    return s << strString->m_strString;
}
