import time
import fib as f
#import cfib as f

if __name__ == '__main__':
    for i in range(43):
        start = time.time()
        result = f.fib(i)
        finish = time.time()
        duration = finish - start
        print('fib({}) = {} - duration: {:0.3f}'.format(i, result, duration))
