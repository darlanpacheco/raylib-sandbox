rm -rf ./build/windows/*
rm -rf ./build/linux/*
cp -r ./assets ./build/windows/.
cp -r ./assets ./build/linux/.

# x86_64-w64-mingw32-g++ $(ls ./src/*.cpp) -o ./build/windows/game.exe -I./include -L./libs/windows -lraylib -lgdi32 -lwinmm -static
g++ $(ls ./src/*.cpp) -o ./build/linux/game -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

./build/linux/game
