"""
    You need to find bugs from the python program below and give a correct python code to
    show as output given below. You can’t add extra lines, you just need to modify the given
    code so that you can get the expected output.

    Code:
    ----------

        >>> data = [{'a':5,'b':10},{'x':15,'y':20}]
        >>> for val in range(data):
        >>>     for key,val2 in val:
        >>>         print(f"Key:{key} Value:{data[key]}")

    Output:
    -----------

        Key:a Value:5
        Key:b Value:10
        Key:x Value:15
        Key:y Value:20
"""

data=[{'a':5,'b':10},{'x':15,'y':20}]

for val in data:
    for key, val2 in val.items():
        print(f"Key:{key} Value:{val[key]}")
