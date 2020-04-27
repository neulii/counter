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
       
public:
    PlayingPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 250,64 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );



};

#endif //PLAYINGPANEL 
