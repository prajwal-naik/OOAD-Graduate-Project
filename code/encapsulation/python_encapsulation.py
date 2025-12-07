# import time
# import psutil
# import os

# class Account:
#     def __init__(self, b):
#         self._balance = b  
        
#     def get_balance(self):
#         return self._balance
        
#     def set_balance(self, b):
#         self._balance = b

# if __name__ == "__main__":
    
#     start = time.perf_counter_ns()
#     process = psutil.Process(os.getpid())
#     memory_before = process.memory_info().rss  # in bytes
#     for i in range(10000000):
#         acc = Account(1000)
#         acc.set_balance(1500)
#         acc.get_balance()
#         acc = None
#     end = time.perf_counter_ns()
#     memory_after = process.memory_info().rss
    
#     print((end - start) / 1e9);   
#     print("Memory used:", memory_after - memory_before, "bytes")


import tracemalloc
import time

class Account:
    def __init__(self, b):
        self._balance = b
    def get_balance(self):
        return self._balance
    def set_balance(self, b):
        self._balance = b

if __name__ == "__main__":
    tracemalloc.start()  # start tracking Python allocations

    start = time.perf_counter_ns()
    N = 10_000_000
    for i in range(N):
        acc = Account(1000)
        acc.set_balance(1500)
        acc.get_balance()
        acc = None
    end = time.perf_counter_ns()

    current, peak = tracemalloc.get_traced_memory()
    tracemalloc.stop()

    print("Execution time:", (end - start)/1e9, "seconds")
    print("Current memory:", current, "bytes")
    print("Peak memory:", peak, "bytes")
