import javafx.scene.shape.Shape;

public class App {
    public static void main(String[] args) throws Exception {
        // int[] default_array = {11,22,33,44,55};
        // System.out.println(AnotherClass.another_method());
        // int a = 23;
        // System.out.println(Integer.toBinaryString(a));
        // AnotherClass.display_arr(default_array);
        // AnotherClass.display_arr(AnotherClass.reset_array(default_array));
        // String formatted_String = String.format("the max of default array is : %d",
        // AnotherClass.max_array(default_array));
        // System.out.println(formatted_String);
        // AnotherClass ac = new AnotherClass();
        // Point p1 = new Point(1, 2);
        // Point p2 = new Point(3, 4);
        // System.out.println((p1.distance(p2)));
        // Line l1Line = new Line(p1, p2);
        // System.out.println(l1Line.length());
        // System.err.println(p1.toString());

        // Point p = new Point(3, 4);
        // double radius = 3.0;
        // circle c = new circle(p, radius);
        // c.draw();
        // arrowLine al = new arrowLine(p1, p2, "red", false, false);
        // al.draw();
        // ShapeManager manager = new ShapeManager();
        // manager.add_shape(new circle(p1, 3.5));
        // manager.add_shape(new Line(p1,p2,"orange"));
        // manager.add_shape(new arrowLine(p1, p2, "klein blue", false, false));
        // manager.draw_all_shapes();
        // child cd = new child();
        // cd.test();
        // System.out.println("---- new Child()");
        // Child c = new Child();
        // System.out.println("\n---- c.action()");
        // c.action();
        // Base b = c;
        // System.out.println("\n---- b.action()");
        // b.action();
        // System.out.println("\n---- b.s: " + b.s);
        // System.out.println("\n---- c.s: " + c.s);
        My_compare mc1 = new Point(2, 3);
        My_compare mc2 = new Point(4, 5);
        System.out.println(mc1.compareTo(mc2));
        System.out.println(mc2.compareTo(mc1));
    }
}

// class AnotherClass {
//     public static String another_method() {
//         return "this is another method.";
//     }

//     public static int[] reset_array(int[] array) {
//         for (int i = 0; i < array.length; i++) {
//             array[i] = i;
//         }
//         return array;
//     }

//     public static void display_arr(int[] array) {
//         for (int i = 0; i < array.length; i++) {
//             System.out.println(array[i]);
//         }
//     }

//     public static int max_array(int[] array) {
//         int init = Integer.MIN_VALUE;
//         for (int i = 0; i < array.length; i++) {
//             if (array[i] > init) {
//                 init = array[i];
//             }
//         }
//         return init;
//     }

//     public static void show_binary_of_data() {
//         System.out.println((Integer.toBinaryString(Float.floatToIntBits(100))));
//         System.out.println((Long.toBinaryString(Double.doubleToLongBits(100))));
//     }
// }

// class Shape {
//     private static final String DEFAULT_COLOR = "black";
//     private String color;

//     public Shape() {
//         this(DEFAULT_COLOR);
//     }

//     public Shape(String color) {
//         this.color = color;
//     }

//     public String getColor() {
//         return color;
//     }

//     public void setColor(String color) {
//         this.color = color;
//     }

//     public void draw() {
//         System.out.println("draw shape." + getClass().getName());
//     }
// }

// class Point {
//     private int x;
//     private int y;

//     public Point(int x, int y) {
//         this.x = x;
//         this.y = y;
//     }

//     public int getX() {
//         return this.x;
//     }

//     public int getY() {
//         return this.y;
//     }

//     public double distance(Point p) {
//         return Math.sqrt(Math.pow(x - p.getX(), 2) + Math.pow(y - p.getY(), 2));
//     }
// }

// class Line extends Shape {
//     private Point start;
//     private Point end;

//     public Line(Point starPoint, Point endPoint, String color) {
//         super(color);
//         this.start = starPoint;
//         this.end = endPoint;
//     }

//     public double length() {
//         return start.distance(end);
//     }

//     @Override
//     public void draw() {
//         System.out.println(
//                 "draw line from " + start.toString() + " to " + end.toString() + " using color : " + super.getColor());
//     }
// }

// class circle extends Shape {
//     private Point centrePoint;
//     private double radius;

//     public circle(Point c, double r) {
//         this.centrePoint = c;
//         this.radius = r;
//     }

