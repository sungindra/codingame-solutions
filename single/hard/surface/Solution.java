import java.util.*;

class Solution {

    private class Point {
        public int row, column;

        public Point(int row, int column) {
            this.row = row;
            this.column = column;
        }

        @Override
        public int hashCode() {
            int hash = 3;
            hash = 47 * hash + this.row;
            hash = 47 * hash + this.column;
            return hash;
        }

        @Override
        public boolean equals(Object obj) {
            if (obj == null) return false;
            
            if (getClass() != obj.getClass()) return false;
            
            final Point other = (Point) obj;
            if (this.row != other.row) return false;
            
            return this.column == other.column;
        }

        @Override
        public String toString() {
            return "Point{" + "row=" + row + ", column=" + column + '}';
        }
        
    }
    
    final int neighborsSize = 4;
    final int[] neighborsRow = new int[]{-1, 0, 0, 1};
    final int[] neighborsColumn = new int[]{0, -1, 1, 0};
    final char LAND = '#';
    
    HashMap<Point, Integer> memo = new HashMap<>();
    int width, height;
    char[][] board;
    Scanner reader = new Scanner(System.in);
    
    void initializeBoard() {
        width = reader.nextInt(); //column
        height = reader.nextInt(); //row
        if (reader.hasNextLine()) reader.nextLine();
        
        board = new char[height][width];
    }
    
    void fillBoard() {
        initializeBoard();
        
        for (int i = 0; i < height; i++) {
            char[] row = reader.nextLine().toCharArray();
            System.arraycopy(row, 0, board[i], 0, width);
        }
    }
    
    boolean isInMap(Point point) {
        if(point.row < 0 || point.row >= height) return false;
        if(point.column < 0 || point.column >= width) return false;
        
        return true;
    }
    
    int BFS(final Point p) {
        if(memo.containsKey(p)) return memo.get(p);
        
        LinkedList<Point> queue = new LinkedList<>();
        
        HashSet<Point> visited = new HashSet<>();
        
        queue.add(p);
        if(board[p.row][p.column] != LAND) visited.add(p);
        while(!queue.isEmpty()) {
            Point current = queue.removeFirst();
            
            if(!isInMap(current)) continue;
            if(board[current.row][current.column] == LAND) continue;
            
            for(int i = 0; i < neighborsSize; i++) {
                int nextRow = current.row + neighborsRow[i];
                int nextColumn = current.column + neighborsColumn[i];
                Point next = new Point(nextRow, nextColumn);
                
                if(!isInMap(next)) continue;
                
                if(board[nextRow][nextColumn] == LAND) continue;
                if(visited.contains(next)) continue;
                
                queue.add(next);
                visited.add(next);
            }
        }
        
        int area = visited.size();
        
        //loop each square visited
        for(Point point : visited) memo.put(point, area);
        
        return area;
    }
    
    public Solution() {
        fillBoard();
        
        int N = reader.nextInt();
        for (int i = 0; i < N; i++) {
            int column = reader.nextInt();
            int row = reader.nextInt();
            if(reader.hasNextLine()) reader.nextLine();
            
            Point point = new Point(row, column);
            System.out.println(BFS(point));
        }
    }
    
    public static void main(String args[]) {
        new Solution();
    }
}