#from distutils.core import setup, Extension
from setuptools import setup, Extension

module = Extension('cfib', 
                   sources = ['cfib.c'], 
                   extra_objects=['../fib_c/lib/fib.o'])
 
setup (name = 'cfib',
        version = '1.0',
        description = 'This is a package for calculating fib(n) in C',        
        ext_modules = [module])

