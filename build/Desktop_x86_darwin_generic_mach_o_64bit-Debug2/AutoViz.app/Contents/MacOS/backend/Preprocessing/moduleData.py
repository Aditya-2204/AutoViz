import json
import sys

moduleType = sys.argv[1]
moduleType = moduleType.lower()

with open("../moduledata.json", "r") as file:
    data = json.load(file)

print(data[moduleType])