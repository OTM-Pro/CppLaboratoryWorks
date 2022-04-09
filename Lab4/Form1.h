#pragma once

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();

			g = this->CreateGraphics();
			for (int i = 0; i < 12; i++)
			{
				String^ fileName = "Sprites\\" + System::Convert::ToString(i) + ".bmp";
				sprites[i] = gcnew Bitmap(fileName);
			}
			generateField();
		}

	private:
		int playerPosX = 4;
		int playerPosY = 9;
		int playerDir = 0;
		int counter = 0;
		bool gameIsOn = true;
		int comp = 1;
		array<int, 2>^ fieldMatrix = gcnew array<int, 2>(10, 10);
		array<int, 2>^ enemies = gcnew array<int, 2>(3, 4);
		array<int, 2>^ bullets = gcnew array<int, 2>(10, 4);
		array<Bitmap^>^ sprites = gcnew array<Bitmap^>(12);
		System::Drawing::Graphics^ g;

	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ complexityToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ easyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ mediumToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ hardToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ newGameToolStripMenuItem;
		
		//Field
		void generateField()
		{
			for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) fieldMatrix[i, j] = 0;
			fieldMatrix[1, 1] = 1;
			fieldMatrix[1, 2] = 1;
			fieldMatrix[1, 3] = 1;
			fieldMatrix[1, 6] = 1;
			fieldMatrix[1, 7] = 1;
			fieldMatrix[1, 8] = 1;

			fieldMatrix[2, 1] = 1;
			fieldMatrix[2, 8] = 1;

			fieldMatrix[3, 1] = 1;
			fieldMatrix[3, 3] = 1;
			fieldMatrix[3, 4] = 1;
			fieldMatrix[3, 5] = 1;
			fieldMatrix[3, 6] = 1;
			fieldMatrix[3, 8] = 1;

			fieldMatrix[4, 3] = 1;
			fieldMatrix[4, 6] = 1;

			fieldMatrix[5, 3] = 1;
			fieldMatrix[5, 6] = 1;

			fieldMatrix[6, 1] = 1;
			fieldMatrix[6, 3] = 1;
			fieldMatrix[6, 4] = 1;
			fieldMatrix[6, 5] = 1;
			fieldMatrix[6, 6] = 1;
			fieldMatrix[6, 8] = 1;

			fieldMatrix[7, 1] = 1;
			fieldMatrix[7, 8] = 1;

			fieldMatrix[8, 1] = 1;
			fieldMatrix[8, 2] = 1;
			fieldMatrix[8, 3] = 1;
			fieldMatrix[8, 6] = 1;
			fieldMatrix[8, 7] = 1;
			fieldMatrix[8, 8] = 1;

			enemies[0, 0] = 1;
			enemies[0, 1] = 0;
			enemies[0, 2] = 0;
			enemies[0, 3] = 2;

			enemies[1, 0] = 1;
			enemies[1, 1] = 5;
			enemies[1, 2] = 0;
			enemies[1, 3] = 2;

			enemies[2, 0] = 1;
			enemies[2, 1] = 9;
			enemies[2, 2] = 0;
			enemies[2, 3] = 2;

			fieldMatrix[enemies[0, 2], enemies[0, 1]] = enemies[0, 3] + 6;
			fieldMatrix[enemies[1, 2], enemies[1, 1]] = enemies[1, 3] + 6;
			fieldMatrix[enemies[2, 2], enemies[2, 1]] = enemies[2, 3] + 6;

			fieldMatrix[playerPosY, playerPosX] = playerDir + 2;
		}

		void drawField()
		{
			Rectangle r = Rectangle(0, 0, 60, 60);
			for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++)
			{
				g->DrawImage(sprites[fieldMatrix[i, j]], 60 * j, 60 * i + 24, r, GraphicsUnit::Pixel);
			}
		}

		//Player
		void movePlayer(int dx, int dy, int dir)
		{
			fieldMatrix[playerPosY, playerPosX] = 0;

			playerPosX += dx;
			playerPosY += dy;
			playerDir = dir;

			fieldMatrix[playerPosY, playerPosX] = playerDir + 2;
			drawField();
		}

		void rotatePlayer(int dir)
		{
			if (playerDir != dir)
			{
				fieldMatrix[playerPosY, playerPosX] = 0;
				drawField();

				playerDir = dir;
				fieldMatrix[playerPosY, playerPosX] = playerDir + 2;
				drawField();
			}
		}

		void shootPlayer()
		{
			int newBulletPosX = playerPosX;
			int newBulletPosY = playerPosY;
			switch (playerDir)
			{
				case 0:
					newBulletPosY--;
					break;

				case 1:
					newBulletPosX++;
					break;

				case 2:
					newBulletPosY++;
					break;

				case 3:
					newBulletPosX--;
					break;
			}

			int cell = fieldMatrix[newBulletPosY, newBulletPosX];
			if (cell == 0) createBullet(newBulletPosX, newBulletPosY, playerDir);
			else if (cell == 1 || (cell > 5 && cell < 11)) destroyObject(newBulletPosX, newBulletPosY);
		}

		//Enemy
		void stepEnemy()
		{
			for (int i = 0; i < 3; i++) if (enemies[i, 0] == 1)
			{
				int dx = playerPosX - enemies[i, 1];
				int dy = playerPosY - enemies[i, 2];

				bool canMoveInDir0 = enemies[i, 2] != 0 && fieldMatrix[enemies[i, 2] - 1, enemies[i, 1]] == 0;
				bool canMoveInDir1 = enemies[i, 1] != 9 && fieldMatrix[enemies[i, 2], enemies[i, 1] + 1] == 0;
				bool canMoveInDir2 = enemies[i, 2] != 9 && fieldMatrix[enemies[i, 2] + 1, enemies[i, 1]] == 0;
				bool canMoveInDir3 = enemies[i, 1] != 0 && fieldMatrix[enemies[i, 2], enemies[i, 1] - 1] == 0;

				bool friendlyFire = false;
				switch (enemies[i, 3])
				{
					case 0:
						for (int j = 0; j < 3; j++) if (i != j && enemies[j, 1] == enemies[i, 1] && enemies[j, 2] < enemies[i, 2]) friendlyFire = true;
						break;

					case 1:
						for (int j = 0; j < 3; j++) if (i != j && enemies[j, 1] > enemies[i, 1] && enemies[j, 2] == enemies[i, 2]) friendlyFire = true;
							break;

					case 2:
						for (int j = 0; j < 3; j++) if (i != j && enemies[j, 1] == enemies[i, 1] && enemies[j, 2] > enemies[i, 2]) friendlyFire = true;
							break;

					case 3:
						for (int j = 0; j < 3; j++) if (i != j && enemies[j, 1] < enemies[i, 1] && enemies[j, 2] == enemies[i, 2]) friendlyFire = true;
							break;
				}

				if (dy < 0 && dx == 0)
				{
					if (enemies[i, 3] == 0 && !friendlyFire) shootEnemy(i);
					else if (canMoveInDir0) moveEnemy(i, 0);
					else rotateEnemy(i, 0);
				}
				else if (dy == 0 && dx > 0)
				{
					if (enemies[i, 3] == 1 && !friendlyFire) shootEnemy(i);
					else if (canMoveInDir1) moveEnemy(i, 1);
					else rotateEnemy(i, 1);
				}
				else if (dy > 0 && dx == 0)
				{
					if (enemies[i, 3] == 2 && !friendlyFire) shootEnemy(i);
					else if (canMoveInDir2) moveEnemy(i, 2);
					else rotateEnemy(i, 2);
				}
				else if (dy == 0 && dx < 0)
				{
					if (enemies[i, 3] == 3 && !friendlyFire) shootEnemy(i);
					else if (canMoveInDir3) moveEnemy(i, 3);
					else rotateEnemy(i, 3);
				}
				else if (dy < 0 && dx > 0) // 0 - 1
				{
					if ((canMoveInDir0) && !(canMoveInDir1)) moveEnemy(i, 0);
					else if (!(canMoveInDir0) && (canMoveInDir1)) moveEnemy(i, 1);
					else if ((canMoveInDir0) && (canMoveInDir1))
					{
						if (Math::Abs(dx) >= Math::Abs(dy)) moveEnemy(i, 1);
						else moveEnemy(i, 0);
					}
				}
				else if (dy > 0 && dx > 0) // 1 - 2
				{
					if ((canMoveInDir1) && !(canMoveInDir2)) moveEnemy(i, 1);
					else if (!(canMoveInDir1) && (canMoveInDir2)) moveEnemy(i, 2);
					else if ((canMoveInDir1) && (canMoveInDir2))
					{
						if (Math::Abs(dx) >= Math::Abs(dy)) moveEnemy(i, 1);
						else moveEnemy(i, 2);
					}
				}
				else if (dy > 0 && dx < 0) // 2 - 3
				{
					if ((canMoveInDir2) && !(canMoveInDir3)) moveEnemy(i, 2);
					else if (!(canMoveInDir2) && (canMoveInDir3)) moveEnemy(i, 3);
					else if ((canMoveInDir2) && (canMoveInDir3))
					{
						if (Math::Abs(dx) >= Math::Abs(dy)) moveEnemy(i, 3);
						else moveEnemy(i, 2);
					}
				}
				else if (dy < 0 && dx < 0) // 3 - 0
				{
					if ((canMoveInDir3) && !(canMoveInDir0)) moveEnemy(i, 3);
					else if (!(canMoveInDir3) && (canMoveInDir0)) moveEnemy(i, 0);
					else if ((canMoveInDir3) && (canMoveInDir0))
					{
						if (Math::Abs(dx) >= Math::Abs(dy)) moveEnemy(i, 3);
						else moveEnemy(i, 0);
					}
				}
			}
		}

		void rotateEnemy(int num, int dir)
		{
			if (enemies[num, 3] != dir)
			{
				fieldMatrix[enemies[num, 2], enemies[num, 1]] = 0;
				drawField();

				enemies[num, 3] = dir;
				fieldMatrix[enemies[num, 2], enemies[num, 1]] = dir + 6;
				drawField();
			}
		}

		void moveEnemy(int num, int dir)
		{
			fieldMatrix[enemies[num, 2], enemies[num, 1]] = 0;

			enemies[num, 3] = dir;
			switch (dir)
			{
				case 0:
					enemies[num, 2]--;
					break;

				case 1:
					enemies[num, 1]++;
					break;

				case 2:
					enemies[num, 2]++;
					break;

				case 3:
					enemies[num, 1]--;
					break;
			}

			fieldMatrix[enemies[num, 2], enemies[num, 1]] = enemies[num, 3] + 6;
			drawField();
		}

		void shootEnemy(int num)
		{
			int newBulletPosX = enemies[num, 1];
			int newBulletPosY = enemies[num, 2];
			switch (enemies[num, 3])
			{
				case 0:
					newBulletPosY--;
					break;

				case 1:
					newBulletPosX++;
					break;

				case 2:
					newBulletPosY++;
					break;

				case 3:
					newBulletPosX--;
					break;
			}

			int cell = fieldMatrix[newBulletPosY, newBulletPosX];
			if (cell == 0) createBullet(newBulletPosX, newBulletPosY, enemies[num, 3]);
			else if (cell == 1 || cell == 10) destroyObject(newBulletPosX, newBulletPosY);
			else if (cell > 1 && cell < 6)
			{
				destroyObject(newBulletPosX, newBulletPosY);
				gameOver();
			}
		}

		//Bullets
		void createBullet(int x, int y, int dir)
		{
			int place = -1;
			for (int i = 0; i < 10; i++)
			{
				if (bullets[i, 0] == 0)
				{
					place = i;
					break;
				}
			}

			if (place != -1)
			{
				bullets[place, 0] = 1;
				bullets[place, 1] = x;
				bullets[place, 2] = y;
				bullets[place, 3] = dir;

				fieldMatrix[y, x] = 10;
				drawField();
			}
		}

		void moveBullets()
		{
			for (int i = 0; i < 10; i++) if (bullets[i, 0] == 1)
			{
				fieldMatrix[bullets[i, 2], bullets[i, 1]] = 0;
				drawField();

				if ((bullets[i, 1] == 0 && bullets[i, 3] == 3) || (bullets[i, 1] == 9 && bullets[i, 3] == 1) ||
					(bullets[i, 2] == 0 && bullets[i, 3] == 0) || (bullets[i, 2] == 9 && bullets[i, 3] == 2))
				{
					destroyBullet(i);
				}
				else
				{
					switch (bullets[i, 3])
					{
					case 0:
						bullets[i, 2]--;
						break;

					case 1:
						bullets[i, 1]++;
						break;

					case 2:
						bullets[i, 2]++;
						break;

					case 3:
						bullets[i, 1]--;
						break;
					}

					int cell = fieldMatrix[bullets[i, 2], bullets[i, 1]];
					if (cell == 0)
					{
						fieldMatrix[bullets[i, 2], bullets[i, 1]] = 10;
						drawField();
					}
					else if (cell == 1 || (cell > 5 && cell < 11))
					{
						destroyObject(bullets[i, 1], bullets[i, 2]);
						destroyBullet(i);
					}
					else if (cell > 1 && cell < 6)
					{
						destroyBullet(i);
						gameOver();
					}
				}
			}
		}

		void destroyBullet(int num)
		{
			bullets[num, 0] = 0;
			bullets[num, 1] = 0;
			bullets[num, 2] = 0;
			bullets[num, 3] = 0;
		}

		//Other
		void newGame()
		{
			gameIsOn = false;
			for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) fieldMatrix[i, j] = 0;
			drawField();
			playerPosX = 4;
			playerPosY = 9;
			playerDir = 0;
			counter = 0;
			generateField();
			for (int i = 0; i < 10; i++) destroyBullet(i);
			drawField();
			gameIsOn = true;
		}

		void destroyObject(int x, int y)
		{
			fieldMatrix[y, x] = 11;
			drawField();

			for (int i = 0; i < 3; i++) if (enemies[i, 1] == x && enemies[i, 2] == y)
			{
				enemies[i, 0] = 0;
				enemies[i, 1] = 0;
				enemies[i, 2] = 0;
				enemies[i, 3] = 0;
			}

			bool enemiesAreAlive = false;
			for (int i = 0; i < 3; i++) if (enemies[i, 0] == 1) enemiesAreAlive = true;
			if (!enemiesAreAlive) epicWin();

			for (int i = 0; i < 10; i++) if (bullets[i, 1] == x && bullets[i, 2] == y) destroyBullet(i);
		}

		void clearBoom()
		{
			for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) if (fieldMatrix[i, j] == 11)
			{
				fieldMatrix[i, j] = 0;
				drawField();
			}
		}

		void epicWin()
		{
			gameIsOn = false;

			MessageBox::Show(
				"Вы победили! Начните заново.",
				"WIN!",
				MessageBoxButtons::OK,
				MessageBoxIcon::Information);
		}

		void gameOver()
		{
			gameIsOn = false;
			fieldMatrix[playerPosY, playerPosX] = 11;
			drawField();

			MessageBox::Show(
				"Игра окончена! Начните заново.",
				"GAME OVER!",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error);
		}


	protected:
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:



