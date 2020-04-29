#include "playingPanel.h"


PlayingPanel::PlayingPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) 
	: wxPanel( parent, id, pos, size, style, name )
{
	wxBoxSizer* playPanelSizer;
	playPanelSizer = new wxBoxSizer(wxVERTICAL);



	this->SetSize(parent->GetSize());

	pointInput = new PointInputPanel(this);
	pointInput_2 = new PointInputPanel(this);
	pointInput_2->SetPosition(wxPoint(100, 100));


	//sizer->Add(playerName, 0, wxALL | wxEXPAND, 5);

	playPanelSizer->Add(pointInput , wxALL | wxEXPAND,5);
	playPanelSizer->Add(pointInput_2, wxALL | wxEXPAND, 5);

	

	this->Layout();
}




