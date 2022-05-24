import java.util.Scanner;

public class Betting {
  public static void main(String[] args) {
    Scanner stdin = new Scanner(System.in);

    float bet_1 = stdin.nextInt();

    float bet_2 = 100 - bet_1;

    System.out.println((bet_1 + bet_2) / bet_1);
    System.out.println((bet_2 + bet_1) / bet_2);
  }
}
