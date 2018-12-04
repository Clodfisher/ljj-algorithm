package main

import (
	"ljjproject/logger"
)

func initLogger(logpath, logname, loglevel string) (err error) {
	m := make(map[string]string, 8)
	m["log_path"] = logpath
	m["log_name"] = logname
	m["log_level"] = loglevel
	m["log_split_type"] = "size"
	m["log_split_size"] = "104857600"

	err = logger.InitLogger("file", m)
	if err != nil {
		return err
	}
	//log = logger.NewConsoleLoger(level)
	logger.Debug("init logger success")
	return
}

func run() {
	for {
		logger.Debug("user server is running")
		//time.Sleep(time.Second)
	}
}
func main() {
	initLogger("d:/ljj", "interface", "debug")
	run()
}
