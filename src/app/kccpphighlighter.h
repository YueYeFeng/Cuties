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

#ifndef KCCPPHIGHLIGHTER_H
#define KCCPPHIGHLIGHTER_H

#include "highlighterGlobal.h"

class textCharFormatMap;

class KCCppHighlighter : public KCHighlighter
{
    Q_OBJECT
public:
    explicit KCCppHighlighter(QObject *parent = 0);

protected:
    void KCHighlightBlock(const QString &text);

private:
    QList<highlight_rule> rules;

    textCharFormatMap *instance;
    void stringHighlightBlock(const QString &text);
    void conmmentHighlightBlock(const QString &text);
};

#endif // KCCPPHIGHLIGHTER_H
