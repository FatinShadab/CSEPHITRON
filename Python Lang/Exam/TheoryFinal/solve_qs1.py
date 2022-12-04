"""
    You have the data given below. You need to write a python program to print as sample output from the data.									10
    data={
        'a':[{
            'aa':{'aax':5,'aay':6,'aaz':7},
            'ab':{'abx':8,'aby':9,'abz':10}
            },
            {
            'aaa':{'aaax':11,'aaay':12,'aaaz':13},
            'aab':{'aabx':14,'aaby':15,'aabz':16}
            }],
        'b':[{
            'ba':{'bax':17,'bay':18,'baz':19},
            'bb':{'bbx':20,'bby':21,'bbz':22}
            },
            {
            'bba':{'bbax':23,'bbay':24,'bbaz':25},
            'bbb':{'bbbx':26,'bbby':27,'bbbz':28}
            }],
        'c':[{
            'ca':{'cax':29,'cay':30,'caz':31},
            'cb':{'cbx':32,'cby':33,'cbz':34}
            },
            {
            'cca':{'ccax':35,'ccay':36,'ccaz':37},
            'ccb':{'ccbx':38,'ccby':39,'ccbz':40}
            }]
    }

    Output:
        Key:aax Value: 5
        Key:aay Value: 6
        Key:aaz Value: 7
        Key:abx Value: 8
        ...
        ...
        Key:ccaz Value: 37
        Key:ccbx Value: 38
        Key:ccby Value: 39
        Key:ccbz Value: 40
"""

from typing import List, Dict

def clean_data(data : List) -> str:
    clean_data : List[str] = []

    for value in data.values():
        for inner_data in value:
            for inner_data_value in inner_data.values():
                for inner_data_value_key in inner_data_value.keys():
                    clean_data.append(f"Key:{inner_data_value_key} Value: {inner_data_value[inner_data_value_key]}")

    return "\n".join(clean_data)


if __name__ == "__main__":

    data : Dict[str, List[Dict[str, Dict[str, int]]]]= {
        'a':[{
            'aa':{'aax':5,'aay':6,'aaz':7},
            'ab':{'abx':8,'aby':9,'abz':10}
            },
            {
            'aaa':{'aaax':11,'aaay':12,'aaaz':13},
            'aab':{'aabx':14,'aaby':15,'aabz':16}
            }],
        'b':[{
            'ba':{'bax':17,'bay':18,'baz':19},
            'bb':{'bbx':20,'bby':21,'bbz':22}
            },
            {
            'bba':{'bbax':23,'bbay':24,'bbaz':25},
            'bbb':{'bbbx':26,'bbby':27,'bbbz':28}
            }],
        'c':[{
            'ca':{'cax':29,'cay':30,'caz':31},
            'cb':{'cbx':32,'cby':33,'cbz':34}
            },
            {
            'cca':{'ccax':35,'ccay':36,'ccaz':37},
            'ccb':{'ccbx':38,'ccby':39,'ccbz':40}
            }]
    }
    
    print(clean_data(data))