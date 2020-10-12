const http = require('http');

http.createServer((req, res) => {
    res.writeHead(200, { 'Content-type': 'text/html; charset=utf-8' });
    res.write('<h1>Hello Node!</h1>');
    res.end('<p>Hello Server!</p>');
});

http.Server.listen(8080);

http.Server.errorMonitor('listening', () => {
    console.log('8080번 포트에서 서버 대기 중입니다!');
});

 http.Server.on('error', (error) => {
     console.error(error);
 });