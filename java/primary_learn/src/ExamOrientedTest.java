import java.util.Map;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Stack;

public class ExamOrientedTest {
    private ExamOriented eo = new ExamOriented();

    private void p1test() {
        eo.fib(10);
    }

    private void p2test() {
        for (Integer x : eo.sieve(2, 100)) {
            System.out.println(x);
        }
    }

    public void executeAllMethods() {
        try {
            Method[] methods = this.getClass().getDeclaredMethods();
            List<Method> methodList = new ArrayList<>();
            Queue<String> methodName = new LinkedList<>();
            for (Method method : methods) {
                if (method.getName() != "executeAllMethods") {
                    methodList.add(method);
                    methodName.add(method.getName());
                }
            }
            for (Method m : methodList) {
                System.out.println("=========" + methodName.poll() + "=============");
                m.invoke(this);
                System.out.println("=====================================");
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

}

class Method {
    private Map<Integer, Integer> memo = new HashMap<>();

    public int fib(int n) {
        if (n <= 1)
            return n;
        return memo.computeIfAbsent(n, k -> fib(k - 1) + fib(k - 2));
    }

    public ArrayList<Integer> primes(int a, int b) {
        ArrayList<Integer> primes = new ArrayList<>();
        ArrayList<Integer> result = new ArrayList<>();
        boolean[] isPrime = new boolean[b + 1];
        for (int i = 0; i < b; i++) {
            isPrime[i] = true;
        }
        for (int i = 2; i <= b; i++) {
            if (isPrime[i] == true) {
                primes.add(i);
            }
            for (int p : primes) {
                if (p * i > b)
                    break;
                isPrime[p * i] = false;
                if (i % p == 0)
                    break;
            }
        }
        for (int p : primes) {
            if (p >= a && p <= b) {
                result.add(p);
            }
            int x = 1;
            int y = 2;
            System.out.println(Math.max(x, y));
        }
        return result;
    }
}
