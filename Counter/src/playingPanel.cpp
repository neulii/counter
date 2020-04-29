#include "playingPanel.h"


PlayingPanel::PlayingPanel( wxWindow* parent,int players, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) 
	: wxPanel( parent, id, pos, size, style, name ), players(this->players)
{
	
	playPanelSizer = new wxBoxSizer(wxVERTICAL);

	this->SetSize(parent->GetSize());

	for (int i = 0; i < players; i++)
	{
		tempPanel = new PointInputPanel(this);;

		tempPanel->SetPosition(wxPoint(0,i*100));

		pointInputPanels.push_back(tempPanel);
		
		playPanelSizer->Add(tempPanel, wxALL | wxEXPAND, 5);

	}



	//sizer->Add(playerName, 0, wxALL | wxEXPAND, 5);

	
	//playPanelSizer->Add(pointInput_2, wxALL | wxEXPAND, 5);

	

	this->Layout();
}






