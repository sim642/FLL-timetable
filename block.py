import csv
import datetime
import math

class Row:
    def __init__(self, block, i):
        self.columns = block.columns
        self.row_time = block.row_time
        self.cleanup_time = block.cleanup_time

        self.total_time = self.row_time + self.cleanup_time
        self.start_time = block.start_time + i * self.total_time

    @property
    def end_time(self):
        return self.start_time + self.total_time

class Block:
    def __init__(self, row):
        self.name = row['name']
        self.columns = int(row['columns'])
        self.start_time = datetime.datetime.strptime(row['start_time'], '%Y-%m-%d %H:%M')
        self.setup_time = datetime.timedelta(minutes=int(row['setup_time']))
        self.row_time = datetime.timedelta(minutes=int(row['row_time']))
        self.cleanup_time = datetime.timedelta(minutes=int(row['cleanup_time']))

        self.rows = []
        self.total_time = datetime.timedelta()

    @property
    def end_time(self):
        return self.start_time + self.total_time

    def create_rows(self, teamcnt):
        rowcnt = math.ceil(teamcnt / self.columns)
        self.rows = [Row(self, i) for i in range(rowcnt)]
        self.total_time = rowcnt * (self.row_time + self.cleanup_time)

    @staticmethod
    def load(filename):
        with open(filename) as csvfile:
            reader = csv.DictReader(csvfile)
            return [Block(row) for row in reader]
