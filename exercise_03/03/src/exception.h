#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

#include <exception>

class OutOfBoundsException : public std::exception
{
    public:
        OutOfBoundsException(std::string strMessage) : m_strMessage(strMessage) {}
        OutOfBoundsException(std::exception const& e)
        {
            m_strMessage = e.what();
        }

        virtual const char* what() const throw()
        {
            return m_strMessage.c_str();
        }

    private:
        std::string m_strMessage;
};

#endif
