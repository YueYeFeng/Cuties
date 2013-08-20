/*
 *  Copyright 2013 Kreogist Dev Team
 *
 *  This file is part of Kreogist-Cuties.
 *
 *    Kreogist-Cuties is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *    Kreogist-Cuties is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Kreogist-Cuties.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef GCC_H
#define GCC_H

#include <QFileInfo>
#include <QRegularExpression>
#include <QDebug>

#include "compilerbase.h"

class gcc : public compilerBase
{
    Q_OBJECT
public:
    explicit gcc(QObject *parent = 0);
    QString path(){return isCompileCpp?gppPath:gccPath;}
    void setCompilerPath(const QString& path);
    QString compilerName(){return "g++";}

protected:
    QStringList getVersionArg();
    QStringList getCompileArg(const QString &filePath);
    QStringList getcompileEnv();

    void parseLine(const QString &text);

private:
    bool isCompileCpp;
    static QString gccPath;
    static QString gppPath;
};

#endif // GCC_H