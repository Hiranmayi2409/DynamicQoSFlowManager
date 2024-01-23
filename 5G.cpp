#include <iostream>
#include <vector>

// Define QoS Flow class
class QoSFlow {
public:
    int flowId;
    int latency;        // in milliseconds
    int throughput;     // in Mbps
    int reliability;    // percentage
    int jitter;         // in milliseconds

    // Constructor
    QoSFlow(int id, int lat, int thr, int rel, int jit)
        : flowId(id), latency(lat), throughput(thr), reliability(rel), jitter(jit) {}

    // Function to update QoS parameters
    void updateQoS(int lat, int thr, int rel, int jit) {
        latency = lat;
        throughput = thr;
        reliability = rel;
        jitter = jit;
    }

    // Function to display QoS information
    void displayQoSInfo() const {
        std::cout << "Flow ID: " << flowId << std::endl;
        std::cout << "Latency: " << latency << " ms" << std::endl;
        std::cout << "Throughput: " << throughput << " Mbps" << std::endl;
        std::cout << "Reliability: " << reliability << "%" << std::endl;
        std::cout << "Jitter: " << jitter << " ms" << std::endl;
        std::cout << std::endl;
    }
};

// Define QoS Manager class
class QoSManager {
public:
    std::vector<QoSFlow> qosFlows;

    // Function to add a predefined QoS flow
    void addQoSFlow(int flowId, int lat, int thr, int rel, int jit) {
        QoSFlow newFlow(flowId, lat, thr, rel, jit);
        qosFlows.push_back(newFlow);
    }

    // Function to create a new QoS flow dynamically
    void createQoSFlow(int flowId) {
        // In a real scenario, you might obtain these parameters from user input or other dynamic sources.
        int lat, thr, rel, jit;
        std::cout << "Enter latency, throughput, reliability, and jitter for Flow " << flowId << ": ";
        std::cin >> lat >> thr >> rel >> jit;

        QoSFlow newFlow(flowId, lat, thr, rel, jit);
        qosFlows.push_back(newFlow);
    }

    // Function to update QoS parameters for a flow
    void updateQoSParameters(int flowId, int lat, int thr, int rel, int jit) {
        for (auto& flow : qosFlows) {
            if (flow.flowId == flowId) {
                flow.updateQoS(lat, thr, rel, jit);
                break;
            }
        }
    }

    // Function to display all QoS flows
    void displayAllQoSFlows() const {
        std::cout << "QoS Flows Information:" << std::endl;
        for (const auto& flow : qosFlows) {
            flow.displayQoSInfo();
        }
    }
};

int main() {
    // Create QoS Manager
    QoSManager qosManager;

    // Add predefined QoS flows
    qosManager.addQoSFlow(1, 10, 100, 99, 5);
    qosManager.addQoSFlow(2, 20, 50, 95, 2);
    qosManager.addQoSFlow(3, 15, 75, 98, 3);

    // Display initial QoS flows
    qosManager.displayAllQoSFlows();

    // Update QoS parameters for a flow
    qosManager.updateQoSParameters(2, 25, 60, 97, 4);

    // Display updated QoS flows
    qosManager.displayAllQoSFlows();

    // Create a new QoS flow dynamically
    qosManager.createQoSFlow(4);

    // Display all QoS flows after dynamic creation
    qosManager.displayAllQoSFlows();

    return 0;
}
