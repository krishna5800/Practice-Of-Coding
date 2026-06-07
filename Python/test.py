import functools as ft

def main():
    List = list()

    List.append(10)
    List.append(11)
    List.append(21)
    List.append(51)

    print("Original List : ", List)
    print()

    print("----- Filter Operation -----")
    print()

    List1 = list(filter((lambda X : not(X % 2 == 0)), List))

    print("After Filter : ", List1)
    print()

    print("----- Map Operation -----")
    print()

    List2 = list(map((lambda X : X*3), List1))

    print("After Map : ", List2)
    print()

    print("----- Reduce Operation -----")
    print()

    List3 = ft.reduce(lambda X, Y : X+Y, List2)

    print("After Map : ", List3)
    print()

if __name__ == "__main__":
    main()