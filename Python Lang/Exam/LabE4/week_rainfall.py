"""
Create a program for storing a week’s worth of rainfall data. Use a list to store
each day’s value, entered sequentially by the user. When an entire week has been
input, display the days with the minimum and maximum rainfall. 
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
 
def main() -> None:
    rainfall_data = get_rainfall_data()
 
    day_with_min_rainfall = get_minimum_rainfall_day(rainfall_data)
    day_with_max_rainfall = get_maximum_rainfall_day(rainfall_data)
 
    print(f"\nMaximum rainfall recorded on '{day_with_max_rainfall}'\nMinimum rainfall recorded on '{day_with_min_rainfall}'")
 
 
if __name__ == "__main__":
    main()