#include "cppregister.h"

CPPRegister::CPPRegister()
{

}

void CPPRegister::setStringType(const QString &str)
{
    if (m_string != str) {
        m_string = str;
        emit stringTypeChanged();
    }
}
