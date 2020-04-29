#ifndef PLAYINGPANEL_H 
#define PLAYINGPANEL_H 

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif


#include "pointInputPanel.h"

class PlayingPanel : public wxPanel
{

private:

    int players;
      
    PointInputPanel* pointInput;
    PointInputPanel * pointInput_2;




public:
    PlayingPanel( wxWindow* parent, int players, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );



};

#endif //PLAYINGPANEL 
