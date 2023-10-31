/**
 * E
 */
public class E {

    public static boolean random(double p) {
        return Math.random() < p;
    }

    /**
     * 
     * @param p   中奖概率
     * @param n   抽奖次数
     * @param nnn 从第nnn次开始，增加中奖概率
     * @param ppp 每次增加的中奖概率
     * @return
     */
    public static int ee(double p, int n, int nnn, double ppp) {

        double pp = p;
        int sum = 0;

        int nn = 0;
        for (int i = 0; i < n; i++) {

            nn++; // 未抽中的次数
            if (random(pp)) { // 抽中
                sum++; // 抽中的次数加一
                // if (nn > nnn) {
                nn = 0; // 未抽中的次数归零
                pp = p; // 概率归零
                // }
            } else {
                if (nn > nnn) { // 未抽中的次数大于nnn
                    pp += ppp; // 概率加ppp
                }
            }
        }
        return sum;
    }

    public static void main(String[] args) {

        int n = 1_0000;

        double sum = 0; // 求和

        for (int i = 0; i < n; i++) {
            int tmp = ee(0.012, 100, 60, 0.06);
            // System.out.println("第" + i + "次抽中" + tmp + "次");
            sum += tmp;
        }

        System.out.println(sum / n);

    }
}