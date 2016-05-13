using namespace System;
using namespace System::Text;
using namespace Threading;

#pragma region Variables
int main()
{
	const int estado_jogo_menu = 0; 
	const int estado_jogo_gameplay = 1;
	const int estado_jogo_venceu = 2;
	const int estado_jogo_perdeu = 3;
	const int estado_jogo_darkside = 4;
	const int estado_jogo_menu_2 = 5;
	const int estado_jogo_menu_3 = 6;

	bool walkRight = true, projetilTela = false, inimigoTela = true;

	int estadoJogo = estado_jogo_menu, naveX = 39, naveY = 25, tiro = 0, inimigoX = 0, inimigoY = 1, inimigoVoltas = 3, tiroY, tiroX;
	int inimigosX[10] = {0, 6, 12, 18, 24, 30, 36, 42, 48, 54};
#pragma endregion
	for (;;) //loop infinito
	{
		switch (estadoJogo)
		{
#pragma region Main Menu
		case estado_jogo_menu:

			Console::SetWindowSize(120, 30);
			Console::SetBufferSize(120, 30);
			Console::BackgroundColor = ConsoleColor::Black;
			Console::Clear();
			Console::ForegroundColor = ConsoleColor::White;

			Console::SetCursorPosition(30, 7);
			Console::Write("   _____                                           _");
			Console::SetCursorPosition(30, 8);
			Console::Write("  / ____|                                         | |");
			Console::SetCursorPosition(30, 9);
			Console::Write(" | (___  _ __   __ _  ___ ___       __ _ _ __   __| |");
			Console::SetCursorPosition(30, 10);
			Console::Write("  \\___ \\| '_ \\ / _` |/ __/ _ \\     / _` | '_ \\ / _` |");
			Console::SetCursorPosition(30, 11);
			Console::Write("  ____) | |_) | (_| | (_|  __/    | (_| | | | | (_| |");
			Console::SetCursorPosition(30, 12);
			Console::Write(" |_____/| .__/ \\__,_|\\___\\___|     \\__,_|_| |_|\\__,_|");

			Console::ForegroundColor = ConsoleColor::Red;
			Console::SetCursorPosition(30, 13);
			Console::Write("             __      __     _____  ______ _____   _____   ");
			Console::SetCursorPosition(30, 14);
			Console::Write("             \\ \\    / /\\   |  __ \\|  ____|  __ \\ / ____| ");
			Console::ForegroundColor = ConsoleColor::White;
			Console::SetCursorPosition(30, 13);
			Console::Write("        | | ");
			Console::SetCursorPosition(30, 14);
			Console::Write("        |_|  ");
			Console::ForegroundColor = ConsoleColor::Red;
			Console::SetCursorPosition(30, 15);
			Console::Write("              \\ \\  / /  \\  | |  | | |__  | |__) | (___  ");
			Console::SetCursorPosition(30, 16);
			Console::Write("               \\ \\/ / /\\ \\ | |  | |  __| |  _  / \\___ \\ ");
			Console::SetCursorPosition(30, 17);
			Console::Write("                \\  / ____ \\| |__| | |____| | \\ \\ ____) |");
			Console::SetCursorPosition(30, 18);
			Console::Write("                 \\/_/    \\_\\_____/|______|_|  \\_\\_____/ ");

			Console::ForegroundColor = ConsoleColor::White;
			Console::SetCursorPosition(28, 22);
			Console::Write("Press L to join the Light Side ");
			Console::ForegroundColor = ConsoleColor::Red;
			Console::Write("| Press D to join the Dark Side");

			if (Console::KeyAvailable); // se uma tecla for pressionada
			{
				ConsoleKeyInfo tecla;
				tecla = Console::ReadKey(true); // paremetro = true -> nada que o jogador pressionar será mostrado na tela

				if (tecla.Key == ConsoleKey::L)
				{
					estadoJogo = estado_jogo_menu_2;
				}
				else if (tecla.Key == ConsoleKey::D)
				{
					estadoJogo = estado_jogo_menu_3;
				}
			}
			break;
#pragma endregion
#pragma region Light Side
		case estado_jogo_menu_2:

			Console::Clear();
			Console::SetCursorPosition(46, 13);
			Console::BackgroundColor = ConsoleColor::Black;
			Console::ForegroundColor = ConsoleColor::White;
			Console::Write("You chose the Light Side.");
			Console::SetCursorPosition(35, 16);
			Console::Write("Press Enter to continue or Backspace to return.");

			if (Console::KeyAvailable); 
			{
				ConsoleKeyInfo tecla;
				tecla = Console::ReadKey(true);

				if (tecla.Key == ConsoleKey::Enter)
				{
					Console::Clear();
					Console::SetCursorPosition(45, 14);
					Console::Write("May the Force be with you!");
					Thread::Sleep(4000);
					estadoJogo = estado_jogo_gameplay;
				}
				else if (tecla.Key == ConsoleKey::Backspace)
				{
					estadoJogo = estado_jogo_menu;
				}
			}
			break;
#pragma endregion
#pragma region Dark Side
		case estado_jogo_menu_3:

			Console::Clear();
			Console::SetCursorPosition(46, 14);
			Console::BackgroundColor = ConsoleColor::Black;
			Console::ForegroundColor = ConsoleColor::White;
			Console::Write("You chose the Dark Side.");
			Console::SetCursorPosition(35, 16);
			Console::Write("Press Enter to continue or Backspace to return.");

			if (Console::KeyAvailable);
			{
				ConsoleKeyInfo tecla;
				tecla = Console::ReadKey(true);

				if (tecla.Key == ConsoleKey::Enter)
				{
					Console::Clear();
					Console::SetCursorPosition(30, 14);
					Console::Write("It is highly recommended that you choose the Light Side.");
					Console::SetCursorPosition(40, 16);
					Console::Write("Would you like to continue anyway?");
					Console::SetCursorPosition(35, 18);
					Console::Write("Press Enter to continue or Backspace to return.");

					if (Console::KeyAvailable);
					{
						ConsoleKeyInfo tecla;
						tecla = Console::ReadKey(true);

						if (tecla.Key == ConsoleKey::Enter)
						{
							Console::Clear();
							Console::SetCursorPosition(35, 14);
							Console::Write("I mean, seriously. Think about it. Last chance.");
							Console::SetCursorPosition(28, 16);
							Console::Write("Press Enter to murder innocent people, or Backspace to return.");

							if (Console::KeyAvailable);
							{
								ConsoleKeyInfo tecla;
								tecla = Console::ReadKey(true);

								if (tecla.Key == ConsoleKey::Enter)
								{
									Console::Clear();
									Console::SetCursorPosition(22, 14);
									Console::Write("Well, don't say I didn't warn you when Obi Wan comes chopping your legs off.");
									Thread::Sleep(5000);
									Console::Clear();
									Console::SetCursorPosition(55, 14);
									Console::Write("Asshole.");
									Thread::Sleep(2000);
									estadoJogo = estado_jogo_gameplay;
								}
								else if (tecla.Key == ConsoleKey::Backspace)
								{
									estadoJogo = estado_jogo_menu;
								}
							}
						}
						else if (tecla.Key == ConsoleKey::Backspace)
						{
							estadoJogo = estado_jogo_menu;
						}

						else if (tecla.Key == ConsoleKey::Backspace)
						{
							estadoJogo = estado_jogo_menu;
						}
					}
				}
			}
			break;
#pragma endregion
#pragma region Gameplay Light
		case estado_jogo_gameplay:

			Console::BackgroundColor = ConsoleColor::Black;
			Console::Clear();

			if (inimigoTela == true)
			{
				for (int i = 0; i < 10; i++)
				{
					Console::ForegroundColor = ConsoleColor::Red;
					Console::SetCursorPosition(inimigosX[i], inimigoY);
					Console::Write("|-O-|");
				}

				for (int j = 0; j < 10; j++)
				{
					inimigoVoltas--;
					if (inimigoVoltas == 0)
					{
						if (walkRight)
						{
							inimigosX[0]++;
							inimigosX[1]++;
							inimigosX[2]++;
							inimigosX[3]++;
							inimigosX[4]++;
							inimigosX[5]++;
							inimigosX[6]++;
							inimigosX[7]++;
							inimigosX[8]++;
							inimigosX[9]++;

							if (inimigosX[9] + 5 == 120)
							{
								inimigoY++;
								walkRight = false;
							}
						}
						else
						{
							inimigosX[0]--;
							inimigosX[1]--;
							inimigosX[2]--;
							inimigosX[3]--;
							inimigosX[4]--;
							inimigosX[5]--;
							inimigosX[6]--;
							inimigosX[7]--;
							inimigosX[8]--;
							inimigosX[9]--;

							if (inimigosX[0] == 0)
							{
								inimigoY++;
								walkRight = true;
							}
						}
						inimigoVoltas = 15;
					}
				}
			}

			Console::ForegroundColor = ConsoleColor::White;
			Console::SetCursorPosition(naveX, naveY);
			Console::Write(" /|__|\\ ");
			Console::SetCursorPosition(naveX, naveY + 1);
			Console::Write("(      )");
			Console::SetCursorPosition(naveX, naveY + 2);
			Console::Write(" `----´");

			if (projetilTela == true)
			{
				Console::SetCursorPosition(tiroX, tiroY);
				Console::Write("o");
			} 

			if (projetilTela == true)
			{
				tiroY--;

                if (tiroY <= 0)
				{
					projetilTela = false;
				}
			}

			if (inimigoX == tiroX && inimigoY == tiroY)
			{
				inimigoTela = false;
			}
			else if (inimigoX + 1 == tiroX && inimigoY == tiroY)
			{
				inimigoTela = false;
			}
			else if (inimigoX + 2 == tiroX && inimigoY == tiroY)
			{
				inimigoTela = false;
			}
			else if (inimigoX + 3 == tiroX && inimigoY == tiroY)
			{
				inimigoTela = false;
			}
			else if (inimigoX + 4 == tiroX && inimigoY == tiroY)
			{
				inimigoTela = false;
			}
		

			if (Console::KeyAvailable) // se uma tecla for pressionada
			{
				ConsoleKeyInfo tecla;
				tecla = Console::ReadKey(true); // paremetro = true -> nada que o jogador pressionar será mostrado na tela

				if (tecla.Key == ConsoleKey::LeftArrow)
				{
					naveX--;
					if (naveX == -1)
						naveX = 0;
				}

				else if (tecla.Key == ConsoleKey::RightArrow)
				{
					naveX++;
					if (naveX == 80)
						naveX = 79;
				}
				
				if (tecla.Key == ConsoleKey::Spacebar)
				{
					if (projetilTela == false)
					{
						projetilTela = true;
						tiroY = naveY - 1;
						tiroX = naveX; 
					}
					
				}

			}
			break;
#pragma endregion 
		}
		Thread::Sleep(16);     
	} 
	return 0;
}