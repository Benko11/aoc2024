import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

enum DoMode {DO, DONT}

public class Class3B {
    public static String readFile(String file) throws IOException {
        Path path = Paths.get(file);
        return Files.readString(path);
    }

    public static void main(String[] args) throws IOException {
        String f = readFile("3list.txt");

        int sum = 0;
        String combinedPattern = "(mul\\((\\d+),(\\d+)\\))|(do\\(\\))|(don't\\(\\))";
        Pattern pattern = Pattern.compile(combinedPattern);
        Matcher matcher = pattern.matcher(f);
        DoMode mode = DoMode.DO;

        while (matcher.find()) {
            if (matcher.group(1) != null) {
                Integer d1 = Integer.parseInt(matcher.group(2));
                Integer d2 = Integer.parseInt(matcher.group(3));

                System.out.println(d1 + ", " + d2);

                if (mode == DoMode.DO)
                    sum += d1 * d2;
            }

            if (matcher.group(4) != null) {
                System.out.println("do()");
                mode = DoMode.DO;
            }

            if (matcher.group(5) != null) {
                System.out.println("don't()");
                mode = DoMode.DONT;
            }
        }

        System.out.println(sum);
    }
}
