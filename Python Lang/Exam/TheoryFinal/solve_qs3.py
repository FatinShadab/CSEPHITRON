"""
    # There are 3 type of scopes of a variable in python,
        1. Local scope
        2. Global scope
        3. Enclosing scope
"""
# 1. Local scope
def func():
    local_val_of_func = True

try:
    print(local_val_of_func)
except NameError as error:
    print("As we tried to call the variable named 'local_val_of_func' outside of the func,")
    print(f"we will get {error}, because local_val_of_func is a local variable of func function.")


# 2. Global scope
global_var = "I am Global"

def global_var_user():
    print("Inside the function : global_var_user")
    print("I can use 'global_var', because it's global.")
    print(f"global_var = {global_var}")

print()
print(global_var)
global_var_user()


# 3. Enclosing scope
print()
my_var = "I am global!"

def outter_func():
    my_var = "I am local!"
    def inner_func():
        my_var = "I am enclosed!"
        print(my_var)
    inner_func()

outter_func()