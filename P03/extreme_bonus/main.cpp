#include <iostream>
#include <vector>
#include "color.h"

int main() {
  std::vector<Color> colors{
    Color::RED, 
    Color::GREEN,
    Color::BLUE,
    Color::RED + Color::BG,
    Color::RED + Color::BLUE,
    Color::RED * Color::BLUE,
    Color::RED * Color::BLACK,
    Color::RED * Color::WHITE,
  };
  Color old_c = Color::BLACK;
  for(auto c : colors) {
      std::cout << c << c.to_string() << Color::RESET;
      if(c == old_c) std::cout << " ==";
      if(c != old_c) std::cout << " !=";
      if(c <  old_c) std::cout << " <";
      if(c <= old_c) std::cout << " <=";
      if(c >  old_c) std::cout << " >";
      if(c >= old_c) std::cout << " >=";
      std::cout << " in subjective brightness to the previous color\n";
      old_c = c;
  }

  std::cout << Color::BLUE+Color::BG << Color::RED   << " Red " 
                                     << Color::WHITE << " White \n" << Color::RESET;

  Color color{Color::RED};
  for(int i=16; i<=256; i+=16) {
      color = color + 16;
      std::cout << color << color.to_string() << '\n';
  }

  color = Color::RED;
  color += Color::BLUE;
  std::cout << color << color.to_string() << '\n';

  color = Color::BLACK;
  for(int i=0; i<=256; i+=4) {
    std::cout << color << 'X';
    color += 4;
  }
  std::cout << '\n'; 

  for(Color c{Color::BLACK}; c<Color::WHITE; ++c) {
    std::cout << c << 'X';
  }
  std::cout << Color::RESET << '\n'; 
     

  while(std::cin) {
    std::cout << "Enter a color as '(red, green, blue)': ";
    std::cin >> color;
    std::cout << color << color.to_string() << Color::RESET << std::endl;
  }

  std::cout << Color::RESET; // Clean up after ourselves
}
