import java.util.Scanner;

public class TriangleArea {
  public static void main(String[] args) {
    Scanner stdin = new Scanner(System.in);

    float height = stdin.nextInt();
    float base = stdin.nextInt();

    float area = (base * height) / 2;

    System.out.println(area);
  }
}
