const express = require('express');

const app = express();

app.use(express.json());

app.post("/", (req, res) => {
    console.log("REQUESE OK");
    console.log(req.body);
    res.send(req.body);
});

app.listen(3000, function () {
    console.log('Example app listening on port 3000!');
});