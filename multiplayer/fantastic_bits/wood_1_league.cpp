#include <cstdlib>
#include <cstdio>
#include <cmath>

#include <algorithm>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

/**
 * Grab Snaffles and try to throw them through the opponent's goal!
 * Move towards a Snaffle and use your team id to determine where you need to throw it.
 **/

const string MY_WIZARD = "WIZARD";
const string OPPONENT_WIZARD = "OPPONENT_WIZARD";
const string SNAFFLE = "SNAFFLE";

const int WIZARD_HAS_SNAFFLE = 1; //for wizard entity status
const int SNAFFLE_GRABBED = 1; //for snaffle entity status

const int MAXIMUM_THRUST = 150;
const int MAXIMUM_POWER = 500;

class Position {
public:
    int x, y;

    Position(int x, int y) : x(x), y(y) {}

    Position() {
        this->x = 0;
        this->y = 0;
    }
};

class Entity {
public:
    int id;
    string type;
    Position position;
    int vx, vy;
    int state;

    Entity(int id, const string &type, const Position &position, int vx, int vy, int state) : id(id), type(type),
                                                                                              position(position),
                                                                                              vx(vx), vy(vy),
                                                                                              state(state) {}

    Entity() {}
};

Position goal_center(const int& my_team_id) {
    Position position;

    if(my_team_id == 1) position = Position(0, 3750);
    else if(my_team_id == 0) position = Position(16000, 3750);

    return position;
}

vector<Entity> snaffles;
vector<Entity> my_wizards;

Entity current_wizard;

int distance_squared(Position p1, Position p2) {
    int x = p1.x - p2.x;
    int y = p1.y - p2.y;

    return x * x + y * y;
}

bool compare(Entity e1, Entity e2) {
    Position p1 = e1.position;
    Position p2 = e2.position;

    int distance1 = distance_squared(p1, current_wizard.position);
    int distance2 = distance_squared(p2, current_wizard.position);

    return distance1 < distance2;
}

int main()
{
    int my_team_id; // if 0 you need to score on the right of the map, if 1 you need to score on the left
    scanf("%d", &my_team_id);

    // game loop
    while (1) {
        int my_score;
        int my_magic;
        scanf("%d%d", &my_score, &my_magic);

        int opponent_score;
        int opponent_magic;
        scanf("%d%d", &opponent_score, &opponent_magic);

        //clear vectors
        snaffles.clear();
        my_wizards.clear();

        int entities; // number of entities still in game
        scanf("%d", &entities);
        for (int i = 0; i < entities; i++) {
            int entity_id; // entity identifier
            char et[21]; // "WIZARD", "OPPONENT_WIZARD" or "SNAFFLE" (or "BLUDGER" after first league)
            int x; // position
            int y; // position
            int vx; // velocity
            int vy; // velocity
            int state; // 1 if the wizard is holding a Snaffle, 0 otherwise
            scanf("%d %s %d %d %d %d %d", &entity_id, et, &x, &y, &vx, &vy, &state);

            string entity_type = string(et);

            Entity entity = Entity(entity_id, entity_type, Position(x, y), vx, vy, state);

            if(entity_type.compare(SNAFFLE) == 0) snaffles.push_back(entity);
            else if(entity_type.compare(MY_WIZARD) == 0) my_wizards.push_back(entity);
        }

        //algo to score
        for(int i = 0; i < (int)my_wizards.size(); i++) {
            current_wizard = my_wizards[i];

            bool done = false;

            if(current_wizard.state == WIZARD_HAS_SNAFFLE) {
                //throw to snaffle at goal
                Position goal = goal_center(my_team_id);

                printf("THROW %d %d %d", goal.x, goal.y, MAXIMUM_POWER);

                done = true;
            }

            if(!done) {
                //sort snaffles
                sort(snaffles.begin(), snaffles.end(), compare);

                Entity current_snaffle = snaffles[0];
                printf("MOVE %d %d %d", current_snaffle.position.x, current_snaffle.position.y, MAXIMUM_THRUST);
                
            }
            printf("\n");
        }
    }
}