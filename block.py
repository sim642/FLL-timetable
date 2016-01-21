import csv
import datetime
import math

class Row:
    def __init__(self, block, i):
        self.block = block

        self.columns = block.columns
        self.setup_time = block.setup_time
        self.row_time = block.row_time
        self.cleanup_time = block.cleanup_time

        self.total_time = self.row_time + self.cleanup_time
        self.start_time = block.start_time + i * self.total_time

        self.teams = []

    @property
    def end_time(self):
        return self.start_time + self.total_time

    @property
    def free_columns(self):
        return self.columns - len(self.teams)

    def during(self, dt):
        return self.start_time - self.setup_time <= dt < self.end_time - self.cleanup_time

    def conflicts(self, other):
        return self.during(other.start_time) or other.during(self.start_time)

    def any_conflicts(self, iterable):
        return any((self.conflicts(other) for other in iterable))

class Block:
    def __init__(self, row):
        self.name = row['name']
        self.columns = int(row['columns'])

        try:
            self.start_time = datetime.datetime.strptime(row['start_time'], '%Y-%m-%d %H:%M')
            self.parent = None
        except ValueError:
            self.start_time = None
            self.parent = row['start_time']

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


def load(filename):
    with open(filename) as csvfile:
        reader = csv.DictReader(csvfile)
        return [Block(row) for row in reader]

def create_rows(teams, blocks):
    for block in blocks:
        if block.parent:
            parents = [parent for parent in blocks if parent.name == block.parent]
            assert len(parents) == 1, 'No/excess parent blocks found'

            block.parent = parents[0]
            block.start_time = block.parent.end_time

        block.create_rows(len(teams))
