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

#ifndef KCDEBUGCONTROLBUTTONS_H
#define KCDEBUGCONTROLBUTTONS_H

#include <QDockWidget>

#include "gdbcontroller.h"

class QToolBar;
class QToolButton;
class GdbController;

class KCDebugControlPanel : public QDockWidget
{
    Q_OBJECT
public:
    explicit KCDebugControlPanel(QWidget *parent = 0);
    void setGdbController(GdbController *controller);

signals:
    void debugStarted();
    void debugStopped();

public slots:
    void retranslate();
    void retranslateAndSet();
    void onDebugStartClicked();
    void onDebugStopClicked();
    void onRunToCursorClicked();
    void onDebugNextClicked();
    void onDebugContinueClicked();
    void onDebugStepClicked();
    void onDebugNextiClicked();
    void onDebugStepiClicked();
    void onDebugReturnClicked();

private slots:

private:
    enum debugContolButtons
    {
        debugStart,
        debugStop,
        debugRunToCursor,
        debugControlButtonCount
    };

    enum debugCursorControlButtons
    {
        debugNext,
        debugContinue,
        debugStep,
        debugNexti,
        debugStepi,
        debugReturn,
        debugCursorControlButtonCount
    };

    GdbController* gdbController;

    QToolBar *toolBar;
    QToolButton *debugControlButton[debugControlButtonCount];
    QToolButton *debugCursorControlButton[debugCursorControlButtonCount];

    QString windowTitleString,
            toolbarTitle;
    QString debugCursorControlCaption[debugCursorControlButtonCount],
            debugCursorControlToolTips[debugCursorControlButtonCount];
    QString debugControlToolTips[debugControlButtonCount];
};

#endif // KCDEBUGCONTROLBUTTONS_H
