#ifndef PLAYINGPANEL_H
#define PLAYINGPANEL_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <vector>


#include "pointInputPanel.h"

class PlayingPanel : public wxPanel
{

private:

    wxBoxSizer* playPanelSizer;

    int players = 0;

    std::vector<PointInputPanel*> pointInputPanels;

public:
    PlayingPanel( wxWindow* parent, int players, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );

};

#endif //PLAYINGPANEL
