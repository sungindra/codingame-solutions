#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> point;

int distance_squared(point a, point b) {
    int x = a.first - b.first;
    int y = a.second - b.second;
    return (x * x) + (y * y);
}
 
int main()
{

    // game loop
    int thrust = 100;
    while (1) {
        int x;
        int y;
        int nextCheckpointX; // x position of the next check point
        int nextCheckpointY; // y position of the next check point
        int nextCheckpointDist; // distance to the next checkpoint
        int nextCheckpointAngle; // angle between your pod orientation and the direction of the next checkpoint
        cin >> x >> y >> nextCheckpointX >> nextCheckpointY >> nextCheckpointDist >> nextCheckpointAngle; cin.ignore();
        int opponentX;
        int opponentY;
        cin >> opponentX >> opponentY; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        cerr << "nextCheckpointDist: " << nextCheckpointDist << endl;
        
        if((nextCheckpointDist <= 2750 && nextCheckpointAngle > 10) || nextCheckpointAngle > 45) {
            thrust -= 15;
            thrust = max(thrust, 20);
            cerr << "Break!" << '\n';
        } else {
            thrust = 100;
        }
        
        // You have to output the target position
        // followed by the power (0 <= thrust <= 100)
        // i.e.: "x y thrust"
        cout << nextCheckpointX << ' ' << nextCheckpointY << ' ' << thrust << '\n';
    }
}