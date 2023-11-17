#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace winrt::Microsoft::Graphics::Canvas::UI::Xaml;
struct winrt::Windows::UI::Color col = winrt::Microsoft::UI::Colors::Red();


// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::win2dBanner::implementation
{
    int32_t MainWindow::MyProperty()
    {
        throw hresult_not_implemented();
        x = 200;
        y = 200;
    }

    void MainWindow::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

}


void winrt::win2dBanner::implementation::MainWindow::CanvasControl_PointerMoved(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Input::PointerRoutedEventArgs const& e)
{
    CanvasControl canvas = sender.as<CanvasControl>();
    x = e.GetCurrentPoint(canvas).Position().X;
    y = e.GetCurrentPoint(canvas).Position().Y;
    canvas.Invalidate();
}

#include <winrt/Microsoft.Graphics.Canvas.Text.h>
using namespace winrt::Microsoft::Graphics::Canvas::Text;
float a1, a2 = 400;
void winrt::win2dBanner::implementation::MainWindow::CanvasControl_Draw(winrt::Microsoft::Graphics::Canvas::UI::Xaml::CanvasControl const& sender, winrt::Microsoft::Graphics::Canvas::UI::Xaml::CanvasDrawEventArgs const& args)
{
    CanvasTextFormat format;
    CanvasControl canvas = sender.as<CanvasControl>();
    format.HorizontalAlignment((CanvasHorizontalAlignment::Center));
    format.VerticalAlignment(CanvasVerticalAlignment::Center);
    format.FontSize(142.0f);
    for (int i = 0; i < 4; i++)
    {
        a1 += i;
    }
    args.DrawingSession().DrawEllipse(x, y, 80, 60, col, 8);
    args.DrawingSession().DrawText(L"Hello", a1, a2, winrt::Microsoft::UI::Colors::Yellow(), format);
    if (a1 > 1000) a1 = 0;
    canvas.Invalidate();
}
