import threading

Add = 0
Mul = 0

def Fun(Num1, Num2):
    global Add
    Add = Num1+Num2

def Gun(Num1, Num2):
    global Mul
    Mul = Num1*Num2

def main():

    Num1 = int(input("Enter Num1 : "))
    Num2 = int(input("Enter Num2 : "))

    Thread1 = threading.Thread(target = Fun, args = (Num1, Num2))
    Thread2 = threading.Thread(target = Gun, args = (Num1, Num2))

    Thread1.start()
    Thread2.start()

    Thread1.join()
    Thread2.join()

    print("Answer for Thread1 : ", Add)
    print("Answer for Thread2 : ", Mul)

if __name__ == "__main__":
    main()