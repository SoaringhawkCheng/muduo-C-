#ifndef MUDUO_EXAMPLES_SIMPLE_ECHO_ECHO_H
#define MUDUO_EXAMPLES_SIMPLE_ECHO_ECHO_H

#include <muduo/net/TcpServer.h>

// RFC 862
class EchoServer
{
 public:
  EchoServer(muduo::net::EventLoop* loop,
             const muduo::net::InetAddress& listenAddr,
             int maxConnections);

  void start();

 private:
  void onConnection(const muduo::net::TcpConnectionPtr& conn);

  void onMessage(const muduo::net::TcpConnectionPtr& conn,
                 muduo::net::Buffer* buf,
                 muduo::Timestamp time);

  muduo::net::TcpServer server_;
  int numConnected_; // should be atomic_int 记录客户连接数目
  const int kMaxConnections_; // 最大连接数量
};

#endif  // MUDUO_EXAMPLES_SIMPLE_ECHO_ECHO_H
