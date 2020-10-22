const express = require('express');
const bodyParser = require('body-parser');

const app = express();

app.use(bodyParser.json());

app.post("/", (req, res) => {
    console.log("REQUESE OK");
    console.log(req.body);
    res.send(req.body);
});

app.listen(3000, function () {
    console.log('Example app listening on port 3000!');
});