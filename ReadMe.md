# README

## POLSKI

### Opis aplikacji
Snake to prosta znana gra z dawnych lat. W tej wersji wąż jest 
reprezentowany przez kwadraty porszuające się po ekranie. Żółtym 
kolorem oznaczona jest głowa węża, a zielonym reszta jego ciała.
W grze występuje jeden typ jedzenia (jabłko), reprezentowane przez
czerwone koło. Po zjedzeniu jabłka wąż rośnie o jedno pole, a gracz
zdobywa 10 punktów. Po uderzeniu w ściane lub zderzeniu się z
jednym z segmentów swoje ciała wąż umiera, a gra zostaje zresetowana.

Wszelkie komunikaty gry wyświetlane są w przezroczystej ramce w
środkowo-górnej części ekranu.

Gracz do sterownia używa strzałek kierunkowych.

### Sposób uruchamiania
Projekt stworzony jest za pośrednictwem środowiska CLion. Do 
uruchomienia należy wykorzystać skrypt
```
build.bat
```
znadujący się w głównym folderze projektu.

Do poprawnego działania skryptu wymagane jest zainstalowanie i
dodanie do ścieżki globalnej systemu następujących elementów:
- CMake w wersji co najmniej 3.27 możliwy do pobrania na stronie:
https://cmake.org/download/

- GCC 13.1.0 MinGW możliwy do pobrania na stronie:
https://www.sfml-dev.org/download/sfml/2.6.1/

## English

### Application description
Snake is a simple, well-known game from the old days. In this 
version there is a snake represented by squares moving around the 
screen. Yellow square is a snake's head and green squares are the rest 
of its body. There is one type of food in the game (apple), 
represented by red circle. After eating an apple, the snake grows by
one square and the player scores 10 points. After hitting a wall 
or colliding with one of the segments of its body the snake dies 
and the game is reset.

All game messages are displayed in a transparent frame
middle-top of the screen.

The player uses directional arrows to control the snake.

### How to run
The project is created using the CLion environment. To build project
use a script
```
build.bat
```
located in the main project folder.

For the script to work properly, it is required to install and
adding the following tools to the global system path:
- CMake version at least 3.27 available for download at:
  https://cmake.org/download/

- GCC 13.1.0 MinGW available for download at:
  https://www.sfml-dev.org/download/sfml/2.6.1/