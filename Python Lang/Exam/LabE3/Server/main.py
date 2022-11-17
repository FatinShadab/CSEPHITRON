import os
import glob
import time
import shutil
from zipfile import ZipFile


class Server:

    POST_FIXS = [1, 2, 3]
    SUPPORTED_FILE_TYPES = ['txt', 'py']
    PARENT_PATH = os.path.dirname(__file__)

    def __init__(self, source_path : str, destination_path : str) -> None:
        self.__active = False

        self.__source_objects = []
        self.__zip_objects = []

        self.source_path = source_path if source_path[-2:] == '/*' else f"{source_path}/*"
        self.destination_path = destination_path if destination_path[-1] == '/' else f"{destination_path}/"

    def __listen_source_event(self) -> bool:
        source_object = glob.glob(self.source_path)

        self.__source_objects += [obj for obj in source_object if obj.split('.')[-1] in self.SUPPORTED_FILE_TYPES and obj not in self.__source_objects]

        return len(self.__source_objects) > 0

    def __txt_file_handler(self, source_obj) -> None:

            temp_files = dict({})
            
            shutil.copy(source_obj, self.PARENT_PATH)

            fname = source_obj.split('\\')[-1].split('.')[0]
            fpath = os.path.join(self.PARENT_PATH, source_obj.split('\\')[-1])

            with open(f"{fpath}", 'r') as f:
                lines = [line.replace('\n', '').rstrip() for line in f.readlines()]

            for postfix in self.POST_FIXS:
                
                new_fname = source_obj.split('\\')[-1].replace(fname, f"{fname}_{postfix}")
                new_fpath = os.path.join(self.PARENT_PATH, new_fname)

                with open(new_fpath, 'w') as new_f:
                    new_f.write("\n".join(lines[:(10*postfix)]))

                temp_files[f"./{new_fname}"] = new_fpath

            zipFname = f"./{fname}_protected.zip"

            with ZipFile(zipFname, 'w') as zipObj2:
                [zipObj2.write(file_path) for file_path in temp_files]
                    
            self.__zip_objects.append(zipFname)

            os.remove(fpath)
            [os.remove(fpath) for fpath in temp_files.values()]

            self.__send()

    def __py_file_handler(self, source_obj) -> None:
        fname = source_obj.split('\\')[-1]

        try:
            shutil.copy(source_obj, self.PARENT_PATH)
        except FileNotFoundError as e:
            pass

        try:
            exec(open(fname).read())
        except Exception as e:
            print(e)

        os.remove(os.path.join(self.PARENT_PATH, fname))

    def __proccess_files(self) -> None:
        for source_obj in self.__source_objects:
            # to handle error occur if a file is being copied to the source folder.
            time.sleep(1)

            if source_obj.split('.')[-1] == 'txt':
                self.__txt_file_handler(source_obj)
            else:
                self.__py_file_handler(source_obj)

            os.remove(source_obj)
            self.__source_objects.remove(source_obj)

    def __send(self) -> None:
        for zipobj in self.__zip_objects:

            with ZipFile(zipobj, 'r') as zip_ref:
                zip_ref.extractall(self.destination_path)

            os.remove(zipobj)
            self.__zip_objects.remove(zipobj)

    def activate(self) -> None:
        self.__active = True

        print("server activated!")
        
        while self.__active:
            if(self.__listen_source_event()):
                self.__proccess_files()

    def deactivate(self) -> None:
        self.__active = False
        print("server deactivated!")


if __name__ == "__main__":
    """
    # Dynamic
    while True:
        try:
            valid_source_path, valid_destination_path = False, False

            while not (valid_source_path and valid_destination_path):
                if not valid_source_path:
                    source_path = input("Enter the source dir path  : ").replace("\\", "/")
                if not valid_destination_path:
                    destination_path = input("Enter the destination dir path  : ").replace("\\", "/")

                if os.path.isdir(source_path):
                    valid_source_path = True
                else:
                    print(f"Invalid source dir path ! path: {source_path}")
                
                if os.path.isdir(destination_path):
                    valid_destination_path = True
                else:
                    print(f"Invalid destination dir path ! path: {destination_path}")

            try:
                server = Server(
                        source_path,
                        destination_path
                    )
                print("Enter Ctrl+C to deactivate.")
                server.activate()
            except KeyboardInterrupt:
                server.deactivate()
                try:
                    cmd = input("Press enter to continue. Ctrl+C to exit")
                    os.system('cls' if os.name == 'nt' else 'clear')
                except (KeyboardInterrupt, EOFError):
                    os.system('cls' if os.name == 'nt' else 'clear')
                    break
        except KeyboardInterrupt:
            print("Server terminated.")
            break
    """
    # Hardcoded

    source_path = "../Source/*"
    destination_path = "../Destination/"

    while True:
        try:
            server = Server(
                source_path,
                destination_path
            )
            print("Enter Ctrl+C to deactivate.")
            server.activate()
        except KeyboardInterrupt:
            server.deactivate()
            break