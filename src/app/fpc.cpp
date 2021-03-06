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

#include "kccompilerconfigure.h"

#include "fpc.h"

fpc::fpc(QObject *parent) :
    KCCompilerBase(parent)
{
    instance=KCCompilerConfigure::getInstance();
}

QString fpc::compilerPath()
{
    return instance->getFpcPath();
}

QStringList fpc::getVersionArg()
{
    QStringList arg;
    arg<<"-iW";
    return arg;
}

QStringList fpc::getCompileArg(const QString &filePath)
{
    QStringList arg;
    arg<<filePath<<"-g";
    return arg;
}

QString fpc::getCompileEnv()
{
    QString env;
    return env;
}

void fpc::parseLine(const QString &text)
{
    QRegularExpression regexp("([A-Za-z]+\\.pas)\\((\\d+),(\\d+)\\)");

    QRegularExpressionMatch match=regexp.match(text);

    if(match.hasMatch())
    {
        compileErrorInfo error;
        error.errorFilePath=match.captured(1);
        error.errorLine=match.captured(2).toInt();
        error.errorColumn=match.captured(3).toInt();
        error.errorDescription=text.mid(match.capturedLength());

        emit compileError(error);
    }
    else
    {
        regexp.setPattern("(Fatal|Error|Warning|Hint|Note)");
        match=regexp.match(text);

        if(match.hasMatch())
        {
            compileErrorInfo error;
            error.errorFilePath.clear();
            error.errorLine=-1;
            error.errorColumn=-1;
            error.errorDescription=text;
        }
    }

    return ;
}
