import java.util.Arrays;

public class Test2451 {
    public String oddString1(String[] words) {
        boolean flag = true;
        int[] diff = new int[words[0].length() - 1];
        for (int i = 0; i < words[0].length() - 1; i++) {
            diff[i] = words[0].charAt(i + 1) - words[0].charAt(i);
        }
        for (int i = 1; i < words.length; i++) {
            for (int j = 0; j < words[i].length() - 1; j++) {
                int tmp = words[i].charAt(j + 1) - words[i].charAt(j);
                if (diff[j] != tmp) { // 与上一次不同
                    if (i > 1) { // 第三个及以后
                        if (flag) { // 之前的都相同
                            return words[i]; // 本次为例外
                        } else { // 之前存在不同AB A
                            return words[i - 1]; // 上次为例外
                        }
                    }
                    flag = false;
                    diff[j] = tmp;
                }
            }
            if (!flag && i > 1) {
                return words[i - 2];
            }

        }
        return null;
    }

    public String oddString2(String[] words) {
        String a = "";
        String b = "";
        a = help(words[0]);
        b = help(words[words.length - 1]);
        for (int i = 1; i < words.length - 1; i++) {
            String m = help(words[i]);
            if (m.equals(a) && m.equals(b)) {
                continue;
            } else if (!m.equals(a) && m.equals(b)) {
                return words[0];
            } else if (m.equals(a) && !m.equals(b)) {
                return words[words.length - 1];
            } else {
                return words[i];
            }
        }
        return "";
    }

    public String help(String temp) {
        StringBuilder sb = new StringBuilder();
        for (int i = 1; i < temp.length(); i++) {
            sb.append(temp.charAt(i) - temp.charAt(i - 1));
            sb.append(",");
        }
        return sb.toString();
    }

    public String oddString3(String[] words) {

        int[] diff0 = new int[words[0].length() - 1];
        int[] diff1 = new int[words[0].length() - 1];
        for (int i = 0; i < words[0].length() - 1; i++) {
            diff0[i] = words[0].charAt(i + 1) - words[0].charAt(i);
            diff1[i] = words[words.length - 1].charAt(i + 1) - words[words.length - 1].charAt(i);
            if (diff0[i] != diff1[i]) {
                break;
            }
        }
        for (int i = 1; i < words.length - 1; i++) {
            for (int j = 0; j < words[i].length() - 1; j++) {
                int tmp = words[i].charAt(j + 1) - words[i].charAt(j);
                if (tmp == diff0[j] && tmp == diff1[j]) {
                    continue;
                } else if (tmp != diff0[j] && tmp == diff1[j]) {
                    return words[0];
                } else if (tmp == diff0[j] && tmp != diff1[j]) {
                    return words[words.length - 1];
                } else {
                    return words[i];
                }
            }
        }
        return null;
    }

    // 官方
    public String oddString(String[] words) {
        int[] diff0 = get(words[0]);
        int[] diff1 = get(words[1]);
        if (Arrays.equals(diff0, diff1)) {
            for (int i = 2; i < words.length; i++) {
                if (!Arrays.equals(diff0, get(words[i]))) {
                    return words[i];
                }
            }
        }
        return Arrays.equals(diff0, get(words[2])) ? words[1] : words[0];
    }

    public int[] get(String word) {
        int[] diff = new int[word.length() - 1];
        for (int i = 0; i + 1 < word.length(); i++) {
            diff[i] = word.charAt(i + 1) - word.charAt(i);
        }
        return diff;
    }
}