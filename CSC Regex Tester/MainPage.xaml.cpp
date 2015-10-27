#include "pch.h"
#include "MainPage.xaml.h"
#include <string>
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

std::wstring testTitle;

void InitTitleBar() {
	// Grab a pointer to the view
	ApplicationView ^view = ApplicationView::GetForCurrentView();

	// Set the colors we are using for the Title Bar
	Color primaryColorDark = ColorHelper::FromArgb(255, 56, 142, 60);

	// Get a pointer to the Title Bar from the view and set the colors
	ApplicationViewTitleBar ^title = view->TitleBar;
	title->BackgroundColor = primaryColorDark;
	title->ButtonBackgroundColor = primaryColorDark;
	title->ButtonForegroundColor = Colors::White;
	title->ForegroundColor = Colors::White;

	return;
}

std::wstring s2ws(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}

std::string ws2s(const std::wstring& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = WideCharToMultiByte(CP_ACP, 0, s.c_str(), slength, 0, 0, 0, 0);
	char* buf = new char[len];
	WideCharToMultiByte(CP_ACP, 0, s.c_str(), slength, buf, len, 0, 0);
	std::string r(buf);
	delete[] buf;
	return r;
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

	// Store the result in a global var so we can reference it in the other method
	testTitle = testString->Text->Data();

	// Display the original test string above the main output,
	// We do this so when we change the main output we can still preview the test string
	txtTestString->Text = testString->Text;

}


void CSC_Regex_Tester::MainPage::tbRegexValue_TextChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e)
{
	// Get the regex pattern text box
	TextBox ^regexValueFromInput = safe_cast<TextBox^>(sender);
	// Get the actual string value of the regex pattern we will be using
	String ^pattern = regexValueFromInput->Text;
	// Convert to a wstring we can use c++ types
	std::wstring pat = pattern->Data();
	// Store the result here
	std::wstring result;

	// Do the Regex search
	try {
		std::wregex regPat(pat);
		std::wsregex_iterator next(testTitle.begin(), testTitle.end(), regPat);
		std::wsregex_iterator end;
		while (next != end) {
			std::wsmatch match = *next;
			result = match.str();
			next++;
		}
	} 
	catch (std::regex_error& e) {
		// Regrex expression error
	}

	// Show the result by converting the string to a wstring and then to Platform::String
	txtResult->Text = ref new String(result.c_str());

}
