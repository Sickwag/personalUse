import java.util.HashMap;
import java.applet.Applet;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.text.CollationElementIterator;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.List;
import java.util.Random;
import java.util.Scanner;
import java.util.stream.Collectors;

// public class Main {
//     public static void main(String[] args) {
//         // ExamOrientedTest ort = new ExamOrientedTest();
//         // ort.executeAllMethods();
//         // String str = "我喜欢学习java!";
//         // System.out.println(str.length());
//         sort4num(1, 3, 8, 2);
//         calcu1to200();
//         baiji();
//     }

//     public static void sort4num(int a, int b, int c, int d) {
//         ArrayList<Integer> list = new ArrayList<>();
//         list.add(a);
//         list.add(b);
//         list.add(c);
//         list.add(d);
//         Collections.sort(list);
//         Collections.reverse(list);
//         for (Integer x : list) {
//             System.out.println(x);
//         }
//     }

//     public static void calcu1to200() {
//         int sum = 0, count = 1;
//         while (count <= 200) {
//             if (count % 3 == 0) {
//                 sum += count;
//             }
//             count++;
//         }
//         System.out.println(sum);
//     }

//     public static void baiji() {
//         final int cost = 100;
//         for (int i = 0; i < 20; i++) {
//             for (int j = 0; j < 33; j++) {
//                 for (int j2 = 0; j2 < 300; j2++) {
//                     if (i * 5 + j * 3 + j2 / 3 == cost && i + j + j2 == cost) {
//                         System.out.println(i + " + " + j + " + " + j2);
//                     }
//                 }
//             }
//         }
//     }
// }

// class Student {
//     private int ID;
//     private String name;
//     private int score;

//     Student(int ID, String name, int score) {
//         this.ID = ID;
//         this.name = name;
//         this.score = score;
//     }

//     int getID() {
//         return this.ID;
//     }
// }

// class Rectangle {
//     private double length;\
//     private double width;

//     public Rectangle(double length, double width) {
//         this.length = length;
//         this.width = width;
//     }
//     public double getArea() {
//         return length * width;
//     }
// }

// class Cuboid extends Rectangle {
//     private double height; 
//     public Cuboid(double length, double width, double height) {
//         super(length, width);
//         this.height = height;
//     }

//     public double getVolume() {
//         return getArea() * height;
//     }
// }

// class Test {
//     public static void main(String[] args) {
//         Cuboid cuboid = new Cuboid(5.0, 4.0, 3.0);

//         System.out.println("the rectangle area is: " + cuboid.getArea());
//         System.out.println("the cuboid volume is: " + cuboid.getVolume());
//     }
// 

// class Gh extends Applet implements ActionListener {
//     Label result;
//     Button btn;
//     TextField tfd1, tfd2;
//     int a = 0, b = 0, max = 0;

//     public void init() {
//         result = new Label();
//         btn = new Button();
//         tfd1 = new TextField();
//         tfd2 = new TextField();
//         add(tfd1);
//         add(tfd2);
//         add(btn);
//         add(result);
//         btn.addActionListener(this);
//     }

//     public void actionPerformed(ActionEvent e) {
//         a = new Integer(tfd1.getText()).intValue();
//         b = new Integer(tfd2.getText()).intValue();
//         result.setText("bigger one is: " + Math.max(a, b));
//     }
// }


// interface InterfaceDefiner {
//     public abstract void showInfo();

//     public abstract void anotherMethod();
// }

// class InterfaceImplementer implements InterfaceDefiner{
//     @Override
//     public void showInfo(){
//         System.out.println("hello");
//     }

//     @Override
//     public void anotherMethod() {
//         System.out.println("anotherMethod");
//         byte $_5b;
//     }
// }

// public class Main {
//     public static void main(String[] args) {
//         Gh gh = new Gh();
//         gh.init();
//     }
// }

public class Main {
    public static void main(String[] args) {
        // ArrayList<Integer> list = new ArrayList<Integer>() {};
        int[] arr = { 10, 1, 2, 3, 4, 5 };
        List<Integer> list = Arrays.stream(arr).boxed().collect(Collectors.toList()); // all changeable
        List<Integer> initList = Arrays.asList(1, 2, 3, 4, 5); // size unchangeable
        int[] listToArray = list.stream().mapToInt(Integer::intValue).toArray();
        List<Integer> arrayToList = Arrays.stream(arr).boxed().collect(Collectors.toList());
        Arrays.sort(arr);
        for (Integer i : arr) {
            System.out.print(" " + i);
        }
        System.out.println("\n==========");
        Collections.reverse(list);
        for (Integer i : list) {
            System.out.print(" " + i);
        }
        System.out.println("\n==========");
        Collections.reverse(initList);
        for (Integer i : initList) {
            System.out.print(" " + i);
        }
        // Collections.reverse(listToArray);
        System.out.println("\n==========");
        Collections.reverse(arrayToList);
        for (Integer i : arrayToList) {
            System.out.print(" " + i);
        }
        // BiggestAndSmallest();
        System.out.println("我".length());
        System.out.println("喜".length());
        System.out.println("欢".length());
        System.out.println("学".length());
        System.out.println("习".length());
        System.out.println("j".length());
        System.out.println("a".length());
        System.out.println("v".length());
        System.out.println("a".length());
        System.out.println("！".length());
        String str = "我喜欢学习java！";
        System.out.println(str.length());
        baiqianbaiji();
        // sort4num();
        Method.nineNineTable();

        String data = "hello world";
        System.out.println(Method.reverseSentence(data));
        int a = -2;
        System.out.println(a >> 3);

    }

