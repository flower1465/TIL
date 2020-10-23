const express = require('express');

const app = express();

app.set('port', precess.env.PORT || 3000);

app.get('/', (req, res) => {
    res.send('hello, Express');
});

app.listen(app.get('port', () => {
    console.log(app.get('port', '빈 포트에서 대기 중'));
}));