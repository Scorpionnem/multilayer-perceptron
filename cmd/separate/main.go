package main

import (
	"fmt"
	"os"
	"time"
	"log"
	"bufio"
	"math/rand"

	"github.com/pborman/options"
)

var opts = struct {
	Help        options.Help `getopt:"--help -h           			display help"`
	Input       string       `getopt:"--input -i=*.csv      		input file"`
	OutputCheck string       `getopt:"--outcheck -c=*.csv      		check output file"`
	OutputTrain string       `getopt:"--outtrain -t=*.csv      		train output file"`
	Seed        int64        `getopt:"--seed -s=int64 				seed for random"`
	Split		float64		 `getopt:--split -S=float				split of input lines`
}{
	Input:       "data.csv",
	OutputCheck: "check.csv",
	OutputTrain: "train.csv",
	Split: 0.5,
	Seed: 0,
}

func main() {
	args := options.RegisterAndParse(&opts)
	args = args

	fmt.Println("Seed:", opts.Seed)

	if (opts.Seed == 0) {
		opts.Seed = time.Now().Unix()
	}
	r := rand.New(rand.NewSource(opts.Seed))

	inputFile, err := os.Open(opts.Input)
	if err != nil {
        log.Fatal(err)
    }
    defer inputFile.Close()

    outputCheckFile, err := os.Create(opts.OutputCheck)
	if err != nil {
           log.Fatal(err)
       }
    defer outputCheckFile.Close()

    outputTrainFile, err := os.Create(opts.OutputTrain)
	if err != nil {
           log.Fatal(err)
       }
    defer outputTrainFile.Close()

    checkLines := 0
    trainLines := 0

    scanner := bufio.NewScanner(inputFile)
    for scanner.Scan() {
    	if (r.Float64() > opts.Split) {
     		_, err := outputCheckFile.WriteString(scanner.Text())
       		if (err != nil) {
         		log.Fatal(err)
         	}
       		checkLines++
		} else {
			_, err := outputTrainFile.WriteString(scanner.Text())
			if (err != nil) {
         		log.Fatal(err)
         	}
			trainLines++
		}
    }

    if err := scanner.Err(); err != nil {
        log.Fatal(err)
    }

	fmt.Printf("Check Lines %d (%s)\n", checkLines, opts.OutputCheck)
    fmt.Printf("Train Lines %d (%s)\n", trainLines, opts.OutputTrain)
}
