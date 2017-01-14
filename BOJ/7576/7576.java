import java.util.Scanner;
 
public class Main {
    static int array[][]= new int[1001][1001];
    static int d[][] = new int[1001][1001];
    static int tailx;
    static int taily;
    static int headx;
    static int heady;
    static int quex[] = new int[1000000];
    static int quey[] = new int[1000000];
    static int rl[] = { -1, 1, 0, 0 };
    static int ud[] = { 0, 0, -1, 1 };
    static int w;
    static int h;
    static int answer;
 
    public static void enque(int x, int y) {
        quex[tailx++] = x;
        quey[taily++] = y;
        tailx %= 1000000;
        taily %= 1000000;
    }
 
    public static int dequex() {
        int num = quex[headx];
        headx++;
        headx %= 1000000;
        return num;
    }
 
    public static int dequey() {
        int num = quey[heady];
        heady++;
        heady %= 1000000;
        return num;
    }
 
    public static boolean empty() {
        return headx == tailx;
    }
 
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        w = scan.nextInt();
        h = scan.nextInt();
        tailx = taily = headx = heady = 0;
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                array[i][j] = scan.nextInt();
                d[i][j] = -1;
                if (array[i][j] == 1) {
                    enque(i, j);
                    d[i][j] = 0;
                }
            }
        }
        while (!empty()) {
            int x = dequex();
            int y = dequey();
            for (int i = 0; i < 4; i++) {
                int nx = x + rl[i];
                int ny = y + ud[i];
                if (nx >= 1 && nx <= h && ny >= 1 && ny <= w) {
                    if (array[nx][ny] == 0 && d[nx][ny] == -1) {
                        d[nx][ny] = d[x][y] + 1;
                        enque(nx, ny);
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                if (ans < d[i][j]) {
                    ans = d[i][j];
                }
            }
        }
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                if (array[i][j] == 0 && d[i][j] == -1) {
                    ans = -1;
                }
            }
        }
        System.out.println(ans);
    }
}