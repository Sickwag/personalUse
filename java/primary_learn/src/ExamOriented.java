import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.HashMap;
import java.util.Map;

public class ExamOriented {
    private Map<Integer, Integer> hash = new HashMap<>();

    public int fib(int n) {
        if (hash.containsKey(n)) {
            return hash.get(n);
        }
        if (n == 1 || n == 2)
            return 1;
        hash.put(n, fib(n - 1) + fib(n - 2));
        return hash.get(n);
    }

    public List<Integer> sieve(int from, int to) {
        if (to < 2) return new ArrayList<>();
        boolean[] isPrime = new boolean[to + 1];
        Arrays.fill(isPrime, true);
        List<Integer> primes = new ArrayList<>();
        for (int i = 2; i <= to; i++) {
            if (isPrime[i]) primes.add(i);
            for (int p : primes) {
                if (i * p > to) break;
                isPrime[i * p] = false;
                if (i % p == 0) break;
            }
        }
        int start = Collections.binarySearch(primes, from);
        start = start < 0 ? -start - 1 : start;
        return primes.subList(start, primes.size());
    }


    public void shuixianhuashu() {
        System.out.println("我喜欢学习java!".length());
    }
}