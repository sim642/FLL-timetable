import csv

class Outputter:
    def __init__(self, teams, blocks):
        self.teams = teams
        self.blocks = blocks

    def by_team(self, filename):
        with open(filename, 'w') as csvfile:
            fields = ['name'] + [block.name for block in self.blocks]
            writer = csv.DictWriter(csvfile, fieldnames=fields)

            writer.writeheader()

            for team in self.teams:
                rowdict = {'name': team.name}
                for row in team.rows:
                    rowdict[row.block.name] = row.start_time.strftime('%Y-%m-%d %H:%M')
                writer.writerow(rowdict)
