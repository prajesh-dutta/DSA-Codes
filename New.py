import phonenumbers
from phonenumbers import geocoder

phone_number1 = phonenumbers.parse("+6737292894")
print("Phone number Location")
print(geocoder.description_for_number(phone_number1, "en"))