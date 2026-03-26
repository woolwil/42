def ft_count_harvest_recursive(curr_day=1, max_days=None):
    if max_days is None:
        max_days = int(input("Days until harvest: "))
    if curr_day > max_days:
        return
    print("Day", curr_day)
    ft_count_harvest_recursive(curr_day + 1, max_days)
