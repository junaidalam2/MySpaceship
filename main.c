#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// up = 0, right = 1, down = 2, left = 3
// right turn = 1, left turn = -1
// if value of d crosses north (i.e. 'up' position), reset values accordingly
int compass(int turn, int d) {

    if (d + turn > 3) {
        d = 0;
    } else if (d + turn < 0) {
        d = 3;
    } else {
        d = d + turn;
    }
    return d;
}


// given direction which is determined from the function compass, advance along x and y axes
void advance(int dir, int *position){
    if (dir==0) {
        position[1]--;
    } else if (dir==2) {
        position[1]++;
    } else if (dir==1) {
        position[0]++;
    } else if (dir==3) {
        position[0]--;
    }
}


// iterate through string input and call compass and advance functions to move along x and y axes
void my_spaceship(char path[]){

    // declare direction and position and set values to starting point
    int d = 0;  // up = 0, right = 1, down = 2, left = 3
    int position[] = {0, 0};  // x and y coordinates, respectively
    char direction[][6] = {"up", "right", "down", "left"};

    if (strlen(path)==0) {

        printf("x: %d, y: %d, direction: %s", position[0], position[1], direction[d]);

    } else {
        int n = strlen(path);

        for (int i = 0; i < n; i++) {

            int turn_number;

            if (path[i]=='A') {
                advance(d, position);
            } else if (path[i]=='R') {
                turn_number = 1;
                d = compass(turn_number, d);
            } else if (path[i]=='L') {
                turn_number = -1;
                d = compass(turn_number, d);
            }
        }
    }

    printf("x: %d, y: %d, direction: %s", position[0], position[1], direction[d]);

}


void main(int argc, char *argv[])
{

    my_spaceship(argv[1]);

}