//     @Override
//     public void draw() {
//         System.out.println(
//                 "draw circle at " + centrePoint.toString() + "with r " + radius + " using color : " + getColor());
//     }
// }

// class arrowLine extends Line {
//     private boolean starArrow;
//     private boolean endArrow;

//     public arrowLine(Point start, Point end, String color, boolean starArrow, boolean endArrow) {
//         super(start, end, color);
//         this.starArrow = starArrow;
//         this.endArrow = endArrow;
//     }

//     @Override
//     public void draw() {
//         super.draw();
//         if (starArrow) {
//             System.out.println("draw start arrow .");
//         }
//         if (endArrow) {
//             System.out.println("draw end arrow .");
//         }
//     }
// }

// class ShapeManager {
//     private static final int MAX_NUM = 100;
//     private Shape[] shapes = new Shape[MAX_NUM];
//     private int shape_num = 0;

//     public void add_shape(Shape shape) {
//         if (shape_num < MAX_NUM) {
//             shapes[shape_num++] = shape;
//         }
//     }

//     public void draw_all_shapes() {
//         for (int i = 0; i < shape_num; i++) {
//             shapes[i].draw();
//         }
//     }

// }

// class base {
// public base() {
// test();
// }

// public void test() {

// }
// }

// class child extends base{
// private int a = 123;
// public child() {

// }

// public void test() {
// System.out.println(a);
// }
// }

// class Base {
//     public static int s;
//     private int a;
//     static {
//         System.out.println("base static code block, s: " + s);
//         s = 1;
//     }
//     {
//         System.out.println("base instance code block, a: " + a);
//         a = 1;
//     }

//     public Base() {
//         System.out.println("base constructor code, a: " + a);
//         a = 2;
//     }

//     protected void step() {
//         System.out.println("base s: " + s + ", a: " + a);
//     }

//     public void action() {
//         System.out.println("start");
//         step();
//         System.out.println("end");
//     }
// }

// class Child extends Base {
//     public static int s;
//     private int a;
//     static {
//         System.out.println("child static code block, s: " + s);
//         s = 10;
//     }
//     {
//         System.out.println("child instance code block, a: " + a);
//         a = 10;
//     }

//     public Child() {
//         System.out.println("child constructor, a: " + a);
//         a = 20;
//     }

//     protected void step() {
//         System.out.println("child s: " + s + ", a: " + a);
//     }
// }

// class Base {
//     private static final int MAX = 100;
//     private int[] array = new int[MAX];
//     private int count = 0;

//     public void add_num(int number) {
//         if (count < MAX) {
//             array[count++] = number;
//         }
//     }

//     public void add_all(int[] numbers) {
//         for (int single_number : numbers) {
//             add_num(single_number);
//         }
//     }
// }

// class Child extends Base {
//     private long sum;

//     @Override
//     public void add_num(int number) {
//         super.add_num(number);
//     }

//     @Override
//     public void add_all(int[] numbers) {
//         super.add_all(numbers);
//     }

//     public long get_sum() {
//         return sum;
//     }
// }

// interface My_compare {
//     int compareTo(Object other);
// }

// class Point implements My_compare {
//     private int x;
//     private int y;

//     public Point(int x,int y) {
//         this.x = x;
//         this.y = y;
//     }    
//     public double distance() {
//         return Math.sqrt(x*x + y*y);
//     }
//     @Override
//     public int compareTo(Object other) {
//         if (!(other instanceof Point)) {
//             throw new IllegalArgumentException();
//         }
//         Point otherPoint = (Point) other;
//         double delta = distance() - otherPoint.distance();
//         return Double.compare(delta, 0);
//     }
//     @Override
//     public String toString() {
//         return "("+x+","+y+")";
//     }
// }

 class CompUtil {
    public static Object max(My_compare[] objs){
        if(objs==null||objs.length==0){
            return null;
        }
        My_compare max = objs[0];
        for(int i=1; i<objs.length; i++){
            if(max.compareTo(objs[i])<0){
                max = objs[i];
            }
        }
        return max;
    }
    public static void sort(My_compare[] objs){
        for(int i=0; i<objs.length; i++){
            int min = i;
            for(int j=i+1; j<objs.length; j++){
                if(objs[j].compareTo(objs[min])<0){
                    min = j;
                }
            }
            if(min!=i){
                 My_compare temp = objs[i];
                 objs[i] = objs[min];
                 objs[min] = temp;
            }
        }
    }
}

