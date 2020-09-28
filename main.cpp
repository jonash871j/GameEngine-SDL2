#include "engine.h"
#include <iostream>
#include <vector>
#include <string>

using namespace Engine;
using namespace SoundLib;

const int size = 9;
char mapArray[size][size];

cstring textArray = "#include <iostream>\n\nint main()\n{\n       std::cout << \"Hello World\\n\";\n       return 0;\n}\n";

int main(int argc, char* argv[])
{
	Window window(300, 300, "Test", false);
	Draw draw(&window);

	window.SetScaleing(3, 3);
	 
	std::string test = "";

	Format* fClick = FormatAny::Import(L"Sounds/Click.wav");

	SoundPlayer sndSpace(L"Sounds/Space.wav");
	SoundPlayer sndEnter(L"Sounds/Enter.wav");
	
	Font font("Fonts/arcade.ttf", 8);
	Text text(&font);

	int index = 0;
	float x = 0.0f;
	
	std::vector<SoundPlayer*> sndClicks;

	while (!window.Events())
	{
		if (index < strlen(textArray))
		{
			if (textArray[index] == '\n')
				sndEnter.Replay();
			else if (textArray[index] == ' ')
				sndSpace.Replay();
			else
			{
				SoundPlayer* sndClick = new SoundPlayer(fClick);
				sndClicks.push_back(sndClick);
				sndClick->Speed(((float)textArray[index] / 100.0f) + 0.5f);
				sndClick->Replay();
			}
			test += textArray[index];

			//if (textArray[index] == '\n')
			//	Core::Delay(100);

			index++;
		}
		else
		{
			Core::Delay(2000);
			
			for (int i = 0; i < sndClicks.size(); i++)
				delete sndClicks[i];
			sndClicks.clear();

			test += "\n";
			index = 0;
		}

		text.SetText(test.c_str());
		text.SetColor(255, 0, 0);

		draw.Color(0, 0, 0);
		draw.Background();
		draw.Text(&text, 8, 8);
		window.Update();
		window.Clear();
		Core::Delay(200);
	}

	/*for (int y = 0; y < size; y++)
		for (int x = 0; x < size; x++)
			mapArray[y][x] = ' ';

	Window window(240, 240, "Test", false);
	Draw draw(&window);

	window.SetIsFullscreen(false);
	window.SetScaleing(4, 4);

	Sprite sprGrid(&window, "Sprite/sprGrid.png");
	Sprite sprSolid(&window, "Sprite/sprSolid.png");
	Sprite sprBlue(&window, "Sprite/sprBlue.png");
	Sprite sprMagenta(&window, "Sprite/sprMagenta.png");
	Sprite sprPurple(&window, "Sprite/sprPurple.png");
	Sprite sprYellow(&window, "Sprite/sprYellow.png");


	int xOffset = window.GetWidth() / 2;
	int yOffset = 0;

	Vector2D player = { 0, 0 };

	while (!window.Events())
	{
		draw.Color(64, 64, 64);
		draw.Background();

		if (Input::KeyPressed(Key::W))
		{
			player.y--;
			player.x--;
		}
		if (Input::KeyPressed(Key::X))
		{
			player.y++;
			player.x++;
		}
		if (Input::KeyPressed(Key::A))
		{
			player.x++;
			player.y--;

		}
		if (Input::KeyPressed(Key::D))
		{
			player.x--;
			player.y++;
		}
		if (Input::KeyPressed(Key::E))
		{
			player.x--;
		}
		if (Input::KeyPressed(Key::Z))
		{
			player.x++;
		}
		if (Input::KeyPressed(Key::Q))
		{
			player.y--;
		}
		if (Input::KeyPressed(Key::C))
		{
			player.y++;
		}

		mapArray[(int)player.y][(int)player.x] = '1';

		for (int i = 1; i <= size; i++)
		{
			for (int j = 0; j < i; j++)
			{
				Vector2D vector = { (((i - 1) - j) * 12 - ((i / 2) * 12)) + xOffset, (i * 6) + yOffset };
				if (i & 1)
					vector.x -= 6;

				switch (mapArray[(i - 1) - j][j])
				{
				case ' ':
					draw.Sprite(&sprGrid, vector);
					break;
				case '#':
					draw.Sprite(&sprSolid, vector);
					break;
				case '1':
					draw.Sprite(&sprBlue, vector);
					break;
				case '2':
					draw.Sprite(&sprMagenta, vector);
					break;
				case '3':
					draw.Sprite(&sprPurple, vector);
					break;
				case '4':
					draw.Sprite(&sprYellow, vector);
					break;
				default:
					break;
				}
			}
			for (int j = 0; j < i; j++)
			{
				if (i == size)
					break;

				Vector2D vector = { (((i - 1) - j) * 12 - ((i / 2) * 12)) + xOffset, ((((size-1) - i) * 6) + ((size / 2) * 12)) + yOffset };

				if (i & 1)
					vector.x -= 6;

				switch (mapArray[(size-1) - (i - j - 1)][(size - 1) - j])
				{
				case ' ':
					draw.Sprite(&sprGrid, vector);
					break;
				case '#':
					draw.Sprite(&sprSolid, vector);
					break;
				case '1':
					draw.Sprite(&sprBlue, vector);
					break;
				case '2':
					draw.Sprite(&sprMagenta, vector);
					break;
				case '3':
					draw.Sprite(&sprPurple, vector);
					break;
				case '4':
					draw.Sprite(&sprYellow, vector);
					break;
				default:
					break;
				}
			}
		}

		window.Update();
		Core::Delay(5);
	}*/

	return 0;
}