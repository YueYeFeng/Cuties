/*
 *  Copyright 2013 Kreogist Dev Team
 *
 *      Wang Luming <wlm199558@126.com>
 *      Miyanaga Saki <tomguts@126.com>
 *      Zhang Jiayi <bf109g2@126.com>
 *
 *  This file is part of Kreogist-Cute-IDE.
 *
 *    Kreogist-Cute-IDE is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *    Kreogist-Cute-IDE is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Kreogist-Cute-IDE.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "compilerbase.h"

compilerBase::compilerBase(QObject *parent) :
    QProcess(parent)
{
}

void compilerBase::setCompilerName(QString newCompilerName)
{
    currentCompilerName=newCompilerName;
}

void compilerBase::emitCompileInfo(const QString &compilerPath,
                                   const QStringList &arg)
{
    QString CompileCmdLine;
    CompileCmdLine=compilerPath;
    for(int i=0; i<arg.count(); i++)
    {
        CompileCmdLine += QString(" ") + arg.at(i);
    }
    CompileCmdLine+="\n";
    emit compileinfo(CompileCmdLine);
}
