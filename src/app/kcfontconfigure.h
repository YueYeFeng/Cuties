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

#ifndef KCFONTCONFIGURE_H
#define KCFONTCONFIGURE_H

#include <QFont>
#include "kcconfigure.h"

class KCFontConfigure : public KCConfigure
{
public:
    void readConfigure();
    void writeConfigure();
    static KCFontConfigure *getInstance();
    
    void initCustomFonts();
    void applyConfigure();
    void setApplicationFont();
    QString getCodeFontName() const;
    void setCodeFontName(const QString &value);
    QFont getCodeFont() const;
    void setCodeFont(const QFont &value);
    QFont getMenuFont() const;
    void setMenuFont(const QFont &value);

signals:
    
public slots:
    
private:
    KCFontConfigure();
    static KCFontConfigure *instance;
    QFont applicationFont;
    QFont codeFont;
    QFont menuFont;
    QString codeFontName;
};

#endif // KCFONTCONFIGURE_H
