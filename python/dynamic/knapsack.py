def init_store():
    store = []
    store.append({"name": "guitar", "weight": 1, "value": 1500})
    store.append({"name": "laptop", "weight": 3, "value": 2000})
    store.append({"name": "stereo", "weight": 4, "value": 3000})
    return store

store = init_store()
pack_size = 4
memo = [[0 for _ in range(pack_size)] for _ in range(len(store))]

def knapsack(store, interactor, pack_capacity):
    print "interactor: ", interactor
    print "capacity: ", pack_capacity
    if memo[interactor][pack_capacity] != 0:
        return memo[interactor][pack_capacity]
    if interactor == len(store) or pack_capacity == 0:
        result = 0
    elif store[interactor]["weight"] > pack_capacity:
        result = knapsack(store, interactor - 1, pack_capacity)
    else:
        no_case = knapsack(store, interactor - 1, pack_capacity)
        yes_case = store[interactor]["value"] + knapsack(store, interactor - 1, pack_capacity - store[interactor]["weight"])
        result = max(no_case, yes_case)
    memo[interactor][pack_capacity] = result
    return result

def main():
    best = knapsack(store, len(store) - 1, pack_size - 1)
    print "best value:", best

if __name__ == "__main__":
    main()