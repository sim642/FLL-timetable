import csv

class Team:
    def __init__(self, row):
        self.name = row['name']

        self.rows = []


def load(filename):
    with open(filename) as csvfile:
        reader = csv.DictReader(csvfile)
        return [Team(row) for row in reader]
