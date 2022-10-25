"""  
2. Use web search to find some API to get weather data. Use that to get your region’s
weather data every 30 minute.

Write a function named weather_data() and write your code inside this function.
"""
import time
import requests


def weather_data() -> None:
    url = 'https://weatherbit-v1-mashape.p.rapidapi.com/forecast/3hourly'

    headers = {
        'X-RapidAPI-Key': '2e3ea4ba7cmshd308ad8f392be24p16394bjsna4af3e4d8e66',
        'X-RapidAPI-Host': 'weatherbit-v1-mashape.p.rapidapi.com'
    }

    params = {'lat': '23.6238', 'lon': '90.5000'} # lat and lon of Narayanganj

    while True:
        
        response = requests.get(url=url, params=params, headers=headers)

        raw_data = response.json()

        for key, value in raw_data.items():
            if key != "data":
                print(f"{key}    : {value}")
            else:
                print("Weather Data    : ")
                for key2, value2 in value[0].items():
                    print(f"    {key2}    : {value2}")

        time.sleep(30*60)



if __name__ == "__main__":
    weather_data()