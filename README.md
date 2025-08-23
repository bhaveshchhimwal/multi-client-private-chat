
# 📘 README — Multi-Client Private Chat (C++

## 🚀 Features
- Multi-client chat using sockets.  
- Each client is identified by a **name**.  
- Messages are displayed as:  
  ClientName: message  
- Private messages with **@mentions**:  
  (private) Alice: hey @Bob  

---

## 🖥️ Build Instructions

### 🔹 macOS / Linux
```bash
g++ -std=c++17 server.cpp -o server
g++ -std=c++17 client.cpp -o client
```
Run the server:
```bash
./server
```
Run a client:
```bash
./client
```

### 🔹 Windows (MinGW / g++)
```powershell
g++ -std=c++17 server.cpp -o server.exe -lws2_32
g++ -std=c++17 client.cpp -o client.exe -lws2_32
```
Run the server:
```powershell
server.exe
```
Run a client:
```powershell
client.exe
```

---

## 🌐 Multi-Device Setup
By default, the client connects to `127.0.0.1` (localhost).  
If you want to connect from **another device on the same Wi-Fi/LAN**, you must change this in **client.cpp**:

```cpp
// Change this line in client.cpp
std::string server_ip = "127.0.0.1";  // default (same computer)

// Example: use your server machine’s LAN IP
std::string server_ip = "192.168.1.100";  // replace with actual IP
```

➡️ To find your server’s LAN IP:
- **macOS/Linux**: `ifconfig` or `ip addr show`
- **Windows**: `ipconfig`

Then rebuild the client and run it from the other device.

---

## 📝 Usage
1. Start the **server** first.  
2. Run multiple **clients** (on same or different machines).  
3. Each client will be asked for a **name**.  
4. Chat messages will appear like:  
   Alice: hello everyone  
   Bob: hi Alice  
5. To send a **private message**:  
   hey @Bob  
   → Only Bob will receive:  
   (private) Alice: hey @Bob  
