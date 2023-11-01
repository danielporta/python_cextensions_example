# tail recursive variant

def fib(n:int):
    return __fib(n,0,1)

def __fib(n:int, a:int, b:int):
    if n < 1:
        return a
    else:
        return __fib(n-1, b, a+b)
