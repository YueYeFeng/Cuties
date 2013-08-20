/*
 *  Copyright 2013 Kreogist Dev Team
 *
 *      Wang Luming <wlm199558@126.com>
 *      Miyanaga Saki <tomguts@126.com>
 *      Zhang Jiayi <bf109g2@126.com>
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

#include "kcimainwindow.h"

kciMainWindow::kciMainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    m_titleBar=new kciTitleBar(this);
    setMenuWidget(m_titleBar);
    setAcceptDrops(true);

    setContentsMargins(2,2,2,2);

#ifdef Q_OS_MACX
    QMainWindow::setUnifiedTitleAndToolBarOnMac(false);
#else
    setWindowFlags(Qt::FramelessWindowHint);
    kciDragProxy *dragProxy=new kciDragProxy(this);
    dragProxy->setBorderWidth(8,8,8,8);
#endif
}

kciTitleBar *kciMainWindow::titleBar() const
{
    return m_titleBar;
}

void kciMainWindow::setTitleBar(kciTitleBar *titleBar)
{
    m_titleBar = titleBar;
}

#ifndef Q_OS_MACX
void kciMainWindow::setMainButtonIcon(const QString &mainIcon)
{
    if(m_titleBar)
    {
        m_titleBar->setMainButtonIcon(mainIcon);
    }
}

void kciMainWindow::setMenu(QMenu *menu)
{
    if(m_titleBar)
    {
        m_titleBar->setMenu(menu);
    }
}
#endif