using System;
using System.Diagnostics;

public class Program
{
    public static int Fibonacci(int n)
    {
        if (n == 0) {
            return 0;
        }
        else if (n==1) {
            return 1;
        } else {
            return Fibonacci(n - 1) + Fibonacci(n - 2);
        }
    }

    static void Main()
    {       
        for (int i=0; i<44; i++) {
            Stopwatch stopwatch = new Stopwatch();
            stopwatch.Start(); // Start the timer

            int result = Fibonacci(i); // Call the Fibonacci method

            stopwatch.Stop(); // Stop the timer

            //Console.WriteLine($"Fibonacci number at position {n} is: {result}");

            TimeSpan timeSpan = stopwatch.Elapsed;
            Console.WriteLine(timeSpan.TotalMilliseconds);
            string elapsedTime = $"{timeSpan.TotalMilliseconds} ms";
            //Console.WriteLine($"Time taken: {elapsedTime}");
            //Console.WriteLine($"{elapsedTime}");
        }
    }
}