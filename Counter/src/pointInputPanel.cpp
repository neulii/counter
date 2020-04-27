#include "pointInputPanel.h"


PointInputPanel::PointInputPanel( wxWindow* parent, const std::string& nameOfPlayer, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) 
	: wxPanel( parent, id, pos, size, style, name )
{
	//wxBoxSizer* panelSizer;
	//panelSizer = new wxBoxSizer( wxHORIZONTAL);

	playerName = new wxStaticText( this, wxID_ANY, wxT("player"), wxPoint(10,10), wxSize( 60,30 ), 0 );

	playerName->SetLabel(nameOfPlayer);

	wxFont* tempFont = new wxFont();
	*tempFont =	playerName->GetFont();
	tempFont->SetPointSize(20);
	playerName->SetFont(*tempFont);
	
	//panelSizer->Add(playerName,1);

	//labelPlayer->Wrap( -1 );
	//panelSizer->Add( labelPlayer, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	inputPoints = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxPoint(10,40), wxSize( 150,30 ), 0 );
	//panelSizer->Add( inputPoints, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

//	this->SetSizer( panelSizer );
	this->Layout();
}

wxTextCtrl& PointInputPanel::getTextField()
{

	return *inputPoints;

}

std::string PointInputPanel::getInput()
{
	wxString input = inputPoints->GetValue();

	std::string st = std::string(input.mb_str(wxConvUTF8));



	return st;
}

void PointInputPanel::setLabelText(std::string labelText)
{
	playerName->SetLabelText(labelText);
}
