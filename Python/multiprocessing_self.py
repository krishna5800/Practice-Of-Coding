import multiprocessing
import os

def Fun(Value1, Value2, Q):
    Q.put(Value1 + Value2)

def Gun(Value1, Value2, Q):
    Q.put(Value1 * Value2)

def main():

    Value1 = int(input("Enter num1 : "))
    Value2 = int(input("Enter num2 : "))

    Q1 = multiprocessing.Queue()        # Queue() used to share data from child process to parent process
    Q2 = multiprocessing.Queue()

    Process1 = multiprocessing.Process(target = Fun, args = (Value1, Value2, Q1))
    Process2 = multiprocessing.Process(target = Gun, args = (Value1, Value2, Q2))

    Process1.start()
    Process2.start()

    Process1.join()
    Process2.join()

    print("Process1 answer : ", Q1.get())
    print("Process2 answer : ", Q2.get())

if __name__ == "__main__":
    main()