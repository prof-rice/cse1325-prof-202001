#include <iostream>

typedef bool Cell;

int main() {
  Cell grid[20][20];
  for(int x=0; x<20; ++x) for(int y=0; y<20; ++y) grid[x][y] = (bool)(rand()%2);
  for(int y=0; y<20; ++y) {
      for(int x=0; x<20; ++x) {
          std::cout << (grid[x][y] ? 'X' : '.');
      }
      std::cout << '\n';
  }
}
