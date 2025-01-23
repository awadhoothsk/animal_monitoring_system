# Smart Animal Monitoring System using IoT and Wireless Sensor Networks

## 📌 Project Overview
The **Smart Animal Monitoring System** is designed to track and analyze various health metrics of animals, such as **heart rate (BPM), temperature, and environmental conditions**, using IoT-based wireless sensor networks. This project helps farmers, veterinarians, and researchers monitor the well-being of animals in real time.

## 📋 Features
- 📡 **IoT-Enabled Monitoring**: Uses wireless sensors to collect real-time data.
- 📊 **Health Parameters Tracking**: Monitors BPM, temperature, and environmental factors.
- 🔗 **Cloud Integration**: Sends collected data to a cloud platform (e.g., Ubidots) for remote access.
- 📈 **Data Visualization**: Displays sensor readings in an interactive dashboard.
- 🔔 **Alert System**: Sends notifications if abnormal readings are detected.

## 🛠️ Technology Stack
- **Hardware**: NodeMCU ESP8266, Pulse Sensor, DHT22 Sensor, MQ-135 Gas Sensor, Water Level Sensor.
- **Software**: Arduino IDE, Python, Ubidots Cloud.
- **Communication**: WiFi-based IoT architecture.

## 🚀 Installation Guide
1. Clone this repository:
   ```sh
   git clone https://github.com/your-username/Smart-Animal-Monitoring.git
   cd Smart-Animal-Monitoring
   ```
2. Install required dependencies:
   ```sh
   pip install requests json
   ```
3. Upload the Arduino sketch to NodeMCU.
4. Configure WiFi settings in the Arduino code.
5. Set up Ubidots API keys for cloud data storage.

## 🖥️ Usage
- Power on the device and connect it to WiFi.
- Sensor data will be transmitted to the cloud.
- Access the Ubidots dashboard to visualize health metrics.
- Receive alerts in case of anomalies.

## 💰 Cost Estimation
| Item/Component | Quantity | Unit Price (INR) | Total Cost (INR) |
|---------------|----------|------------------|------------------|
| NodeMCU ESP8266 | 1 | ₹450 | ₹450 |
| Pulse Sensor | 1 | ₹300 | ₹300 |
| MQ-135 Gas Sensor | 1 | ₹250 | ₹250 |
| DHT22 Sensor | 1 | ₹350 | ₹350 |
| Water Level Sensor | 1 | ₹200 | ₹200 |
| Miscellaneous (Wires, PCB, etc.) | 1 | ₹1,500 | ₹1,500 |
| Power Supply (Batteries, Chargers) | 1 | ₹500 | ₹500 |
| Enclosure for Sensors | 1 | ₹300 | ₹300 |
| Ubidots Subscription (1 Month) | 1 | ₹3,700 | ₹3,700 |
| **Total Cost** | - | - | **₹7,550** |

## 📝 Authors
- **Aditya H** (1SI21CS002)
- **Awadhooth Shrinivas Kulkarni** (1SI21CS025)
- **Dhanush M** (1SI21CS038)

## 🎯 Future Scope
- 📶 Integration with **LoRaWAN** for long-range communication.
- 📊 AI-based **health prediction models** for early disease detection.
- 📡 Expansion to **livestock tracking** using GPS modules.

## 📜 License
This project is open-source and available under the **MIT License**.
