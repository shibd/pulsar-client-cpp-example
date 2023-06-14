#include <pulsar/Client.h>
#include <iostream>

int main(int argc, char *argv[]) {
    pulsar::ClientConfiguration config;
    pulsar::Client client("pulsar://localhost:6650", config);

    pulsar::ProducerConfiguration producerConfig;
    pulsar::Producer producer = client.createProducer("my-topic", producerConfig);

    producer.send(pulsar::MessageBuilder().setContent("Hello, Pulsar!").build());

    pulsar::ConsumerConfiguration consumerConfig;
    pulsar::Consumer consumer = client.subscribe("my-topic", "my-subscription", consumerConfig);

    pulsar::Message msg;
    consumer.receive(msg);

    std::cout << "Received message with content '" << msg.getDataAsString() << "'" << std::endl;

    return 0;
}