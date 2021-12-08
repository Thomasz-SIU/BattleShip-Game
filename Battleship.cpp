/*
Thomas Zemen
Battleship
Creates 8x8 grid which will contain hidden ships and the user will be able to guess 
coordinates to try and destroy the hidden ships.  The user will have 24 guesses, 
and at the end, the game will let the user know if they successfully destroyed 
all of the ships or not.
*/
#include <cstdlib>
#include <iostream>

using namespace std;


//use malloc() to allocate a 2D char array
void print_grid(char ** input_grid, int input_grid_size);
char ** generate_grid(int input_grid_size);
void populate_result_grid(char ** result_grid, int grid_size);

int main()
{

srand(time(NULL));
//
int grid_size = 8;

int guess_count = 24;
int o_total = 0;

char ** guess_grid = generate_grid(grid_size);
char ** result_grid = generate_grid(grid_size);
populate_result_grid(result_grid, grid_size);
//print_grid(result_grid, grid_size);

cout << "LETS PLAY BATTLESHIP"<<endl;

while(guess_count > 0)
{
    int x;
		int y;
    cout<<""<<endl;
		cout << "Please entere an x coordinate between 0 and " << grid_size - 1 << ":  " << endl;
		cin >> x;

		cout << "Please entere a y coordinate between 0 and " << grid_size - 1 << ":  " << endl;
		cin >> y;
    cout<<""<<endl;

    if((x >= grid_size) && (y>= grid_size))
    {
      cout<<"Out of bounds! Try again!"<<endl;
      guess_count--;
      continue;
    }
		if(result_grid[y][x] == 'O')
		{
			cout << "Kaboom!" << endl;
            cout<<""<<endl;

			guess_grid[y][x] = 'O';
            result_grid[y][x] = 'X';
            print_grid(guess_grid, grid_size);
		}
		else
		{
      guess_grid[y][x] = 'X';
      result_grid[y][x] = 'X';
      print_grid(guess_grid, grid_size);
			cout << "Sploosh." << endl;
            cout<<""<<endl;
		}
	
  guess_count--;
}
for(int i = 0; i < grid_size; i++)
	{
		for(int j = 0; j < grid_size; j++)
		{

			if((result_grid[i][j] == 'O'))
			{
				o_total++;
			}
		
		}
	}

cout<<""<<endl;
cout<<"Below is your guess grid"<<endl;
print_grid(guess_grid, grid_size);
cout<<""<<endl;

cout<<"Below is the actual grid"<<endl;

if(o_total == 0)
{
 cout<<"Congrats you hit all the ships!"<<endl;
 cout<<"Ships Left: "<<o_total<<endl;
} else {
 cout<<"You did not hit every ship."<<endl;
 cout<<"Ships Left: "<<o_total<<endl;
}

print_grid(result_grid, grid_size);

return 0;
}

void populate_result_grid(char ** result_grid, int grid_size)
{
  int o_count = 0;
  int current_rand;

	for(int i = 0; i < grid_size; i++)
	{
		for(int j = 0; j < grid_size; j++)
		{
			current_rand = rand() % grid_size;
             
             if(result_grid[i][j] == 'O')
             {
               continue;
             }

			if((o_count < 10) && (current_rand == 1))
			{
				result_grid[i][j] = 'O';
				o_count++;
			}
			else
			{
				result_grid[i][j] = '-';
			}
		}
	}
    for(int i = 0; i < grid_size; i++)
	{
		for(int j = 0; j < grid_size; j++)
		{
			current_rand = rand() % grid_size;
             
             if(result_grid[i][j] == 'O')
             {
               continue;
             }

			if((o_count < 10) && (current_rand == 1))
			{
				result_grid[i][j] = 'O';
				o_count++;
			}
			else
			{
				result_grid[i][j] = '-';
			}
		}
	}
}


void print_grid(char ** input_grid, int input_grid_size)
{
  for(int i = 0; i < input_grid_size; i++)
	{
		for(int j = 0; j < input_grid_size; j++)
		{
			cout << input_grid[i][j] << " ";
		}

		cout << endl;
	}
}
char ** generate_grid(int input_grid_size) 
{
 
  char ** grid = (char **) malloc(input_grid_size * sizeof(char *));

  if(grid == NULL)
	{
		cout << "malloc failed!" << endl;
	}

  for(int i = 0; i < input_grid_size; i++)
	{
		grid[i] = (char *) malloc(input_grid_size * sizeof(char));

		if(grid[i] == NULL)
		{
			cout << "malloc failed!" << endl;
		}
	}

	for(int i = 0; i < input_grid_size; i++)
	{
		for(int j = 0; j < input_grid_size; j++)
		{
				grid[i][j] = '-';
			
		}
	}

  return grid;
}