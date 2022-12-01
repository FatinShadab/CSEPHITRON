from __future__ import annotations
from abc import ABC, abstractmethod
from typing import List

import time
import random


class SUBJECT(ABC):
    """                                               ###                                           
        The abstract class or the interface/blueprint 
        for the SUBJECT child classes. 
    ###                                               """

    @abstractmethod
    def attach(self, observer : Observer) -> None:
        """                                     ###
            Attach an observer to the subject.
        ###                                     """
        pass

    @abstractmethod
    def detach(self, observer : Observer) -> None:
        """                                      ###
            Detach an observer from the subject.
        ###                                      """
        pass
    
    @abstractmethod
    def notify(self) -> None:
        """                                     ###
            Notify all observers about an event.
        ###                                     """
        pass


class OBSERVER(ABC):
    """                                               ###                                           
        The abstract class or the interface/blueprint 
        for the OBSERVER child classes. 
    ###                                               """

    @abstractmethod
    def update(self, msg : str) -> None:
        """                             ###
            Receive update from SUBJECT.
        ###                             """
        pass


class MAIN_WEATHER_STATION(SUBJECT):
    """                                                  ###
        MAIN_WEATHER_STATION is a child class of SUBJECT
        class. It will notify other Substations (each
        child class object of OBSERVER class) about the
        weather condition of some zones.
    ###                                                  """

    # the class will select danger zone randomly from 
    # __danger_zones list and store that in __current_danger_zone .
    __danger_zones: List[str] = ['Chittagong', 'Barishal', 'Khulna', 'COX-BAZAR']
    __current_danger_zone : str = None

    # list of all sub stations (instance of child class of OBSERVER class)
    __sub_stations: List[OBSERVER] = []

    def attach(self, observer : OBSERVER) -> None:
        print(f"{observer.zone} station attached.")
        self.__sub_stations.append(observer)

    def detach(self, observer : OBSERVER) -> None:
        if observer in self.__sub_stations:
            print(f"{observer.zone} station detached.")
            self.__sub_stations.remove(observer)

    def notify(self) -> None:
        print("\nSending bad weather signal to all sub stations ... ")
        [station.update(self.__current_danger_zone) for station in self.__sub_stations]

    def get_weather_update(self) -> None:
        """                                         ###
            This method will randomly choose a zone
            as red zone and call the notify method.
        ###                                         """
        print("\n Getting weather information ...")
        self.__current_danger_zone = random.choice(self.__danger_zones)
        self.notify()


class SUB_STATION(OBSERVER):
    """                                                 ###
        SUB_STATION is a child class of class OBSERVER.
        The instances of this class will listen for
        activity of MAIN_WEATHER_STATION class intance,
        and will act accourding to that.
    ###                                                 """
    def __init__(self, zone : str) -> None:
        super().__init__()
        self.zone : str = zone

    def update(self, msg : str) -> None:
        print(f"\n\tStation ({self.zone}) :Weather data received.")

        if msg == self.zone:
            self.start_evacuation()
        else:
            self.send_help(msg)

        time.sleep(1.5) # to make the printing more realistic

    def start_evacuation(self) -> None:
        print(f"\tStation ({self.zone}) : We are starting the evacution process !!")

    def send_help(self, zone : str) -> None:
        print(f"\tStation ({self.zone}) : We are sending help to {zone} !!")


if __name__ == "__main__":

    weatherStationBD : SUBJECT = MAIN_WEATHER_STATION()

    zones : List[str] = ['Chittagong', 'Barishal', 'Khulna', 'COX-BAZAR', 'Dhaka', 'Rajshahi', 'Syllet']

    sub_stations : List[OBSERVER] = [SUB_STATION(zone) for zone in zones]

    [weatherStationBD.attach(station) for station in sub_stations]
    
    while True:
        try:
            weatherStationBD.get_weather_update()
            print()
            for i in range(60):
                print(f"getting weather update in {i}s", end="\r")
                time.sleep(1)
            print(' '*60)
        except KeyboardInterrupt as terminate:
            print("Program terminated !")
            break