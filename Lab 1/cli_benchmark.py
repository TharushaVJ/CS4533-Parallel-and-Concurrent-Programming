import subprocess
import json
import statistics

# Configuration parameters
# You can modify these parameters as needed
implementation = "serial"           # Options: "serial", "mutex", "rwlock"
threads = 1                         # Number of threads (ignored for serial implementation)
number_of_nodes = 1000              # Initial number of nodes in the list
number_of_operations = 10000        # Total number of operations to perform
mMember = 0.99                      # Fraction of member operations
mInsert = 0.005                     # Fraction of insert operations
mDelete = 0.005                     # Fraction of delete operations
seed = None                         # Random seed (None for random seed)
trial_count = 40                    # Number of trials to run


COMMAND = ["./lablist", "--impl", implementation, "--threads", str(threads), "--n", str(number_of_nodes), "--m", str(number_of_operations), "--mMember", str(mMember), "--mInsert", str(mInsert), "--mDelete", str(mDelete)]
if seed is not None:
    COMMAND += ["--seed", str(seed)]
    
elapsed_times = []

for _ in range(trial_count):
    result = subprocess.run(COMMAND, capture_output=True, text=True)
    try:
        output_json = json.loads(result.stdout.strip())
        elapsed_times.append(output_json["elapsed_sec"])
    except Exception as e:
        print(f"Error parsing output: {e}")
        continue

if elapsed_times:
    avg_time = sum(elapsed_times) / len(elapsed_times)
    std_dev = statistics.stdev(elapsed_times)
    print(f"| {implementation} | Threads: {threads} | n: {number_of_nodes} | m: {number_of_operations} | mMember: {mMember} | mInsert: {mInsert} | mDelete: {mDelete} |")
    print(f"Average execution time: {avg_time:.9f} seconds")
    print(f"Standard deviation: {std_dev:.9f} seconds")
else:
    print("No valid elapsed_sec values collected.")