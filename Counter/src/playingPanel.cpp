#include "playingPanel.h"


PlayingPanel::PlayingPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) 
	: wxPanel( parent, id, pos, size, style, name )
{
	wxBoxSizer* panelSizer;
	panelSizer = new wxBoxSizer(wxHORIZONTAL);


	

	this->Layout();
}




