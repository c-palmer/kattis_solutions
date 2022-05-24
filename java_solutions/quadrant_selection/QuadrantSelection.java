import java.util.Scanner;

public class QuadrantSelection {
  public static void main(String[] args) {
    Scanner stdin = new Scanner(System.in);

    int x = stdin.nextInt();
    int y = stdin.nextInt();

    int quad;

    if (0 < x)
      quad = 0 < y ? 1 : 4;
    else 
      quad = 0 < y ? 2 : 3;

    System.out.println(quad);
  }
}
