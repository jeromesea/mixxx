#ifndef DLGHIDDEN_H
#define DLGHIDDEN_H

#include "library/ui_dlghidden.h"
#include "preferences/usersettings.h"
#include "library/library.h"
#include "library/libraryview.h"
#include "library/trackcollection.h"
#include "controllers/keyboard/keyboardeventfilter.h"

class WTrackTableView;
class HiddenTableModel;
class QItemSelection;

class DlgHidden : public QWidget, public Ui::DlgHidden, public LibraryView {
    Q_OBJECT
  public:
    DlgHidden(QWidget* parent, UserSettingsPointer pConfig, TrackCollection* pTrackCollection,
              KeyboardEventFilter* pKeyboard);
    virtual ~DlgHidden();

    void onShow();
    void onSearch(const QString& text);
    void setTrackTable(Library* pLibrary, WTrackTableView* pTrackTableView, int paneId);
    inline void setFocusedPane(int focusedPane) { 
        m_focusedPane = focusedPane;
    }

  public slots:
    void clicked();
    void selectAll();
    void selectionChanged(const QItemSelection&, const QItemSelection&);    

  signals:
    void trackSelected(TrackPointer pTrack);

  private:
    void activateButtons(bool enable);
    HiddenTableModel* m_pHiddenTableModel;
    QHash<int, WTrackTableView*> m_trackTableView;
    int m_focusedPane;
};

#endif //DLGHIDDEN_H
