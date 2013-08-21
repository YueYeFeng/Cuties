#ifndef KCICONFIGURE_H
#define KCICONFIGURE_H

#include <QString>

class kciConfigure
{
public:
    virtual void readConfigure() = 0;
    virtual void writeConfigure() = 0;
    static QString getCfgFileName() const {return cfgFileName;}
    static void setCfgFileName(const QString &value){cfgFileName = value;}

private:
    static QString cfgFileName;

};

#endif // KCICONFIGURE_H