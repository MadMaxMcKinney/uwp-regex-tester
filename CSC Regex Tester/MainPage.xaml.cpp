//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"
#include <regex>

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


void CSC_Regex_Tester::MainPage::tbTestString_TextChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e)
{
	// Get the current test string. We need to safe cast it in order to convert from sender to a useful object
	TextBox ^testString = safe_cast<TextBox^>(sender);

	// Show the result in the preview text
	txtResult->Text = testString->Text;
	// Display the original test string above the main output,
	// We do this so when we change the main output we can still preview the test string
	txtTestString->Text = testString->Text;

}


void CSC_Regex_Tester::MainPage::tbRegexValue_TextChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e)
{
	// Show the test string result with the given regex
}
