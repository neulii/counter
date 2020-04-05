#ifndef NEWGAMEWINDOW_H
#define NEWGAMEWINDOW_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "inputPanel.h"

class NewGameWindow :
	public wxDialog
{

public:
	NewGameWindow(const wxString& title, const wxPoint& pos, const wxSize& size);

	//evt functionso
	void OnClose(wxCloseEvent& event);
	void SelectedNumberOfPlayersChoice(wxCommandEvent& event);
	void ButtonClicked(wxCommandEvent& event);
	
	void setGuiPlayers(int playerNumber);

private:
	int newNumberOfPlayers = 2;
	
	wxPanel* mainPanel;

	wxChoice* numberOfPlayers;					//field to select number of players
	std::vector<InputPanel*> inputPanels;		//input lines for player

	wxButton* okButton;
	wxButton* cancelButton;


	wxDECLARE_EVENT_TABLE();

};

enum newGameWindowIDs
{
	ID_NumberOfPlayers = 11,
	ID_InputFieldBasic = 1000,
	ID_Button_Ok = 2001,
	ID_Button_Cancel = 2002
};

#endif // !NEWGAMEWINDOW_H