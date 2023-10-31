public class Printer {
    protected int value = 0;

    public void print() {
        System.out.println(value);
    }
}

class FastPrinter extends Printer {

    public int value = 1;

    @Override
    public void print() {
        System.out.println(value);
    }

}

class TestPrint {
    public static void main(String[] args) {
        Printer fastPrinter = new FastPrinter();
        // ((FastPrinter) fastPrinter).value = 2;
        fastPrinter.value = 2;
        fastPrinter.print();
    }
}