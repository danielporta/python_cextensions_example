package org.example;

public class Main {
    public static void main(String[] args) {
        System.out.println("Hello world!");
        for (int i=0; i<44; i++) {
            long start = System.currentTimeMillis();
            long f = fib(i);
            long end = System.currentTimeMillis();
            long dur = end-start;
            //System.out.println(i + " (" + dur + ") -->  " + f);
	    System.out.println(dur);
        }
    }
    
    public static long fib(long n) {
        if (n==0) {
            return 0;
        } else if (n==1) {
            return 1;
        }
        else {
            return fib(n-1) + fib(n-2);
        }
    }
}
