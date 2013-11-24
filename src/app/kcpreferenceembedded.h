#ifndef KCPREFERENCEEMBEDDED_H
#define KCPREFERENCEEMBEDDED_H

#include <QWidget>
#include <QString>
#include <QList>

#include "kcpreferencesuperlist.h"
#include "Controls/Preference/kcpreferenceitembooleangroup.h"

#include "kcgeneralconfigure.h"
#include "kceditorconfigure.h"
#include "kccompilerconfigure.h"
#include "kcdebuggerconfigure.h"
#include "kcfileassociation.h"
#include "kclanguageconfigure.h"
#include "kchistoryconfigure.h"
#include "kcclipboard.h"

class KCPreferenceEmbeddedGeneral : public KCPreferenceSuperList
{
    Q_OBJECT
public:
    explicit KCPreferenceEmbeddedGeneral(QWidget *parent = 0);

signals:

public slots:
    void retranslate();
    void retranslateAndSet();
    void applyPreference();

private:
    enum GeneralTitleEnum
    {
        titleEnvironment,
        titleAutomaticRemember,
        titleHistory,
        titleSearchOptions,
        titleCount
    };
    QString generalTitleText[titleCount];
    QLabel *generalTitles[titleCount];

    enum GeneralComboItem
    {
        comboDefaultProgrammingLanguage,
        comboSearchEngine,
        comboItemCount
    };
    QString comboItemCaption[comboItemCount];
    QList<QString> comboItemText[comboItemCount];
    KCPreferenceItemCombo *generalCombos[comboItemCount];

    enum GeneralBooleanItem
    {
        booleanUseDefaultLanguageOnOpen,
        booleanUseDefaultLanguageOnSave,
        booleanAutoOpenUnclosed,
        booleanItemCount
    };
    QString booleanItemCaption[booleanItemCount];
    KCPreferenceItemBoolean *generalBooleans[booleanItemCount];

    enum GeneralIntItem
    {
        intItemHistoryMax,
        intItemCount
    };
    QString intItemCaption[intItemCount];
    KCPreferenceItemInt *generalInts[intItemCount];

    KCGeneralConfigure *instance;
};

class KCPreferenceEmbeddedEditor : public KCPreferenceSuperList
{
    Q_OBJECT
public:
    explicit KCPreferenceEmbeddedEditor(QWidget *parent = 0);

public slots:
    void retranslate();
    void retranslateAndSet();
    void applyPreference();

private:
    enum EditorTitleEnum
    {
        titleViewOptions,
        titleMultipleTabs,
        titleClipboard,
        titleCount
    };
    QString editorTitleText[titleCount];
    QLabel *editorTitles[titleCount];

    enum EditorComboEnum
    {
        comboWordWrapMode,
        comboItemCount
    };
    QString comboItemCaption[comboItemCount];
    QList<QString> comboItemText[comboItemCount];
    KCPreferenceItemCombo *editorCombos[comboItemCount];

    enum EditorBooleanEnum
    {
        booleanShowLinePanel,
        booleanTabMoveable,
        booleanTabCloseable,
        booleanItemCount
    };
    QString booleanItemCaption[booleanItemCount];
    KCPreferenceItemBoolean *editorBooleans[booleanItemCount];

    enum EditorBooleanGroupEnum
    {
        booleanGroupSpacingInsteadOfTab,
        booleanGroupCount
    };
    QString booleanGroupCaption[booleanGroupCount];
    KCPreferenceItemBooleanGroup *editorBooleanGroups[booleanGroupCount];

    enum EditorIntEnum
    {
        intTabSpacing,
        intSpacePerTab,
        intCursorWidth,
        intClipboardTrackingMax,
        intItemCount
    };
    QString intItemCaption[intItemCount];
    KCPreferenceItemInt *editorInts[intItemCount];

    KCPreferenceItemBooleanGroup *tabSpacingItem;

    KCEditorConfigure *instance;
};

class KCPreferenceEmbeddedCompiler : public KCPreferenceSuperList
{
    Q_OBJECT
public:
    explicit KCPreferenceEmbeddedCompiler(QWidget *parent = 0);

public slots:
    void retranslate();
    void retranslateAndSet();
    void applyPreference();

private:
    enum CompilerTitleEnum
    {
        titleCompilerPath,
        titleCount
    };
    QString compilerTitleText[titleCount];
    QLabel *compilerTitles[titleCount];

    enum CompilerPathItemEnum
    {
        pathGPPCompiler,
        pathGCCCompiler,
        pathFPCCompiler,
        pathItemCount
    };
    KCPreferenceItemPath *compilerPathItems[pathItemCount];
    QString pathItemCaption[pathItemCount];
    QString pathItemTitleCaption[pathItemCount];

    KCCompilerConfigure *instance;
};

class KCPreferenceEmbeddedDebugger : public KCPreferenceSuperList
{
    Q_OBJECT
public:
    explicit KCPreferenceEmbeddedDebugger(QWidget *parent = 0);

public slots:
    void retranslate();
    void retranslateAndSet();
    void applyPreference();

private:
    enum DebuggerTitleEnum
    {
        titleGDBSettings,
        titleCount
    };
    QString debuggerTitleText[titleCount];
    QLabel *debuggerTitles[titleCount];

    enum DebuggerPathItem
    {
        pathGDBDebugger,
        pathItemCount
    };
    KCPreferenceItemPath *debuggerPathItems[pathItemCount];
    QString pathItemCaption[pathItemCount];
    QString pathItemTitleCaption[pathItemCount];

    KCDebuggerConfigure *instance;
};

class KCPreferenceEmbeddedFileAssociation : public KCPreferenceSuperList
{
    Q_OBJECT
public:
    explicit KCPreferenceEmbeddedFileAssociation(QWidget *parent = 0);

public slots:
    void applyPreference();

private:

};

class KCPreferenceEmbeddedLanguage : public QWidget
{
    Q_OBJECT
public:
    explicit KCPreferenceEmbeddedLanguage(QWidget *parent = 0);

private:

};

#endif // KCPREFERENCEEMBEDDED_H
