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

#include "kcfontconfigure.h"

#include <QDir>
#include <QList>
#include <QFile>
#include <QFileInfo>
#include <QStringList>
#include <QApplication>
#include <QFontDatabase>
#include <QMessageBox>

KCFontConfigure *KCFontConfigure::instance=nullptr;

KCFontConfigure *KCFontConfigure::getInstance()
{
    return instance==nullptr?instance=new KCFontConfigure:instance;
}

KCFontConfigure::KCFontConfigure()
{
    //Initalize Default Font
    initCustomFonts();
#ifdef Q_OS_WIN32
    applicationFont=QFont("Hiragino Sans GB W3");
    applicationFont.setPixelSize(13);
    codeFontName="Monaco";
    codeFont=QFont(codeFontName);
    codeFont.setPixelSize(12);
    menuFont=applicationFont;
    menuFont.setPixelSize(16);
#endif
#ifdef Q_OS_UNIX
    applicationFont=QFont("Hiragino Sans GB W3");
    applicationFont.setPixelSize(13);
    codeFontName="Monaco";
    codeFont=QFont(codeFontName);
    codeFont.setPixelSize(12);
    menuFont.setPixelSize(16);
    menuFont.setStyleStrategy(QFont::PreferAntialias);
#endif
#ifdef Q_OS_WIN32
    menuFont=applicationFont;
#else
#ifdef Q_OS_UNIX
    menuFont=QFont("sao");
#endif
#endif
    applyConfigure();
}

QFont KCFontConfigure::getMenuFont() const
{
    return menuFont;
}

void KCFontConfigure::setMenuFont(const QFont &value)
{
    menuFont = value;
}

QFont KCFontConfigure::getCodeFont() const
{
    return codeFont;
}

void KCFontConfigure::setCodeFont(const QFont &value)
{
    codeFont = value;
}

void KCFontConfigure::applyConfigure()
{
    setApplicationFont();
}

void KCFontConfigure::readConfigure()
{
    ;
}

void KCFontConfigure::writeConfigure()
{
    ;
}

void KCFontConfigure::setApplicationFont()
{
    qApp->setFont(applicationFont);
}

void KCFontConfigure::initCustomFonts()
{
    QStringList filter;
    QDir *dir=new QDir(QString(qApp->applicationDirPath() + "/Fonts/"));
    QList<QFileInfo> *list=new QList<QFileInfo>(dir->entryInfoList(filter));

    int fontID(-1);
    bool fontWarningShown(false);
    for(QList<QFileInfo>::iterator i=list->begin();
        i!=list->end();
        ++i)
    {
        if(i->fileName().length() < 4)
        {
            continue;
        }
        QFile res(i->filePath());
        if(res.open(QIODevice::ReadOnly) == false)
        {
            if(fontWarningShown == false)
            {
                QMessageBox::warning(0,
                                     QApplication::applicationName(),
                                     QString(QApplication::tr("Error occur when load font file.")) +
                                     "\n" +
                                     QString(QApplication::tr("Error: ")) +
                                     res.errorString());
                fontWarningShown = true;
            }
        }
        else
        {
            fontID = QFontDatabase::addApplicationFontFromData(res.readAll());
            if(fontID == -1 && fontWarningShown == false)
            {
                QMessageBox::warning(0,
                                     QApplication::applicationName(),
                                     QString(QApplication::tr("Error occur when load font file.")) +
                                     "\n" +
                                     QString(QApplication::tr("Error: ")) +
                                     res.errorString());
                fontWarningShown = true;
            }
        }
    }
}

QString KCFontConfigure::getCodeFontName() const
{
    return codeFontName;
}

void KCFontConfigure::setCodeFontName(const QString &value)
{
    codeFontName = value;
}

