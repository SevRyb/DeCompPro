#ifndef UTILS_H
#define UTILS_H

#include <QString>

class Utils
{

public:
    template<class T>
    static bool getBit(T number, T pos)
    {
        return (bool) ((number >> pos) & (T)1);
    };
    template<class T>
    static T setBit(T number, T pos, bool value)
    {
        return (number & ~((T)1 << pos)) | ((T)value << pos);
    };

    template<class T>
    static QString toBinStr(T number, int nBits)
    {
        //QString str(nBits, 0);
        QString str;
        for (int i = (nBits - 1); i >= 0; --i)
        {
            bool bit = getBit(number, i);
            //str[i] = QString::number(bit).at(1);
            str.append(QString::number(bit));
        }
        return str;
    };


private:


};

#endif // UTILS_H
