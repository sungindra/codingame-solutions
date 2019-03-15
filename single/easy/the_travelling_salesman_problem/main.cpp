#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstdbool>

#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#define mp make_pair

using namespace std;
typedef pair<int, int> point;
typedef vector<point> vp;

const int MAXIMUM = 0x3f3f3f3f;

vp points;

double** distance_matrix;

double euclidean_distance(point a, point b) {
    int x = a.first - b.first;
    int y = a.second - b.second;

    double distance = sqrt(x * x + y * y * 1.0);
    return distance;
}

void init_tables() {
    //distance_matrix
    int size = (int)points.size();
    distance_matrix = new double*[size];
    for(int i = 0; i < size; i++) {
        distance_matrix[i] = new double[size];
        for(int j = 0; j < size; j++) {
            distance_matrix[i][j] = MAXIMUM * 1.0;
        }
    }
}

void delete_tables() {
    //distance_matrix
    int size = (int)points.size();
    for(int i = 0; i < size; i++) {
        delete [] distance_matrix[i];
    }
    delete [] distance_matrix;
}

void build_matrix() {
    init_tables();

    int size = (int)points.size();
    for(int a = 0; a < size - 1; a++) {
        for(int b = a + 1; b < size; b++) {
            //a <- source, b <- destination
            distance_matrix[a][b] = euclidean_distance(points[a], points[b]);
            distance_matrix[b][a] = distance_matrix[a][b];
        }
    }
}

bool element_exists(const unordered_set<int>& visited_idx, const int& idx) {
    return visited_idx.find(idx) != visited_idx.end();
}

double calculate_distance() {
    unordered_set<int> visited_idx;

    double result = 0.0;
    int source = 0;

    do {
        visited_idx.insert(source);

        //check all neighbors
        double current_distance = MAXIMUM * 1.0;
        int current_destination = -1;
        for(int destination = 0; destination < (int)points.size(); destination++) {
            if(destination == source) continue;
            if(element_exists(visited_idx, destination)) continue;

            if(distance_matrix[source][destination] < current_distance) {
                current_destination = destination;
                current_distance = distance_matrix[source][destination];
            }
        }

        result += current_distance;
        source = current_destination;

    } while(visited_idx.size() + 1 < points.size());

    result += distance_matrix[source][0];

    return result;
}

int main() {
    int N;
    scanf("%d", &N);

    points.clear();

    while(N--) {
        int x, y;
        scanf("%d %d", &x, &y);

        point p = mp(x, y);
        points.push_back(p);
    }

    //build distance matrix
    build_matrix();

    //calculate, dammit!
    double answer = 1.0 * calculate_distance();
    printf("%d", (int)round(answer));

    //delete tables
    delete_tables();
}