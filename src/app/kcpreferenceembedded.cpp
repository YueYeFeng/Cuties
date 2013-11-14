#include "kcpreferenceembedded.h"

KCPreferenceEmbeddedGeneral::KCPreferenceEmbeddedGeneral(QWidget *parent) :
    KCPreferenceSuperList(parent)
{
    //Get translate
    retranslate();

    //Get configure settings
    instance=KCGeneralConfigure::getInstance();

    addTitle(generalTitleText[titleEnvironment]);
    addItemCombo(comboItemCaption[comboDefaultProgrammingLanguage],
                 comboItemText[comboDefaultProgrammingLanguage],
                 instance->getDefaultLanguageMode());
    addItemBoolean(booleanItemCaption[booleanUseDefaultLanguageOnOpen],
                   instance->getUseDefaultLanguageWhenOpen());
    addItemBoolean(booleanItemCaption[booleanUseDefaultLanguageOnSave],
                   instance->getUseDefaultLanguageWhenSave());
    addTitle(generalTitleText[titleAutomaticRemember]);
    addItemBoolean(booleanItemCaption[booleanAutoOpenUnclosed],
                   instance->getRememberUnclosedFile());
    addTitle(generalTitleText[titleHistory]);
    addItemInt(intItemCaption[intItemHistoryMax],
               KCHistoryConfigure::getInstance()->getMaxRecentFilesSize(),
               100,
               4);
    addTitle(generalTitleText[titleSearchOptions]);
    addItemCombo(comboItemCaption[comboSearchEngine],
                 comboItemText[comboSearchEngine],
                 instance->getSearchEngineIndex());
    addStretch();
}

void KCPreferenceEmbeddedGeneral::retranslate()
{
    generalTitleText[titleEnvironment]=QString(" " + tr("Envronment"));
    generalTitleText[titleAutomaticRemember]=QString(" " + tr("Automatic Remember"));
    generalTitleText[titleHistory]=QString(" " + tr("History"));
    generalTitleText[titleSearchOptions]=QString(" " + tr("Search Options"));

    comboItemCaption[comboDefaultProgrammingLanguage]=tr("Default Programming Language:");
    comboItemText[comboDefaultProgrammingLanguage].clear();
    comboItemText[comboDefaultProgrammingLanguage].append(tr("Plain Text"));
    comboItemText[comboDefaultProgrammingLanguage].append(tr("C"));
    comboItemText[comboDefaultProgrammingLanguage].append(tr("C++"));
    comboItemText[comboDefaultProgrammingLanguage].append(tr("Pascal"));

    comboItemCaption[comboSearchEngine]=tr("Online Search Engine:");
    comboItemText[comboSearchEngine].clear();
    QList<searchEngine> searchEngines=KCGeneralConfigure::getInstance()->getSearchEngineList();
    for(int i=0; i<searchEngines.count(); i++)
    {
        comboItemText[comboSearchEngine].append(searchEngines[i].name);
    }

    booleanItemCaption[booleanUseDefaultLanguageOnOpen]=tr("Auto select default language file suffix when opening files:");
    booleanItemCaption[booleanUseDefaultLanguageOnSave]=tr("Auto select default language file suffix when saving a file:");
    booleanItemCaption[booleanAutoOpenUnclosed]=tr("Restore files when quitting and re-opening files:");

    intItemCaption[intItemHistoryMax]=tr("Maximum History Tracking Items:");
}

void KCPreferenceEmbeddedGeneral::retranslateAndSet()
{
    retranslate();
    for(int i=titleEnvironment; i<titleCount; i++)
    {
        contents->getSuperListTitles().at(i)->setText(generalTitleText[i]);
    }
}