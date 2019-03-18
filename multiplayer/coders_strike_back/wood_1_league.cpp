#include <cstdlib>
#include <cstdio>
#include <cstring>

int main() {

    // game loop
    while (1) {
        int x;
        int y;
        int nextCheckpointX; // x position of the next check point
        int nextCheckpointY; // y position of the next check point
        int nextCheckpointDist; // distance to the next checkpoint
        int nextCheckpointAngle; // angle between your pod orientation and the direction of the next checkpoint
        scanf("%d %d %d %d %d %d", &x, &y, &nextCheckpointX, &nextCheckpointY, &nextCheckpointDist, &nextCheckpointAngle);
        int opponentX;
        int opponentY;
        scanf("%d%d", &opponentX, &opponentY);

        int power = 0;

        if(nextCheckpointAngle >= 90 || nextCheckpointAngle <= -90) {
            power = 10;
        } else {
            if(power < 50) {
                //BOOST
                printf("%d %d BOOST\n", nextCheckpointX, nextCheckpointY);
                continue;
            } else {
                power = 100;
            }
        }

        printf("%d %d %d\n", nextCheckpointX, nextCheckpointY, power);
    }
}