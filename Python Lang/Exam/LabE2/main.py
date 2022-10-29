"""
1. Make a class named Star_Cinema which will have one class attribute named
hall_list which is an empty list initially. Make a method named entry_hall() to
insert an object of class Hall (Described below) inside its hall_list. (5)

2. Make a class named Hall which will have 5 instance attributes given below
a. seats which is an dictionary of seats information
b. show_list which is an list of tuples
c. rows which is the row of the seats in that hall
d. cols which is the column of the seats in that hall
e. hall_no which is the unique no. of that hall
Initialize an object of class Hall with rows, cols and hall_no. And insert that object
to the Star_Cinema class attribute named hall_list inside the initializer using
inheritance. seats and show_list will be empty initially. (20)

3. Make a method in Hall class named entry_show() which will take id, movie_name
and time in string format. Make a tuple with all of the information and append it to the
show_list attribute. Allocate seats with rows and cols using 2d list, initially all
seats will be free. Make a key with id to the attribute seats and value will be the 2d
list.
(10)

4. Make a method in Hall class named book_seats() which will take the customer
name, phone number, an id of the show and list of tuples where every tuple contains
the row and col of the seat. You need to check the id of the show, and book the
seats. (10)

5. Make a method in Hall class named view_show_list() which will view all the
shows running. (5)

6. Make a method in Hall class named view_available_seats() which will take an
id of show, and view the seats that are available in that show (10)

7. Make a replica system so that the counter can view all shows that are running, view
available seats in a show and can book tickets in a show. (20)

8. You need to handle the errors, for example- (10)
a. If someone gives a wrong id of a show
b. If someone tries to book a seat that is invalid
c. If someone tries to book a seat that is already booked

9. Make the information of the classes as protected/private as you can so that the attributes
can’t be accessed outside the class. (10)
"""
import os


class Star_Cinema:
    __hall_list = []

    @staticmethod
    def entry_hall(hall_obj : 'Hall') -> None:

        if hall_obj not in Star_Cinema.__hall_list:
            Star_Cinema.__hall_list.append(hall_obj)
            print(f"Hall : {hall_obj.hall_no} has been registered.")
        else:
            print(f"Hall : {hall_obj.hall_no} is already registered!")

        return

    @staticmethod
    def show_halls() -> None:
        for hall in Star_Cinema.__hall_list:
            print(hall)


class Hall:
    def __init__(self, seats : dict, show_list : list, rows : int, cols : int, hall_no : int) -> None:
        
        self.__cols = cols
        self.__rows = rows
        self.__seats = seats
        self.__hall_no = hall_no
        self.__show_list = show_list

    def __str__(self) -> str:
        return f'Hall NO : {self.__hall_no}'

    def get_show_ids(self) -> list:
        return [show[0] for show in self.__show_list]

    def entry_show(self, iD : int, movie_name : str, time : str) -> None:
        show = (iD, movie_name, time)

        if show not in self.__show_list:
            self.__show_list.append(show)
            self.__seats[iD] = [[('free',) for col in range(self.__cols)] for row in range(self.__rows)]

            print(f"{movie_name} has been added to the streaming list.")
        else:
            print(f"{movie_name} is already in the streaming list.")

        return

    def book_seats(self, customer_name : str, phone_number : str, show_id : int, booked_seats : list) -> None:

        if show_id in self.__seats.keys():
            for seat_row, seat_col in booked_seats:
                if (seat_row < self.__rows and seat_row > -1) and (seat_col < self.__cols and seat_col > -1):
                    if self.__seats[show_id][seat_row][seat_col][0] == 'free':
                        self.__seats[show_id][seat_row][seat_col] = ('Booked', customer_name, phone_number)
                    else:
                        print(f"Sorry the seat isn't available.")
                else:
                    print(f"Invalid seat number {seat_row}{seat_col}")
        else:
            print(f"There isn't any show streaming with id : {show_id}")

        return

    def view_show_list(self) -> None:
        show_strings = [f"ID: {show[0]} Name: {show[1]} Time: {show[2]}" for show in self.__show_list]

        border = "="*(len(max(show_strings))+2)

        print(f"{border}\nShows That are streaming now\n{border}")
        for detail in show_strings:
            print(f"{detail}\n{border}")
        
        return

    def view_available_seats(self, show_id : int) -> None:
        if show_id in self.__seats.keys():
            show = [sh[1] for sh in self.__show_list if sh[0] == show_id]
            available_seats = []

            print(f"Available seats for show : {show[0]}")

            [print(f"  {i}  ", end="") for i in range(len(self.seats[show_id][0]))]
            print()

            for r_idx, row in enumerate(self.seats[show_id]):
                for c_idx, seat in enumerate(row):
                    if seat[0] == 'free':
                        available_seats.append(f"row : {r_idx} col : {c_idx}")
                print(f"{r_idx}{['-' if seat[0] == 'free' else 'X' for seat in row]}")

            print(f"Available seats :\n{available_seats}")
        else:
            print(f"There isn't any show streaming with id : {show_id}")

    @property
    def hall_no(self) -> int:
        return self.__hall_no

    @property
    def seats(self) -> dict:
        return self.__seats


