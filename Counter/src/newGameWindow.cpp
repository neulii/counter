#include "newGameWindow.h"

NewGameWindow::NewGameWindow(const wxString& title, const wxPoint& pos, const wxSize& size)
	:wxDialog(NULL, wxID_ANY, title, pos, size)
{

	mainPanel = new wxPanel(this,1, wxDefaultPosition, wxDefaultSize);
	
	
	int heightOfLine = 25;

	wxStaticText* numberPlayersText = new wxStaticText(mainPanel, 
													   wxID_ANY, 
													   "Anzahl Spieler", 
													   wxPoint(20, heightOfLine));

	wxArrayString choices;
	choices.Add("2");
	choices.Add("3");

	numberOfPlayers = new wxChoice(mainPanel, 
								   ID_NumberOfPlayers, 
								   wxPoint(150, 20), 
								   wxSize(50, heightOfLine),
								   choices);
	numberOfPlayers->Select(0);
	setGuiPlayers(2);


	//ok button + position
	
	int buttonWidth = 100;

	wxSize okButtonSize(buttonWidth, 30);
	wxSize okButtonOffsetRightBottom(50, 160);

	int xPosOK = this->GetSize().GetWidth() - okButtonOffsetRightBottom.GetWidth() - okButtonSize.GetWidth();
	int yPosOK = this->GetSize().GetHeight() - okButtonOffsetRightBottom.GetHeight() - okButtonSize.GetHeight();

	wxPoint okButtonPosition(xPosOK, yPosOK);
	okButton = new wxButton(mainPanel, ID_Button_Ok, "OK", okButtonPosition, okButtonSize);

	//cancel button + position
	wxSize cancelButtonSize(buttonWidth, 30);
	

	int offsetOk_Cancel = 10;
	int xPosCANCEL = okButtonPosition.x;
	int yPosCANCEL = okButtonPosition.y + offsetOk_Cancel + okButton->GetSize().GetHeight();

	wxPoint cancelButtonPosition(xPosCANCEL, yPosCANCEL);

	cancelButton = new wxButton(mainPanel, ID_Button_Cancel, "Abbrechen", cancelButtonPosition, cancelButtonSize);



	this->Center();
	
	inputPanels.at(0)->SetFocus();
}

void NewGameWindow::OnClose(wxCloseEvent& event)
{
	Destroy();
}

void NewGameWindow::SelectedNumberOfPlayersChoice(wxCommandEvent& event)
{

	int selected = 0;

	selected = numberOfPlayers->GetSelection();
	
	newNumberOfPlayers = selected + 2;

	setGuiPlayers(newNumberOfPlayers);

	inputPanels.at(0)->SetFocus(); }
void NewGameWindow::setGuiPlayers(int playerNumber)
{
	//panelPlayers= new wxPanel(this, wxID_ANY);
	//panelPlayers->SetSize(this->GetSize());
	
	int yStart = 100;
	int xStart = 20;

	int yLine;

	int offsetBetweenLines = 20;
	
		for (int ii = 0; ii <inputPanels.size(); ii++)
		{
			inputPanels.at(ii)->Destroy();

		}

	inputPanels.clear();
	
	for (int i = 0; i < playerNumber; i++)
	{
		
		yLine = yStart + i * 25 + i * offsetBetweenLines;
		
		//size of InputPanel
		int panelWidth = 200;
		int panelHeight = 40;

		InputPanel* tempPanel = new InputPanel(mainPanel, 1000 + 1, wxPoint(100, yLine), wxSize(panelWidth, panelHeight));
		tempPanel->setLabelText("Spieler " + std::to_string(i+1));
		inputPanels.push_back(tempPanel);
	}
}

void NewGameWindow::ButtonClicked(wxCommandEvent& event)
{
	int answer = 0;
	
	wxMessageDialog* question = new wxMessageDialog(NULL,
		wxT("Wollen Sie wirklich abbrechen?"), wxT("Achtung!! Die eingegebenen Daten gehen verloren!!"),
		wxYES_NO | wxNO_DEFAULT | wxICON_WARNING);
	
	switch (event.GetId())
	{

	//Cancel Button
	case ID_Button_Cancel:
		answer = question->ShowModal();

		if (answer == wxID_YES) {
			question->Destroy();
			this->Destroy();
		
		}
		break;
	
	//OK Button
	case ID_Button_Ok:

		//collect data from input fields





		break;
	default:
		break;
	}

}

wxBEGIN_EVENT_TABLE(NewGameWindow, wxDialog)
	EVT_CLOSE(NewGameWindow::OnClose)
	EVT_CHOICE(ID_NumberOfPlayers, NewGameWindow::SelectedNumberOfPlayersChoice)
	EVT_BUTTON(ID_Button_Cancel, NewGameWindow::ButtonClicked)
	EVT_BUTTON(ID_Button_Ok, NewGameWindow::ButtonClicked)
wxEND_EVENT_TABLE()
