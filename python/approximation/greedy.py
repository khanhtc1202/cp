def init():
    states = set(["mt", "wa", "or", "id", "nv", "ut", "ca", "az"])
    stations = {}
    stations["kone"] = set(["id", "nv", "ut"])
    stations["ktwo"] = set(["wa", "id", "mt"])
    stations["kthree"] = set(["or", "nv", "ca"])
    stations["kfour"] = set(["nv", "ut"])
    stations["kfive"] = set(["ca", "az"])
    return stations, states

def greedy(stations, total_states):
    final_stations = set()
    while total_states:
        best_station = None
        states_covered = set()
        for station, states in stations.items():
            covered = total_states & states
            if len(covered) > len(states_covered):
                best_station = station
                states_covered = covered
        total_states -= states_covered
        final_stations.add(best_station)
    return final_stations

def main():
    stations, states = init()
    best_stations = greedy(stations, states)
    print best_stations

if __name__ == "__main__":
    main()