#include <pulsar/Client.h>
#include <iostream>

int main(int argc, char *argv[]) {
    pulsar::ClientConfiguration config;
    pulsar::Client client("pulsar://localhost:6650", config);

    pulsar::Producer producer;
    pulsar::Result result = client.createProducer("my-topic", producer);

    producer.send(pulsar::MessageBuilder().setContent("Hello, Pulsar!").build());

    pulsar::Consumer consumer;
    pulsar::Result cResult = client.subscribe("my-topic", "my-subscription", consumer);

    pulsar::Message msg;
    consumer.receive(msg);

    std::cout << "Received message with content '" << msg.getDataAsString() << "'" << std::endl;

    return 0;
}