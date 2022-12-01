"""
Create a program for storing a week’s worth of rainfall data. Use a list to store
each day’s value, entered sequentially by the user. When an entire week has been
input, display the days with the minimum and maximum rainfall.

Extend your answer to the previous exercise (4) so that it also displays the mean
and standard deviation of the values. The mean is the sum of all the values
divided by the number of values. The standard deviation is the square root of the
sum of the squares of the difference between each value and the mean, divided
by the number of items. (You can’t use any library)
"""
import calendar
 
 
def get_week_day_name(day : int) -> str:
    calendar.setfirstweekday(calendar.SATURDAY)
    return calendar.weekheader(9).split()[day]
 
def get_rainfall_data() -> tuple:
    return tuple(int(input(f"Enter the rainfall data of {get_week_day_name(day)} : ")) for day in range(7))

def get_minimum_rainfall_day(data : tuple) -> str:
    _min = min(data)
    all_min_indices = [idx for idx, d in enumerate(data) if d == _min]
    return ' '.join([get_week_day_name(index) for index in all_min_indices]).rstrip()
 
def get_maximum_rainfall_day(data : tuple) -> str:
    _max = max(data)
    all_max_indices = [idx for idx, d in enumerate(data) if d == _max]
    return ' '.join([get_week_day_name(index) for index in all_max_indices]).rstrip()
 
def get_mean(data : tuple) -> float:
    _sum = 0
    total_entry = 0

    for d in data:
        _sum += d
        total_entry += 1

    return _sum/total_entry

def get_std_deviation(data : tuple) -> float:
    data_mean = get_mean(data)

    sq_dif_sum = 0
    total_entry = 0

    for d in data:
        sq_dif_sum += (d - data_mean)**2 if d > data_mean else (data_mean - d)**2
        total_entry += 1

    return (sq_dif_sum/total_entry)**(1/2)
 
def main() -> None:
    rainfall_data = get_rainfall_data()
 
    day_with_min_rainfall = get_minimum_rainfall_day(rainfall_data)
    day_with_max_rainfall = get_maximum_rainfall_day(rainfall_data)

    print(f"\nThe mean of the data : {rainfall_data} is : {get_mean(rainfall_data)}")
    print(f"\nThe std deviation of the data : {rainfall_data} is : {get_std_deviation(rainfall_data)}")
 
    print(f"\nMaximum rainfall recorded on '{day_with_max_rainfall}'")
    print(f"\nMinimum rainfall recorded on '{day_with_min_rainfall}'")
 
 
if __name__ == "__main__":
    main()