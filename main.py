import team, block
import generator
import outputter

teams = team.Team.load('teams.csv')
blocks = block.Block.load('blocks.csv')

for block in blocks:
    block.create_rows(len(teams))
    #print(block.name, block.start_time, block.end_time)

if generator.generate(teams, blocks):
    print('generate successful')
    output = outputter.Outputter(teams, blocks)
    output.by_team('by_team.csv')
    output.all_blocks('block_')
else:
    print('generate failed')
