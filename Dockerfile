FROM debian:stretch-slim AS builder
RUN apt-get update && apt-get -y install --no-install-recommends \
    cmake \
    dpkg-dev \
    g++ \
    cmake \
    python3 \
    && rm -rf /var/lib/apt/lists/*
COPY . /src
WORKDIR /build
RUN cmake -DCMAKE_BUILD_FOR_DOCKER_IMAGE=1 /src
RUN make -j package

FROM debian:stretch-slim
COPY --from=builder /build/enjector-event.grid-0.0.1-Linux-event.grid-node.deb /
RUN dpkg --install /enjector-event.grid-0.0.1-Linux-event.grid-node.deb
CMD ["event.grid-node"]
