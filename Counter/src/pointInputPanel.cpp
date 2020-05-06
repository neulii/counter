#include "pointInputPanel.h"


PointInputPanel::PointInputPanel(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxPanel(parent, id, pos, size, style, name)
{

	wxLogDebug("new pointinputpanel");
	wxBoxSizer* sizer;
	sizer = new wxBoxSizer(wxVERTICAL);

	playerName = new wxStaticText(this, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
	playerName->Wrap(-1);
	playerName->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString));

	sizer->Add(playerName, 0, wxALL | wxEXPAND , 5);

	pointsInput = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTER);
	pointsInput->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString));

	sizer->Add(pointsInput, 0, wxALL | wxEXPAND, 5);

	this->SetSizer(sizer);
	this->Layout();
}

wxTextCtrl& PointInputPanel::getTextField()
{

	return *pointsInput;

}

std::string PointInputPanel::getInput()
{
	wxString input = pointsInput->GetValue();

	std::string st = std::string(input.mb_str(wxConvUTF8));

	return st;
}

void PointInputPanel::setLabelText(std::string labelText)
{
	playerName->SetLabelText(labelText);
}
