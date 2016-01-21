import team, block
import generator
import outputter

teams = team.Team.load('teams.csv')
blocks = block.Block.load('blocks.csv')

block.Block.blocks_create_rows(teams, blocks)

for block in blocks:
    print(block.name, block.start_time, block.end_time)

if generator.generate(teams, blocks):
    print('generate successful')
    output = outputter.Outputter(teams, blocks)
    output.by_team('by_team.csv')
    output.all_blocks('block_')
else:
    print('generate failed')
