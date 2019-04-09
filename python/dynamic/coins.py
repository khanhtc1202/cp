import time

def rec_trait(total, arr_coins, index):
    if index < 0: return 0
    if arr_coins[index] > total:
        return rec_trait(total, arr_coins, index - 1)
    else:
        get_coin = rec_trait(total - arr_coins[index], arr_coins, index) + 1
        not_get_coin = rec_trait(total, arr_coins, index - 1)
        return min(get_coin, not_get_coin) # <- shit here

def greedy_trait(total, arr_coins, index):
    if index < 0: return 0
    if arr_coins[index] > total:
        return greedy_trait(total, arr_coins, index - 1)
    else:
        n = total / arr_coins[index]
        total -= (n*arr_coins[index])
        return greedy_trait(total, arr_coins, index - 1) + n

def run_time(func, print_output, *args):
    start_time = time.time()
    out = func(*args)
    end_time = time.time()
    if print_output: print out
    return end_time - start_time

def main():
    total = 241
    coins = [1, 5, 10, 50, 100, 500]
    print("Greedy trait strategy %f" % (run_time(greedy_trait, True, total, coins, len(coins) - 1)))
    print("Recursion trait strategy %f" % (run_time(rec_trait, True, total, coins, len(coins) - 1)))

if __name__ == "__main__":
    main()