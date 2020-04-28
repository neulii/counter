#include "playingPanel.h"


PlayingPanel::PlayingPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) 
	: wxPanel( parent, id, pos, size, style, name )
{


	this->SetSize(parent->GetSize());

	pointInput = new PointInputPanel(this);

	//this->Layout();
}




