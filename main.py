import team, block
import generator
import outputter

teams = team.load('teams.csv')
blocks = block.load('blocks.csv')

block.create_rows(teams, blocks)

for block in blocks:
    print(block.name, block.start_time, block.end_time)

if generator.generate(teams, blocks):
    print('generate successful')
    output = outputter.Outputter(teams, blocks)
    output.by_team('by_team.csv')
    output.all_blocks('block_{}.csv')
else:
    print('generate failed')
