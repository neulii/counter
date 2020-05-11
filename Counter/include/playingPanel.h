#ifndef PLAYINGPANEL_H
#define PLAYINGPANEL_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <vector>

#include <wx/grid.h>
#include "pointInputPanel.h"
#include "game.h"

class PlayingPanel : public wxPanel
{

private:


    wxBoxSizer* playPanelSizer;
    wxBoxSizer* leftSizer;
    wxBoxSizer* rightSizer;

    int players = 0;

    Game* game = nullptr;
    wxGrid* pointGrid;
    
    std::vector<PointInputPanel*> pointInputPanels;

    wxButton* enterInputButton;

public:
    PlayingPanel( wxWindow* parent, int players, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );
    PlayingPanel( wxWindow* parent, Game& game);
};

#endif //PLAYINGPANEL
