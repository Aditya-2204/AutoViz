def extract_and_send():
    """
    Extracts data from NetworkTables and sends it over a TCP connection.
    The data includes the angle and velocity of each swerve module.
    """
    import socket
    import json
    import time
    import os
    from networktables import NetworkTables  # type: ignore

    # Load swerve module names from the JSON file
    cwd = os.getcwd()
    cwd = cwd.replace("build/Desktop_x86_darwin_generic_mach_o_64bit-Debug/AutoViz.app/Contents/MacOS","")
    config_loc = os.path.join(cwd, "NTData/config.json")


    with open(config_loc, "r") as file:
        data = json.load(file)

    try:
        swerve_module_names = data["swerve-modules"]
    except KeyError:
        raise KeyError("Missing 'swerve-modules' key in config.json")

    # Initialize NetworkTables
    NetworkTables.initialize(server='localhost')
    inst = NetworkTables.getDefault()

    # Wait for NetworkTables connection (with timeout)
    start_time = time.time()
    while not inst.isConnected():
        if time.time() - start_time > 10:
            raise TimeoutError("NetworkTables failed to connect within 10 seconds.")
        time.sleep(0.1)

    swerve_table = NetworkTables.getTable("SwerveDrive")

    # Create a TCP/IP socket
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.settimeout(30)  # Timeout for client connection
    server_socket.bind(('localhost', 0))  # Bind to a free port
    server_socket.listen(1)

    host, port = server_socket.getsockname()
    print(f"Waiting for a client to connect on {host}:{port}...")

    # Update port in JSON and save
    data["free-port"]=port

    with open(config_loc, "w") as file:
        json.dump(data, file, indent=2)

    try:
        client_socket, addr = server_socket.accept()
    except socket.timeout:
        print("No client connected within timeout window.")
        server_socket.close()
        return

    print(f"Client connected from {addr}")

    try:
        while True:
            packet = {}
            for key,name in swerve_module_names.items():
                angle = swerve_table.getNumber(f"{name}/angle", 0)
                velocity = swerve_table.getNumber(f"{name}/velocity", 0)
                packet[name] = {"angle": angle, "velocity": velocity}
                packet[key] = {
                    "name": name,
                    "angle": angle,
                    "velocity": velocity
                    }
            # Send the packet as a JSON string
            json_packet = json.dumps(packet)
            client_socket.sendall(json_packet.encode('utf-8'))
            print(f"Sent packet: {json_packet}")

    except (ConnectionResetError, BrokenPipeError):
        print("Client disconnected.")
    except KeyboardInterrupt:
        print("Server interrupted by user.")
    finally:
        client_socket.close()
        server_socket.close()

if __name__ == "__main__":
    extract_and_send()
