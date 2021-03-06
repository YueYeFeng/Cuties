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

#ifndef FPC_H
#define FPC_H

#include <QRegularExpression>
#include <QDebug>

#include "kccompilerbase.h"

class KCCompilerConfigure;

class fpc : public KCCompilerBase
{
    Q_OBJECT
public:
    explicit fpc(QObject *parent = 0);
    void startCompile(const QString &filePath);
    QString compilerPath();
    virtual QString compilerName()
    {
        return "fpc";
    }

protected:
    QStringList getVersionArg();
    QStringList getCompileArg(const QString &filePath);
    QString getCompileEnv();

    void parseLine(const QString &text);

private:
    KCCompilerConfigure *instance;
};

#endif // FPC_H
