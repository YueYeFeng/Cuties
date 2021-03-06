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

#ifndef KCMARKPANEL_H
#define KCMARKPANEL_H

#include <QVector>
#include <QPoint>

#include "kcpanel.h"

class KCMarkPanel : public KCPanel
{
    Q_OBJECT
public:
    explicit KCMarkPanel(QWidget *parent = 0);

    QPixmap getMarkPix() const;
    void setMarkPix(const QPixmap &value);

public slots:

protected:
    void draw(QPainter *painter, QTextBlock *block,
              int x, int y, int w, int h,
              bool isCurrentLine);

    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

private:
    QPixmap markPix;
    QPoint pressedPos;
    bool isPressed;
};

#endif // KCMARKPANEL_H