def clear_terminal() -> None:
    """A function to clear the terminal output"""
    if os.name == 'nt':
        os.system('cls')
    else:
        os.system('clear')

def system_start(hall : 'Hall') -> None:
    """Home menu design"""
    print(hall)
    hall.view_show_list()
    print("\n=========================================")
    print("||To see available seats enter :     1 ||")
    print("\n=========================================")
    print("||For booking tickets enter :        2 ||")
    print("\n=========================================")
    print("||To exit enter :                    3 ||")
    print("\n=========================================")


if __name__ == "__main__":
    # Create the company
    star_cinema = Star_Cinema()

    # Create the Hall
    jamuna_hall = Hall(
        seats = dict({}),
        show_list = [],
        rows = 5,
        cols = 5,
        hall_no = 11222004
    )

    # Adding Hall to the company
    star_cinema.entry_hall(jamuna_hall)
    # hall_list is a private attribute
    # to see the list uncomment the next line
    #star_cinema.show_halls()
    
    # Adding shows to hall
    jamuna_hall.entry_show(1, 'Iron Man I', '12:00 PM')
    jamuna_hall.entry_show(2, 'Iron Man II', '3:00 AM')
    jamuna_hall.entry_show(3, 'Iron Man III', '6:00 AM')

    clear_terminal()

    # The replica system
    while True:
        system_start(jamuna_hall)
        uinput = int(input('Enter A valid choice : '))

        if uinput in range(1, 4):
            if uinput == 3:
                clear_terminal()
                break

            elif uinput == 2:
                clear_terminal()

                jamuna_hall.view_show_list()

                show_id = int(input("Enter the id of the show you want to booked - "))

                if show_id in jamuna_hall.get_show_ids():
                    clear_terminal()
                    jamuna_hall.view_available_seats(show_id)

                    name = input("Enter you're name - ")
                    phone_number = input("Enter you're phone number - ")
                    seat_for_booked = int(input("Enter how many seats you want - "))

                    jamuna_hall.book_seats(name, phone_number, show_id, [(int(input(f"Enter the row number of seat {seat} - ")), int(input(f"Enter the col number of seat {seat} - "))) for seat in range(1, seat_for_booked+1)])
                    input("Booking completed ! press Enter to go to home.")
                    clear_terminal()
                else:
                    print(f"There are no show streaming with id : {show_id}")
                    input("Press Enter to go to home")
                    clear_terminal()

            elif uinput == 1:
                clear_terminal()

                jamuna_hall.view_show_list()

                show_id = int(input("Enter the id of the show - "))
                
                if show_id in jamuna_hall.get_show_ids():
                    clear_terminal()
                    jamuna_hall.view_available_seats(show_id)
                    input("Press Enter to go to home")
                    clear_terminal()
                else:
                    print(f"There are no show streaming with id : {show_id}")
                    input("Press Enter to go to home")
                    clear_terminal()
        else:
            clear_terminal()
            print("Invalid choice !! please choose again.")