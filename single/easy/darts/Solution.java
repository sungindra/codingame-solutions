import java.util.*;

class Solution {

    private static class Point {
        public int x, y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public Point() {}
    }

    private class Player implements Comparable<Player> {
        String name;
        int score;

        public Player(String name, int score) {
            this.name = name;
            this.score = score;
        }

        @Override
        public int compareTo(Player o) {
            return Integer.compare(o.score, this.score);
        }
    }

    private static class Square {
        public static final int score() {
            return 5;
        }

        public static int length () {
            return Solution.SIZE;
        }

        //quadrant convention
        public static final int TOP_RIGHT = 1;
        public static final int TOP_LEFT = 2;
        public static final int BOTTOM_LEFT = 3;
        public static final int BOTTOM_RIGHT = 4;

        public static Point center() {
            return Solution.center();
        }

        public static boolean isOutside(final Point point) {
            HashMap<Integer, Point> allPoints = getAllPoints();

            //for x
            if(point.x < allPoints.get(TOP_LEFT).x) return false;
            if(point.x > allPoints.get(BOTTOM_RIGHT).x) return false;

            //for y
            if(point.y < allPoints.get(BOTTOM_LEFT).y) return false;
            if(point.y > allPoints.get(TOP_RIGHT).y) return false;

            return true;
        }

        public static HashMap<Integer, Point> getAllPoints() {
            HashMap<Integer, Point> points = new HashMap<>();

            points.put(TOP_LEFT, new Point(center().x - (length() >> 1), center().y + (length() >> 1)));
            points.put(TOP_RIGHT, new Point(center().x + (length() >> 1), center().y + (length() >> 1)));
            points.put(BOTTOM_LEFT, new Point(center().x - (length() >> 1), center().y - (length() >> 1)));
            points.put(BOTTOM_RIGHT, new Point(center().x + (length() >> 1), center().y - (length() >> 1)));

            return points;
        }
    }

    private static class Circle {
        public static final int score() {
            return 10;
        }

        public static int diameter() {
            return Solution.SIZE;
        }

        public static Point center() {
            return Solution.center();
        }

        public static int radius() {
            return diameter() >> 1;
        }

        public static boolean isOutside(Point point) {
            int distanceSquared = distanceSquared(Circle.center(), point);

            return distanceSquared <= (Circle.radius() * Circle.radius());
        }
    }

    private static class Diamond {
        public static final int score() {
            return 15;
        }

        public static int length() {
            return Solution.SIZE;
        }

        //quadrant convention
        public static final int TOP = 1, LEFT = 2, BOTTOM = 3, RIGHT = 4;

        public static Point center() {
            return Solution.center();
        }

        public static HashMap<Integer, Point> getAllPoints() {
            HashMap<Integer, Point> points = new HashMap<>();

            points.put(TOP, new Point(center().x, center().y + (length() >> 1)));
            points.put(LEFT, new Point(center().x - (length() >> 1), center().y));
            points.put(BOTTOM, new Point(center().x, center().y - (length() >> 1)));
            points.put(RIGHT, new Point(center().x + (length() >> 1), center().y));

            return points;
        }

        public static boolean isOutside(Point point) {
            boolean status = true;

            //clockwise test
            HashMap<Integer, Point> allPoints = getAllPoints();

            status &= (orientation(point, allPoints.get(LEFT), allPoints.get(TOP)) >= 0);
            status &= (orientation(point, allPoints.get(TOP), allPoints.get(RIGHT)) >= 0);
            status &= (orientation(point, allPoints.get(RIGHT), allPoints.get(BOTTOM)) >= 0);
            status &= (orientation(point, allPoints.get(BOTTOM), allPoints.get(LEFT)) >= 0);

            return status;
        }
    }

    static int orientation(final Point p1, final Point p2, final Point p3) {
        int val = (p2.y - p1.y) * (p3.x - p2.x) -
                  (p2.x - p1.x) * (p3.y - p2.y);

        return val;
    }

    static Point center() {
        return new Point(0, 0);
    }

    static int distanceSquared(final Point a, final Point b) {
        int x = a.x - b.x;
        int y = a.y - b.y;

        return x * x + y * y;
    }

    static double distance(final Point a, final Point b) {
        return Math.sqrt(distanceSquared(a, b) * 1.0d);
    }

    static int SIZE;

    public Solution() {
        Scanner reader = new Scanner(System.in);
        SIZE = reader.nextInt();

        int N = reader.nextInt();
        if (reader.hasNextLine()) reader.nextLine();
        Player[] players = new Player[N];
        HashMap<String, Integer> nameMap = new HashMap<>();
        for (int i = 0; i < N; i++) {
            String name = reader.nextLine();
            players[i] = (new Player(name, 0));
            nameMap.put(name, i);
        }

        int T = reader.nextInt();
        for (int i = 0; i < T; i++) {
            String throwName = reader.next();
            int throwX = reader.nextInt();
            int throwY = reader.nextInt();
            Point point = new Point(throwX, throwY);

            //calculate score
            int score = 0;

            if(Diamond.isOutside(point)) score += Diamond.score();
            else if(Circle.isOutside(point)) score += Circle.score();
            else if(Square.isOutside(point)) score += Square.score();

            int idx = nameMap.get(throwName);
            players[idx].score += score;
        }

        Arrays.sort(players);

        for(int i = 0; i < players.length; i++) {
            System.out.printf("%s %d\n", players[i].name, players[i].score);
        }
    }

    public static void main(String args[]) {
        new Solution();
    }
}