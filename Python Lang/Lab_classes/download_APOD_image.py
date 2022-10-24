import requests

APOD_API = "https://api.nasa.gov/planetary/apod?api_key=DEMO_KEY"

# get the json response
response = requests.get(APOD_API)
content_dict = response.json()

# get the image url from the dict
image_url = content_dict["url"]
image_name = image_url.split('/')[-1]
url_image = requests.get(image_url)

# download and save the image
with open(image_name, 'wb') as image:
    image.write(url_image.content)