"""
Have to encrypt data using "Casear Cipher" technique.

"Casear Cipher":

    It is a type of substitution cipher in which each letter in 
    the plaintext is replaced by a letter some fixed number of 
    positions down the alphabet. For example, with a left shift 
    of 3, D would be replaced by A, E would become B, and so on.

    for more - https://en.wikipedia.org/wiki/Caesar_cipher

Test case :

Input    :    
Output   :

"""
data = input("Enter the data to Encrypt - ")

shift = 4

enq_data = "".join([chr((ord(char)+shift - 97) % 26 + 97) for char in data])

print(f"The encrypted data - {enq_data}")