"""
    Explain with examples - Single Inheritance, Multiple Inheritance 
    and Multilevel inheritance.
"""
from __future__ import annotations
from typing import List
# ==========================================#
#              Single Inheritance           #
#===========================================#
class Person:
    def __init__(self : Person, name : str, age : int, gender : str, nationality : str) -> None:
        self.age : int = age
        self.name : str = name
        self.gender : str = gender
        self.nationality : str = nationality

    def about(self : Person) -> None:
        print(f"Name        : {self.name}")
        print(f"Age         : {self.age}")
        print(f"Gender      : {self.gender}")
        print(f"Nationality : {self.nationality}")


class Employee(Person):
    def __init__(self : Employee, name : str, age : int, gender : str, nationality : str, company : str, title : str, salary : float) -> None:
        super().__init__(name, age, gender, nationality)
        self.company : str = company
        self.title : str = title
        self.salary : float = salary

    def about(self : Employee) -> None:
        super().about()
        print(f"\nCompany     : {self.company}")
        print(f"Title       : {self.title}")
        print(f"Salary      : {self.salary}")
# ==========================================#
#              Multiple Inheritance         #
#===========================================#
class Father:
    def __init__(self : Father, name : str, profession : str) -> None:
        self.father_name : str = name
        self.father_profession : str = profession

    def about(self : Father) -> None:
        print("About Father :")
        print(f"\tName       : {self.father_name}")
        print(f"\tProfession : {self.father_profession}")


class Mother:
    def __init__(self : Mother, name : str, profession : str) -> None:
        self.mother_name : str = name
        self.mother_profession : str = profession

    def about(self : Mother) -> None:
        print("About Mother :")
        print(f"\tName       : {self.mother_name}")
        print(f"\tProfession : {self.mother_profession}")


class Child(Father, Mother):
    def __init__(self : Child, name : str, father_name : str, father_profession : str, mother_name : str, mother_profession : str) -> None:
        Father.__init__(self, father_name, father_profession)
        Mother.__init__(self, mother_name, mother_profession)

        self.child_name : str = name

    def about(self : Child) -> None:
        print("About Child")
        print(f"\tName       : {self.child_name}")
        Father.about(self)
        Mother.about(self)
# ==========================================#
#             Multilevel Inheritance        #
#===========================================#
class GrandFather:
    SKILLS : List[str] = ['Singing', 'Drawing', 'Swimming']


class FATHER(GrandFather):
    SKILLS : List[str] = ['Driving', 'Dancing'] + GrandFather.SKILLS


class Son(FATHER):
    SKILLS : List[str] = ['programming'] + FATHER.SKILLS

    @staticmethod
    def skills() -> None:
        for skill in Son.SKILLS:
            print(skill)

if __name__ == "__main__":
    # ==========================================#
    #              Single Inheritance           #
    #===========================================#
    print("Single Inheritance Example ...")
    em = Employee("Turja", 21, "male", "BD", "macrotech", "Founder", 20000000.00)
    em.about()
    # ==========================================#
    #              Multiple Inheritance         #
    #===========================================#
    print("\nMultiple Inheritance Example ...")
    jon = Child('Jon', 'Mr.Henrray', 'Doctor', 'Ms.Kenny', 'Teacher')
    jon.about()
    # ==========================================#
    #             Multilevel Inheritance        #
    #===========================================#
    print("\nMultilevel Inheritance Example ...")
    son = Son()
    son.skills()