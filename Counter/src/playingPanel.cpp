#include "playingPanel.h"
#include "include/main_lib.h"




PlayingPanel::PlayingPanel( wxWindow* parent,int players, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name )
	: wxPanel( parent, id, pos, size, style, name ), players(this->players)
{

	playPanelSizer = new wxBoxSizer(wxVERTICAL);

	this->SetSize(parent->GetSize());

	//wxMessageBox(neulib::intToC_String(pointInputPanels.size()));


	for (int i = 0; i < players; i++)
	{
		PointInputPanel* tempPanel = new PointInputPanel(this);

		tempPanel->SetPosition(wxPoint(0,i*100));

		pointInputPanels.push_back(tempPanel);

		playPanelSizer->Add(tempPanel, wxALL | wxEXPAND, 5);

	}

	this->Layout();
}