    public static void baiqianbaiji() {
        for (int gongji = 0; gongji <= 100 / 5; gongji++) {
            for (int muji = 0; muji <= 100 / 3; muji++) {
                int xiaoji = 100 - gongji - muji;
                if (xiaoji % 3 != 0)
                    continue; // 小鸡必须是3的倍数
                if (gongji * 5 + muji * 3 + xiaoji / 3 == 100) {
                    System.out.println(gongji + "公鸡+" + muji + "母鸡+" + xiaoji + "小鸡");
                }
            }
        }
    }

    public static void sort4num() {
        Scanner s = new Scanner(System.in);
        ArrayList<Integer> list = new ArrayList<>();
        for (int i = 0; i < 4; i++) {
            list.add(s.nextInt());
        }
        // Collections.sort(list);
        System.out.println("max one: " + Collections.max(list));
        System.out.println("min one: " + Collections.min(list));
    }

    public static void BiggestAndSmallest() {
        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> list = new ArrayList<>();
        for (int i = 0; i < 5; i++) {
            list.add(sc.nextInt());
        }

        list.sort(Collections.reverseOrder());
        ArrayList<Integer> al = new ArrayList<>(Arrays.asList(1, 2, 3, 4, 5));
        al.sort(Collections.reverseOrder());
        Collections.sort(list);
        System.out.println("max one: " + list.get(list.size() - 1));
        System.out.println("min one: " + list.get(0));
        sc.close();
        int[] arr = { 1, 2, 3, 4, 5 };
        List<Integer> arrayToList = Arrays.stream(arr).boxed().collect(Collectors.toList());
        List<Integer> initList = Arrays.asList(1, 2, 3, 4, 5);
        int[] listToArray = list.stream().mapToInt(Integer::intValue).toArray();

        Arrays.sort(arr);// sort array
        Collections.reverse(arrayToList);
        Collections.sort(list);
        list.sort(Collections.reverseOrder());

        try (BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));) {
            int a = Integer.parseInt(bf.readLine());
            char c = (char) bf.read();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }
}

class Method {
    private static HashMap<Integer, Integer> memo = new HashMap<>();

    public static int fib(int n) {
        if (n <= 1)
            return n;
        return memo.computeIfAbsent(n, k -> fib(k - 1) + fib(k - 2));
    }

    public static ArrayList<Integer> primes(int a, int b) {
        ArrayList<Integer> res = new ArrayList<>();
        boolean[] isPrime = new boolean[b + 1];
        ArrayList<Integer> primes = new ArrayList<>();
        for (int i = 2; i <= b; i++)
            isPrime[i] = true;
        for (int i = 2; i <= b; i++) {
            if (isPrime[i])
                primes.add(i);
            for (int p : primes) {
                if (p * i > b)
                    break;
                isPrime[p * i] = false;
                if (i % p == 0)
                    break;
            }
        }
        for (int p : primes) {
            if (p >= a)
                res.add(p);
        }
        return res;
    }

    public static void nineNineTable() {
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= i; j++) {
                System.out.print(j + " * " + i + " = " + i * j + '\t');
                if (j == i)
                    System.out.println();
            }
        }
    }

    public static String reverseSentence(String data) {
        String[] splitedWords = data.split(" ");
        StringBuffer ans = new StringBuffer();
        for (int i = 0; i < splitedWords.length; i++) {
            StringBuffer sb = new StringBuffer(splitedWords[i]).reverse();
            if (i != splitedWords.length - 1) {
                sb.append(" ");
            }
            ans.append(sb);
        }
        return ans.toString();
    }

    public static boolean isRightEmail(String emailString) {
        String data = "hello";
        return true;
    }
}

// public class Main {

// public static void main(String[] args) {
// // FrameInout fi = new FrameInout();
// Thread t1 = new Thread(new MessagePrinter("hello, thread 1"));
// Thread t2 = new Thread(new MessagePrinter("hello, thread 2"));
// t1.start();
// try{
// Thread.sleep(500);
// } catch (InterruptedException e) {
// e.printStackTrace();
// }
// t2.start();
// }
// }

// class MessagePrinter implements Runnable {

// private String message;
// MessagePrinter(String message) {
// this.message = message;
// }
// @Override
// public void run() {
// while (true) {
// System.out.println(message + "-" + java.time.LocalTime.now());
// try {
// Thread.sleep(1000);
// } catch (InterruptedException e) {
// e.printStackTrace();
// break;
// }
// }
// }
// }

// class FrameInout extends Frame implements ActionListener {
// Label propmt;
// Button bt;
// TextField input, output;

// FrameInout() {
// propmt = new Label("please input your name: ");
// bt = new Button("Class");
// input = new TextField(10);
// output = new TextField(20);
// setLayout(new FlowLayout());
// add(propmt);
// add(input);
// add(output);
// add(bt);
// input.addActionListener(this);
// output.addActionListener(this);
// setSize(300, 200);
// show();
// }

// public void actionPerformed(ActionEvent e) {
// if (e.getSource() == input) {
// output.setText(input.getText() + " welcome to you");
// }
// else {
// dispose();
// System.exit(0);
// }
// }
// }

// class FrameOut extends Frame {

// FrameOut() {
// super("Button");
// Button btn = new Button("click");
// setLayout(new FlowLayout());
// add(btn);
// setSize(300, 200);
// show();
// }
// public static void method() {
// try{
// System.out.println();
// }catch(Exception e){
// e.getStackTrace();
// }
// }
// }