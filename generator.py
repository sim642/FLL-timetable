def generate(teams, blocks, i=0, j=0):
    #print(i, j)
    if i == len(teams):
        return True
    elif j == len(blocks):
        return generate(teams, blocks, i + 1, 0)
    else:
        team = teams[i]
        for row in blocks[j].rows:
            if row.free_columns > 0 and not row.any_conflicts(team.rows):
                team.rows.append(row)
                row.teams.append(team)

                r = generate(teams, blocks, i, j + 1)
                if r:
                    return True

                row.teams.pop()
                team.rows.pop()
        return False
