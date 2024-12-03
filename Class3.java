import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Class3 {
    public static void main(String[] args) {
        int sum = 0;

        try {
            File file = new File("3list.txt");
            Scanner scanner = new Scanner(file);
            while (scanner.hasNextLine()) {
                String data = scanner.nextLine();

                String match = "mul\\((\\d++),(\\d++)\\)";
                Pattern pattern = Pattern.compile(match);
                Matcher matcher = pattern.matcher(data);

                while (matcher.find()) {
                    Integer d1 = Integer.parseInt(matcher.group(1));
                    Integer d2 = Integer.parseInt(matcher.group(2));

                    sum += d1 * d2;

                    System.out.println(d1 + ", " + d2);
                }
            }
        } catch (FileNotFoundException e) {
            System.out.println("File not found");
        } finally {
            System.out.println(sum);
        }
    }
}
