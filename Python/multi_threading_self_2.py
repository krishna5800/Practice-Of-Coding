import threading
from queue import Queue

def Fun(Num1, Num2, Q):
    Q.put(Num1+Num2)

def Gun(Num1, Num2, Q):
    Q.put(Num1*Num2)

def main():

    Num1 = int(input("Enter Num1 : "))
    Num2 = int(input("Enter Num2 : "))

    Q1 = Queue()
    Q2 = Queue()

    Thread1 = threading.Thread(target = Fun, args = (Num1, Num2, Q1))
    Thread2 = threading.Thread(target = Gun, args = (Num1, Num2, Q2))

    Thread1.start()
    Thread2.start()

    Thread1.join()
    Thread2.join()

    print("Answer for Thread1 : ", Q1.get())
    print("Answer for Thread2 : ", Q2.get())

if __name__ == "__main__":
    main()