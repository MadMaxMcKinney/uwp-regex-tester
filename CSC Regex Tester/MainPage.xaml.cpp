//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"

using namespace CSC_Regex_Tester;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;
using namespace Windows::UI::ViewManagement;

void InitTitleBar() {
	// Grab a pointer to the view
	ApplicationView ^view = ApplicationView::GetForCurrentView();

	// Set the colors we are using for the Title Bar
	Color primaryColorDark = ColorHelper::FromArgb(255, 25, 118, 210);

	// Get a pointer to the Title Bar from the view and set the colors
	ApplicationViewTitleBar ^title = view->TitleBar;
	title->BackgroundColor = primaryColorDark;
	title->ButtonBackgroundColor = primaryColorDark;
	title->ButtonForegroundColor = Colors::White;
	title->ForegroundColor = Colors::White;

	return;
}

MainPage::MainPage()
{
	InitializeComponent();
	// Setup the styling on the Title Bar
	InitTitleBar();

}