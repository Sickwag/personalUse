import http.server
import socketserver
import json
import urllib.parse

class MyHandler(http.server.BaseHTTPRequestHandler):
    def do_OPTIONS(self):
        self.send_response(200)
        self.send_header('Access-Control-Allow-Origin', '*')
        self.send_header('Access-Control-Allow-Methods', 'POST, GET, OPTIONS')
        self.send_header('Access-Control-Allow-Headers', 'Content-Type')
        self.send_header('Access-Control-Max-Age', '86400')
        self.send_header('Content-Length', '0')
        self.end_headers()
    
    def do_POST(self):
        content_length = int(self.headers['Content-Length'])
        post_data = self.rfile.read(content_length)
        
        print(f"Received POST request to {self.path}")
        print(f"Data: {post_data.decode('utf-8')}")
        
        # 解析 JSON 数据
        try:
            data = json.loads(post_data.decode('utf-8'))
            username = data.get('username', '')
            password = data.get('password', '')
            
            print(f"Username: {username}, Password: {password}")
            
            # 模拟响应
            if self.path == '/register':
                response_data = {"success": True, "message": "Registration successful"}
            elif self.path == '/login':
                response_data = {"success": True, "message": "Login successful"}
            else:
                response_data = {"success": False, "message": "Unknown path"}
                
        except json.JSONDecodeError:
            response_data = {"success": False, "message": "Invalid JSON"}
        
        # 发送响应
        self.send_response(200)
        self.send_header('Content-Type', 'application/json')
        self.send_header('Access-Control-Allow-Origin', '*')
        self.send_header('Access-Control-Allow-Methods', 'POST, GET, OPTIONS')
        self.send_header('Access-Control-Allow-Headers', 'Content-Type')
        response_body = json.dumps(response_data).encode('utf-8')
        self.send_header('Content-Length', str(len(response_body)))
        self.end_headers()
        self.wfile.write(response_body)

# 启动服务器
PORT = 8080
with socketserver.TCPServer(("", PORT), MyHandler) as httpd:
    print(f"Server running on http://localhost:{PORT}")
    httpd.serve_forever()
