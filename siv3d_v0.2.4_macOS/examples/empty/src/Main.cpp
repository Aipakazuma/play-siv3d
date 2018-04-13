	# include <Siv3D.hpp>

// こｎ記事をコピペ
// https://github.com/Siv3D/Reference-JP/wiki/%E3%83%89%E3%83%83%E3%83%88%E3%81%8A%E7%B5%B5%E3%81%8B%E3%81%8D
void Main()
{
  Graphics::SetBackground(Palette::White);
  
  const int32 dotSize = 40;
  
  Grid<int32> dots(Window::Width() / dotSize, Window::Height() / dotSize);
  
  while (System::Update())
  {
    for (auto p : step({ dots.width(), dots.height() }))
    {
      const Rect rect(p * dotSize, dotSize, dotSize);
      
      if (rect.leftClicked())
      {
        dots[p.y][p.x] = 1;
      }
      
      if (rect.rightClicked())
      {
        dots[p.y][p.x] = 0;
      }
      
      const Color color(240 - 240 * dots[p.y][p.x]);
      rect.stretched(-1).draw(color);
    }
  }
}
