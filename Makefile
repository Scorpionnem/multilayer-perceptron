BINS = separate train predict

all: $(BINS)

train:
	go build -o train ./cmd/train

predict:
	go build -o predict ./cmd/predict

separate:
	go build -o separate ./cmd/separate

clean:
	rm -f $(BINS) *.png

re: clean all

.PHONY: all clean re train predict separate
