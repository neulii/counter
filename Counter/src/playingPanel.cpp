#include "playingPanel.h"
#include "include/main_lib.h"

PlayingPanel::PlayingPanel(wxWindow* parent, int players, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name)
	: wxPanel(parent, id, pos, size, style, name), players(players),game(NULL)
{

	playPanelSizer = new wxBoxSizer(wxHORIZONTAL);
	leftSizer = new wxBoxSizer(wxVERTICAL);






	//rightSizer = new wxBoxSizer(wxVERTICAL);

	this->SetSize(parent->GetSize());

	//wxMessageBox(neulib::intToC_String(pointInputPanels.size()));

	for (int i = 0; i < players; i++)
	{
		PointInputPanel* tempPanel = new PointInputPanel(this);

		//tempPanel->SetPosition(wxPoint(0,i*100));

		pointInputPanels.push_back(tempPanel);

		leftSizer->Add(tempPanel, 1, wxEXPAND | wxALL, 5);
	}

	enterInputButton = new wxButton(this, 1001, "Enter",wxPoint(0,players*100+50) , wxSize(100, 50));

	leftSizer->Add(enterInputButton);
	playPanelSizer->Add(leftSizer, 1, wxALL, 5);
	


	rightSizer = new wxBoxSizer(wxVERTICAL);
	
	pointGrid = new wxGrid(parent, wxID_ANY);
	pointGrid->CreateGrid(1, 3);

	rightSizer->Add(pointGrid);

	playPanelSizer->Add(rightSizer, 1, wxEXPAND, 5);

	this->SetSizer(playPanelSizer);

	this->Layout();
	this->SetFocus();
}

PlayingPanel::PlayingPanel( wxWindow* parent,Game& game)
	: PlayingPanel(parent, game.getPlayers().size())
{
	//wxMessageBox(neulib::intToC_String(players), "tst");

	this->game = &game;
	this->players = game.getPlayers().size();

	for(int i = 0; i<players;i++)
	{
		//title the labels of the pointinputpanels with the name
		pointInputPanels.at(i)->setLabelText(game.getPlayers().at(i)->getName());

		//title the grid labels
		pointGrid->SetColLabelValue(i, this->game->getPlayers().at(i)->getName());
		
	}

	pointGrid->SetColLabelValue(players , "Differenz");

}
