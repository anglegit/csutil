#test

#PARAM
CSUTIL_DIR 	= ../..

include $(CSUTIL_DIR)/makefile.header

BASE_DIR 	= $(CSUTIL_DIR)/base
CS_DIR 		= $(CSUTIL_DIR)/cs
FTP_DIR 	= $(CSUTIL_DIR)/ftp
PROBUF_DIR 	= /usr/local/protobuf/include
CC 			= g++
CFLAGS 		= -g -c -Wall -fPIC  -I$(CSUTIL_DIR) -I$(PROBUF_DIR) -pthread
OBJS 		= $(BASE_DIR)/log.o $(BASE_DIR)/random.o $(BASE_DIR)/ip.o\
			  $(BASE_DIR)/time.o $(BASE_DIR)/load_ctrl.o $(BASE_DIR)/event_poll.o\
			  $(BASE_DIR)/coding.o $(BASE_DIR)/msg.o \
			  $(BASE_DIR)/event_loop.o $(BASE_DIR)/config.o\
			  $(BASE_DIR)/util.o $(BASE_DIR)/statistic.o\
			  $(CS_DIR)/server.o\
			  $(CS_DIR)/client.o\
			  $(FTP_DIR)/pb/src/ftp_model.pb.o $(FTP_DIR)/pb/src/ftp_rpc.pb.o\
			  client_ftp.o
LIB 		+= /usr/local/protobuf/lib/libprotobuf.a
ifeq ($(PLATFORM), Linux)
OBJS 		+= $(BASE_DIR)/event_epoll.o
endif

#.PHONY
.PHONY : all client clean

all : client clean

client : $(OBJS)
	$(CC) -o $@ $^ $(LIB) -lpthread

clean : 
	rm -fr $(OBJS)

#OBJS
$(OBJS) : %.o : %.cc
	$(CC) $(CFLAGS) -o $@ $<
