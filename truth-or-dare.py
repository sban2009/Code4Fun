import random


def truth_or_dare(number_of_players):
    """
    Plays a truth or dare game with number_of_players as the upper limit of choices.
    Returns a string like x -> y where player x challenges player y.
    """
    if number_of_players <= 1 or not isinstance(number_of_players, int):
        return "Please enter an integer greater than 1."

    x = random.randint(1, number_of_players)
    choices = [i for i in range(1, number_of_players + 1) if i != x]
    y = random.choice(choices)

    return f"{x} -> {y}"


result = truth_or_dare(5)
print(result)


def truth_or_dare_labelled(player_list_string):
    """
    Plays a truth or dare game with player_list_string as the comma-separated list of players.
    Returns a string like "Alice -> Bob" where player named Alice challenges player named Bob.
    """
    player_list = player_list_string.split(",")
    player_list.sort()
    print(player_list)
    number_of_players = len(player_list)
    if number_of_players <= 1:
        return "Please enter an integer greater than 1."
    if len(set(player_list)) != len(player_list):
        return "Please enter unique player names."
    x = random.choice(player_list)
    player_list.remove(x)
    y = random.choice(player_list)

    return f"{x} -> {y}"


alt_result = truth_or_dare_labelled("Alice,Bob,Charlie,David")
print(alt_result)
