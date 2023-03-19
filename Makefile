game: main.c
	gcc main.c -o game -lm -lGL -lGLU -lglut

clean:
	rm game

