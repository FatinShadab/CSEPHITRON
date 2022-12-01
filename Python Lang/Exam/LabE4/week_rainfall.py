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
    return tuple(input(f"Enter the rainfall data of {get_week_day_name(day)} : ") for day in range(7))
 
def get_minimum_rainfall_day(data : tuple) -> str:
    return get_week_day_name(data.index(min(data)))
 
def get_maximum_rainfall_day(data : tuple) -> str:
    return get_week_day_name(data.index(max(data)))
 
def main() -> None:
    rainfall_data = get_rainfall_data()
 
    day_with_min_rainfall = get_minimum_rainfall_day(rainfall_data)
    day_with_max_rainfall = get_maximum_rainfall_day(rainfall_data)
 
    print(f"\nMaximum rainfall recorded on '{day_with_max_rainfall}'\nMinimum rainfall recorded on '{day_with_min_rainfall}")
 
 
if __name__ == "__main__":
    main()