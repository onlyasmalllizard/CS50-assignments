from cs50 import get_int


def main():

    # declares the variable size
    size = ask()

    # prints vertically for the number of rows specified
    for i in range(size):
        # prints any necessary spacing before the first hashes
        for j in range(size - (i + 1)):
            print(" ", end="")
        # prints the first pyramid's hashes horizontally
        for k in range(i + 1):
            print("#", end="")
        # prints the space between the pyramids
        for l in range(2):
            print(" ", end="")
        # prints the second pyramid's hashes horizontally
        for m in range(i + 1):
            print("#", end="")
        # moves onto the next line
        print()


def ask():
    # asks the user for a number until they return a valid input
    while True:
        x = get_int("Enter a number between 1 and 8: ")
        if x > 0 and x < 9:
            return x


if __name__ == "__main__":
    main()
