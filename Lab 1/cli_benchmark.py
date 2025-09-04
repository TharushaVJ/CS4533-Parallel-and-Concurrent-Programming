import subprocess
import json
import statistics

COMMAND = ["./lablist", "--impl", "mutex", "--threads", "4", "--n", "1000", "--m", "10000", "--mMember", "0.99", "--mInsert", "0.005", "--mDelete", "0.005"] 
elapsed_times = []

for _ in range(40):
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
    print(f"Average execution time: {avg_time:.9f} seconds")
    print(f"Standard deviation: {std_dev:.9f} seconds")
else:
    print("No valid elapsed_sec values collected.")