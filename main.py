import team, block
import generator
import outputter

teams = team.Team.load('teams.csv')
blocks = block.Block.load('blocks.csv')

for block in blocks:
    block.create_rows(len(teams))
    print(block.name, block.start_time, block.end_time)

generator.generate(teams, blocks)

output = outputter.Outputter(teams, blocks)
output.by_team('by_team.csv')
