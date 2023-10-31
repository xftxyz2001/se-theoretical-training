import java.util.ArrayList;
import java.util.List;

public class TestList {
    public static void main(String[] args) {
        // List<Father> lf = new ArrayList<Child>();
        List<? extends Father> lef = new ArrayList<Child>();
        List<? super Child> lsc = new ArrayList<Child>();
        List<? super Child> lsc2 = new ArrayList<Father>();
        System.out.println(lef);
        System.out.println(lsc);
        System.out.println(lsc2);
    }
}

/**
 * Child
 */
class Child extends Father {

}

class Father {

}