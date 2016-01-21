import team, block

teams = team.Team.load('teams.csv')
blocks = block.Block.load('blocks.csv')

for block in blocks:
    block.create_rows(len(teams))
    print(block.name, block.start_time, block.end_time)
