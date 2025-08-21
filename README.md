# 🔒 Multi-Client Private Chat (C++ Sockets)

This is a simple **multi-client private chat system** built with **C++** and sockets.  
It allows multiple clients to connect to a central server and exchange private messages.  

---

## ✨ Features
- Multi-client support (each client handled in a separate thread)  
- Clients are identified by **usernames**  
- Server can send private messages to any client  
- Works both on **same device (localhost)** and on **different devices in same network (LAN/WiFi)**  

---

## ⚙️ Requirements
- A C++11 or higher compatible compiler (g++, clang++)
- Unix-based OS (Linux / macOS).  
  > Windows users can use WSL (Windows Subsystem for Linux).  

---

## 🛠️ Compilation

### Compile the server:
```bash
g++ -std=c++11 server.cpp -o server -pthread
```

### Compile the client:
```bash
g++ -std=c++11 client.cpp -o client -pthread
```

---

## 🚀 Usage

### 1. Run on the **same device**
1. Start the server:
   ```bash
   ./server
   ```
   You should see:
   ```
   [INFO] Server listening on port 12345
   ```

2. Start clients (open multiple terminals):
   ```bash
   ./client
   ```
   Enter your username when prompted.  

3. Now you can chat!  
   - Clients send messages to the server.  
   - The server can send private messages using:
     ```
     ClientName: message
     ```

---

### 2. Run on **different devices (LAN/WiFi)**
1. On the **server machine**, check your local IP address:  
   ```bash
   ifconfig | grep inet
   ```
   Example result:
   ```
   inet 192.168.202.155
   ```
   This is the **server IP**.

2. Run the server on that machine:
   ```bash
   ./server
   ```

3. On the **client machine**, run:
   ```bash
   ./client 192.168.202.155
   ```
   (Replace with the server’s IP).  

4. If both devices are on the same WiFi/LAN, the client should connect successfully.  

✅ You can confirm connectivity using `ping`:
```bash
ping 192.168.202.155
```

---

## 📌 Example
- Server starts on IP `192.168.202.155:12345`  
- Alice runs `./client 192.168.202.155`  
- Bob runs `./client 192.168.202.155`  
- Server can type:
  ```
  Alice: Hello!
  ```
  ✅ Alice receives: `Server: Hello!`  

---

## ⚠️ Notes
- Both server and clients must be on the **same network** for LAN communication.  
- For communication over the internet (WAN), you’d need **port forwarding** on the router (advanced).  
- By default, the server listens on port `12345` (can be changed in `server.cpp`).  
