from cs50 import get_int


def main():

    # declares the variable size
    size = ask()

    # prints vertically for the number of rows specified
    for i in range(size):
        # prints any necessary spacing before the first hashes
        print(" " * (size - (i + 1)), end="")
        # prints the first pyramid's hashes horizontally
        print("#" * (i + 1), end="")
        # prints the space between the pyramids
        print(" " * 2, end="")
        # prints the second pyramid's hashes horizontally
        print("#" * (i + 1), end="")
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
