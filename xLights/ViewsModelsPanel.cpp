#include "ViewsModelsPanel.h"

//(*InternalHeaders(ViewsModelsPanel)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include "../include/model-16.xpm"
#include "../include/timing-16.xpm"
#include "../include/eye-16.xpm"
#include "../include/eye-16_gray.xpm"
#include <wx/xml/xml.h>
#include "sequencer/SequenceElements.h"
#include "xLightsMain.h"
#include "SequenceViewManager.h"
#include <wx/dnd.h>

#define TIMING_IMAGE 2
#define MODEL_IMAGE 3

//(*IdInit(ViewsModelsPanel)
const long ViewsModelsPanel::ID_LISTCTRL1 = wxNewId();
const long ViewsModelsPanel::ID_BUTTON3 = wxNewId();
const long ViewsModelsPanel::ID_BUTTON4 = wxNewId();
const long ViewsModelsPanel::ID_BUTTON5 = wxNewId();
const long ViewsModelsPanel::ID_BUTTON6 = wxNewId();
const long ViewsModelsPanel::ID_STATICTEXT1 = wxNewId();
const long ViewsModelsPanel::ID_LISTCTRL_VIEWS = wxNewId();
const long ViewsModelsPanel::ID_BUTTON1 = wxNewId();
const long ViewsModelsPanel::ID_BUTTON2 = wxNewId();
const long ViewsModelsPanel::ID_LISTCTRL_MODELS = wxNewId();
const long ViewsModelsPanel::ID_SCROLLEDWINDOW1 = wxNewId();
const long ViewsModelsPanel::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ViewsModelsPanel,wxPanel)
	//(*EventTable(ViewsModelsPanel)
	//*)
    EVT_COMMAND(wxID_ANY, EVT_LISTITEM_CHECKED, ViewsModelsPanel::OnListCtrlItemCheck)
END_EVENT_TABLE()

