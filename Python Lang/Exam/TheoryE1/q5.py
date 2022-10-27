"""
5. Write a python program to read student_name and mark from 
keyboard and store the data in a text file with an unique 
student_id .
"""
import os

def register_student(name : str, mark : int, db_path : str) -> None:
    student_id = 1

    if not os.path.isfile(db_path):
        with open(db_path, 'w') as db:
            pass

    with open(db_path, 'r') as db:
        data = db.readlines()

    if data:
        student_id += int(data[-1].split()[1].replace(',', ' ').rstrip())

    with open(db_path, 'a') as db:
        db.write(f"ID: {student_id}, Name : {name}, Mark : {mark}\n")     


if __name__ == "__main__":
    current_path = os.path.dirname(__file__).replace('\\', '/')
    db_path = f"{current_path}/db.txt"

    student_name = input("Name : ")
    student_mark = int(input("Marks obtained : "))

    register_student(student_name, student_mark, db_path)