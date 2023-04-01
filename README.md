# Dynamic Loading
Code created during recording the [Dynamic Loading](https://youtu.be/PhMZYrzJBC8) video.

# Code for the Self-Modifying Code video
Code created during recording the [Self-Modifying Code in Assembly](https://youtu.be/VO6gMLtQOKM) video.

# Build
## C
```
gcc -std=gnu17 -Wall -g main.c -o main -ldl
./main
gcc -std=gnu17 -Wall -g exit.c -o doit.so -fPIC -shared  
gcc -std=gnu17 -Wall -g hello.c -o doit.so -fPIC -shared
```
## C++
```
g++ -std=gnu++17 -Wall -I./ -g main.cpp -o main -ldl
g++ -std=gnu++17 -Wall -fPIC -shared -I./ -g cupcake.cpp -o cupcake.so
g++ -std=gnu++17 -Wall -fPIC -shared -I./ -g donut.cpp -o donut.so
./main
./main 1
./main 2
```