#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->newGameToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->complexityToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->easyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mediumToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->hardToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->newGameToolStripMenuItem,
					this->complexityToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(600, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// newGameToolStripMenuItem
			// 
			this->newGameToolStripMenuItem->Name = L"newGameToolStripMenuItem";
			this->newGameToolStripMenuItem->Size = System::Drawing::Size(76, 20);
			this->newGameToolStripMenuItem->Text = L"New game";
			this->newGameToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::newGameToolStripMenuItem_Click);
			// 
			// complexityToolStripMenuItem
			// 
			this->complexityToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->easyToolStripMenuItem,
					this->mediumToolStripMenuItem, this->hardToolStripMenuItem
			});
			this->complexityToolStripMenuItem->Name = L"complexityToolStripMenuItem";
			this->complexityToolStripMenuItem->Size = System::Drawing::Size(80, 20);
			this->complexityToolStripMenuItem->Text = L"Complexity";
			// 
			// easyToolStripMenuItem
			// 
			this->easyToolStripMenuItem->Name = L"easyToolStripMenuItem";
			this->easyToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->easyToolStripMenuItem->Text = L"1 - Easy";
			this->easyToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::easyToolStripMenuItem_Click);
			// 
			// mediumToolStripMenuItem
			// 
			this->mediumToolStripMenuItem->Name = L"mediumToolStripMenuItem";
			this->mediumToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->mediumToolStripMenuItem->Text = L"2 - Medium";
			this->mediumToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::mediumToolStripMenuItem_Click);
			// 
			// hardToolStripMenuItem
			// 
			this->hardToolStripMenuItem->Name = L"hardToolStripMenuItem";
			this->hardToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->hardToolStripMenuItem->Text = L"3 - Hard";
			this->hardToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::hardToolStripMenuItem_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::WindowFrame;
			this->ClientSize = System::Drawing::Size(600, 621);
			this->Controls->Add(this->menuStrip1);
			this->KeyPreview = true;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyDown);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
	{
		if ((e->KeyCode == Keys::Up || e->KeyCode == Keys::W) && gameIsOn)
		{
			if (playerPosY != 0 && fieldMatrix[playerPosY - 1, playerPosX] == 0) movePlayer(0, -1, 0);
			else rotatePlayer(0);
		}
		if ((e->KeyCode == Keys::Down || e->KeyCode == Keys::S) && gameIsOn)
		{
			if (playerPosY != 9 && fieldMatrix[playerPosY + 1, playerPosX] == 0) movePlayer(0, 1, 2);
			else rotatePlayer(2);
		}
		if ((e->KeyCode == Keys::Right || e->KeyCode == Keys::D) && gameIsOn)
		{
			if (playerPosX != 9 && fieldMatrix[playerPosY, playerPosX + 1] == 0) movePlayer(1, 0, 1);
			else rotatePlayer(1);
		}
		if ((e->KeyCode == Keys::Left || e->KeyCode == Keys::A) && gameIsOn)
		{
			if (playerPosX != 0 && fieldMatrix[playerPosY, playerPosX - 1] == 0) movePlayer(-1, 0, 3);
			else rotatePlayer(3);
		}
		if (e->KeyCode == Keys::Space && gameIsOn)
		{
			int x = playerPosX;
			int y = playerPosY;
			int d = playerDir;
			if ((y != 0 || d != 0) && (x != 9 || d != 1) && (y != 9 || d != 2) && (x != 0 || d != 3)) shootPlayer();
		}
	}
	private: System::Void Form1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
	{
		drawField();
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		counter++;
		if (gameIsOn) moveBullets();
		switch (comp)
		{
			case 1:
				if (counter % 7 == 0 && gameIsOn) stepEnemy();
				break;

			case 2:
				if (counter % 4 == 0 && gameIsOn) stepEnemy();
				break;

			case 3:
				if (counter % 1 == 0 && gameIsOn) stepEnemy();
				break;
		}
		if (counter % 3 == 0 && gameIsOn) clearBoom();
	}
	private: System::Void newGameToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		newGame();
	}
	private: System::Void easyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		comp = 1;
		newGame();
	}

	private: System::Void mediumToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		comp = 2;
		newGame();
	}

	private: System::Void hardToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		comp = 3;
		newGame();
	}
};
}
