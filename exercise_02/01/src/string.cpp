#include "string.h"

String::String()
{
    std::cout << __FILE__ << " at line " << __LINE__ << ": ";
    std::cout << "Calling default constructor";
    std::cout << std::endl << std::endl;

}

String::String(const String& source)
{
    std::cout << __FILE__ << " at line " << __LINE__ << ": ";
    std::cout << " Calling copy-constructor String(String&)";
    std::cout << std::endl << std::endl;

    this->m_strString = source.m_strString;
}

String::String(string strInput) {
    std::cout << __FILE__ << " at line " << __LINE__ << ": ";
    std::cout << "Calling overladed String(string)";
    std::cout << std::endl << std::endl;

    this->m_strString = strInput;
}

String& String::operator=(const string& strInput) {
    std::cout << __FILE__ << " at line " << __LINE__ << ": ";
    std::cout << "Calling operator=(string&) ";
    std::cout << std::endl << std::endl;

    m_strString = strInput;

    return *this;
}

String& String::operator=(const String& strInput)
{
    std::cout << __FILE__ << " at line " << __LINE__ << ": ";
    std::cout << "Calling operator=(String&) ";
    std::cout << std::endl << std::endl;

    m_strString = strInput.m_strString;

    return *this;
}

void* String::operator new(size_t size)
{
    std::cout << __FILE__ << " at line " << __LINE__ << ": ";
    std::cout << "calling operator new(size_t) ";
    std::cout << std::endl << std::endl;

    return malloc(size);
}

void String::operator delete (void* ptr)
{
    std::cout << __FILE__ << " at line " << __LINE__ << ": ";
    std::cout << "calling operator delete(size_t) ";
    std::cout << std::endl << std::endl;

    free(ptr);
}

char& String::operator[] (const int nIndex)
{
    //TODO: Check index!

    std::cout << __FILE__ << " at line " << __LINE__ << ": ";
    std::cout << "calling operator [](int): ";
    std::cout << this->m_strString.at(nIndex);
    std::cout << std::endl << std::endl;

    return this->m_strString.at(nIndex);
}

std::ostream& operator<<(std::ostream& s, const String strString) {
    return s << strString.m_strString;
}

std::ostream& operator<<(std::ostream& s, const String* strString) {
    return s << strString->m_strString;
}
