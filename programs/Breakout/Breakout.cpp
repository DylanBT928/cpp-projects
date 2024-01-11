#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>

bool loseLife;
int life;
int const screenHeight = 20;
int const screenWidth = 30;
int map[screenHeight][screenWidth];
char level[8][18] = { "..#####...#####..",
				      "..#####...#####..",
					  "..#####...#####..",
					  "..#####...#####..",
					  "..#####...#####..",
					  "..#####...#####..",
					  "..#####...#####.." };
					 
class Paddle
{
public:
    int x;
    int y;
    int speed;
    char direction;
    int delay;
    int countDelay;
		
	void draw()
    {
		for (int i = 0; i < 9; i++)
			map[y][x+i] = 1;
	}
	
	void move()
    {
		if (countDelay == delay)
        {
			if (direction == 'L' && x - speed > 0)
				x -= speed;
            else if (direction == 'R' && x + speed < screenWidth - 9)
				x += speed;
			countDelay = 0;
		}

		countDelay++;

		if (loseLife)
        {
			direction = 'S';
			x = screenWidth / 2 - 5;
			y = screenHeight - screenHeight / 7 - 1;
			loseLife = false;
		}
	}
};

class Ball
{
public:
    int x;
    int y;
    int speed;
    int direction;
		
	void draw()
    {
		map[y][x] = 3;
	}

	void bounce(int fx, int fy)
    {
		if (direction == 0)
        {
			if (fx < x) 
                direction = 1;
			else if (fy < y) 
                direction = 2;
			else if (fx < x && fy < y) 
                direction = 0;
		}
        else if (direction == 1)
        {
			if (fx > x) 
                direction = 0;
			else if (fy < y) 
                direction = 3;
			else if (fx > x && fy < y) 
                direction = 1;
		}
        else if (direction == 2)
        {
			if (fx < x) 
                direction = 3;
			else if (fy > y) 
                direction = 0;
			else if (fx < x && fy > y) 
                direction = 2;
		}
        else if (direction == 3)
        {
			if (fx > x) 
                direction = 2;
			else if (fy > y) 
                direction = 1;
			else if (fx > x && fy > y) 
                direction = 3;
		}
	}

    bool collision (int fx, int fy)
    {
		if (map[fy][x] == 5)
        {
			loseLife = true;
			x = screenWidth / 2 - 1;
			y = screenHeight - screenHeight / 7 - 3;
			direction = 4;
			life--;
		}
        else if (map[fy][fx] != 0 || map[y][fx] != 0 || map[fy][x] != 0 || map[fy][fx] == 2 || map[y][fx] == 2 || map[fy][x] == 2)
        {
			if (map[fy][fx] == 2) 
                level[fy - 2][fx - 6] = '.';
			if (map[y][fx] == 2) 
                level[y - 2][fx - 6] = '.';
			if (map[fy][x] == 2) 
                level[fy - 2][x - 6] = '.';
			
			if (map[y][fx] != 0) 
                bounce(fx,y);
			else if (map[fy][x] != 0) 
                bounce(x,fy);
			else if (map[fy][fx] != 0) 
                bounce(fx,fy);
			
			return true;
		}
		
		return false;
	}

	void move()
    {
		if (direction == 0 && !collision(x-speed, y-speed))
        {
			x -= speed;
			y -= speed;
		}
        else if (direction == 1 && !collision(x+speed, y-speed))
        {
			x += speed;
			y -= speed;
		}
        else if (direction == 2 && !collision(x-speed, y+speed))
        {
			x -= speed;
			y += speed;
		} 
        else if (direction == 3 && !collision(x+speed, y+speed))
        {
			x += speed;
			y += speed;
		}
	}
};

Paddle paddle;
Ball ball;

void goToPosition(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void hideCursor()
{
	CONSOLE_CURSOR_INFO cursor;
	cursor.dwSize = 100;
	cursor.bVisible = false;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

void createBricks()
{
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 17; j++)
			if (level[i][j] == '#') 
                map[i + 2][j + 6] = 2;
}

void createWall()
{
	for (int i = 0; i < screenHeight; i++)
		for (int j = 0; j < screenWidth; j++)
        {
			if (j == 0 || j == screenWidth - 1) 
                map[i][j] = 6;
			else if (i == 0) 
                map[i][j] = 4;
			else if (i == screenHeight - 1) 
                map[i][j] = 5;
			else 
                map[i][j] = 0;
		}
}

void setup()
{
	srand(time(NULL));
	loseLife = false;
	life = 5;
	paddle.x = screenWidth / 2 - 5;
	paddle.y = screenHeight - screenHeight / 7 - 1;
	paddle.speed = 1;
	paddle.delay = 1;
	ball.x = screenWidth / 2;
	ball.y = screenHeight - screenHeight / 7 - 2;
	ball.speed = 1;
	ball.direction = rand()%4;
}

void layout()
{
	createWall();
	paddle.draw();
	ball.draw();
	createBricks();
}

void display()
{
	goToPosition(2,1); 
    std::cout << "LIVES: " << life;
	
	// 6 = Side wall
    // 5 = Score wall
	// 4 = Top wall
	// 3 = Ball
	// 2 = Bricks
    // 1 = Paddle
	// 0 = Blanks
	
	for (int i = 0; i < screenHeight; i++)
		for (int j = 0; j < screenWidth; j++){
			goToPosition(j + 2, i + 3);
            if (map[i][j] == 6)
                std::cout << char(219);
            if (map[i][j] == 5)
                std::cout << char(240);
            if (map[i][j] == 4)
                std::cout << char(219);
            if (map[i][j] == 3)
                std::cout << char(254);
            if (map[i][j] == 2)
                std::cout << char(233);
            if (map[i][j] == 1)
                std::cout << char(219);
            if (map[i][j] == 0)
                std::cout << char(32);
		}
}

void input()
{
	if (kbhit())
    {
		switch (getch())
        {
			case 75:
				paddle.direction = 'L';
				break;
			case 77:
				paddle.direction = 'R';
				break;
		}

		if (ball.direction == 4)
            ball.direction = rand()%2;
	}
}

void movement()
{
	paddle.move();
	ball.move();
}

void gameOver(){
	system("cls");
    std::cout << "GAME OVER.\n";
    system("pause");
}

int main()
{
	hideCursor();
	setup();

	while (life > 0)
    {
		display();
		layout();
		input();
		movement();
	}
    
	gameOver();
    return 0;
}
