import threading
import time
import subprocess
import signal
import sys
import os

from Start_Server import start_server  # renamed function
from Extract import extract_and_send

# Global so the main thread can access it
gradle_proc = None

def cleanup(signum, frame):
    print(f"Received signal {signum}, terminating gradlew...")
    global gradle_proc
    if gradle_proc is not None:
        try:
            os.killpg(os.getpgid(gradle_proc.pid), signal.SIGTERM)
        except Exception as e:
            print(f"Error killing gradlew: {e}")
    sys.exit(0)

def start_gradlew():
    global gradle_proc
    gradle_proc = subprocess.Popen(
        ["./gradlew", "simulateJava"],
        cwd="/Users/adityachakraborty/Desktop/Code/Java/Robotics/2025/NetworkTablesDrivetrain",
        preexec_fn=os.setsid  # Create new process group
    )
    gradle_proc.wait()

if __name__ == "__main__":
    # Set up signal handlers in main thread
    signal.signal(signal.SIGTERM, cleanup)
    signal.signal(signal.SIGINT, cleanup)

    # Start gradlew in its own thread
    thread_a = threading.Thread(target=start_gradlew)
    thread_a.start()

    # Wait a little, then start extract_and_send
    time.sleep(2)
    thread_b = threading.Thread(target=extract_and_send)
    thread_b.start()

    # Wait for both
    thread_a.join()
    thread_b.join()

    print("Both threads finished.")