ViewsModelsPanel::ViewsModelsPanel(xLightsFrame *frame, wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size) : _xlFrame(frame)
{
	//(*Initialize(ViewsModelsPanel)
	wxFlexGridSizer* FlexGridSizer4;
	wxFlexGridSizer* FlexGridSizer10;
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer5;
	wxFlexGridSizer* FlexGridSizer9;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer7;
	wxFlexGridSizer* FlexGridSizer8;
	wxFlexGridSizer* FlexGridSizer6;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));
	FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer1->AddGrowableCol(0);
	FlexGridSizer1->AddGrowableRow(0);
	Panel_Sizer = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	FlexGridSizer9 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer9->AddGrowableRow(0);
	ScrolledWindowViewsModels = new wxScrolledWindow(Panel_Sizer, ID_SCROLLEDWINDOW1, wxDefaultPosition, wxDefaultSize, wxVSCROLL|wxHSCROLL, _T("ID_SCROLLEDWINDOW1"));
	FlexGridSizer10 = new wxFlexGridSizer(0, 3, 0, 0);
	FlexGridSizer10->AddGrowableCol(2);
	FlexGridSizer10->AddGrowableRow(0);
	FlexGridSizer2 = new wxFlexGridSizer(0, 3, 0, 0);
	FlexGridSizer2->AddGrowableCol(0);
	FlexGridSizer2->AddGrowableRow(0);
	ListCtrlNonModels = new wxListCtrl(ScrolledWindowViewsModels, ID_LISTCTRL1, wxDefaultPosition, wxDefaultSize, wxLC_REPORT, wxDefaultValidator, _T("ID_LISTCTRL1"));
	FlexGridSizer2->Add(ListCtrlNonModels, 1, wxALL|wxEXPAND, 5);
	FlexGridSizer10->Add(FlexGridSizer2, 1, wxALL|wxEXPAND, 5);
	FlexGridSizer5 = new wxFlexGridSizer(0, 1, 0, 0);
	Button_AddAll = new wxButton(ScrolledWindowViewsModels, ID_BUTTON3, _(">>"), wxDefaultPosition, wxSize(32,30), 0, wxDefaultValidator, _T("ID_BUTTON3"));
	FlexGridSizer5->Add(Button_AddAll, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button_AddSelected = new wxButton(ScrolledWindowViewsModels, ID_BUTTON4, _(">"), wxDefaultPosition, wxSize(32,32), 0, wxDefaultValidator, _T("ID_BUTTON4"));
	FlexGridSizer5->Add(Button_AddSelected, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button_RemoveSelected = new wxButton(ScrolledWindowViewsModels, ID_BUTTON5, _("<"), wxDefaultPosition, wxSize(32,32), 0, wxDefaultValidator, _T("ID_BUTTON5"));
	FlexGridSizer5->Add(Button_RemoveSelected, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button_RemoveAll = new wxButton(ScrolledWindowViewsModels, ID_BUTTON6, _("<<"), wxDefaultPosition, wxSize(32,32), 0, wxDefaultValidator, _T("ID_BUTTON6"));
	FlexGridSizer5->Add(Button_RemoveAll, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer10->Add(FlexGridSizer5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer3 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer3->AddGrowableCol(0);
	FlexGridSizer3->AddGrowableRow(1);
	FlexGridSizer6 = new wxFlexGridSizer(0, 2, 0, 0);
	FlexGridSizer6->AddGrowableCol(0);
	FlexGridSizer6->AddGrowableRow(0);
	FlexGridSizer7 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer7->AddGrowableCol(0);
	FlexGridSizer7->AddGrowableRow(1);
	StaticText1 = new wxStaticText(ScrolledWindowViewsModels, ID_STATICTEXT1, _("View:"), wxDefaultPosition, wxSize(44,16), 0, _T("ID_STATICTEXT1"));
	FlexGridSizer7->Add(StaticText1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	ListCtrlViews = new wxCheckedListCtrl(ScrolledWindowViewsModels, ID_LISTCTRL_VIEWS, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxLC_SINGLE_SEL, wxDefaultValidator, _T("ID_LISTCTRL_VIEWS"));
	ListCtrlViews->SetMinSize(wxDLG_UNIT(ScrolledWindowViewsModels,wxSize(100,50)));
	FlexGridSizer7->Add(ListCtrlViews, 1, wxALL|wxEXPAND, 5);
	FlexGridSizer6->Add(FlexGridSizer7, 1, wxALL|wxEXPAND, 5);
	FlexGridSizer8 = new wxFlexGridSizer(0, 1, 0, 0);
	Button_AddView = new wxButton(ScrolledWindowViewsModels, ID_BUTTON1, _("Add"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer8->Add(Button_AddView, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button_DeleteView = new wxButton(ScrolledWindowViewsModels, ID_BUTTON2, _("Delete"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	FlexGridSizer8->Add(Button_DeleteView, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer6->Add(FlexGridSizer8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer3->Add(FlexGridSizer6, 1, wxALL|wxEXPAND, 5);
	FlexGridSizer4 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer4->AddGrowableCol(0);
	FlexGridSizer4->AddGrowableRow(0);
	ListCtrlModels = new wxCheckedListCtrl(ScrolledWindowViewsModels, ID_LISTCTRL_MODELS, wxDefaultPosition, wxDefaultSize, wxLC_REPORT, wxDefaultValidator, _T("ID_LISTCTRL_MODELS"));
	ListCtrlModels->SetMinSize(wxDLG_UNIT(ScrolledWindowViewsModels,wxSize(75,85)));
	FlexGridSizer4->Add(ListCtrlModels, 1, wxALL|wxEXPAND, 5);
	FlexGridSizer3->Add(FlexGridSizer4, 1, wxALL|wxEXPAND, 5);
	FlexGridSizer10->Add(FlexGridSizer3, 1, wxALL|wxEXPAND, 5);
	ScrolledWindowViewsModels->SetSizer(FlexGridSizer10);
	FlexGridSizer10->Fit(ScrolledWindowViewsModels);
	FlexGridSizer10->SetSizeHints(ScrolledWindowViewsModels);
	FlexGridSizer9->Add(ScrolledWindowViewsModels, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel_Sizer->SetSizer(FlexGridSizer9);
	FlexGridSizer9->Fit(Panel_Sizer);
	FlexGridSizer9->SetSizeHints(Panel_Sizer);
	FlexGridSizer1->Add(Panel_Sizer, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_BEGIN_DRAG,(wxObjectEventFunction)&ViewsModelsPanel::OnListCtrlNonModelsBeginDrag);
	Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&ViewsModelsPanel::OnListCtrlNonModelsItemSelect);
	Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_KEY_DOWN,(wxObjectEventFunction)&ViewsModelsPanel::OnListCtrlNonModelsKeyDown);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ViewsModelsPanel::OnButton_AddAllClick);
	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ViewsModelsPanel::OnButton_AddSelectedClick);
	Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ViewsModelsPanel::OnButton_RemoveSelectedClick);
	Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ViewsModelsPanel::OnButton_RemoveAllClick);
	Connect(ID_LISTCTRL_VIEWS,wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&ViewsModelsPanel::OnListCtrlViewsItemSelect);
	Connect(ID_LISTCTRL_VIEWS,wxEVT_COMMAND_LIST_KEY_DOWN,(wxObjectEventFunction)&ViewsModelsPanel::OnListCtrlViewsKeyDown);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ViewsModelsPanel::OnButton_AddViewClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ViewsModelsPanel::OnButton_DeleteViewClick);
	Connect(ID_LISTCTRL_MODELS,wxEVT_COMMAND_LIST_BEGIN_DRAG,(wxObjectEventFunction)&ViewsModelsPanel::OnListView_ViewItemsBeginDrag);
	Connect(ID_LISTCTRL_MODELS,wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&ViewsModelsPanel::OnListView_ViewItemsItemSelect);
	Connect(ID_LISTCTRL_MODELS,wxEVT_COMMAND_LIST_KEY_DOWN,(wxObjectEventFunction)&ViewsModelsPanel::OnListView_ViewItemsKeyDown);
	Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&ViewsModelsPanel::OnLeftUp);
	Connect(wxEVT_SIZE,(wxObjectEventFunction)&ViewsModelsPanel::OnResize);
	//*)

    //Connect(ID_LISTCTRL_VIEWS, wxEVT_LIST_ITEM_CHECKED, (wxObjectEventFunction)&ViewsModelsPanel::OnListCtrlViewsItemCheck);

    ListCtrlViews->SetImages((char**)eye_16, (char**)eye_16_gray);

    _numViews = 0;
    _numModels = 0;
    _numNonModels = 0;
    _sequenceElements = nullptr;
    _mainViewsChoice = nullptr;

    ListCtrlModels->SetImages((char**)eye_16, (char**)eye_16_gray);
    ListCtrlModels->AddImage((char**)timing_16);
    ListCtrlModels->AddImage((char**)model_16);

    _imageList = new wxImageList(16, 16, true);
    _imageList->Add(wxIcon((char**)timing_16));
    _imageList->Add(wxIcon((char**)model_16));

    MyTextDropTarget *mdt = new MyTextDropTarget(ListCtrlModels);
    ListCtrlModels->SetDropTarget(mdt);

    mdt = new MyTextDropTarget(ListCtrlNonModels);
    ListCtrlNonModels->SetDropTarget(mdt);

    ValidateWindow();
}

ViewsModelsPanel::~ViewsModelsPanel()
{
	//(*Destroy(ViewsModelsPanel)
	//*)
    delete _imageList;
}

void ViewsModelsPanel::PopulateModels()
{
    ListCtrlNonModels->ClearAll();

    ListCtrlNonModels->SetImageList(_imageList, wxIMAGE_LIST_SMALL);

    wxListItem nm0;
    nm0.SetId(0);
    nm0.SetImage(-1);
    nm0.SetText(_(""));
    nm0.SetWidth(22);
    ListCtrlNonModels->InsertColumn(0, nm0);

    wxListItem nm1;
    nm1.SetId(1);
    nm1.SetText(_("Timing/Model"));
    nm1.SetWidth(130);
    ListCtrlNonModels->InsertColumn(1, nm1);

    ListCtrlModels->ClearAll();

    wxListItem col0;
    col0.SetId(0);
    col0.SetText(_(""));
    col0.SetWidth(28);
    ListCtrlModels->InsertColumn(0, col0);

    wxListItem col1;
    col1.SetId(1);
    col1.SetText(_(""));
    col1.SetWidth(22);
    ListCtrlModels->InsertColumn(1, col1);

    wxListItem col2;
    col2.SetId(2);
    col2.SetText(_("Timing/Model"));
    col2.SetWidth(130);
    ListCtrlModels->InsertColumn(2, col2);

    _numModels = 0;
    _numNonModels = 0;
    int current_view = _sequenceElements->GetCurrentView();
    for (int i = 0; i < _sequenceElements->GetElementCount(); i++)
    {
        Element* elem = _sequenceElements->GetElement(i);
        if (elem->GetType() == ELEMENT_TYPE_TIMING)
        {
            TimingElement *te = dynamic_cast<TimingElement*>(elem);
            if (current_view == MASTER_VIEW || _sequenceElements->TimingIsPartOfView(te, current_view))
            {
                AddTimingToList(elem);
            }
            else
            {
                AddTimingToNotList(elem);
            }
        }
    }

    if (current_view > 0)
    {
        _sequenceViewManager->SetSelectedView(current_view);
        SequenceView * view = _sequenceViewManager->GetSelectedView();
        if (view != nullptr)
        {
            _sequenceElements->AddMissingModelsToSequence(view->GetModelsString());
            auto models = view->GetModels();
            for (auto it = models.begin(); it != models.end(); ++it)
            {
                Element* elem = _sequenceElements->GetElement(*it);
                AddModelToList(elem);
            }

            // add everything that isnt in the view
            for (int i = 0; i < _sequenceElements->GetElementCount(); i++)
            {
                Element* elem = _sequenceElements->GetElement(i);
                if (elem->GetType() == ELEMENT_TYPE_MODEL && std::find(models.begin(), models.end(), elem->GetName()) == models.end())
                {
                    AddModelToNotList(elem);
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < _sequenceElements->GetElementCount(); i++)
        {
            Element* elem = _sequenceElements->GetElement(i);
            if (elem->GetType() == ELEMENT_TYPE_MODEL)
            {
                AddModelToList(elem);
            }
        }
    }
}

int ViewsModelsPanel::GetFirstModelIndex()
{
    for (int i = 0; i < ListCtrlModels->GetItemCount(); i++)
    {
        Element* e = (Element*)ListCtrlModels->GetItemData(i);
        if (e->GetType() == ELEMENT_TYPE_MODEL)
        {
            return i;
        }
    }
    return 0;
}

bool ViewsModelsPanel::IsModelAGroup(const std::string& modelname) const
{
    for (auto it = _modelGroups->GetChildren(); it != nullptr; it = it->GetNext())
    {
        if (it->GetName() == "modelGroup" && it->GetAttribute("name") == modelname)
        {
            return true;
        }
    }
    return false;
}

void ViewsModelsPanel::OnListView_ViewItemsBeginDrag(wxListEvent& event)
{
    ValidateWindow();
}

void ViewsModelsPanel::OnListView_ViewItemsItemSelect(wxListEvent& event)
{
    ValidateWindow();
}

void ViewsModelsPanel::OnListView_ViewItemsKeyDown(wxListEvent& event)
{
    auto key = event.GetKeyCode();
    if (key == WXK_LEFT || key == WXK_DELETE || key == WXK_NUMPAD_DELETE)
    {
        RemoveSelectedModels();
    }

    ValidateWindow();
}

bool IsItemSelected(wxListCtrl* ctrl, int item)
{
    return ctrl->GetItemState(item, wxLIST_STATE_SELECTED) == wxLIST_STATE_SELECTED;
}

void ViewsModelsPanel::RemoveSelectedModels()
{
    if (_seqData->NumFrames() == 0) return;

    if (_sequenceElements->GetCurrentView() == MASTER_VIEW)
    {
        if (wxMessageBox("Delete all effects and layers for the selected model(s)?", "Confirm Delete?", wxICON_QUESTION | wxYES_NO) == wxYES)
        {
            for (size_t i = 0; i < ListCtrlModels->GetItemCount(); ++i)
            {
                if (IsItemSelected(ListCtrlModels, i))
                {
                    // Got a selected item so handle it
                    Element* e = (Element*)ListCtrlModels->GetItemData(i);
                    _sequenceElements->DeleteElement(e->GetName());
                }
            }
        }
    }
    else
    {
        for (size_t i = 0; i < ListCtrlModels->GetItemCount(); ++i)
        {
            if (IsItemSelected(ListCtrlModels, i))
            {
                // Got a selected item so handle it
                Element* e = (Element*)ListCtrlModels->GetItemData(i);
                if (e->GetType() == ELEMENT_TYPE_MODEL)
                {
                    _sequenceElements->DeleteElementFromView(e->GetName(), _sequenceElements->GetCurrentView());
                }
                else
                {
                    _sequenceElements->DeleteTimingFromView(e->GetName(), _sequenceElements->GetCurrentView());
                    _sequenceElements->SetTimingVisibility(_sequenceElements->GetViewName(_sequenceElements->GetCurrentView()));
                }
            }
        }
        UpdateModelsForSelectedView();
    }

    MarkViewsChanged();

    PopulateModels();

    // Update Grid
    _xlFrame->DoForceSequencerRefresh();
}

void ViewsModelsPanel::AddSelectedModels()
{
    if (_seqData->NumFrames() == 0) return;

    std::string type = "model";
    int current_view = _sequenceElements->GetCurrentView();

    if (current_view == MASTER_VIEW)
    {
        for (size_t i = 0; i < ListCtrlNonModels->GetItemCount(); ++i)
        {
            if (IsItemSelected(ListCtrlNonModels, i))
            {
                Element* ee = (Element*)ListCtrlNonModels->GetItemData(i);
                if (ee != nullptr && ee->GetType() != ELEMENT_TYPE_TIMING)
                {
                    Element* e = _sequenceElements->AddElement(ListCtrlNonModels->GetItemText(i, 1).ToStdString(), type, true, false, false, false);
                    if (e != nullptr)
                    {
                        e->AddEffectLayer();
                    }
                }
            }
        }
    }
    else
    {
        auto view = _sequenceViewManager->GetSelectedView();
        for (size_t i = 0; i < ListCtrlNonModels->GetItemCount(); ++i)
        {
            if (IsItemSelected(ListCtrlNonModels, i))
            {
                Element* ee = (Element*)ListCtrlNonModels->GetItemData(i);
                if (ee != nullptr && ee->GetType() != ELEMENT_TYPE_TIMING)
                {
                    view->AddModel(ListCtrlNonModels->GetItemText(i, 1).ToStdString());
                }
            }
        }

        _sequenceElements->AddMissingModelsToSequence(view->GetModelsString());
        for (size_t i = 0; i < ListCtrlNonModels->GetItemCount(); ++i)
        {
            if (IsItemSelected(ListCtrlNonModels, i))
            {
                Element* e = _sequenceElements->GetElement(ListCtrlNonModels->GetItemText(i, 1).ToStdString());
                if (e != nullptr && e->GetType() != ELEMENT_TYPE_TIMING)
                {
                    e->SetVisible(true);
                }
            }
        }

        std::string modelsString = _sequenceElements->GetViewModels(view->GetName());
        _sequenceElements->PopulateView(modelsString, current_view);

        std::vector<std::string> timings;
        for (size_t i = 0; i < ListCtrlNonModels->GetItemCount(); ++i)
        {
            if (IsItemSelected(ListCtrlNonModels, i))
            {
                Element* ee = (Element*)ListCtrlNonModels->GetItemData(i);
                if (ee != nullptr && ee->GetType() == ELEMENT_TYPE_TIMING)
                {
                    timings.push_back(ListCtrlNonModels->GetItemText(i, 1).ToStdString());
                }
            }
        }

        if (timings.size() > 0)
        {
            _sequenceElements->AddViewToTimings(timings, view->GetName());
        }

        _sequenceElements->SetTimingVisibility(view->GetName());
    }
    MarkViewsChanged();

    PopulateModels();

    // Update Grid
    _xlFrame->DoForceSequencerRefresh();
}

void ViewsModelsPanel::OnButton_AddAllClick(wxCommandEvent& event)
{
    for (int i = 0; i < ListCtrlNonModels->GetItemCount(); i++)
    {
        ListCtrlNonModels->SetItemState(i, wxLIST_STATE_SELECTED, wxLIST_STATE_SELECTED);
    }
    AddSelectedModels();

    ValidateWindow();
}

void ViewsModelsPanel::OnButton_AddSelectedClick(wxCommandEvent& event)
{
    AddSelectedModels();

    ValidateWindow();
}

void ViewsModelsPanel::OnButton_RemoveSelectedClick(wxCommandEvent& event)
{
    RemoveSelectedModels();

    ValidateWindow();
}

void ViewsModelsPanel::OnButton_RemoveAllClick(wxCommandEvent& event)
{
    for (int i = 0; i < ListCtrlModels->GetItemCount(); i++)
    {
        ListCtrlModels->SetItemState(i, wxLIST_STATE_SELECTED, wxLIST_STATE_SELECTED);
    }
    RemoveSelectedModels();

    ValidateWindow();
}

void ViewsModelsPanel::Initialize()
{
    if (_seqData->NumFrames() == 0) return;
    PopulateViews();
    PopulateModels();
    Fit();
    FitInside();
    ValidateWindow();
}

void ViewsModelsPanel::SetSequenceElementsModelsViews(SequenceData* seqData, SequenceElements* sequenceElements, wxXmlNode* modelsNode, wxXmlNode* modelGroupsNode, SequenceViewManager* sequenceViewManager)
{
    _sequenceElements = sequenceElements;
    _seqData = seqData;
    _models = modelsNode;
    _sequenceViewManager = sequenceViewManager;
    _modelGroups = modelGroupsNode;
}

void ViewsModelsPanel::ValidateWindow()
{
    if (ListCtrlNonModels->GetSelectedItemCount() == 0)
    {
        Button_AddSelected->Enable(false);
    }
    else
    {
        Button_AddSelected->Enable(true);
    }

    if (ListCtrlModels->GetSelectedItemCount() == 0)
    {
        Button_RemoveSelected->Enable(false);
    }
    else
    {
        Button_RemoveSelected->Enable(true);
    }

    if (ListCtrlViews->GetSelectedItemCount() == 0 || _sequenceViewManager->GetSelectedViewIndex() == MASTER_VIEW)
    {
        Button_DeleteView->Enable(false);
    }
    else
    {
        Button_DeleteView->Enable(true);
    }
}

void ViewsModelsPanel::UpdateModelsForSelectedView()
{
    int current_view = _sequenceElements->GetCurrentView();
    if (current_view != MASTER_VIEW)
    {
        wxString viewName = ListCtrlViews->GetItemText(current_view, 1);
        wxString models = "";
        for (int i = 0; i < _sequenceElements->GetElementCount(current_view); i++)
        {
            Element* elem = _sequenceElements->GetElement(i, current_view);
            if (elem->GetType() == ELEMENT_TYPE_MODEL)
            {
                if (models != "")
                {
                    models += ",";
                }
                models += elem->GetName();
            }
        }

        SequenceView* view = _sequenceViewManager->GetView(viewName.ToStdString());
        view->SetModels(models.ToStdString());
    }
    PopulateModels();
}

void ViewsModelsPanel::AddTimingToList(Element* timing)
{
    if (timing != nullptr)
    {
        wxListItem li;
        li.SetId(_numModels);
        ListCtrlModels->InsertItem(li);
        ListCtrlModels->SetItemPtrData(_numModels, (wxUIntPtr)timing);
        ListCtrlModels->SetItem(_numModels, 2, timing->GetName());
        ListCtrlModels->SetChecked(_numModels, timing->GetVisible());
        ListCtrlModels->SetItemColumnImage(_numModels, 1, TIMING_IMAGE);
        _numModels++;
    }
}

void ViewsModelsPanel::AddTimingToNotList(Element* timing)
{
    if (timing != nullptr)
    {
        wxListItem li;
        li.SetId(_numNonModels);
        ListCtrlNonModels->InsertItem(li, 0);
        ListCtrlNonModels->SetItemPtrData(_numNonModels, (wxUIntPtr)timing);
        ListCtrlNonModels->SetItem(_numNonModels, 1, timing->GetName());

        _numNonModels++;
    }
}

void ViewsModelsPanel::AddModelToList(Element* model)
{
    if (model != nullptr)
    {
        wxListItem li;
        li.SetId(_numModels);
        ListCtrlModels->InsertItem(li);
        ListCtrlModels->SetItemPtrData(_numModels, (wxUIntPtr)model);
        ListCtrlModels->SetItem(_numModels, 2, model->GetName());
        ListCtrlModels->SetChecked(_numModels, model->GetVisible());
        // Need to solve this ... I think we only want images for groups.
        if (IsModelAGroup(model->GetName()))
        {
            ListCtrlModels->SetItemColumnImage(_numModels, 1, MODEL_IMAGE);
        }
        _numModels++;
    }
}

void ViewsModelsPanel::AddModelToNotList(Element* model)
{
    if (model != nullptr)
    {
        wxListItem li;
        li.SetId(_numNonModels);
        if (IsModelAGroup(model->GetName()))
        {
            ListCtrlNonModels->InsertItem(li, 1);
        }
        else
        {
            ListCtrlNonModels->InsertItem(li, -1);
        }
        ListCtrlNonModels->SetItemPtrData(_numNonModels, (wxUIntPtr)model);
        ListCtrlNonModels->SetItem(_numNonModels, 1, model->GetName());

        _numNonModels++;
    }
}

#pragma region View List
void ViewsModelsPanel::OnListCtrlViewsItemSelect(wxListEvent& event)
{
    int index = event.m_itemIndex;
    SelectView(ListCtrlViews->GetItemText(index, 1).ToStdString());
}

void ViewsModelsPanel::OnListCtrlItemCheck(wxCommandEvent& event)
{
    //int index = event.m_itemIndex;
    //SelectView(ListCtrlViews->GetItemText(index, 1).ToStdString());
    Element* e = (Element*)event.GetClientData();
    if (e == nullptr)
    {
        auto sv = _sequenceViewManager->GetSelectedView();

        int selected = 0;
        const int itemCount = ListCtrlViews->GetItemCount();
        for (int i = 0; i<itemCount; i++)
        {
            if (ListCtrlViews->IsChecked(i))
            {
                selected++;
            }
        }

        if (selected == 0)
        {
            SelectView(sv->GetName());
        }
        else if (selected == 2)
        {
            for (int i = 0; i < itemCount; i++)
            {
                if (ListCtrlViews->IsChecked(i))
                {
                    if (sv->GetName() == ListCtrlViews->GetItemText(i, 1))
                    {
                        ListCtrlViews->SetChecked(i, false);
                    }
                    else
                    {
                        SelectView(ListCtrlViews->GetItemText(i, 1).ToStdString());
                    }
                }
            }
        }
        else
        {
            bool found = false;
            for (int i = 0; i < itemCount; i++)
            {
                if (ListCtrlViews->IsChecked(i))
                {
                    if (!found)
                    {
                        found = true;
                        SelectView(ListCtrlViews->GetItemText(i, 1).ToStdString());
                    }
                    else
                    {
                        ListCtrlViews->SetChecked(i, false);
                    }
                }
            }
        }
    }
    else
    {
        e->SetVisible(!e->GetVisible());
    }

    MarkViewsChanged();

    // Update Grid
    _xlFrame->DoForceSequencerRefresh();
    ValidateWindow();
}

void ViewsModelsPanel::SelectView(const std::string& view)
{
    if (_seqData->NumFrames() == 0) return;
    ListCtrlViews->SetChecked(_sequenceElements->GetCurrentView(), false);
    int selected_view = GetViewIndex(view);
    if (selected_view > 0)
    {
        std::string modelsString = _sequenceElements->GetViewModels(view);
        _sequenceElements->AddMissingModelsToSequence(modelsString);
        _sequenceElements->PopulateView(modelsString, selected_view);
    }
    _sequenceViewManager->SetSelectedView(selected_view);
    _sequenceElements->SetCurrentView(selected_view);
    _sequenceElements->SetTimingVisibility(view);
    PopulateModels();
    ListCtrlViews->SetChecked(_sequenceElements->GetCurrentView(), true);
    _mainViewsChoice->SetStringSelection(view);

    _xlFrame->DoForceSequencerRefresh();
    ValidateWindow();
}

int ViewsModelsPanel::GetViewIndex(const wxString& name)
{
    return _sequenceViewManager->GetViewIndex(name.ToStdString());
}

void ViewsModelsPanel::MarkViewsChanged()
{
    wxCommandEvent eventRgbEffects(EVT_RGBEFFECTS_CHANGED);
    wxPostEvent(GetParent(), eventRgbEffects);
}

// This gives the panel a pointer to the view choice box on the sequencer tab
void ViewsModelsPanel::SetViewChoice(wxChoice* choice)
{
    _mainViewsChoice = choice;

    // this directs events from sequencer tab
    _mainViewsChoice->Connect(wxEVT_CHOICE, (wxObjectEventFunction)&ViewsModelsPanel::OnViewSelect, nullptr, this);
}

void ViewsModelsPanel::OnViewSelect(wxCommandEvent &event) {
    SelectView(_mainViewsChoice->GetString(_mainViewsChoice->GetSelection()).ToStdString());
    ValidateWindow();
}

void ViewsModelsPanel::PopulateViews()
{
    ListCtrlViews->ClearAll();
    if (_mainViewsChoice != nullptr) {
        _mainViewsChoice->Clear();
    }

    wxListItem col0;
    col0.SetId(0);
    col0.SetText(_(""));
    col0.SetWidth(30);
    ListCtrlViews->InsertColumn(0, col0);

    wxListItem col1;
    col1.SetId(1);
    col1.SetText(_("View"));
    col1.SetWidth(130);
    ListCtrlViews->InsertColumn(1, col1);

    _numViews = 0;
    auto views = _sequenceViewManager->GetViews();
    for (auto it = views.begin(); it != views.end(); ++it)
    {
        bool isChecked = _sequenceViewManager->GetSelectedView() == *it;
        AddViewToList((*it)->GetName(), isChecked);
        if (isChecked)
        {
            ListCtrlViews->SetChecked(0, false);
        }
    }

    _mainViewsChoice->SetSelection(_sequenceViewManager->GetSelectedViewIndex());
}

void ViewsModelsPanel::AddViewToList(const wxString& viewName, bool isChecked)
{
    wxListItem li;
    li.SetId(_numViews);
    ListCtrlViews->InsertItem(li);
    ListCtrlViews->SetItem(_numViews, 1, viewName);
    ListCtrlViews->SetChecked(_numViews, isChecked);
    _numViews++;

    _mainViewsChoice->Append(viewName);
}

void ViewsModelsPanel::OnButton_AddViewClick(wxCommandEvent& event)
{
    if (_seqData->NumFrames() == 0) return;
    wxTextEntryDialog dialog(this, _("Enter Name for View"), _("Create View"));
    int DlgResult = dialog.ShowModal();;
    if (DlgResult != wxID_OK) return;
    std::string viewName = dialog.GetValue().Trim().ToStdString();

    _sequenceViewManager->AddView(viewName);

    AddViewToList(viewName, true);
    _sequenceElements->AddView(viewName);
    SelectView(viewName);
    MarkViewsChanged();
    PopulateViews();
    ValidateWindow();
}

void ViewsModelsPanel::DeleteSelectedView()
{
    if (_seqData->NumFrames() == 0) return;

    int result = wxMessageBox("Are you sure you want to delete this View?", "Confirm Deletion", wxOK | wxCANCEL | wxCENTER);
    if (result != wxOK) return;

    ListCtrlViews->Freeze();
    long itemIndex = -1;

    for (;;) {
        itemIndex = ListCtrlViews->GetNextItem(itemIndex,
            wxLIST_NEXT_ALL,
            wxLIST_STATE_SELECTED);

        if (itemIndex == -1) break;

        // Got a selected item so handle it
        if (itemIndex > 0)  // don't delete master view
        {
            _sequenceElements->RemoveView(itemIndex);
            wxString name = _sequenceElements->GetViewName(itemIndex);
            _sequenceViewManager->DeleteView(name.ToStdString());

            ListCtrlViews->DeleteItem(itemIndex);
            _numViews--;
            break;
        }
        itemIndex = -1; // reset to delete next item which may have same index
    }
    ListCtrlViews->Thaw();
    ListCtrlViews->Refresh();
    _sequenceElements->SetCurrentView(MASTER_VIEW);
    SelectView("Master View");
    MarkViewsChanged();
    PopulateViews();
    ValidateWindow();
}

void ViewsModelsPanel::OnButton_DeleteViewClick(wxCommandEvent& event)
{
    DeleteSelectedView();
}
#pragma endregion


void ViewsModelsPanel::OnResize(wxSizeEvent& event)
{
    wxSize s = GetSize();
    Panel_Sizer->SetSize(s);
    Panel_Sizer->SetMinSize(s);
    Panel_Sizer->SetMaxSize(s);
    Panel_Sizer->Refresh();

    ScrolledWindowViewsModels->SetSize(s);
    ScrolledWindowViewsModels->SetMinSize(s);
    ScrolledWindowViewsModels->SetMaxSize(s);

    ScrolledWindowViewsModels->FitInside();
    ScrolledWindowViewsModels->SetScrollRate(5, 5);
    ScrolledWindowViewsModels->Refresh();
}

void ViewsModelsPanel::OnLeftUp(wxMouseEvent& event)
{
    _xlFrame->DoForceSequencerRefresh();
    ValidateWindow();
}

void ViewsModelsPanel::OnListCtrlNonModelsItemSelect(wxListEvent& event)
{
    ValidateWindow();
}

void ViewsModelsPanel::OnListCtrlNonModelsBeginDrag(wxListEvent& event)
{
    _dragRowModel = false;
    _dragRowNonModel = true;	// save the start index
    wxTextDataObject my_data("test");
    wxDropSource dragSource(this);
    dragSource.SetData(my_data);
    wxDragResult result = dragSource.DoDragDrop(wxDrag_DefaultMove);

    // give visual feedback that we are doing something
    SetCursor(wxCursor(wxCURSOR_NO_ENTRY));

    ValidateWindow();
}

bool ViewsModelsPanel::GiveFeedback(wxDragResult effect)
{
    if (_dragRowModel)
    {
        
    }
    else if (_dragRowNonModel)
    {
        if (ListCtrlModels->GetRect().Contains(wxGetMousePosition()))
        {
            SetCursor(wxCursor(wxCURSOR_HAND));
        }
        else
        {
            SetCursor(wxCursor(wxCURSOR_NO_ENTRY));
        }
    }
    else
    {
        return false;
    }

    return true;
}

void ViewsModelsPanel::OnNonModelsDragUp(wxMouseEvent& event)
{
    SetCursor(wxCursor(*wxSTANDARD_CURSOR));
    // disconnect both functions
    ListCtrlNonModels->Disconnect(wxEVT_LEFT_UP,
        wxMouseEventHandler(ViewsModelsPanel::OnNonModelsDragUp));
    ListCtrlNonModels->Disconnect(wxEVT_MOTION,
        wxMouseEventHandler(ViewsModelsPanel::OnNonModelsDragMotion));
}

void ViewsModelsPanel::OnNonModelsDragMotion(wxMouseEvent& event)
{
    static log4cpp::Category &logger_base = log4cpp::Category::getInstance(std::string("log_base"));
    logger_base.debug("Does source: %d,%d-%d,%d dest: %d,%d-%d,%d contain %d,%d", 
        ListCtrlNonModels->GetPosition().x, ListCtrlNonModels->GetPosition().y, ListCtrlNonModels->GetPosition().x + ListCtrlNonModels->GetSize().GetWidth(), ListCtrlNonModels->GetPosition().y + ListCtrlNonModels->GetSize().GetHeight(),
        ListCtrlModels->GetPosition().x, ListCtrlModels->GetPosition().y, ListCtrlModels->GetPosition().x + ListCtrlModels->GetSize().GetWidth(), ListCtrlModels->GetPosition().y + ListCtrlModels->GetSize().GetHeight(), 
        event.GetPosition().x, event.GetPosition().y);
    auto pos = event.GetPosition();
    if (ListCtrlModels->GetRect().Contains(event.GetPosition()))
    {
        SetCursor(wxCURSOR_HAND);
    }
    else
    {
        SetCursor(wxCURSOR_NO_ENTRY);
    }
}

void ViewsModelsPanel::OnListCtrlNonModelsKeyDown(wxListEvent& event)
{
    if (event.GetKeyCode() == WXK_RIGHT)
    {
        AddSelectedModels();
    }
    ValidateWindow();
}

void ViewsModelsPanel::OnListCtrlViewsKeyDown(wxListEvent& event)
{
    auto key = event.GetKeyCode();
    if ((key == WXK_DELETE || key == WXK_NUMPAD_DELETE) && Button_DeleteView->IsEnabled())
    {
        DeleteSelectedView();
    }
}

bool MyTextDropTarget::OnDropText(wxCoord x, wxCoord y, const wxString& data)
{
    return true;
}
