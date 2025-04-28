def start_server():
    import subprocess
    import signal
    import sys
    import os
    """
    Starts the NetworkTables server and listens for incoming connections.
    The server sends swerve module data to the connected client.
    """
    # Start gradlew, but make sure it stays attached
    gradle_proc = subprocess.Popen(
        ["./gradlew", "simulateJava"],
        cwd="/Users/adityachakraborty/Desktop/Code/Java/Robotics/2025/NetworkTablesDrivetrain",
        preexec_fn=os.setsid  # <- important
    )

    def cleanup(signum, frame):
        os.killpg(os.getpgid(gradle_proc.pid), signal.SIGTERM)
        sys.exit(0)

    signal.signal(signal.SIGTERM, cleanup)
    signal.signal(signal.SIGINT, cleanup)

    gradle_proc.wait()