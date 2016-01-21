import csv
import datetime

class Block:
    def __init__(self, row):
        self.name = row['name']
        self.columns = int(row['columns'])
        self.start_time = datetime.datetime.strptime(row['start_time'], '%Y-%m-%d %H:%M')
        self.setup_time = datetime.timedelta(minutes=int(row['setup_time']))
        self.row_time = datetime.timedelta(minutes=int(row['row_time']))
        self.cleanup_time = datetime.timedelta(minutes=int(row['cleanup_time']))

    @staticmethod
    def load(filename):
        with open(filename) as csvfile:
            reader = csv.DictReader(csvfile)
            return [Block(row) for row in reader]
